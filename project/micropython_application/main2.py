import time
import gc
import array
from machine import I2C
import bmi270 # Using the name recognized by your board
import deepcraft_model as m

# ============================================================
# 1. Configuration and Initialization
# ============================================================

# Labels exactly according to your model.h
LABELS = ["unlabeled", "On", "Off", "Dimmer", "Lighter"]

print("Initializing system...")
gc.collect()

# AI Model Initialization
model = m.DEEPCRAFT()
model.init()

# I2C and Sensor Initialization (P0_2 and P0_3 are standard for PSoC6)
try:
    i2c = I2C(id=0, scl='P0_2', sda='P0_3', freq=100000)
    imu = bmi270.BMI270(i2c)
    print("Sensor connected on P0_2/P0_3")
except Exception as e:
    print("Error during sensor initialization:", e)

# Prepare output buffer (5 classes according to model.h)
out_dim = model.get_model_output_dim()
probs = array.array('f', [0.0] * out_dim)

def get_prediction():
    try:
        # Data reading (universal format)
        acc = imu.accel()
        gyro = imu.gyro()

        # Model preparation (Input shape [40,6] requires enqueue of 6 elements)
        sample = array.array('f', [acc[0], acc[1], acc[2], gyro[0], gyro[1], gyro[2]])
        model.enqueue(sample)

        # Retrieving results
        if model.dequeue(probs) == 0:
            prob_max = max(probs)
            
            # Detection threshold 30% (as modified in your snippet)
            if prob_max >= 0.3:
                idx = 0
                for i in range(len(probs)):
                    if probs[i] == prob_max:
                        idx = i
                        break
                
                # Ignore (unlabeled) at index 0
                if idx > 0:
                    return idx, LABELS[idx], prob_max
    except:
        pass
    return None, None, 0

# ============================================================
# 2. Main Loop
# ============================================================

print("--- SYSTEM READY ---")
print("Waiting for gesture (On, Off, Dimmer, Lighter)...")

while True:
    # Attempt detection
    p_id, p_name, p_conf = get_prediction()

    if p_id is not None:
        print("\n>>> DETECTED: {} ({:.1f}%)".format(p_name, p_conf * 100))
        # Pause after successful detection to prevent "spamming"
        time.sleep_ms(800)
    else:
        # Small dot every 500ms as a "heartbeat"
        if time.ticks_ms() % 500 < 20:
            print(".", end="")

    # KEY TO STABILITY: 
    # 1. Clear RAM in every cycle
    gc.collect()
    
    # 2. Short 7ms pause (from the working example)
    time.sleep_ms(7)