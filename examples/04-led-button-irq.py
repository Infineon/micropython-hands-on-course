from machine import Pin
import time

led = Pin('P5_3', mode=Pin.OUT)

# Check Pin API
button = Pin('P5_2', Pin.IN, Pin.PULL_UP)

def button_isr(pin):
    global led
    led.toggle()
    # Debouncing delay
    time.sleep_ms(20)
    
button.irq(handler=button_isr, trigger=Pin.IRQ_FALLING)

