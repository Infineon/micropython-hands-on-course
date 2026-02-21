from machine import Pin
import time

led = Pin('P5_3', mode=Pin.OUT)

# Check Pin API
button = Pin('P5_2', Pin.IN, Pin.PULL_UP)


while True:
    if button.value() == False:
        led.on()
    else:
        led.off()
    # Debouncing delay
    time.sleep_ms(20)
