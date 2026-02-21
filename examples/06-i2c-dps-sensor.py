import mip
mip.install("github:Infineon/micropython-xensiv-dps3xx")

from machine import I2C
import Dps3xx
from time import sleep

i2c = I2C(scl='P0_2', sda='P0_3', freq=400000)
dps = Dps3xx.Dps3xx(i2c)

for i in range(20):
    t = dps.measureTemperatureOnce()
    p = dps.measurePressureOnce()
    print(f'Pressure: {p},\t Temperature: {t}')
    sleep(1)