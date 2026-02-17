# Edge AI Inventory System — API Usage Guide

This guide details how to interact with the backend API of the Edge AI Inventory System. It's designed for developers integrating edge devices (like PSoC6 using MicroPython) or building new client applications.

## Base URL

By default, the backend runs on port `5000`.

- **Local Development:** `http://localhost:5000`
- **Network Access:** `http://<server-ip>:5000` (Ensure the server is running on `0.0.0.0`)

---

## Authentication

Most endpoints are public, but **POST /api/detections** (the primary device endpoint) requires an API Key.

- **Header:** `X-API-Key: <your-device-api-key>`
- **Obtaining a Key:** An API key is generated automatically when you register a device via `POST /api/devices`.

---

## Endpoints

### 1. System

#### `GET /api/health`
Check if the API is running.

- **Response:** `200 OK`
  ```json
  { "status": "ok" }
  ```

---

### 2. Devices (Management)

#### `GET /api/devices`
List all registered devices.

- **Response:** `200 OK` (Array of device objects)

#### `GET /api/devices/<id>`
Get details for a specific device.

- **Response:** `200 OK`

#### `POST /api/devices`
Register a new edge device. **Save the returned `api_key`!**

- **Body:**
  ```json
  {
    "name": "psoc6-01",
    "location": "Warehouse A"
  }
  ```
- **Response:** `201 Created`
  ```json
  {
    "id": 1,
    "name": "psoc6-01",
    "location": "Warehouse A",
    "api_key": "e4f5a6b7c8d9...",  // <--- SAVE THIS
    "status": "online",
    "last_seen": "...",
    "created_at": "..."
  }
  ```

#### `PUT /api/devices/<id>`
Update a device's name or location.

- **Body:** `{ "name": "new-name", "location": "new-loc" }` (Both optional)
- **Response:** `200 OK`

#### `DELETE /api/devices/<id>`
Remove a device from the system.

- **Response:** `200 OK`

---

### 3. Detections (Device Reporting)

#### `POST /api/detections`
Submit a classification result from an edge device.

- **Headers:** `X-API-Key: <device-api-key>`
- **Body:**
  ```json
  {
    "device_id": 1,
    "label": "empty_box",
    "confidence": 0.95,
    "status": "detected"  // Optional: "detected" (default) or "cleared"
  }
  ```
- **Response:** `201 Created`
  ```json
  {
    "message": "Detection recorded",
    "event": { ... },
    "inventory_item": { ... }
  }
  ```
- **Errors:**
  - `401 Unauthorized`: Missing or invalid API key.
  - `403 Forbidden`: API key does not match the provided `device_id`.

#### `GET /api/detections`
Query detection history.

- **Query Params:**
  - `device_id`: Filter by device ID.
  - `label`: Filter by classification label.
  - `limit`: Number of results (default 50).
- **Response:** `200 OK` (Array of detection events)

---

### 4. Inventory (State)

#### `GET /api/inventory`
Get the current state of inventory items.

- **Query Params:** `device_id`, `label`, `status`
- **Response:** `200 OK` (Array of inventory items)

#### `GET /api/inventory/stats`
Get aggregated statistics for dashboards.

- **Response:** `200 OK`
  ```json
  {
    "total_items": 12,
    "items_by_label": {
      "empty_box": { "detected": 3, "cleared": 1 }
    },
    "active_devices": 2,
    "total_devices": 3,
    "total_detections": 156,
    "recent_detections": 14
  }
  ```

---

## MicroPython Client Example

Below is a complete example for a PSoC6 (or ESP32) device running MicroPython.

### Setup
1. **Register your device** first (e.g., via Postman or cURL) to get a `DEVICE_ID` and `API_KEY`.
2. Update the `CONFIGURATION` section in the code below.

### Code (`main.py`)

```python
import network
import urequests
import ujson
import time

# ============================================================
# CONFIGURATION
# ============================================================
WIFI_SSID = "YourWiFiSSID"
WIFI_PASS = "YourWiFiPassword"

# Replace with your server's IP address (check with ipconfig/ifconfig)
SERVER_IP = "192.168.1.100"
SERVER_PORT = 5000
API_BASE = "http://{}:{}".format(SERVER_IP, SERVER_PORT)

# Device credentials (from registration)
DEVICE_ID = 1
API_KEY = "your-64-char-hex-api-key"

DETECTION_INTERVAL = 10  # Seconds

# ============================================================
# Networking
# ============================================================
def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print("[WiFi] Connecting to", WIFI_SSID)
        wlan.connect(WIFI_SSID, WIFI_PASS)
        while not wlan.isconnected():
            time.sleep(1)
    print("[WiFi] Connected:", wlan.ifconfig())

# ============================================================
# API Client
# ============================================================
def send_detection(label, confidence, status="detected"):
    url = API_BASE + "/api/detections"
    headers = {
        "Content-Type": "application/json",
        "X-API-Key": API_KEY
    }
    payload = ujson.dumps({
        "device_id": DEVICE_ID,
        "label": label,
        "confidence": confidence,
        "status": status
    })

    try:
        response = urequests.post(url, data=payload, headers=headers)
        print("[API] Status:", response.status_code)
        if response.status_code == 201:
            print("      Success:", response.json().get("message"))
        else:
            print("      Error:", response.text)
        response.close()
    except Exception as e:
        print("[API] Failed:", e)

# ============================================================
# Main Loop
# ============================================================
def main():
    connect_wifi()
    
    print("Starting detection loop...")
    while True:
        # --- REPLACE WITH REAL INFERENCE ---
        # label, confidence = model.predict()
        label = "empty_box"
        confidence = 0.95
        # -----------------------------------

        print(f"Sending: {label} ({confidence})")
        send_detection(label, confidence)
        
        time.sleep(DETECTION_INTERVAL)

if __name__ == "__main__":
    main()
```
