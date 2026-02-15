# ============================================================
# Inventory API Client
# ============================================================
# Lightweight HTTP client for the Edge AI Inventory server.
# Uses `urequests` for HTTP and authenticates via X-API-Key.
# ============================================================

import urequests
import ujson

import config


# ---- Helpers ----

def _url(path):
    """Build a full URL from a relative API path."""
    return config.API_BASE + path


def _auth_headers():
    """Return headers with JSON content type and API key."""
    return {
        "Content-Type": "application/json",
        "X-API-Key": config.API_KEY,
    }


# ---- Public API ----

def health_check():
    """
    Check if the server is reachable.

    Returns:
        bool: True if server responds with 200 on /api/health.
    """
    try:
        res = urequests.get(_url("/api/health"))
        ok = res.status_code == 200
        res.close()
        return ok
    except Exception as e:
        print("[API] Health check failed:", e)
        return False


def send_detection(label, confidence, status="detected"):
    """
    Send a detection result to the inventory server.

    This is the primary function your detection loop should call.
    It records the detection event and updates the inventory.

    Args:
        label (str):       Classification label (e.g. "empty_box").
        confidence (float): Model confidence between 0.0 and 1.0.
        status (str):      "detected" or "cleared".

    Returns:
        dict: Parsed JSON response on success, None on failure.
    """
    payload = ujson.dumps({
        "device_id": config.DEVICE_ID,
        "label": label,
        "confidence": confidence,
        "status": status,
    })

    try:
        print("[API] POST /api/detections")
        print("  ->", payload)

        res = urequests.post(
            _url("/api/detections"),
            data=payload,
            headers=_auth_headers(),
        )

        print("  <- status:", res.status_code)

        if res.status_code == 201:
            data = res.json()
            print("  OK:", data.get("message", ""))
            res.close()
            return data
        else:
            print("  ERROR:", res.text)
            res.close()
            return None

    except Exception as e:
        print("[API] Request failed:", e)
        return None


def get_inventory():
    """
    Fetch the current inventory from the server.

    Returns:
        list: Array of inventory item dicts, or empty list on failure.
    """
    try:
        res = urequests.get(_url("/api/inventory"))
        if res.status_code == 200:
            data = res.json()
            res.close()
            return data
        res.close()
        return []
    except Exception as e:
        print("[API] Failed to fetch inventory:", e)
        return []
