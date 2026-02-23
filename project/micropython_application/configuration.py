# Wifi
SSID = "iPhone von Manuel"
KEY = "Licht1234"

# Deepcraft
LABELS = [".", "1", "0", "+","-"]

SAMPLE_FREQ = 50 # Hz
SAMPLE_TIME = 1.0 / SAMPLE_FREQ

GESTURE_THRESHOLD = 0.1
COOLDOWN_MS = 800

# Lamp Network
BULB_IP = "172.20.10.2"
BULB_PORT = 55443
SOCKET_TIMEOUT = 1.5

#EFFECT = "smooth"
EFFECT = "sudden"
DURATION_POWER = 500
DURATION_DIM = 300
DURATION_COLOR = 300   # Dauer für den Wechsel der Farbtemperatur

# Brightness (1 - 100)
BRIGHTNESS_START = 100
BRIGHTNESS_STEP = 10
MAX_BRIGHTNESS = 100
MIN_BRIGHTNESS = 1

# colour temp (Kelvin)
CT_START = 4000
CT_STEP = 500
CT_MIN = 2700  # Warmweiß
CT_MAX = 6500  # Kaltweiß / Tageslicht

# IMU
I2C_SCL = 'P0_2'
I2C_SDA = 'P0_3'

# User Button
USER_BUTTON = 'P5_2'
USER_LED = 'P5_3'