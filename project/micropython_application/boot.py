# ============================================================
# boot.py — Runs once on device power-up / hard reset
# ============================================================
# Connects to Wi-Fi so that main.py can immediately use the
# network.  If Wi-Fi fails here, main.py should handle retries.
# ============================================================

import wifi

print()
print("=" * 40)
print("  Edge AI Inventory — PSoC6 Client")
print("=" * 40)

try:
    wifi.connect()
except RuntimeError as e:
    print(e)
    print("[Boot] Will retry in main.py")
