import array
import time
import deepcraft_model as m
from machine import I2C, Pin
import bmi270
import configuration as cfg

# -------------------------
# INITIALISIERUNG
# -------------------------

model = m.DEEPCRAFT()
model.init()

output_dim = model.get_model_output_dim()
input_dim = model.get_model_input_dim()

output_buffer = array.array('f', [0.0] * output_dim)
input_buffer = array.array('f', [0.0] * input_dim)

i2c = I2C(scl=Pin(cfg.I2C_SCL), sda=Pin(cfg.I2C_SDA))
bmi = bmi270.BMI270(i2c)

sample_time_ms = int(cfg.SAMPLE_TIME * 1000)

max_score = -1
best_label = 0
cnt = 0

# -------------------------------------------------
# Hilfsfunktionen
# -------------------------------------------------

def argmax(buffer, length):
    max_index = 0
    max_value = buffer[0]

    for i in range(1, length):
        if buffer[i] > max_value:
            max_value = buffer[i]
            max_index = i

    return max_index, max_value

print("Start main loop")

# -------------------------
# MAIN LOOP
# -------------------------

while True:

    loop_start = time.ticks_ms()

    # -------- Sensor lesen --------
    try:
        ax, ay, az = bmi.accel()
        gx, gy, gz = bmi.gyro()
    except:
        continue # I2C Fehler ignorieren
    
    input_buffer[0] = ax
    input_buffer[1] = ay
    input_buffer[2] = az
    input_buffer[3] = gx
    input_buffer[4] = gy
    input_buffer[5] = gz
    
    # -------- Modell beladen --------
    model.enqueue(input_buffer)

    # -------- Ergebnis verarbeiten --------
    if model.dequeue(output_buffer) == 0:
        
        # wahrscheinlichstes Ergebnis speichern
        best_label, max_score = argmax(output_buffer, output_dim)

        if max_score > cfg.GESTURE_THRESHOLD:
            print(cfg.LABELS[best_label])
            
            # visibility in the terminal
            cnt += 1
            if cnt > 10:
                print("")
                cnt = 0

    # -------- Sauberes Timing --------
    elapsed = time.ticks_diff(time.ticks_ms(), loop_start)

    if elapsed < sample_time_ms:
        time.sleep_ms(sample_time_ms - elapsed)
        