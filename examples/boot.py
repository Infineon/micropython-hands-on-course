ssid = "iPhone von Manuel"
key = "Leontina"

def network_connect() :
    import network
    from utime import sleep,sleep_ms
    wlan = network.WLAN(network.STA_IF)
    if wlan.isconnected():
        print('[Network] already connected')
        return

    # enable and connect wlan
    wlan.active(True)
    wlan.connect(ssid,key)

    # wait for the connection to establish
    sleep(5)
    for i in range(0,100):
        if not wlan.isconnected() and wlan.status() >= 0:
            print("[Network] Waiting to connect..")
            sleep(2)

    # check connection
    if not wlan.isconnected():
        print("[Network] Connection failed!")
    else:
        print(wlan.ifconfig())
        
network_connect()