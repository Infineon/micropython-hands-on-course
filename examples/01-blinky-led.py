from machine import Pin
import time

# Pin API Docs : https://ifx-micropython.readthedocs.io/en/latest/library/machine.Pin.html
# Check the manual : https://www.infineon.com/assets/row/public/documents/30/44/infineon-cy8ckit-062s2-user-guide-usermanual-en.pdf

led = Pin('P5_3', mode=Pin.OUT)

# Time API Docs: https://ifx-micropython.readthedocs.io/en/latest/library/time.html

sleep_time_in_seconds = 1

while True:
    time.sleep(sleep_time_in_seconds)
    led.toggle()

# TODO: Now make it blink every 300 milliseconds