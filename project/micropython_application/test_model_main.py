import array
import time
import deepcraft_model as m
from machine import I2C
import bmi270
import configuration as cfg
from lightbulb import MiLight

# --- Initialisierung ---
# Yeelight Instanz
bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

# DeepCraft AI Modell Setup
model = m.DEEPCRAFT()
model.init()
output_dim = model.get_model_output_dim()
input_dim = model.get_model_input_dim()
output_buffer = array.array('f', [0.0] * output_dim)
input_buffer = array.array('f', [0.0] * input_dim)

# IMU (BMI270) Setup
i2c = I2C(scl=cfg.I2C_SCL, sda=cfg.I2C_SDA)
bmi = bmi270.BMI270(i2c)

# Timing Variablen
next_tick = time.ticks_ms()
last_action_time = 0

# other variables
last_label_idx = -1
last_heartbeat = time.ticks_ms()

print("System gestartet. Warte auf Gesten...")

# --- Main Loop ---
while True:
    # 1. Daten holen (viele IMU-Treiber liefern Tupel, das ist okay)
    ax, ay, az = bmi.accel()
    gx, gy, gz = bmi.gyro()
    
    # 2. Das bestehende Array direkt befüllen (keine neue Liste!)
    input_buffer[0], input_buffer[1], input_buffer[2] = ax, ay, az
    input_buffer[3], input_buffer[4], input_buffer[5] = gx, gy, gz
    
    if model.enqueue(input_buffer) == -1:
        print("error enqueue")

    # --- model output ---
    dequeue_val = model.dequeue(output_buffer)
    
    if dequeue_val == 0:
        score = max(output_buffer)
        current_idx = list(output_buffer).index(score)
        
        # Diagnose: Alle 3 Sekunden den aktuellen Score zeigen, auch ohne Änderung
        if time.ticks_diff(time.ticks_ms(), last_heartbeat) > 3000:
            print(f"[Live] Index: {current_idx}, Score: {score*100:.1f}%")
            last_heartbeat = time.ticks_ms()

        if score > cfg.GESTURE_THRESHOLD:
            if current_idx != last_label_idx:
                label_name = cfg.LABELS[current_idx] if hasattr(cfg, 'LABELS') else current_idx
                print(f"EVENT: {label_name} ({score*100:.1f}%)")
                last_label_idx = current_idx


    # --- Timing (50Hz Steuerung) ---
    # SAMPLE_TIME ist in Sekunden angegeben
    sample_time_ms = int(cfg.SAMPLE_TIME * 1000)
    next_tick = time.ticks_add(next_tick, sample_time_ms)
    
    sleep_duration = time.ticks_diff(next_tick, time.ticks_ms())
    if sleep_duration > 0:
        time.sleep_ms(sleep_duration)
