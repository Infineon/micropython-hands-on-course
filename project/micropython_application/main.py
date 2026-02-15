# Deepcraft
import array
import deepcraft_model
from configuration import LABELS

# IMU
from machine import I2C
import bmi270

# Timing (50Hz main loop)
import time
from configuratioin import SAMPLE_TIME

# --- set up the deepcraft model ---
model = deepcraft_model.DEEPCRAFT()
model.init()

input_dim = model.get_model_input_dim()
output_dim = model.get_model_output_dim()

# Output-Buffer Array aus Floats, mit 0.0 initialisiert
output_buffer = array.array(’f’, [0.0] * output_dim)


# --- initialize the bmi270 IMU ---
# documentation: https://www.hackster.io/Infineon_Team/accelerometer-gyroscope-with-psoc-6-and-micropython-757eb3
i2c = I2C(scl='P0_2', sda='P0_3')
bmi = bmi270.BMI270(i2c)

# --- initialize the 50 Hz time ---
# Set the base point for the 50Hz calculation. The starting point of the next iteration is calculated in the main loop
next_loop = time.ticks_ms()

# --- Main Loop ---
while True:    
    # --- read sensor data ---
    # [2,3] array
    # Data format from Deepcraft: Accel_X,Accel_Y,Accel_Z,Gyro_X,Gyro_Y,Gyro_Z
    sensor_data = [bmi.accel(), bmi.gyro()]


    # --- feed the model with data ---
    model.enqueue(sensor_data)
    

    # --- print result ---
    # Test if the model has calculated a result
    if model.dequeue(output_buffer) == 0:
        # print out the result to the serial port
        for idx, score in enumerate(output_buffer):
            # End is a carriage return and not a newline. This way the output gets overwritten
            print(f"Label: {LABELS[idx]:<12} Score: {score*100:.2f}%", end='\r')
    
    
    # --- timing to 50Hz ---
    # calculate the starting point of the next iteration
    next_loop = time.ticks_add(next_tick, SAMPLE_TIME)
    # calculate the necessary sleep time
    sleep_duration = time.ticks_diff(next_tick, time.ticks_ms())
    
    if sleep_duration > 0:
        time.sleep_ms(sleep_duration)

# --- eof ---