import socket
import configuration as cfg

class Lightbulb:
    def __init__(self, ip, port):
        self.ip = ip
        self.port = port
        self.brightness = cfg.BRIGHTNESS_START
        self.ct = cfg.CT_START

    def _send(self, method, params):
        """Helper to format and send JSON commands via TCP."""
        msg = '{"id":1,"method":"' + method + '","params":' + str(params).replace("'", '"') + '}\r\n'
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.settimeout(cfg.SOCKET_TIMEOUT)
            s.connect((self.ip, self.port))
            s.send(msg.encode())
            s.close()
            return True
        except:
            return False

    def turn_on(self):
        return self._send("set_power", ["on", cfg.EFFECT, cfg.DURATION_POWER])

    def turn_off(self):
        return self._send("set_power", ["off", cfg.EFFECT, cfg.DURATION_POWER])

    def brighten(self):
        self.brightness = min(cfg.MAX_BRIGHTNESS, self.brightness + cfg.BRIGHTNESS_STEP)
        return self._send("set_bright", [self.brightness, cfg.EFFECT, cfg.DURATION_DIM])

    def dim(self):
        self.brightness = max(cfg.MIN_BRIGHTNESS, self.brightness - cfg.BRIGHTNESS_STEP)
        return self._send("set_bright", [self.brightness, cfg.EFFECT, cfg.DURATION_DIM])
    
    def warmer(self):
        self.ct = max(cfg.CT_MIN, self.ct - cfg.CT_STEP)
        return self._send("set_ct_abx", [self.ct, cfg.EFFECT, cfg.DURATION_COLOR])

    def cooler(self):
        self.ct = min(cfg.CT_MAX, self.ct + cfg.CT_STEP)
        return self._send("set_ct_abx", [self.ct, cfg.EFFECT, cfg.DURATION_COLOR])
