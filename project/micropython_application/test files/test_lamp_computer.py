import configuration as cfg
from lightbulb import MiLight

# 1. Initialisierung der Lampe (Daten aus der configuration.py)
bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

print("Kommandozeilen-Testprogramm gestartet.")
print("-" * 40)
print("Verfügbare Befehle:")
print(" 'on'  -> Einschalten")
print(" 'off' -> Ausschalten")
print(" '+'   -> Heller")
print(" '-'   -> Dunkler")
print(" 'w'   -> Wärmeres Licht (Gelblicher)")
print(" 'c'   -> Kälteres Licht (Bläulicher)")
print(" 'q'   -> Programm beenden")
print("-" * 40)

# 2. Endlosschleife für die Kommandozeilen-Eingabe
while True:
    command = input("Kommando eingeben: ").strip().lower()
    
    match command:
        case 'q':
            print("Programm beendet.")
            break
            
        case 'on':
            print("Sende Turn On...")
            bulb.turn_on()
            
        case 'off':
            print("Sende Turn Off...")
            bulb.turn_off()
            
        case '+':
            print(f"Sende Heller... (Ziel: {min(100, bulb.brightness + cfg.BRIGHTNESS_STEP)}%)")
            bulb.brighten()
            
        case '-':
            print(f"Sende Dunkler... (Ziel: {max(1, bulb.brightness - cfg.BRIGHTNESS_STEP)}%)")
            bulb.dim()

        case 'w':
            print(f"Sende Wärmer... (Ziel: {max(cfg.CT_MIN, bulb.ct - cfg.CT_STEP)}K)")
            bulb.warmer()

        case 'c':
            print(f"Sende Kälter... (Ziel: {min(cfg.CT_MAX, bulb.ct + cfg.CT_STEP)}K)")
            bulb.cooler()
            
        case _:
            print("Unbekannt! Nutze: on, off, t, +, -, w, c oder q")