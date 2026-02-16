import socket
from configuration import BRIGHTNESS_STEP

class MiLight:
    def __init__(self, ip, port):
        self.ip = ip
        self.port = port
        self.is_on = False
        self.brightness = 50  
        self.step = BRIGHTNESS_STEP

    def _send(self, method, params):
        """Helper to format and send JSON commands via TCP."""
        msg = '{"id":1,"method":"' + method + '","params":' + str(params).replace("'", '"') + '}\r\n'
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.settimeout(1.5)
            s.connect((self.ip, self.port))
            s.send(msg.encode())
            s.close()
            return True
        except:
            return False

    def turn_on(self):
        self.is_on = True
        return self._send("set_power", ["on", "smooth", 500])

    def turn_off(self):
        self.is_on = False
        return self._send("set_power", ["off", "smooth", 500])

    def toggle(self):
        return self.turn_off() if self.is_on else self.turn_on()

    def brighten(self):
        if self.brightness < 100:
            self.brightness = min(100, self.brightness + self.step)
            return self._send("set_bright", [self.brightness, "smooth", 300])
        return True

    def dim(self):
        if self.brightness > 1:
            self.brightness = max(1, self.brightness - self.step)
            return self._send("set_bright", [self.brightness, "smooth", 300])
        return True