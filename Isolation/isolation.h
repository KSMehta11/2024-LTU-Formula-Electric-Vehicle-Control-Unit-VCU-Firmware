
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// This file must define:
// base monitor struct
// function signature for CRC calculation
// function signature for getting system tick value (100 us step)
#include "canmonitorutil.h"



// def @IMD_Request CAN Message (34)
#define IMD_Request_IDE (0U)
#define IMD_Request_DLC (5U)
#define IMD_Request_CANID (0x22U)
typedef struct
{

  // 255 - "S_IMD_ERROR_FRAME" 
  // 226 - "S_VIFC_GET_IMC_ALIVE" 
  // 225 - "S_VIFC_GET_TEMP" 
  // 224 - "S_VIFC_GET_LOCK" 
  // 223 - "S_VIFC_GET_POWER_MODE" 
  // 222 - "S_VIFC_GET_VERSION" 
  // 221 - "S_VIFC_GET_HV_RELAIS" 
  // 220 - "S_VIFC_GET_STATUS" 
  // 210 - "S_VIFC_SET_HV_RELAIS" 
  // 203 - "S_VIFC_CTL_MEASUREMENT" 
  // 202 - "S_VIFC_CTL_LOCK" 
  // 201 - "S_VIFC_CTL_POWER_MODE" 
  // 200 - "S_VIFC_CTL_IMC_RESET" 
  // 90 - "S_IMC_GET_TEST_CNT" 
  // 61 - "S_IMC_GET_MANUFACTURER" 
  // 60 - "S_IMC_GET_MEAN_FACTOR" 
  // 59 - "S_IMC_GET_EEPROM" 
  // 58 - "S_IMC_GET_HV_2" 
  // 57 - "S_IMC_GET_R_ISO_WRN_THR" 
  // 55 - "S_IMC_GET_STATUS" 
  // 54 - "S_IMC_GET_HV_1" 
  // 53 - "S_IMC_GET_R_ISO" 
  // 51 - "S_IMC_GET_VERSION" 
  // 50 - "S_IMC_GET_R_ISO_ERR_THR" 
  // 43 - "S_IMC_SET_MEAN_FACTOR" 
  // 42 - "S_IMC_SET_EEPROM" 
  // 41 - "S_IMC_SET_R_ISO_WRN_THR" 
  // 40 - "S_IMC_SET_R_ISO_ERR_THR" 
  // 35 - "S_IMC_CTL_SYS_UPDATE" 
  // 34 - "S_IMC_CTL_CALIB" 
  // 33 - "S_IMC_CTL_SELFTEST" 
  // 0 - "S_VIFC_CTL_DUMMY" 

  uint8_t IMD_Request_Command;              //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t MG_IMC_MANUFACT_INDEX;           //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unkown" 
  // 3 - "PowerDown" 
  // 2 - "PowerUp" 
  // 1 - "PowerOn" 
  // 0 - "PowerOff" 

  uint16_t MG_VIFC_POWER_MODE;              //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unkown" 
  // 3 - "PowerDown" 
  // 2 - "PowerUp" 
  // 1 - "PowerOn" 
  // 0 - "PowerOff" 

  uint16_t MC_VIFC_POWER_MODE;              //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 2 - "Firmware ID" 
  // 1 - "Firmware" 
  // 0 - "Bootloader" 

  uint16_t MG_VIFC_VERSION_INDEX;           //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 2 - "Firmware ID" 
  // 1 - "Firmware" 
  // 0 - "Bootloader" 

  uint16_t MG_IMC_VERSION_INDEX;            //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t MG_IMC_EEPROM_INDEX;             //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 1 - "Deactivated" 
  // 0 - "Activated" 

  uint16_t MC_VIFC_MEASURE_MODE;            //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t MS_IMC_MEAN_FACTOR;              //      Bits=16.  [ 1     , 20     ]  Unit:''     

  uint16_t MS_IMC_EEPROM_INDEX;             //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 2 - "BlockedToManyRetries" 
  // 1 - "Locked" 
  // 0 - "Unlocked" 

  uint16_t MC_VIFC_LOCK_MODE;               //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IMD_Request_DataWord1;           //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t MS_IMC_R_ISO_WRN_THR;            //      Bits=16.  [ 40    , 2000   ]  Unit:'kOhm' 

  // 6 - "GainCalibrationHV2" 
  // 5 - "OffsetCalibrationHV2" 
  // 4 - "ARef_12V_5V_Calibration" 
  // 3 - "IsoCalibration" 
  // 2 - "GainCalibrationHV1" 
  // 1 - "OffsetCalibrationHV1" 
  // 0 - "NoAction" 

  uint16_t MC_IMC_CALIB_STEP;               //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "HV_1_POS" 
  // 0 - "HV_1_NEG" 

  uint16_t MS_VIFC_HV_RELAIS;               //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 2 - "ParameterConfig" 
  // 1 - "OverAll" 
  // 0 - "NoAction" 

  uint16_t MC_IMC_SELFTEST_SCR;             //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t MS_IMC_R_ISO_ERR_THR;            //      Bits=16.  [ 30    , 1000   ]  Unit:'kOhm' 

  uint16_t MS_IMC_EEPROM_DATA;              //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t MC_VIFC_LOCK_PWD;                //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IMD_Request_DataWord2;           //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "HVEnabled" 
  // 0 - "HVDisabled" 

  uint16_t MS_VIFC_HV_RELAIS_STATE;         //      Bits=16.  [ 0     , 0      ]  Unit:''     
} IMD_Request_t;

