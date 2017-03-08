/*
  MSP - Library for MultiWii Serial Protocol
  Created by Filip Prochazka (jacktech24), 2015.
  Released under GNUGPLv3 license.
*/

#ifndef QUADCOPTER_CONTROLLER_MSP_MESSAGES_H
#define QUADCOPTER_CONTROLLER_MSP_MESSAGES_H

enum MSP_Messages
{
  MSP_MSG_IDENT = 100,
  MSP_MSG_STATUS = 101,
  MSP_MSG_RAW_IMU = 102,
  MSP_MSG_SERVO = 103,
  MSP_MSG_MOTOR = 104,
  MSP_MSG_RC = 105,
  MSP_MSG_RAW_GPS = 106,
  MSP_MSG_COMP_GPS = 107,
  MSP_MSG_ATTITUDE = 108,
  MSP_MSG_ALTITUDE = 109,
  MSP_MSG_ANALOG = 110,
  MSP_MSG_RC_TUNING = 111,
  MSP_MSG_PID = 112,
  MSP_MSG_BOX = 113,
  MSP_MSG_MISC = 114,
  MSP_MSG_MOTOR_PINS = 115,
  MSP_MSG_BOXNAMES = 116,
  MSP_MSG_PIDNAMES = 117,
  MSP_MSG_WP = 118,
  MSP_MSG_BOXIDS = 119,
  MSP_MSG_SERVO_CONFIGURATIONS = 120,
  MSP_MSG_3D = 121,

  MSP_MSG_SET_RAW_RC = 200,
  MSP_MSG_SET_RAW_GPS = 201,
  MSP_MSG_SET_PID = 202,
  MSP_MSG_SET_BOX = 203,
  MSP_MSG_SET_RC_TUNING = 204,
  MSP_MSG_ACC_CALIBRATION = 205,
  MSP_MSG_MAG_CALIBRATION = 206,
  MSP_MSG_SET_MISC = 207,
  MSP_MSG_RESET_CONF = 208,
  MSP_MSG_SET_WP = 209,
  MSP_MSG_SELECT_SETTING = 210,
  MSP_MSG_SET_HEAD = 211,
  MSP_MSG_SET_SERVO_CONFIGURATION = 212,
  MSP_MSG_SET_MOTOR = 214,
  MSP_MSG_SET_3D = 217,

  MSP_MSG_SERVO_MIX_RULES = 241,
  MSP_MSG_SET_SERVO_MIX_RULE = 242,

  MSP_MSG_EEPROM_WRITE = 250,

  MSP_MSG_DEBUGMSG = 253,
  MSP_MSG_DEBUG = 254,

  // baseflight only
  MSP_MSG_UID = 160,
  MSP_MSG_ACC_TRIM = 240,
  MSP_MSG_SET_ACC_TRIM = 239,
  MSP_MSG_GPS_SV_INFO = 164
};

enum MSP_Constants
{
  MSP_PREAMBLE_PART1 = 0x24,
  MSP_PREAMBLE_PART2 = 0x4D,

  MSP_DIRECTION_IN = 0x3E,
  MSP_DIRECTION_OUT = 0x3C
};

#endif // QUADCOPTER_CONTROLLER_MSP_MESSAGES_H