# ============================================================
# main.py — Detection Loop Entry Point
# ============================================================
# Runs after boot.py.  Performs the following cycle:
#   1. Ensure Wi-Fi is connected (reconnect if dropped)
#   2. Run AI inference (placeholder — integrate DeepCraft)
#   3. Send detection result to the inventory server
#   4. Sleep and repeat
# ============================================================

import time

import config
import wifi
import api_client


def run_inference():
    """
    Run the AI model and return (label, confidence).

    >>> REPLACE THIS with your actual DeepCraft model call <<<

    Example with DeepCraft:
        from deepcraft import Model
        model = Model("inventory_classifier")
        result = model.predict(camera.capture())
        return result.label, result.confidence
    """
    # --- Placeholder: simulated detection ---
    label = "empty_box"
    confidence = 0.92
    return label, confidence


def main():
    print("\n[Main] Starting detection loop")
    print("  Server :", config.API_BASE)
    print("  Device :", config.DEVICE_ID)
    print("  Interval:", config.DETECTION_INTERVAL, "s\n")

    # Initial server check
    wifi.ensure_connected()

    if api_client.health_check():
        print("[Main] Server is reachable!\n")
    else:
        print("[Main] WARNING: Server not reachable — will retry per cycle\n")

    # Detection loop
    cycle = 0
    while True:
        cycle += 1
        print("--- Cycle {} ---".format(cycle))

        try:
            # 1. Ensure Wi-Fi
            wifi.ensure_connected()

            # 2. Run inference
            label, confidence = run_inference()
            print("[Inference] {} ({:.1f}%)".format(label, confidence * 100))

            # 3. Send to server
            api_client.send_detection(label, confidence)

        except Exception as e:
            print("[Main] Error in cycle {}:".format(cycle), e)

        # 4. Wait
        print()
        time.sleep(config.DETECTION_INTERVAL)


# ============================================================
# Entry point
# ============================================================
main()
