# ============================================================
# Wi-Fi Connection Manager
# ============================================================
# Handles connecting, reconnecting, and checking Wi-Fi status.
# Uses the MicroPython `network` module (STA mode).
# ============================================================

import network
import time

import config


_wlan = None


def _get_wlan():
    """Get or create the WLAN interface (singleton)."""
    global _wlan
    if _wlan is None:
        _wlan = network.WLAN(network.STA_IF)
    return _wlan


def connect():
    """
    Connect to Wi-Fi using credentials from config.

    Returns:
        str: The device's IP address on success.

    Raises:
        RuntimeError: If connection fails within the timeout.
    """
    wlan = _get_wlan()
    wlan.active(True)

    if wlan.isconnected():
        ip = wlan.ifconfig()[0]
        print("[WiFi] Already connected — IP:", ip)
        return ip

    print("[WiFi] Connecting to '{}'...".format(config.WIFI_SSID))
    wlan.connect(config.WIFI_SSID, config.WIFI_PASS)

    deadline = time.time() + config.WIFI_TIMEOUT
    while not wlan.isconnected():
        if time.time() >= deadline:
            wlan.active(False)
            raise RuntimeError(
                "[WiFi] Connection to '{}' timed out after {}s".format(
                    config.WIFI_SSID, config.WIFI_TIMEOUT
                )
            )
        time.sleep(1)
        remaining = int(deadline - time.time())
        print("  waiting... ({}s left)".format(remaining))

    ip = wlan.ifconfig()[0]
    print("[WiFi] Connected — IP:", ip)
    return ip


def disconnect():
    """Disconnect from Wi-Fi and deactivate the interface."""
    wlan = _get_wlan()
    if wlan.isconnected():
        wlan.disconnect()
    wlan.active(False)
    print("[WiFi] Disconnected")


def is_connected():
    """Check if Wi-Fi is currently connected."""
    wlan = _get_wlan()
    return wlan.active() and wlan.isconnected()


def get_ip():
    """Return the current IP address, or None if not connected."""
    wlan = _get_wlan()
    if wlan.isconnected():
        return wlan.ifconfig()[0]
    return None


def ensure_connected():
    """
    Reconnect if the connection has dropped.

    Returns:
        str: The device's IP address.
    """
    if is_connected():
        return get_ip()
    print("[WiFi] Connection lost — reconnecting...")
    return connect()
