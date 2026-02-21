import gc # Garbagecollector
import array
import time
import deepcraft_model as m
from machine import I2C, Pin
import bmi270
import configuration as cfg
from lightbulb import Lightbulb

# -------------------------
# INITIALISIERUNG
# -------------------------
# lightbulb
bulb = Lightbulb(cfg.BULB_IP, cfg.BULB_PORT)

# model
model = m.DEEPCRAFT()
model.init()
output_dim = model.get_model_output_dim()
input_dim = model.get_model_input_dim()
output_buffer = array.array('f', [0.0] * output_dim)
input_buffer = array.array('f', [0.0] * input_dim)

# IMU
i2c = I2C(scl=Pin(cfg.I2C_SCL), sda=Pin(cfg.I2C_SDA))
bmi = bmi270.BMI270(i2c)

# LED init
led = Pin(cfg.USER_LED, Pin.OUT)
led_state = False  # Eigene Variable für den Zustand
led_timer = time.ticks_ms()

# Variables and constants
sample_time_ms = int(cfg.SAMPLE_TIME * 1000)
loop_start = 0
last_action_time = 0

max_score = -1
best_label = 0

result = 0

# -------------------------
# Hilfsfunktionen
# -------------------------

def argmax(buffer, length):
    max_index = 0
    max_value = buffer[0]

    for i in range(1, length):
        if buffer[i] > max_value:
            max_value = buffer[i]
            max_index = i

    return max_index, max_value

# -------------------------
# MAIN LOOP
# -------------------------

print("Start main loop")

while True:    

    loop_start = time.ticks_ms()

    # -------- Heartbeat LED (korrigiert) --------
    if time.ticks_diff(loop_start, led_timer) > 1000:
        print('b') # debug message
        
        led_state = not led_state  # Zustand in Software umschalten
        led.value(1 if led_state else 0)
        led_timer = loop_start

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
    result = model.enqueue(input_buffer)

    # -------- Ergebnis verarbeiten --------
    if model.dequeue(output_buffer) == 0:
        
        # wahrscheinlichstes Ergebnis speichern
        best_label, max_score = argmax(output_buffer, output_dim)

        # only send command if above threshold. Dont send commands twice -> COOLDWON time between commands
        if max_score > cfg.GESTURE_THRESHOLD and best_label != 0 and loop_start > last_action_time + cfg.COOLDOWN_MS:
            last_action_time = loop_start
            
            """
            try:
                if best_label == 1:
                    bulb.turn_on()
                elif best_label == 2:
                    bulb.turn_off()
                elif best_label == 3:
                    bulb.brighten()
                elif best_label == 4:
                    bulb.dim()
            except Exception as e:
                print("Netzwerkfehler:", e)
            """
    """
    else:
        # --- Speicher management ---
        # in schnellen durchläufen aufräumen
        gc.collect()
    """
        
    # debug message:
    #t_model = time.ticks_diff(time.ticks_ms(), loop_start)
    #print(t_model)
    
    # -------- Sauberes Timing --------
    elapsed = time.ticks_diff(time.ticks_ms(), loop_start)

    if elapsed < sample_time_ms:
        time.sleep_ms(sample_time_ms - elapsed)
    else:
        # Debug message
        print("Timing")