// def @IMD_Response CAN Message (35)
#define IMD_Response_IDE (0U)
#define IMD_Response_DLC (5U)
#define IMD_Response_CANID (0x23U)
typedef struct
{

  // 255 - "S_IMD_ERROR_FRAME" 
  // 226 - "S_VIFC_GET_IMC_ALIVE" 
  // 225 - "S_VIFC_GET_TEMP" 
  // 224 - "S_VIFC_GET_LOCK" 
  // 223 - "S_VIFC_GET_POWER_MODE" 
  // 222 - "S_VIFC_GET_VERSION" 
  // 221 - "S_VIFC_GET_HV_RELAIS" 
  // 220 - "S_VIFC_GET_STATUS" 
  // 210 - "S_VIFC_SET_HV_RELAIS" 
  // 203 - "S_VIFC_CTL_MEASUREMENT" 
  // 202 - "S_VIFC_CTL_LOCK" 
  // 201 - "S_VIFC_CTL_POWER_MODE" 
  // 200 - "S_VIFC_CTL_IMC_RESET" 
  // 90 - "S_IMC_GET_TEST_CNT" 
  // 61 - "S_IMC_GET_MANUFACTURER" 
  // 60 - "S_IMC_GET_MEAN_FACTOR" 
  // 59 - "S_IMC_GET_EEPROM" 
  // 58 - "S_IMC_GET_HV_2" 
  // 57 - "S_IMC_GET_R_ISO_WRN_THR" 
  // 55 - "S_IMC_GET_STATUS" 
  // 54 - "S_IMC_GET_HV_1" 
  // 53 - "S_IMC_GET_R_ISO" 
  // 51 - "S_IMC_GET_VERSION" 
  // 50 - "S_IMC_GET_R_ISO_ERR_THR" 
  // 43 - "S_IMC_SET_MEAN_FACTOR" 
  // 42 - "S_IMC_SET_EEPROM" 
  // 41 - "S_IMC_SET_R_ISO_WRN_THR" 
  // 40 - "S_IMC_SET_R_ISO_ERR_THR" 
  // 35 - "S_IMC_CTL_SYS_UPDATE" 
  // 34 - "S_IMC_CTL_CALIB" 
  // 33 - "S_IMC_CTL_SELFTEST" 
  // 0 - "S_VIFC_CTL_DUMMY" 

  uint8_t IMD_Response_Command;                  //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_MANUFACT_INDEX;                //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_VIFC_TEMP;                         //      Bits=16.  [ 0     , 0      ]  Unit:'?C'   

  // 100 - "Unknown" 
  // 2 - "OutOfRange" 
  // 1 - "Error" 
  // 0 - "Running" 

  uint16_t IG_VIFC_IMC_ALIVE;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unkown" 
  // 3 - "PowerDown" 
  // 2 - "PowerUp" 
  // 1 - "PowerOn" 
  // 0 - "PowerOff" 

  uint16_t IG_VIFC_POWER_MODE;                   //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unkown" 
  // 3 - "PowerDown" 
  // 2 - "PowerUp" 
  // 1 - "PowerOn" 
  // 0 - "PowerOff" 

  uint16_t IC_VIFC_POWER_MODE;                   //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IS_IMC_MEAN_FACTOR;                   //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IS_IMC_EEPROM_INDEX;                  //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 6 - "GainCalibrationHV2" 
  // 5 - "OffsetCalibrationHV2" 
  // 4 - "ARef_12V_5V_Calibration" 
  // 3 - "IsoCalibration" 
  // 2 - "GainCalibrationHV1" 
  // 1 - "OffsetCalibrationHV1" 
  // 0 - "NoAction" 

  uint16_t IC_IMC_CALIB_STEP;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IS_IMC_R_ISO_WRN_THR;                 //      Bits=16.  [ 0     , 0      ]  Unit:'kOhm' 

  uint16_t IS_IMC_R_ISO_ERR_THR;                 //      Bits=16.  [ 0     , 0      ]  Unit:'kOhm' 

  uint16_t IC_VIFC_MEASURE_MODE;                 //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 2 - "BlockedToManyRetries" 
  // 1 - "Locked" 
  // 0 - "Unlocked" 

  uint16_t IC_VIFC_LOCK_MODE;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "HV_1_POS" 
  // 0 - "HV_1_NEG" 

  uint16_t IS_VIFC_HV_RELAIS;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_EEPROM_INDEX;                  //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_MEAN_FACTOR;                   //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 2 - "BlockedToManyRetries" 
  // 1 - "Locked" 
  // 0 - "Unlocked" 

  uint16_t IG_VIFC_LOCK_MODE;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 1 - "Deactivated" 
  // 0 - "Activated" 

  uint8_t IG_VIFC_STATUS_00_IsoMeasurement;      //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 2 - "Hardware" 
  // 1 - "Firmware" 
  // 0 - "Bootloader" 

  uint16_t IG_VIFC_VERSION_INDEX;                //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "HV_1_POS" 
  // 0 - "HV_1_NEG" 

  uint16_t IG_VIFC_HV_RELAIS;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_00_IsoFailure;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1038 - "VIFC_NoResponseTimeout" 
  // 1037 - "VIFC_RepeatedOrMissingFrame" 
  // 1035 - "VIFC_UnknownCommand" 
  // 1034 - "VIFC_InvalidParameter" 
  // 1033 - "VIFC_ChecksumErrorInFrame" 
  // 1032 - "VIFC_Timeout10msExpired" 
  // 1001 - "VIFC_QueueFullCommandRejected" 
  // 1000 - "VIFC_CommandLocked" 
  // 37 - "RepeatedOrMissingFrame" 
  // 36 - "ErrorDuringWritingEEProms" 
  // 35 - "UnknownCommand" 
  // 34 - "InvalidParameter" 
  // 33 - "ChecksumErrorInFrame" 
  // 32 - "Timeout10msExpired" 

  uint16_t IG_IMD_ERROR_CODE;                    //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_HV_2;                          //      Bits=16.  [ 0     , 0      ]  Unit:'Volt' 

  uint16_t IG_IMC_HV_1;                          //      Bits=16.  [ 0     , 0      ]  Unit:'Volt' 

  uint16_t IG_IMC_R_ISO_WRN_THR;                 //      Bits=16.  [ 0     , 0      ]  Unit:'kOhm' 

  uint16_t IG_IMC_R_ISO_ERR_THR;                 //      Bits=16.  [ 0     , 0      ]  Unit:'kOhm' 

  uint16_t IG_IMC_R_ISO;                         //      Bits=16.  [ 0     , 0      ]  Unit:'kOhm' 

  // 2 - "ParameterConfig" 
  // 1 - "OverAll" 
  // 0 - "NoAction" 

  uint16_t IC_IMC_SELFTEST_SCR;                  //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_TEST_CNT;                      //      Bits=16.  [ 0     , 0      ]  Unit:'Calls'

  // 2 - "Firmware ID" 
  // 1 - "Firmware" 
  // 0 - "Bootloader" 

  uint16_t IG_IMC_VERSION_INDEX;                 //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IMD_Response_DataWord1;               //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_VIFC_STATUS_01_IMCConnection;       //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_01_Ground;               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_VIFC_STATUS_02_IMC_Alive;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_02_System;               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "Running" 
  // 0 - "NotRunning" 

  uint8_t IG_IMC_STATUS_03_Calibration;          //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "Running" 
  // 0 - "NotRunning" 

  uint8_t IG_IMC_STATUS_04_Selftest;             //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Warning" 
  // 0 - "NoWarning" 

  uint8_t IG_IMC_STATUS_05_IsoWarning;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t IG_VIFC_STATUS_08_Outdated;            //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t IG_VIFC_VERSION_MIN;                   //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t IG_IMC_VERSION_MIN;                    //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_MANUFACT_DATA;                 //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 2 - "FailureOnHV+" 
  // 1 - "FailureOnHV-" 
  // 0 - "Unknown" 

  uint8_t IG_IMC_R_ISO_BIAS;                     //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t IS_IMC_EEPROM_DATA;                   //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "HVEnabled" 
  // 0 - "HVDisabled" 

  uint16_t IS_VIFC_HV_RELAIS_STATE;              //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint16_t IG_IMC_EEPROM_DATA;                   //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 100 - "Unknown" 
  // 1 - "HVEnabled" 
  // 0 - "HVDisabled" 

  uint16_t IG_VIFC_HV_RELAIS_STATE;              //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_00_Calibration;      //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 255 - "S_IMD_ERROR_FRAME" 
  // 226 - "S_VIFC_GET_IMC_ALIVE" 
  // 225 - "S_VIFC_GET_TEMP" 
  // 224 - "S_VIFC_GET_LOCK" 
  // 223 - "S_VIFC_GET_POWER_MODE" 
  // 222 - "S_VIFC_GET_VERSION" 
  // 221 - "S_VIFC_GET_HV_RELAIS" 
  // 220 - "S_VIFC_GET_STATUS" 
  // 210 - "S_VIFC_SET_HV_RELAIS" 
  // 203 - "S_VIFC_CTL_MEASUREMENT" 
  // 202 - "S_VIFC_CTL_LOCK" 
  // 201 - "S_VIFC_CTL_POWER_MODE" 
  // 200 - "S_VIFC_CTL_IMC_RESET" 
  // 90 - "S_IMC_GET_TEST_CNT" 
  // 61 - "S_IMC_GET_MANUFACTURER" 
  // 60 - "S_IMC_GET_MEAN_FACTOR" 
  // 59 - "S_IMC_GET_EEPROM" 
  // 58 - "S_IMC_GET_HV_2" 
  // 57 - "S_IMC_GET_R_ISO_WRN_THR" 
  // 55 - "S_IMC_GET_STATUS" 
  // 54 - "S_IMC_GET_HV_1" 
  // 53 - "S_IMC_GET_R_ISO" 
  // 51 - "S_IMC_GET_VERSION" 
  // 50 - "S_IMC_GET_R_ISO_ERR_THR" 
  // 43 - "S_IMC_SET_MEAN_FACTOR" 
  // 42 - "S_IMC_SET_EEPROM" 
  // 41 - "S_IMC_SET_R_ISO_WRN_THR" 
  // 40 - "S_IMC_SET_R_ISO_ERR_THR" 
  // 35 - "S_IMC_CTL_SYS_UPDATE" 
  // 34 - "S_IMC_CTL_CALIB" 
  // 33 - "S_IMC_CTL_SELFTEST" 
  // 0 - "S_VIFC_CTL_DUMMY" 

  uint8_t IG_IMD_FAILED_CMD;                     //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t IMD_Response_DataWord2;               //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_01_Hardware;         //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_02_EEPROM;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_03_Flash;            //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_04_RAM;              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_05_Stack;            //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_06_Reserved;         //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_07_Parameter;        //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t IG_IMC_R_ISO_CNT;                      //      Bits=08.  [ 0     , 0      ]  Unit:'Count'

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_08_TestPulse;        //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t IG_VIFC_VERSION_MAJ;                   //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t IG_IMC_VERSION_MAJ;                    //      Bits=08.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_09_12V_POS;          //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_10_12V_NEG;          //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_11_FuseBits;         //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_12_HV1;              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_13_HV2;              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_14_IDString;         //      Bits=01.  [ 0     , 0      ]  Unit:''     

  // 1 - "Error" 
  // 0 - "NoError" 

  uint8_t IG_IMC_STATUS_EXT_15_Reserved;         //      Bits=01.  [ 0     , 0      ]  Unit:''     
} IMD_Response_t;

