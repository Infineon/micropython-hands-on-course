import array
import time
import deepcraft_model
from machine import I2C
import bmi270
import configuration as cfg
from yeelight import MiLight

# --- Initialization ---
# Initialize the light using parameters from config
bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

# Setup DeepCraft AI model
model = deepcraft_model.DEEPCRAFT()
model.init()
output_dim = model.get_model_output_dim()
output_buffer = array.array('f', [0.0] * output_dim)

# Setup IMU (BMI270) using configured pins
i2c = I2C(scl=cfg.I2C_SCL, sda=cfg.I2C_SDA)
bmi = bmi270.BMI270(i2c)

# Timing and state variables
next_tick = time.ticks_ms()
last_action_time = 0

# --- Main Loop ---
while True:    
    # Capture sensor data (Acceleration and Gyroscope)
    sensor_data = [bmi.accel(), bmi.gyro()]
    model.enqueue(sensor_data)

    # Check if the model has a new prediction ready
    if model.dequeue(output_buffer) == 0:
        # Get the label with the highest confidence score
        max_score = max(output_buffer)
        max_idx = list(output_buffer).index(max_score)
        label = cfg.LABELS[max_idx]

        # Trigger action only if confidence exceeds threshold and cooldown has expired
        current_time = time.ticks_ms()
        if max_score > cfg.GESTURE_THRESHOLD and (time.ticks_diff(current_time, last_action_time) > cfg.COOLDOWN_MS):
            
            # Map the predicted label to the corresponding bulb method
            match label:
                case "Geste_Toggle":
                    bulb.toggle()
                case "Geste_Heller":
                    bulb.brighten()
                case "Geste_Dunkler":
                    bulb.dim()
                case "Geste_Aus":
                    bulb.turn_off()
            
            last_action_time = current_time

    # Frequency control for 50Hz operation
    next_tick = time.ticks_add(next_tick, cfg.SAMPLE_TIME)
    sleep_duration = time.ticks_diff(next_tick, time.ticks_ms())
    
    if sleep_duration > 0:
        time.sleep_ms(sleep_duration)