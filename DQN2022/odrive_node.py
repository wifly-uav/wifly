import time
from logging import getLogger
import logging
logging.basicConfig(level=logging.INFO)
logger = getLogger(__name__)

import odrive
from odrive.enums import *
from odrive.utils import * 

class ODriveNode(object):

    def __init__(self):
        self.cpr = 2**14
        self.driver = None
    
    def get_version_string(self):
        if not self.driver:
            return "Not connected."
        return "ODrive %s, hw v%d.%d-%d, fw v%d.%d.%d%s, sdk v%s" % (
            str(self.driver.serial_number),
            self.driver.hw_version_major, self.driver.hw_version_minor, self.driver.hw_version_variant,
            self.driver.fw_version_major, self.driver.fw_version_minor, self.driver.fw_version_revision,
            "-dev" if self.driver.fw_version_unreleased else "",
            odrive.version.get_version_str())
    
    def reboot(self):
        if not self.driver:
            logger.info("Not connected.")
            return False
        try:
            self.driver.reboot()
        except KeyError:
            logger.info("Rebooted ODrive.")
        except:
            logger.info("Failed to reboot")
        finally:
            self.driver = None
        return True

    def connect(self, serial_number, timeout = 10):
        if self.driver:
            logger.info("Already connected. Disconnecting and reconnecting.")
            self.disconnect()
        try:
            self.driver = odrive.find_any(serial_number=serial_number, timeout=timeout)
            self.axes = (self.driver.axis0, self.driver.axis1)
            logger.info("Find!!")
        except:
            logger.info("No ODrive found. Is device powered?")
            return False
        self.right_axis = self.driver.axis0
        self.left_axis  = self.driver.axis1
        
        # check for no errors
        for axis in [self.right_axis, self.left_axis]:
            if axis.error != 0:
                error_str = "Had error on startup, rebooting. Axis error 0x%x, motor error 0x%x, encoder error 0x%x. Rebooting." % (axis.error, axis.motor.error, axis.encoder.error)
                logger.error(error_str)
                self.reboot()
                return False
        logger.info("Connected to ODrive. " + self.get_version_string())
        return True

    def connect_any(self):
        if self.driver:
            logger.info("Already connected. Disconnecting and reconnecting.")
        try:
            self.driver = odrive.find_any()
            self.axes = (self.driver.axis0, self.driver.axis1)
        except:
            logger.warning("No ODrive found. Is device powered?")
            return False
        self.right_axis = self.driver.axis0
        self.left_axis  = self.driver.axis1
        
        # check for no errors
        for axis in [self.right_axis, self.left_axis]:
            if axis.error != 0:
                error_str = "Had error on startup, rebooting. Axis error 0x%x, motor error 0x%x, encoder error 0x%x. Rebooting." % (axis.error, axis.motor.error, axis.encoder.error)
                logger.error(error_str)
                self.reboot()
                return False
        logger.info("Connected to ODrive. ")# + self.get_version_string())
        serial_number = str(self.driver.serial_number)
        return serial_number

    def disconnect(self):
        if not self.driver:
            logger.info("Not connected.")
            return False
        logger.info("Disconnect")
        self.get_errors(clear=False)
        for axis in self.axes: 
            axis.requested_state = AXIS_STATE_IDLE
        logger.info("IDLE_disconnect")
        del self.driver
        self.driver = None
        return True

    def get_errors(self, clear=True, mode=0):
        # TODO: add error parsing, see: https://github.com/madcowswe/ODrive/blob/master/tools/odrive/utils.py#L34
        if not self.driver:
            logger.warning("Not connected.")
            return None
            
        axis_error = self.axes[0].error or self.axes[1].error
        
        if axis_error:
            error_string = "Errors(hex): L: a%x m%x e%x c%x, R: a%x m%x e%x c%x" % (
                self.left_axis.error,  self.left_axis.motor.error,  self.left_axis.encoder.error,  self.left_axis.controller.error,
                self.right_axis.error, self.right_axis.motor.error, self.right_axis.encoder.error, self.right_axis.controller.error,
            )
            logger.error(error_string)
            logger.error(dump_errors(self.driver))
        else:
            logger.info("No error")
            #pass
        
        if clear:
            for axis in self.axes:
                axis.error = 0
                axis.motor.error = 0
                axis.encoder.error = 0
                axis.controller.error = 0
        
        if mode==1:
            dump_errors(self.driver)

        if axis_error:
            return error_string
    
    def set_config(self, axis=0, encoder_pin=4):
        if not self.driver:
            logger.warning("Not connected.")
            return False
        try:
            self.axes[axis].motor.config.current_lim = 11
            self.axes[axis].motor.config.calibration_current = 5
            self.axes[axis].controller.config.vel_limit = 300
            self.driver.config.brake_resistance = 0.6
            self.axes[axis].motor.config.pole_pairs = 21
            self.axes[axis].motor.config.torque_constant = 0.07
            self.axes[axis].motor.config.resistance_calib_max_voltage = 6.0
            self.axes[axis].encoder.config.abs_spi_cs_gpio_pin = encoder_pin 
            self.axes[axis].encoder.config.mode = ENCODER_MODE_SPI_ABS_AMS
            self.axes[axis].encoder.config.cpr = 2**14
            self.axes[axis].controller.config.inertia  = 0
            self.axes[axis].motor.config.pre_calibrated = True
            self.axes[axis].encoder.config.pre_calibrated = True
            
            self.axes[axis].controller.config.input_filter_bandwidth = 2.0
            self.axes[axis].trap_traj.config.vel_limit = 1.0
            self.axes[axis].trap_traj.config.accel_limit = 1.0
            self.axes[axis].trap_traj.config.decel_limit = 1.0
            self.axes[axis].controller.config.inertia = 0

            self.driver.save_configuration()
        except:
            error_str = "Had error on startup, rebooting. Axis error 0x%x, motor error 0x%x, encoder error 0x%x. Rebooting." % (axis.error, axis.motor.error, axis.encoder.error)
            logger.error(error_str)
            return False
        self.driver.reboot()
        return True

    def reset_config(self): self.driver.erase_configuration()

    def save(self):
        self.driver.save_configuration()

    def calibrate(self, axis=0, mode=0):
        if not self.driver:
            logger.warning("Not connected.")
            return False

        logger.debug("Vbus %.2fV" % self.driver.vbus_voltage)
        logger.info("Calibrating axis %d..." % axis)

        if mode:
            self.axes[axis].requested_state = AXIS_STATE_MOTOR_CALIBRATION
            time.sleep(1)
            while self.axes[axis].current_state != AXIS_STATE_IDLE:
                time.sleep(0.1)
            if self.axes[axis].error != 0:
                logger.error("Failed calibration with axis error 0x%x, motor error 0x%x" % (self.axes[axis].error, self.axes[axis].motor.error))
                return False
            self.axes[axis].requested_state = AXIS_STATE_ENCODER_OFFSET_CALIBRATION
            time.sleep(1)
            while self.axes[axis].current_state != AXIS_STATE_IDLE:
                time.sleep(0.1)
            if self.axes[axis].error != 0:
                logger.error("Failed calibration with axis error 0x%x, motor error 0x%x" % (self.axes[axis].error, self.axes[axis].motor.error))
                return False

        self.axes[axis].requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
        time.sleep(1)
        while self.axes[axis].current_state != AXIS_STATE_IDLE:
            time.sleep(0.1)
        if self.axes[axis].error != 0:
            logger.error("Failed calibration with axis error 0x%x, motor error 0x%x" % (self.axes[axis].error, self.axes[axis].motor.error))
            return False
        #self.driver.save_configuration()
        return True

    def set_PID(self, axis=0, pos_P=20, vel_P=0.16, vel_I=0.33):
        self.axes[axis].controller.config.pos_gain = pos_P
        self.axes[axis].controller.config.vel_gain = vel_P
        self.axes[axis].controller.config.vel_integrator_gain = vel_I
        self.driver.save_configuration()
        return True
    
    def engage(self , axis=0 , mode=0):
        if mode == 1:
            self.search(axis)
            while self.axes[axis].current_state != AXIS_STATE_IDLE:
                time.sleep(0.1)
        self.axes[axis].requested_state  = AXIS_STATE_CLOSED_LOOP_CONTROL
        return True

    def search_index(self , axis=0):
        self.search(axis)
        #while self.axes[axis].current_state != AXIS_STATE_IDLE:
        #    time.sleep(0.1)
        return True

    def idle(self, axis=0): self.axes[axis].requested_state = AXIS_STATE_IDLE

    def search(self, axis=0): self.axes[axis].requested_state = AXIS_STATE_ENCODER_INDEX_SEARCH

    def input_mode(self, axis=0, mode=1):
        #input_mode = 1 def
        #input_mode = 3 filter
        #input_mode = 5 trap
        self.axes[axis].controller.config.input_mode = mode

    def control_mode(self, axis=0, mode="POS"):
        if mode=="POS":
            self.axes[axis].controller.config.control_mode = CONTROL_MODE_POSITION_CONTROL
        if mode=="VEL":
            self.axes[axis].controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
        if mode=="TOR":
            self.axes[axis].controller.config.control_mode = CONTROL_MODE_TORQUE_CONTROL

    def drive_pos(self, axis=0, val=0): self.axes[axis].controller.input_pos = val
    def drive_vel(self, axis=0, val=0): self.axes[axis].controller.input_vel = val
    def drive_tor(self, axis=0, val=0): self.axes[axis].controller.input_torque = val

    def get_current(self, axis=0):  return self.axes[axis].motor.current_control.Iq_measured
    def get_count(self, axis=0):  return self.axes[axis].encoder.shadow_count
    def get_pos(self, axis=0):  return self.axes[axis].encoder.pos_estimate
    def get_vel(self, axis=0):  return self.axes[axis].encoder.vel_estimate
    
    def set_start_closed(self, axis=0):
        self.axes[axis].config.startup_closed_loop_control = True
        self.driver.save_configuration()

    def config_endstop(self, axis=0, max_pin=6, min_pin=7):
        self.axes[axis].max_endstop.config.gpio_num = max_pin
        self.axes[axis].min_endstop.config.gpio_num = min_pin
        self.axes[axis].max_endstop.config.enabled = True
        self.axes[axis].min_endstop.config.enabled = True
        self.axes[axis].min_endstop.config.offset = 0.0
        self.axes[axis].max_endstop.config.debounce_ms = 50
        self.axes[axis].min_endstop.config.debounce_ms = 50
        self.axes[axis].max_endstop.config.is_active_high = False
        self.axes[axis].min_endstop.config.is_active_high = False
        self.axes[axis].min_endstop.config.pullup
        self.axes[axis].max_endstop.config.pullup
        self.driver.save_configuration()
        self.driver.reboot()
    
    def cancel_endstop(self, axis=0):
        self.axes[axis].max_endstop.config.enabled = False
        self.axes[axis].min_endstop.config.enabled = False

    def switch_test(self, axis=0):  return self.axes[axis].max_endstop.endstop_state , self.axes[axis].min_endstop.endstop_state

    def config_homing(self, axis=0):
        self.axes[axis].controller.config.homing_speed = 0.25
        self.axes[axis].controller.config.vel_ramp_rate = 0.1
        self.axes[axis].trap_traj.config.vel_limit = 0.1
        self.axes[axis].trap_traj.config.accel_limit = 0.1
        self.axes[axis].trap_traj.config.decel_limit = 0.1
        self.driver.save_configuration()

    def homing(self, axis=0):   self.axes[axis].requested_state = AXIS_STATE_HOMING

    def move(self, axis=0,direction=1, vel_limit=0.1):
        self.axes[axis].trap_traj.config.vel_limit = vel_limit
        self.axes[axis].controller.move_incremental(direction*1000000, False)

    def read_vbus_voltage(self):
        voltage = self.driver.vbus_voltage
        return voltage