// def @IMD_Info CAN Message (55)
#define IMD_Info_IDE (0U)
#define IMD_Info_DLC (6U)
#define IMD_Info_CANID (0x37U)
#define IMD_Info_CYC (1000U)
typedef struct
{

  uint16_t II_IMC_R_ISO;                         //      Bits=16.  [ 0     , 0      ]  Unit:'kOhm' 

  uint8_t II_IMC_STATUS_00_IsoFailure;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_IMC_STATUS_01_Ground;               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_IMC_STATUS_02_System;               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_IMC_STATUS_03_Calibration;          //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_IMC_STATUS_04_Selftest;             //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_IMC_STATUS_05_IsoWarning;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_VIFC_STATUS_00_IsoMeasurement;      //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_VIFC_STATUS_01_IMC_Connection;      //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_VIFC_STATUS_02_IMC_Alive;           //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t II_VIFC_STATUS_08_Outdated;            //      Bits=01.  [ 0     , 0      ]  Unit:''     
} IMD_Info_t;

// def @UDS_IMD_FLASH_REQ CAN Message (1806)
#define UDS_IMD_FLASH_REQ_IDE (0U)
#define UDS_IMD_FLASH_REQ_DLC (8U)
#define UDS_IMD_FLASH_REQ_CANID (0x70EU)
typedef struct
{

  uint8_t UDS_IMD_FLASH_REQ_B0;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B1;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B2;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B3;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B4;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B5;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B6;             //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_REQ_B7;             //      Bits=08.  [ 0     , 0      ]  Unit:''     
} UDS_IMD_FLASH_REQ_t;

