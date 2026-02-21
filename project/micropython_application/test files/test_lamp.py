import time
import configuration as cfg
from lightbulb import MiLight

bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

# Helper variables
brightness_steps = int((cfg.MAX_BRIGHTNESS - cfg.MIN_BRIGHTNESS) / cfg.BRIGHTNESS_STEP)
ct_steps = int((cfg.CT_MAX - cfg.CT_MIN) / cfg.CT_STEP)

while True:
    # --- PHASE 1: Helligkeit iterieren ---
    # Zuerst auf Minimum setzen
    bulb.brightness = cfg.MIN_BRIGHTNESS
    bulb.brighten()
    time.sleep(1)

    for i in range(brightness_steps):
        bulb.brighten()
        time.sleep(0.5)

    # --- PHASE 2: Farbtemperatur iterieren ---
    # Zuerst auf Minimum (Warmweiß) setzen
    bulb.ct = cfg.CT_MIN
    bulb.warmer() 
    time.sleep(1)

    for i in range(ct_steps):
        bulb.cooler()
        time.sleep(0.5)

    # --- PHASE 3: Ein- und Ausschalten ---
    bulb.turn_off()
    time.sleep(2)
    
    bulb.turn_on()
    time.sleep(2)
    
    # delay until next loop iteration
    time.sleep(1)