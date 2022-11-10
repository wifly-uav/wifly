from odrive_node import ODriveNode
import threading
import time

if __name__ == '__main__':
    odrv = ODriveNode()
    odrv.connect_any()
    time.sleep(1)
    #odrv.calibrate()
    odrv.get_errors(clear=False)
    #odrv.control_mode(mode="VEL")
    odrv.engage()
    odrv.drive_vel(val=0)
    time.sleep(0.1)
    odrv.idle()
    odrv.disconnect()