// def @UDS_IMD_FLASH_RESP CAN Message (1912)
#define UDS_IMD_FLASH_RESP_IDE (0U)
#define UDS_IMD_FLASH_RESP_DLC (8U)
#define UDS_IMD_FLASH_RESP_CANID (0x778U)
typedef struct
{

  uint8_t UDS_IMD_FLASH_RESP_B0;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B1;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B2;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B3;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B4;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B5;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B6;            //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t UDS_IMD_FLASH_RESP_B7;            //      Bits=08.  [ 0     , 0      ]  Unit:''     
} UDS_IMD_FLASH_RESP_t;

uint32_t Unpack_IMD_Request_isolation(IMD_Request_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_IMD_Request_isolation(const IMD_Request_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_IMD_Response_isolation(IMD_Response_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_IMD_Response_isolation(const IMD_Response_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_IMD_Info_isolation(IMD_Info_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_IMD_Info_isolation(const IMD_Info_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_UDS_IMD_FLASH_REQ_isolation(UDS_IMD_FLASH_REQ_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_UDS_IMD_FLASH_REQ_isolation(const UDS_IMD_FLASH_REQ_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_UDS_IMD_FLASH_RESP_isolation(UDS_IMD_FLASH_RESP_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_UDS_IMD_FLASH_RESP_isolation(const UDS_IMD_FLASH_RESP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);

#ifdef __cplusplus
}
#endif

