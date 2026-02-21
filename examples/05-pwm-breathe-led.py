from machine import PWM
import time

# Visit PWM API: https://ifx-micropython.readthedocs.io/en/latest/psoc6/quickref.html#pwm-pulse-width-modulation
intensity_step = 1638
max_intensity = 65535
intensity = 0

led = PWM('P5_3', freq=100, duty_u16=intensity_step)

while True:
    # Increase every 50 ms the intensity (duty cycle)
    # up to 2 seconds.
    # That gives a breathing effect of increase intensity.
    time.sleep_ms(50)
    intensity += intensity_step
    intensity = intensity % max_intensity
    led.duty_u16(intensity)
    
# Now implement the "breathe out" effect with decreasing intensity