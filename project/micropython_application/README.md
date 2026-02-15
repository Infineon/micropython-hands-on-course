# PSoC6 MicroPython Client — Edge AI Inventory

Client firmware for the PSoC6 board that classifies objects using an on-device AI model and reports results to the inventory server.

## File Structure

```
micropython_application/
├── config.py       # Wi-Fi, server, device credentials
├── wifi.py         # Wi-Fi connection manager
├── api_client.py   # HTTP client for the inventory API
├── boot.py         # Runs on power-up (Wi-Fi connect)
├── main.py         # Detection loop entry point
└── README.md
```

## Setup

### 1. Register your device on the server

```bash
curl -X POST http://<server-ip>:5000/api/devices \
  -H "Content-Type: application/json" \
  -d '{"name": "psoc6-01", "location": "Warehouse A"}'
```

Save the `id` and `api_key` from the response.

### 2. Edit `config.py`

Update these values:

```python
WIFI_SSID = "YourNetwork"
WIFI_PASS = "YourPassword"
SERVER_HOST = "192.168.1.100"   # Flask server IP
DEVICE_ID = 1                   # from step 1
API_KEY = "abc123..."           # from step 1
```

### 3. Upload to PSoC6

Copy all `.py` files to the board's filesystem (e.g. via Thonny, `mpremote`, or `ampy`):

```bash
mpremote cp config.py wifi.py api_client.py boot.py main.py :
```

### 4. Reset the board

The device will:
1. Connect to Wi-Fi (`boot.py`)
2. Start the detection loop (`main.py`)
3. Send results to the server every `DETECTION_INTERVAL` seconds

## Integrating Your AI Model

Replace the placeholder in `main.py` → `run_inference()` with your actual DeepCraft model call:

```python
def run_inference():
    from deepcraft import Model
    model = Model("inventory_classifier")
    result = model.predict(camera.capture())
    return result.label, result.confidence
```

## API Endpoints Used

| Endpoint               | Method | Purpose                    |
|------------------------|--------|----------------------------|
| `/api/health`          | GET    | Server health check        |
| `/api/detections`      | POST   | Submit detection result     |
| `/api/inventory`       | GET    | Fetch current inventory     |
