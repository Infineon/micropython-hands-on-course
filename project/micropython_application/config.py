# ============================================================
# Edge AI Inventory — Device Configuration
# ============================================================
# Copy this file and update values for your environment.
# This file is imported by all other modules.
# ============================================================

# ---- Wi-Fi ----
WIFI_SSID = "Galaxy S24"
WIFI_PASS = "nix12345"
WIFI_TIMEOUT = 15  # seconds to wait for connection

# ---- Server ----
SERVER_HOST = "192.168.1.100"  # IP of the machine running Flask
SERVER_PORT = 5000
API_BASE = "http://{}:{}".format(SERVER_HOST, SERVER_PORT)

# ---- Device Identity ----
# These are obtained after registering via POST /api/devices
DEVICE_ID = 1
API_KEY = "your-64-char-hex-api-key"

# ---- Detection Loop ----
DETECTION_INTERVAL = 10  # seconds between inference cycles

# ---- Hardware (PSoC6) ----
LED_PIN = "P13_7"  # Onboard LED for status indication
