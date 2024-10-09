
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
//#include "canmonitorutil.h"



// def @ECU_NMT_command CAN Message (0)
#define ECU_NMT_command_IDE (0U)
#define ECU_NMT_command_DLC (2U)
#define ECU_NMT_command_CANID (0x0U)
#define ECU_NMT_command_CYC (400U)
typedef struct
{

  uint8_t ECU_NMT_CommandSpecifier;         //      Bits=08.  [ 0     , 130    ]  Unit:''     

  uint8_t ECU_NMT_NodeId;                   //      Bits=08.  [ 0     , 127    ]  Unit:''     
} ECU_NMT_command_t;

// def @ECU_SYNC CAN Message (128)
#define ECU_SYNC_IDE (0U)
#define ECU_SYNC_DLC (1U)
#define ECU_SYNC_CANID (0x80U)
#define ECU_SYNC_CYC (10U)
// -- Counter not implemented
typedef struct
{

  // Counter is not implemented by EMD
  uint8_t ECU_SYNCH_Counter;                //      Bits=08.  [ 0     , 255    ]  Unit:''     
} ECU_SYNC_t;

// def @EMD_TxPDO_5 CAN Message (442)
#define EMD_TxPDO_5_IDE (0U)
#define EMD_TxPDO_5_DLC (4U)
#define EMD_TxPDO_5_CANID (0x1BAU)
#define EMD_TxPDO_5_CYC (1000U)
// -- Message with actual values. The transmission type and transmission cycle can be configured.
// signal: @EMD_ACT_MaxJunctionTemp
#define EMD_TxPDO_5_EMD_ACT_MaxJunctionTemp_CovFactor (1)
// conversion value to CAN signal
#define EMD_TxPDO_5_EMD_ACT_MaxJunctionTemp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define EMD_TxPDO_5_EMD_ACT_MaxJunctionTemp_fromS(x) (x)

// signal: @EMD_ACT_MotorTemperature
#define EMD_TxPDO_5_EMD_ACT_MotorTemperature_CovFactor (1)
// conversion value to CAN signal
#define EMD_TxPDO_5_EMD_ACT_MotorTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define EMD_TxPDO_5_EMD_ACT_MotorTemperature_fromS(x) (x)

typedef struct
{

  // Indicates the actual maximum junction temperature in the power module.
  int16_t EMD_ACT_MaxJunctionTemp;           //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  // Indicates the actual motor (stator) temperature.
  int16_t EMD_ACT_MotorTemperature;          //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  // Indicates the active control strategy (defined by the load type).
  // 7 - "unused" 
  // 6 - "BRC" 
  // 5 - "BLDC" 
  // 4 - "reserved" 
  // 3 - "IFOC ASM" 
  // 2 - "FOC IPM" 
  // 1 - "FOC PSM" 
  // 0 - "none (no operation)" 

  uint8_t EMD_ACT_ControlStrategy;           //      Bits=03.  [ 0     , 7      ]  Unit:''     

  // Validity of actual motor temperature.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_MotorTemperature_VAL;      //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Validity of actual maximum junction temperature.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_MaxJunctionTemp_VAL;       //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Message counter of TxPDO5.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_TxPDO5;                 //      Bits=04.  [ 0     , 15     ]  Unit:''     
} EMD_TxPDO_5_t;

// def @EMD_TxPDO_1 CAN Message (506)
#define EMD_TxPDO_1_IDE (0U)
#define EMD_TxPDO_1_DLC (8U)
#define EMD_TxPDO_1_CANID (0x1FAU)
#define EMD_TxPDO_1_CYC (10U)
// -- Message with actual values. The transmission type and transmission cycle can be configured.
// signal: @EMD_ACT_InverterLosses
#define EMD_TxPDO_1_EMD_ACT_InverterLosses_CovFactor (10)
// conversion value to CAN signal
#define EMD_TxPDO_1_EMD_ACT_InverterLosses_toS(x) ((uint16_t)((x) / 10))
// conversion value from CAN signal
#define EMD_TxPDO_1_EMD_ACT_InverterLosses_fromS(x) ((x) * 10)

// signal: @EMD_ACT_MotorLosses
#define EMD_TxPDO_1_EMD_ACT_MotorLosses_CovFactor (10)
// conversion value to CAN signal
#define EMD_TxPDO_1_EMD_ACT_MotorLosses_toS(x) ((uint16_t)((x) / 10))
// conversion value from CAN signal
#define EMD_TxPDO_1_EMD_ACT_MotorLosses_fromS(x) ((x) * 10)

typedef struct
{

  // Indicates the sum of the conduction and switching losses in the inverter.  Losses = inverter losses + motor losses.  Note: depending on machine type, not all motor losses are calculated
  uint16_t EMD_ACT_InverterLosses;          //      Bits=12.  [ 0     , 40950  ]  Unit:'W'     Factor= 10    

  // Indicates the actual state of the inverter firmware.
  // 0 - "undef" 
  // 1 - "Initializing" 
  // 2 - "Ready (PWM off)" 
  // 3 - "Enable (PWM on)" 
  // 4 - "unused" 
  // 5 - "Error" 
  // 6 - "Initialization Failed" 
  // 7 - "reserved" 
  // 8 - "reserved" 
  // 9 - "Restart" 
  // 10 - "Shutting Down" 
  // 11 - "Position Sensor Calibration" 
  // 12 - "HV Disabled" 
  // 13 - "unused" 
  // 14 - "unused" 
  // 15 - "unused" 

  uint8_t EMD_ACT_InverterState;            //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Indicates the actual losses in the motor.  Losses = inverter losses + motor losses.    Note: depending on machine type, not all motor losses are calculated
  uint16_t EMD_ACT_MotorLosses;             //      Bits=12.  [ 0     , 40950  ]  Unit:'W'     Factor= 10    

  // Message counter of TxPDO1.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_TxPDO1;                //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Indicates the most recent error indicated (consecutive error after causing error).   If only one error is detected LastError = CausingError.
  // 0 - "No error" 
  // 1 - "Short circuit (DSCP) L1 TOP" 
  // 2 - "Short circuit (DSCP) L1 BOT" 
  // 3 - "Short circuit (DSCP) L2 TOP" 
  // 4 - "Short circuit (DSCP) L2 BOT" 
  // 5 - "Short circuit (DSCP) L3 TOP" 
  // 6 - "Short circuit (DSCP) L3 BOT" 
  // 7 - "Undervoltage (UVP) L1 TOP" 
  // 8 - "Undervoltage (UVP) L1 BOT" 
  // 9 - "Undervoltage (UVP) L2 TOP" 
  // 10 - "Undervoltage (UVP) L2 BOT" 
  // 11 - "Undervoltage (UVP) L3 TOP" 
  // 12 - "Undervoltage (UVP) L3 BOT" 
  // 13 - "Overcurrent phase L1 POS" 
  // 14 - "Overcurrent phase L1 NEG" 
  // 15 - "Overcurrent phase L2 POS" 
  // 16 - "Overcurrent phase L2 NEG" 
  // 17 - "Overcurrent phase L3 POS" 
  // 18 - "Overcurrent phase L3 NEG" 
  // 19 - "DC link overvoltage" 
  // 20 - "Supply undervoltage" 
  // 21 - "DCB overtemp. L1 (HW)" 
  // 22 - "DCB overtemp. L2 (HW)" 
  // 23 - "DCB overtemp. L3 (HW)" 
  // 24 - "PCB overtemperature (HW)" 
  // 25 - "Motor temp. sensor error" 
  // 26 - "Resolver track lost" 
  // 27 - "Resolver track high" 
  // 28 - "Resolver degenerated" 
  // 29 - "Resolver config parity" 
  // 30 - "Resolver phase high" 
  // 31 - "Resolver speed high" 
  // 32 - "Resolver sin/cos fail" 
  // 33 - "Resolver sin/cos high" 
  // 34 - "Resolver sin/cos low" 
  // 35 - "Resolver sin/cos cut" 
  // 39 - "HVIL missing" 
  // 43 - "DC link undervoltage" 
  // 44 - "DC link overvoltage" 
  // 48 - "PCB overtemperature (SW)" 
  // 50 - "Motor overtemperature" 
  // 51 - "Motor overspeed" 
  // 52 - "FPGA communication failed" 
  // 54 - "CAN A node guard expired" 
  // 55 - "CAN bus A off" 
  // 58 - "CAN bus A bitrate " 
  // 60 - "CAN bus A channel" 
  // 62 - "CAN bus A general" 
  // 63 - "CAN B node guard expired" 
  // 64 - "CAN bus B off" 
  // 67 - "CAN bus B bitrate " 
  // 69 - "CAN bus B channel" 
  // 71 - "CAN bus B general" 
  // 72 - "Encoder signal deg." 
  // 73 - "Watchdog occurred" 
  // 74 - "D current difference" 
  // 75 - "Q current difference" 
  // 78 - "Timing exceeded" 
  // 79 - "Initialization failed" 
  // 80 - "Table version wrong" 
  // 81 - "Table checksum flash" 
  // 100 - "Enable denied speed" 
  // 101 - "Fatal error" 
  // 102 - "SPO / External Error" 
  // 103 - "Inverter init failed" 
  // 104 - "CAN initialization failed" 
  // 105 - "License invalid" 
  // 106 - "Scope init failed" 
  // 110 - "Table not initialized" 
  // 111 - "Division by zero" 
  // 112 - "Table positive Id value" 
  // 114 - "PTC resistor is zero" 
  // 116 - "Sample mode undefined" 
  // 117 - "Position init failed" 
  // 118 - "PWM modulation invalid" 
  // 119 - "Float out of range" 
  // 120 - "Parameter read failed (store)" 
  // 121 - "Parameter read failed (format)" 
  // 122 - "Parameter table checksum " 
  // 123 - "ASC overvoltage" 
  // 126 - "Max. torque table invalid" 
  // 127 - "Max. current [0x2100]" 
  // 129 - "Adapt torque [0x2499]" 
  // 135 - "Init error log failed" 
  // 136 - "PLL not locked" 
  // 137 - "PLL not synchronized" 
  // 138 - "PLL [0x2173]-[0x2174]" 
  // 139 - "EEPROM init failed" 
  // 141 - "Invalid device information" 
  // 142 - "Motor type [0x2119]" 
  // 143 - "PWM Frequency [0x2077]" 
  // 144 - "External temp. sensor [0x214A]" 
  // 145 - "Read hour counter failed" 
  // 146 - "Write hour counter failed" 
  // 147 - "Max cutback limits" 
  // 148 - "Min cutback limits" 
  // 150 - "Kp is wrong [0x21B5]" 
  // 151 - "Ki is wrong [0x21B6]" 
  // 152 - "Cutback bit is invalid" 
  // 153 - "Current Sensor 1 Offset" 
  // 154 - "Current Sensor 3 Offset" 
  // 155 - "Cutback I2T [2513] [2514]" 
  // 156 - "Current sensor offset calib." 
  // 157 - "Invalid ASC state feedback" 
  // 158 - "Control mode not supported" 
  // 159 - "Junction overtemperature" 
  // 160 - "Torque limitation supervision" 
  // 161 - "Undervoltage supply input " 
  // 162 - "Current Sensor 2 Offset" 
  // 163 - "Kirchhoff current check" 
  // 164 - "DCB plausibility check" 
  // 165 - "Resolver loss of signal" 
  // 166 - "Dead time currents conflict" 
  // 167 - "S-shape initialization" 
  // 168 - "Memory test failed" 
  // 169 - "Stack overflow detected" 
  // 170 - "Angle offset uncalibrated" 
  // 174 - "Timing exceeded 1ms" 
  // 175 - "Store to EEPROM failed" 
  // 176 - "Init event log failed" 
  // 178 - "Cutback active while PS calib." 
  // 179 - "Invalid CAN parameter" 
  // 180 - "Ext. temp. 2 Error" 
  // 181 - "Ext. temp. 2 overtemp." 
  // 182 - "Table Motor Type" 
  // 183 - "Id boost cutback conflict" 
  // 184 - "CANopen message timeout" 
  // 185 - "CANopen message counter" 
  // 186 - "Invalid Poles" 
  // 187 - "Comp. observer config" 
  // 188 - "Voltage drop comp. [0x21ED-1] " 
  // 190 - "PS calib high current" 
  // 191 - "PS calib low current" 
  // 192 - "PS calib ramp up time low" 
  // 193 - "PS calib speed 1 high or 0" 
  // 194 - "PS calib speed ramp up low" 
  // 195 - "PS calib speed 2 high or 0" 
  // 196 - "PS calib wrong motor type" 
  // 197 - "PS calib few measurements" 
  // 198 - "PS calib high current error" 
  // 199 - "PS calib not rotating" 
  // 200 - "PS calib bad rotating sense" 
  // 201 - "PS calib bad speed 1" 
  // 202 - "PS calib bad speed 2" 
  // 203 - "PS calib bad speed and sense " 
  // 207 - "PS calib time out speed (fine)" 
  // 209 - "PS calib stop time out" 
  // 211 - "PS calib low speed 1" 
  // 212 - "PS calib low speed 2" 
  // 213 - "PS calib timeout 0 current" 
  // 215 - "PS calib failed speed 1 (fine)" 
  // 216 - "PS calib failed speed 2 (fine)" 
  // 217 - "PS calib over speed 1 " 
  // 219 - "PS calib general error" 
  // 220 - "HW code limit exceeded" 
  // 221 - "Part number FW not valid" 
  // 222 - "Part number BL is not valid" 
  // 223 - "S-shape initialization" 
  // 224 - "J1939 debug request timeout" 
  // 225 - "Unexpected shut-down" 
  // 226 - "Resolver plausibility check" 
  // 227 - "Indexes [0x2069]/[0x2111]>1" 
  // 228 - "Inverter type not supported" 
  // 229 - "HW code data inconsistent" 
  // 230 - "Invalid control mode requested" 
  // 231 - "Reading UDS config failed" 
  // 232 - "Dc link voltage sensor error" 
  // 233 - "ADC ref. voltage error" 
  // 234 - "Incompatible PDO map" 
  // 235 - "DC link power selection [2029]" 
  // 236 - "Encoder lines [0x2188] < 1" 
  // 237 - "Timing exceeded main loop" 
  // 238 - "NMT command disabled the PWM" 
  // 750 - "J1939 nominal torque" 
  // 751 - "J1939 stuck speed/torque req. " 
  // 752 - "J1939 DC power limits" 
  // 753 - "CAN J1939 enable message" 
  // 754 - "J1939 speed/torque timeout" 
  // 755 - "AC over current error" 
  // 756 - "Current gain mismatch 2 3" 
  // 757 - "Current gain mismatch 1 2" 
  // 758 - "UDS parameter mismatch" 
  // 759 - "DC link power ctrl. conflict" 

  uint16_t EMD_ACT_LastError;               //      Bits=10.  [ 0     , 1023   ]  Unit:''     

  // Validity of actual inverter losses.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_InverterLosses_VAL;       //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Validity of actual motor losses.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_MotorLosses_VAL;          //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Indicates the status of the digital output 1 (MP_DO_C1).
  // 0 - "low" 
  // 1 - "high" 

  uint8_t EMD_ACT_DigitalOutput1;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Indicates the status of the digital output 2 (MP_DO_C2).
  // 0 - "low" 
  // 1 - "high" 

  uint8_t EMD_ACT_DigitalOutput2;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Indicates the error the has initially caused the transition to error state (disabling PWM).
  // 0 - "No error" 
  // 1 - "Short circuit (DSCP) L1 TOP" 
  // 2 - "Short circuit (DSCP) L1 BOT" 
  // 3 - "Short circuit (DSCP) L2 TOP" 
  // 4 - "Short circuit (DSCP) L2 BOT" 
  // 5 - "Short circuit (DSCP) L3 TOP" 
  // 6 - "Short circuit (DSCP) L3 BOT" 
  // 7 - "Undervoltage (UVP) L1 TOP" 
  // 8 - "Undervoltage (UVP) L1 BOT" 
  // 9 - "Undervoltage (UVP) L2 TOP" 
  // 10 - "Undervoltage (UVP) L2 BOT" 
  // 11 - "Undervoltage (UVP) L3 TOP" 
  // 12 - "Undervoltage (UVP) L3 BOT" 
  // 13 - "Overcurrent phase L1 POS" 
  // 14 - "Overcurrent phase L1 NEG" 
  // 15 - "Overcurrent phase L2 POS" 
  // 16 - "Overcurrent phase L2 NEG" 
  // 17 - "Overcurrent phase L3 POS" 
  // 18 - "Overcurrent phase L3 NEG" 
  // 19 - "DC link overvoltage" 
  // 20 - "Supply undervoltage" 
  // 21 - "DCB overtemp. L1 (HW)" 
  // 22 - "DCB overtemp. L2 (HW)" 
  // 23 - "DCB overtemp. L3 (HW)" 
  // 24 - "PCB overtemperature (HW)" 
  // 25 - "Motor temp. sensor error" 
  // 26 - "Resolver track lost" 
  // 27 - "Resolver track high" 
  // 28 - "Resolver degenerated" 
  // 29 - "Resolver config parity" 
  // 30 - "Resolver phase high" 
  // 31 - "Resolver speed high" 
  // 32 - "Resolver sin/cos fail" 
  // 33 - "Resolver sin/cos high" 
  // 34 - "Resolver sin/cos low" 
  // 35 - "Resolver sin/cos cut" 
  // 39 - "HVIL missing" 
  // 43 - "DC link undervoltage" 
  // 44 - "DC link overvoltage" 
  // 48 - "PCB overtemperature (SW)" 
  // 50 - "Motor overtemperature" 
  // 51 - "Motor overspeed" 
  // 52 - "FPGA communication failed" 
  // 54 - "CAN A node guard expired" 
  // 55 - "CAN bus A off" 
  // 58 - "CAN bus A bitrate " 
  // 60 - "CAN bus A channel" 
  // 62 - "CAN bus A general" 
  // 63 - "CAN B node guard expired" 
  // 64 - "CAN bus B off" 
  // 67 - "CAN bus B bitrate " 
  // 69 - "CAN bus B channel" 
  // 71 - "CAN bus B general" 
  // 72 - "Encoder signal deg." 
  // 73 - "Watchdog occurred" 
  // 74 - "D current difference" 
  // 75 - "Q current difference" 
  // 78 - "Timing exceeded" 
  // 79 - "Initialization failed" 
  // 80 - "Table version wrong" 
  // 81 - "Table checksum flash" 
  // 100 - "Enable denied speed" 
  // 101 - "Fatal error" 
  // 102 - "SPO / External Error" 
  // 103 - "Inverter init failed" 
  // 104 - "CAN initialization failed" 
  // 105 - "License invalid" 
  // 106 - "Scope init failed" 
  // 110 - "Table not initialized" 
  // 111 - "Division by zero" 
  // 112 - "Table positive Id value" 
  // 114 - "PTC resistor is zero" 
  // 116 - "Sample mode undefined" 
  // 117 - "Position init failed" 
  // 118 - "PWM modulation invalid" 
  // 119 - "Float out of range" 
  // 120 - "Parameter read failed (store)" 
  // 121 - "Parameter read failed (format)" 
  // 122 - "Parameter table checksum " 
  // 123 - "ASC overvoltage" 
  // 126 - "Max. torque table invalid" 
  // 127 - "Max. current [0x2100]" 
  // 129 - "Adapt torque [0x2499]" 
  // 135 - "Init error log failed" 
  // 136 - "PLL not locked" 
  // 137 - "PLL not synchronized" 
  // 138 - "PLL [0x2173]-[0x2174]" 
  // 139 - "EEPROM init failed" 
  // 141 - "Invalid device information" 
  // 142 - "Motor type [0x2119]" 
  // 143 - "PWM Frequency [0x2077]" 
  // 144 - "External temp. sensor [0x214A]" 
  // 145 - "Read hour counter failed" 
  // 146 - "Write hour counter failed" 
  // 147 - "Max cutback limits" 
  // 148 - "Min cutback limits" 
  // 150 - "Kp is wrong [0x21B5]" 
  // 151 - "Ki is wrong [0x21B6]" 
  // 152 - "Cutback bit is invalid" 
  // 153 - "Current Sensor 1 Offset" 
  // 154 - "Current Sensor 3 Offset" 
  // 155 - "Cutback I2T [2513] [2514]" 
  // 156 - "Current sensor offset calib." 
  // 157 - "Invalid ASC state feedback" 
  // 158 - "Control mode not supported" 
  // 159 - "Junction overtemperature" 
  // 160 - "Torque limitation supervision" 
  // 161 - "Undervoltage supply input " 
  // 162 - "Current Sensor 2 Offset" 
  // 163 - "Kirchhoff current check" 
  // 164 - "DCB plausibility check" 
  // 165 - "Resolver loss of signal" 
  // 166 - "Dead time currents conflict" 
  // 167 - "S-shape initialization" 
  // 168 - "Memory test failed" 
  // 169 - "Stack overflow detected" 
  // 170 - "Angle offset uncalibrated" 
  // 174 - "Timing exceeded 1ms" 
  // 175 - "Store to EEPROM failed" 
  // 176 - "Init event log failed" 
  // 178 - "Cutback active while PS calib." 
  // 179 - "Invalid CAN parameter" 
  // 180 - "Ext. temp. 2 Error" 
  // 181 - "Ext. temp. 2 overtemp." 
  // 182 - "Table Motor Type" 
  // 183 - "Id boost cutback conflict" 
  // 184 - "CANopen message timeout" 
  // 185 - "CANopen message counter" 
  // 186 - "Invalid Poles" 
  // 187 - "Comp. observer config" 
  // 188 - "Voltage drop comp. [0x21ED-1] " 
  // 190 - "PS calib high current" 
  // 191 - "PS calib low current" 
  // 192 - "PS calib ramp up time low" 
  // 193 - "PS calib speed 1 high or 0" 
  // 194 - "PS calib speed ramp up low" 
  // 195 - "PS calib speed 2 high or 0" 
  // 196 - "PS calib wrong motor type" 
  // 197 - "PS calib few measurements" 
  // 198 - "PS calib high current error" 
  // 199 - "PS calib not rotating" 
  // 200 - "PS calib bad rotating sense" 
  // 201 - "PS calib bad speed 1" 
  // 202 - "PS calib bad speed 2" 
  // 203 - "PS calib bad speed and sense " 
  // 207 - "PS calib time out speed (fine)" 
  // 209 - "PS calib stop time out" 
  // 211 - "PS calib low speed 1" 
  // 212 - "PS calib low speed 2" 
  // 213 - "PS calib timeout 0 current" 
  // 215 - "PS calib failed speed 1 (fine)" 
  // 216 - "PS calib failed speed 2 (fine)" 
  // 217 - "PS calib over speed 1 " 
  // 219 - "PS calib general error" 
  // 220 - "HW code limit exceeded" 
  // 221 - "Part number FW not valid" 
  // 222 - "Part number BL is not valid" 
  // 223 - "S-shape initialization" 
  // 224 - "J1939 debug request timeout" 
  // 225 - "Unexpected shut-down" 
  // 226 - "Resolver plausibility check" 
  // 227 - "Indexes [0x2069]/[0x2111]>1" 
  // 228 - "Inverter type not supported" 
  // 229 - "HW code data inconsistent" 
  // 230 - "Invalid control mode requested" 
  // 231 - "Reading UDS config failed" 
  // 232 - "Dc link voltage sensor error" 
  // 233 - "ADC ref. voltage error" 
  // 234 - "Incompatible PDO map" 
  // 235 - "DC link power selection [2029]" 
  // 236 - "Encoder lines [0x2188] < 1" 
  // 237 - "Timing exceeded main loop" 
  // 238 - "NMT command disabled the PWM" 
  // 750 - "J1939 nominal torque" 
  // 751 - "J1939 stuck speed/torque req. " 
  // 752 - "J1939 DC power limits" 
  // 753 - "CAN J1939 enable message" 
  // 754 - "J1939 speed/torque timeout" 
  // 755 - "AC over current error" 
  // 756 - "Current gain mismatch 2 3" 
  // 757 - "Current gain mismatch 1 2" 
  // 758 - "UDS parameter mismatch" 
  // 759 - "DC link power ctrl. conflict" 

  uint16_t EMD_ACT_CausingError;            //      Bits=10.  [ 0     , 1023   ]  Unit:''     

  // Indicates the status of the digital input 1 (MP_DI_C1).
  // 0 - "low" 
  // 1 - "high" 

  uint8_t EMD_ACT_DigitalInput1;            //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Indicates the status of the digital input 2 (MP_DI_C2)
  // 0 - "low" 
  // 1 - "high" 

  uint8_t EMD_ACT_DigitalInput2;            //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Indicates the actual limitation mode. It defines the source of the reference values (EMD_CMD_xxx).   Symmetric: SpeedRefLim. resp. TorqueRefLim  Asymmetric: SpeedLimitLow/SpeedLimitHigh resp. TorqueLimitLow/TorqueLimitHigh
  // 0 - "Symmetric speed or torque limit" 
  // 1 - "Asymmetric speed or torque limit" 

  uint8_t EMD_ACT_LimitationMode;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // State of active short circuit (three phase short circuit).
  // 0 - "ASCState off" 
  // 1 - "ASC active" 

  uint8_t EMD_ACT_ASCState;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Indicates the acutal state of the active discharge function of the inverter.
  // 0 - "Active Discharge off" 
  // 1 - "Active Discharge active" 

  uint8_t EMD_ACT_DischargeState;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Indicates the actual raw status of the SPO input. When the SPO input goes low a error is set.   The error remains active even if the SPO input goes high again. The error must be cleared before enabling is possible again.
  // 1 - "high (pulse on )" 
  // 0 - "low (pulse off)" 

  uint8_t EMD_ACT_SpoInput;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     
} EMD_TxPDO_1_t;

// def @EMD_RxPDO_5 CAN Message (570)
#define EMD_RxPDO_5_IDE (0U)
#define EMD_RxPDO_5_DLC (5U)
#define EMD_RxPDO_5_CANID (0x23AU)
#define EMD_RxPDO_5_CYC (10U)
// -- Message only required is asymetric limits are used.  If limitation mode is symetric the message is not needed (unless message counter and message timeout are activated.
// signal: @EMD_CMD_SpeedLimitHigh
#define EMD_RxPDO_5_EMD_CMD_SpeedLimitHigh_CovFactor (1)
// conversion value to CAN signal
#define EMD_RxPDO_5_EMD_CMD_SpeedLimitHigh_toS(x) ((int32_t)((x) + 32768))
// conversion value from CAN signal
#define EMD_RxPDO_5_EMD_CMD_SpeedLimitHigh_fromS(x) ((x))

// signal: @EMD_CMD_SpeedLimitLow
#define EMD_RxPDO_5_EMD_CMD_SpeedLimitLow_CovFactor (1)
// conversion value to CAN signal
#define EMD_RxPDO_5_EMD_CMD_SpeedLimitLow_toS(x) ((int32_t)((x) + 32768))
// conversion value from CAN signal
#define EMD_RxPDO_5_EMD_CMD_SpeedLimitLow_fromS(x) ((x))

typedef struct
{

  // Command to request the high speed limit in torque control mode when asymetric limitation mode is active.
  int32_t EMD_CMD_SpeedLimitHigh;           //      Bits=16.  [ -32768, 32767  ]  Unit:'rpm'   Offset= -32768   

  // Command to request the lower speed limit in torque control mode when asymetric limitation mode is active.
  int32_t EMD_CMD_SpeedLimitLow;            //      Bits=16.  [ -32768, 32767  ]  Unit:'rpm'   Offset= -32768   

  // Validity of request speed limit high.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_SpeedLimitHigh_VAL;       //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Valdity of requested speed limit low.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_SpeedLimitLow_VAL;        //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Message counter of RxPDO5.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_RxPDO5;                //      Bits=04.  [ 0     , 15     ]  Unit:''     
} EMD_RxPDO_5_t;

// def @EMD_RxPDO_1 CAN Message (634)
#define EMD_RxPDO_1_IDE (0U)
#define EMD_RxPDO_1_DLC (6U)
#define EMD_RxPDO_1_CANID (0x27AU)
#define EMD_RxPDO_1_CYC (10U)
// -- Message only required for test modes.   If no test mode is active the message is not needed (unless message counter and message timeout are activated.
// signal: @EMD_CMD_IdCurrentTest
#define EMD_RxPDO_1_EMD_CMD_IdCurrentTest_CovFactor (1)
// conversion value to CAN signal
#define EMD_RxPDO_1_EMD_CMD_IdCurrentTest_toS(x) ((int16_t)((x) + 2048))
// conversion value from CAN signal
#define EMD_RxPDO_1_EMD_CMD_IdCurrentTest_fromS(x) ((x))

// signal: @EMD_CMD_IqCurrentTest
#define EMD_RxPDO_1_EMD_CMD_IqCurrentTest_CovFactor (1)
// conversion value to CAN signal
#define EMD_RxPDO_1_EMD_CMD_IqCurrentTest_toS(x) ((int16_t)((x) + 2048))
// conversion value from CAN signal
#define EMD_RxPDO_1_EMD_CMD_IqCurrentTest_fromS(x) ((x))

// signal: @EMD_CMD_StatorFrequencyTest
#define EMD_RxPDO_1_EMD_CMD_StatorFrequencyTest_CovFactor (0.2)
// conversion value to CAN signal
#define EMD_RxPDO_1_EMD_CMD_StatorFrequencyTest_toS(x) ((uint16_t)((x) / 0.2))
// conversion value from CAN signal
#define EMD_RxPDO_1_EMD_CMD_StatorFrequencyTest_fromS(x) ((x) * 0.2)

typedef struct
{

  // Command to request the Id current for test mode (EMD_CMD_ControlMode = Test Id/Iq)
  int16_t EMD_CMD_IdCurrentTest;                //      Bits=12.  [ -2048 , 2047   ]  Unit:'Apeak' Offset= -2048    

  // Validity of requested Id test current.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_IdCurrentTest_VAL;            //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Validity of requested Iq test current.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_IqCurrentTest_VAL;            //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Command to request the Iq current for test mode (EMD_CMD_ControlMode = Test Id/Iq or Test closed loop)
  int16_t EMD_CMD_IqCurrentTest;                //      Bits=12.  [ -2048 , 2047   ]  Unit:'Apeak' Offset= -2048    

  // Message counter of RxPDO1.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_RxPDO1;                    //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Command to request the motor stator frequency for test mode (EMD_CMD_ControlMode = Test closes loop)
  uint16_t EMD_CMD_StatorFrequencyTest;         //      Bits=14.  [ 0     , 3276.6 ]  Unit:'Hz'    Factor= 0.2   

  // Validity of requested motor stator test frequency.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_StatorFrequencyTest_VAL;      //      Bits=02.  [ 0     , 3      ]  Unit:''     
} EMD_RxPDO_1_t;

// def @EMD_TxPDO_2 CAN Message (762)
#define EMD_TxPDO_2_IDE (0U)
#define EMD_TxPDO_2_DLC (8U)
#define EMD_TxPDO_2_CANID (0x2FAU)
#define EMD_TxPDO_2_CYC (10U)
// -- Message with actual values. The transmission type and transmission cycle can be configured.
// signal: @EMD_ACT_ReferenceTorqueLim
#define EMD_TxPDO_2_EMD_ACT_ReferenceTorqueLim_CovFactor (0.02)
// conversion value to CAN signal
#define EMD_TxPDO_2_EMD_ACT_ReferenceTorqueLim_toS(x) ((int16_t)((x) / 0.02 + 5000))
// conversion value from CAN signal
#define EMD_TxPDO_2_EMD_ACT_ReferenceTorqueLim_fromS(x) ((x) * 0.02)

// signal: @EMD_ACT_MaxAvailableTorque
#define EMD_TxPDO_2_EMD_ACT_MaxAvailableTorque_CovFactor (0.02)
// conversion value to CAN signal
#define EMD_TxPDO_2_EMD_ACT_MaxAvailableTorque_toS(x) ((uint16_t)((x) / 0.02))
// conversion value from CAN signal
#define EMD_TxPDO_2_EMD_ACT_MaxAvailableTorque_fromS(x) ((x) * 0.02)

// signal: @EMD_ACT_Torque
#define EMD_TxPDO_2_EMD_ACT_Torque_CovFactor (0.02)
// conversion value to CAN signal
#define EMD_TxPDO_2_EMD_ACT_Torque_toS(x) ((int16_t)((x) / 0.02 + 5000))
// conversion value from CAN signal
#define EMD_TxPDO_2_EMD_ACT_Torque_fromS(x) ((x) * 0.02)

typedef struct
{

  // Indicates actual limied reference torque (reference after applying limiter factor).
  int16_t EMD_ACT_ReferenceTorqueLim;          //      Bits=14.  [ -100  , 100    ]  Unit:'%'     Offset= -100      Factor= 0.02  

  // Validity of actual limited reference torque.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_ReferenceTorqueLim_VAL;      //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Indicates the maximum available torque. This value is a forcast an may change with changing working points.
  uint16_t EMD_ACT_MaxAvailableTorque;         //      Bits=14.  [ 0     , 327.66 ]  Unit:'%'     Factor= 0.02  

  // Validity of actual maximum available torque.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_MaxAvailableTorque_VAL;      //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Indicates the most limiting cutback limiter (the limiter causing the actual limitation).
  // 15 - "Low speed limiter" 
  // 14 - "DC link power" 
  // 13 - "Max. table" 
  // 12 - "DC link current" 
  // 11 - "Mechanical power" 
  // 10 - "Speed reference" 
  // 9 - "Maximum speed" 
  // 8 - "I2T" 
  // 7 - "SOA" 
  // 6 - "Maximum DC link" 
  // 5 - "Minimum DC link " 
  // 4 - "Junction/DCB temperature" 
  // 3 - "PCB temperature" 
  // 2 - "Motor accelleration" 
  // 1 - "Motor temperature" 
  // 0 - "Not active" 

  uint8_t EMD_ACT_CutbackNumber;               //      Bits=08.  [ 0     , 15     ]  Unit:''     

  // Indicates the actual torque (calculated).
  int16_t EMD_ACT_Torque;                      //      Bits=14.  [ -100  , 100    ]  Unit:'%'     Offset= -100      Factor= 0.02  

  // Validity of the actual torque.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_Torque_VAL;                  //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Message counter of TxPDO2.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_TxPDO2;                   //      Bits=04.  [ 0     , 15     ]  Unit:''     
} EMD_TxPDO_2_t;

// def @EMD_RxPDO_2 CAN Message (890)
#define EMD_RxPDO_2_IDE (0U)
#define EMD_RxPDO_2_DLC (5U)
#define EMD_RxPDO_2_CANID (0x37AU)
#define EMD_RxPDO_2_CYC (1000U)
// -- Message only required if power limiter is activated.  If the power limiter is not used, this message is not needed (unless message counter and message timeout are activated).
// signal: @EMD_CMD_PowerLimitGenerating
#define EMD_RxPDO_2_EMD_CMD_PowerLimitGenerating_CovFactor (0.002)
// conversion value to CAN signal
#define EMD_RxPDO_2_EMD_CMD_PowerLimitGenerating_toS(x) ((uint16_t)((x) / 0.002))
// conversion value from CAN signal
#define EMD_RxPDO_2_EMD_CMD_PowerLimitGenerating_fromS(x) ((x) * 0.002)

// signal: @EMD_CMD_PowerLimitMotoring
#define EMD_RxPDO_2_EMD_CMD_PowerLimitMotoring_CovFactor (0.002)
// conversion value to CAN signal
#define EMD_RxPDO_2_EMD_CMD_PowerLimitMotoring_toS(x) ((uint16_t)((x) / 0.002))
// conversion value from CAN signal
#define EMD_RxPDO_2_EMD_CMD_PowerLimitMotoring_fromS(x) ((x) * 0.002)

typedef struct
{

  // Command to request the power limit in generating mode.
  uint16_t EMD_CMD_PowerLimitGenerating;         //      Bits=16.  [ 0     , 100    ]  Unit:'%'     Factor= 0.002 

  // Command to request the power limit in motoring mode.
  uint16_t EMD_CMD_PowerLimitMotoring;           //      Bits=16.  [ 0     , 100    ]  Unit:'%'     Factor= 0.002 

  // Validity of requested  power limit in generating mode.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_PowerLimitGenerating_VAL;      //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Validity of requested  power limit in motoring mode.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_PowerLimitMotoring_VAL;        //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Message counter of RxPDO2.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_RxPDO2;                     //      Bits=04.  [ 0     , 15     ]  Unit:''     
} EMD_RxPDO_2_t;

// def @EMD_TxPDO_3 CAN Message (1018)
#define EMD_TxPDO_3_IDE (0U)
#define EMD_TxPDO_3_DLC (8U)
#define EMD_TxPDO_3_CANID (0x3FAU)
#define EMD_TxPDO_3_CYC (10U)
// -- Message with actual values. The transmission type and transmission cycle can be configured.
// signal: @EMD_ACT_MotorSpeed
#define EMD_TxPDO_3_EMD_ACT_MotorSpeed_CovFactor (1)
// conversion value to CAN signal
#define EMD_TxPDO_3_EMD_ACT_MotorSpeed_toS(x) ((int32_t)((x) + 32768))
// conversion value from CAN signal
#define EMD_TxPDO_3_EMD_ACT_MotorSpeed_fromS(x) (x);

// signal: @EMD_ACT_MechanicPower
#define EMD_TxPDO_3_EMD_ACT_MechanicPower_CovFactor (10)
// conversion value to CAN signal
#define EMD_TxPDO_3_EMD_ACT_MechanicPower_toS(x) ((int32_t)((x) / 10 + 32768))
// conversion value from CAN signal
#define EMD_TxPDO_3_EMD_ACT_MechanicPower_fromS(x) ((x) * 10)

// signal: @EMD_ACT_DcLinkPower
#define EMD_TxPDO_3_EMD_ACT_DcLinkPower_CovFactor (10)
// conversion value to CAN signal
#define EMD_TxPDO_3_EMD_ACT_DcLinkPower_toS(x) ((int32_t)((x) / 10 + 32768))
// conversion value from CAN signal
#define EMD_TxPDO_3_EMD_ACT_DcLinkPower_fromS(x) ((x) * 10)

typedef struct
{

  // Indicates the actual speed of the motor.
  int32_t EMD_ACT_MotorSpeed;               //      Bits=16.  [ -32768, 32767  ]  Unit:'rpm'   Offset= -32768   

  // Indicates the actual mechanic power (Calculated by Pmech = w * T)
  int32_t EMD_ACT_MechanicPower;            //      Bits=16.  [ -327680, 327670 ]  Unit:'W'     Offset= -327680   Factor= 10    

  // Indicates the actual DC link power (calculated power consumption of the inverter).
  int32_t EMD_ACT_DcLinkPower;              //      Bits=16.  [ -327680, 327670 ]  Unit:'W'     Offset= -327680   Factor= 10    

  // Message counter of TxPDO3.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_TxPDO3;                //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Validity of actual mechanic power.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_MechanicPower_VAL;        //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Validity of actual motor speed.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_MotorSpeed_VAL;           //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Validity for actual DC link power.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_DcLinkPower_VAL;          //      Bits=02.  [ 0     , 3      ]  Unit:''     
} EMD_TxPDO_3_t;

// def @EMD_RxPDO_3 CAN Message (1146)
#define EMD_RxPDO_3_IDE (0U)
#define EMD_RxPDO_3_DLC (6U)
#define EMD_RxPDO_3_CANID (0x47AU)
#define EMD_RxPDO_3_CYC (10U)
// -- Message must be sent in any case, because it is used for general inverter control.
// signal: @EMD_CMD_TorqueRefLim
#define EMD_RxPDO_3_EMD_CMD_TorqueRefLim_CovFactor (0.02)
// conversion value to CAN signal
#define EMD_RxPDO_3_EMD_CMD_TorqueRefLim_toS(x) ((int16_t)((x) / 0.02 + 5000))
// conversion value from CAN signal
#define EMD_RxPDO_3_EMD_CMD_TorqueRefLim_fromS(x) ((x) * 0.02)

// signal: @EMD_CMD_SpeedRefLim
#define EMD_RxPDO_3_EMD_CMD_SpeedRefLim_CovFactor (1)
// conversion value to CAN signal
#define EMD_RxPDO_3_EMD_CMD_SpeedRefLim_toS(x) ((int32_t)((x) + 32768))
// conversion value from CAN signal
#define EMD_RxPDO_3_EMD_CMD_SpeedRefLim_fromS(x) ((x))

typedef struct
{

  // Command to request the motor torque in torque control mode.   OR  Command to request the motor torque limit in speed control mode if limitation mode is symmetric.  
  int16_t EMD_CMD_TorqueRefLim;             //      Bits=14.  [ -100  , 100    ]  Unit:'%'     Offset= -100      Factor= 0.02  

  // Validity of requested torque resp. torque limit.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_TorqueRefLim_VAL;         //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Command to request the motor speed in speed control mode.   OR  Command to request the motor speed limit in torque control mode if limitation mode is symmetric.  
  int32_t EMD_CMD_SpeedRefLim;              //      Bits=16.  [ -32768, 32767  ]  Unit:'rpm'   Offset= -32768   

  // Command to set the desired control mode. E.g. to enable and disable the inverter.
  // 0 - "Disabled" 
  // 1 - "Torque control mode" 
  // 2 - "Speed control mode" 
  // 3 - "reserved" 
  // 4 - "Brake chopper" 
  // 5 - "Position sensor calibration" 
  // 6 - "unused" 
  // 7 - "unused" 
  // 8 - "Test Id/Iq" 
  // 9 - "Test Closed Loop" 
  // 10 - "reserved" 
  // 11 - "reserved" 
  // 12 - "reserved" 
  // 13 - "unused" 
  // 14 - "unused" 
  // 15 - "unused" 

  uint8_t EMD_CMD_ControlMode;              //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Message counter of RxPDO3.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_RxPDO3;                //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Validity of requested speed resp. speed limit.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_SpeedRefLim_VAL;          //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Command to clear errors.   Errors are cleared if an positive edge (transition from 0 to 1)  is detected in this signal and EMD_CMD_ControlMode is set to 0.
  uint8_t EMD_CMD_ClearErrors;              //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Command to request a restart (soft reset of micro controller). The restart is only initiated if a positive edge is detected and EMD_CMD_ControlMode is 0.
  uint8_t EMD_CMD_RestartRequest;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Command to activate the inverters internal active discharge feature.
  // 0 - "Active discharge disabled" 
  // 1 - "Active discharge enabled" 

  uint8_t EMD_CMD_ActiveDischarge;          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Command to request the limitation mode. If symmetric limits are used, only RxPDO3 is required.   For asymmetric limitation RxPDO4 with torque limits must be sent in speed mode.   RxPDO5 with speed limits must be sent in torque mode.
  // 0 - "Symmetric speed or torque limit" 
  // 1 - "Asymmetric speed or torque limit" 

  uint8_t EMD_CMD_LimitationMode;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Command to control the digital output 2 (MP_DO_C2).
  // 0 - "low" 
  // 1 - "high" 

  uint8_t EMD_CMD_DigitalOutput2;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  // Command to control the digital output 1 (MP_DO_C1).
  // 0 - "low" 
  // 1 - "high" 

  uint8_t EMD_CMD_DigitalOutput1;           //      Bits=01.  [ 0     , 1      ]  Unit:''     
} EMD_RxPDO_3_t;

// def @EMD_TxPDO_4 CAN Message (1274)
#define EMD_TxPDO_4_IDE (0U)
#define EMD_TxPDO_4_DLC (6U)
#define EMD_TxPDO_4_CANID (0x4FAU)
#define EMD_TxPDO_4_CYC (100U)
// -- Message with actual values. The transmission type and transmission cycle can be configured.
// signal: @EMD_ACT_PhaseCurrent
#define EMD_TxPDO_4_EMD_ACT_PhaseCurrent_CovFactor (0.1)
// conversion value to CAN signal
#define EMD_TxPDO_4_EMD_ACT_PhaseCurrent_toS(x) ((uint16_t)((x) / 0.1))
// conversion value from CAN signal
#define EMD_TxPDO_4_EMD_ACT_PhaseCurrent_fromS(x) ((x) * 0.1)

// signal: @EMD_ACT_DcLinkVoltage
#define EMD_TxPDO_4_EMD_ACT_DcLinkVoltage_CovFactor (0.1)
// conversion value to CAN signal
#define EMD_TxPDO_4_EMD_ACT_DcLinkVoltage_toS(x) ((uint16_t)((x) / 0.1))
// conversion value from CAN signal
#define EMD_TxPDO_4_EMD_ACT_DcLinkVoltage_fromS(x) ((x) * 0.1)

typedef struct
{

  // Indicates the actual phase current (Idq abs).
  uint16_t EMD_ACT_PhaseCurrent;            //      Bits=14.  [ 0     , 1638.3 ]  Unit:'Apeak' Factor= 0.1   

  // Validity of actual phase current.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_PhaseCurrent_VAL;         //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Indicates the actual DC link voltage.
  uint16_t EMD_ACT_DcLinkVoltage;           //      Bits=14.  [ 0     , 1638.3 ]  Unit:'V'     Factor= 0.1   

  // Valitidity of actual DC link voltage.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_ACT_DcLinkVoltage_VAL;        //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Indicates the active control mode.
  // 0 - "Disabled" 
  // 1 - "Torque control mode" 
  // 2 - "Speed control mode" 
  // 3 - "reserved" 
  // 4 - "Brake chopper" 
  // 5 - "Position sensor calibration" 
  // 6 - "unused" 
  // 7 - "unused" 
  // 8 - "Test Id/Iq" 
  // 9 - "Test Closed Loop" 
  // 10 - "reserved" 
  // 11 - "reserved" 
  // 12 - "reserved" 
  // 13 - "unused" 
  // 14 - "unused" 
  // 15 - "unused" 

  uint8_t EMD_ACT_ControlMode;              //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Message counter of TxPDO4.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_TxPDO4;                //      Bits=04.  [ 0     , 15     ]  Unit:''     

  // Indicates the actual warning state. The value is bit coded and multiple warnings may be active.
  // 32 - "Angle offset not calibrated" 
  // 1 - "Cutback limiter active" 
  // 2 - "Reference limits corrected" 
  // 4 - "Reserved" 
  // 8 - "Speed higher as the ref. limits" 
  // 16 - "Iq reduced to zero" 

  uint8_t EMD_ACT_SystemWarning;            //      Bits=08.  [ 0     , 255    ]  Unit:''     
} EMD_TxPDO_4_t;

// def @EMD_RxPDO_4 CAN Message (1402)
#define EMD_RxPDO_4_IDE (0U)
#define EMD_RxPDO_4_DLC (5U)
#define EMD_RxPDO_4_CANID (0x57AU)
#define EMD_RxPDO_4_CYC (10U)
// -- Message only required is asymetric limits are used.  If limitation mode is symetric, this message is not needed (unless message counter and message timeout are activated).
// signal: @EMD_CMD_TorqueLimitHigh
#define EMD_RxPDO_4_EMD_CMD_TorqueLimitHigh_CovFactor (0.02)
// conversion value to CAN signal
#define EMD_RxPDO_4_EMD_CMD_TorqueLimitHigh_toS(x) ((int16_t)((x) / 0.02 + 5000))
// conversion value from CAN signal
#define EMD_RxPDO_4_EMD_CMD_TorqueLimitHigh_fromS(x) ((x) * 0.02)

// signal: @EMD_CMD_TorqueLimitLow
#define EMD_RxPDO_4_EMD_CMD_TorqueLimitLow_CovFactor (0.02)
// conversion value to CAN signal
#define EMD_RxPDO_4_EMD_CMD_TorqueLimitLow_toS(x) ((int16_t)((x) / 0.02 + 5000))
// conversion value from CAN signal
#define EMD_RxPDO_4_EMD_CMD_TorqueLimitLow_fromS(x) ((x) * 0.02)

typedef struct
{

  // Command to request the high torque limit in speed control mode when asymetric limitation mode is active.
  int16_t EMD_CMD_TorqueLimitHigh;          //      Bits=14.  [ -100  , 100    ]  Unit:'%'     Offset= -100      Factor= 0.02  

  // Validity of requested torque limit low.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_TorqueLimitLow_VAL;       //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Command to request the low torque limit in speed control mode when asymetric limitation mode is active.
  int16_t EMD_CMD_TorqueLimitLow;           //      Bits=14.  [ -100  , 100    ]  Unit:'%'     Offset= -100      Factor= 0.02  

  // Validity of requested torque limit high.
  // 3 - "Not available: invalid signal" 
  // 2 - "Error indicator: invalid signal" 
  // 1 - "Inaccurate signal" 
  // 0 - "Valid signal" 

  uint8_t EMD_CMD_TorqueLimitHigh_VAL;      //      Bits=02.  [ 0     , 3      ]  Unit:''     

  // Message counter of RxPDO4.   If the message counter supervision feature is active, the counter must be incremented for every sent message.
  uint8_t EMD_MSGCNT_RxPDO4;                //      Bits=04.  [ 0     , 15     ]  Unit:''     
} EMD_RxPDO_4_t;

// def @EMD_TxSDO CAN Message (1530)
#define EMD_TxSDO_IDE (0U)
#define EMD_TxSDO_DLC (8U)
#define EMD_TxSDO_CANID (0x5FAU)
typedef struct
{

  // CANopen SDO response command.
  // 79 - "Send data to client, 1 bytes" 
  // 75 - "Send data to client, 2 bytes" 
  // 67 - "Send data to client, 4 bytes" 

  uint8_t EMD_SDO_RespCmd;                  //      Bits=08.  [ 0     , 0      ]  Unit:''     

  // CANopen SDO response object ID. 
  uint16_t EMD_SDO_RespObjectId;            //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // CANopen SDO response sub index.
  int8_t EMD_SDO_RespSubindex;              //  [-] Bits=08.  [ 0     , 0      ]  Unit:''     

  // CANopen SDO response data
  uint32_t EMD_SDO_RespData;                //      Bits=32.  [ 0     , 0      ]  Unit:''     
} EMD_TxSDO_t;

// def @EMD_RxSDO CAN Message (1658)
#define EMD_RxSDO_IDE (0U)
#define EMD_RxSDO_DLC (8U)
#define EMD_RxSDO_CANID (0x67AU)
typedef struct
{

  // CANopen SDO requested command.
  // 64 - "Request data from the server" 
  // 47 - "Download request, max. 1 bytes" 
  // 43 - "Download request, max. 2 bytes" 
  // 35 - "Download request, max. 4 bytes" 

  uint8_t EMD_SDO_ReqCmd;                   //      Bits=08.  [ 0     , 0      ]  Unit:''     

  // CANopen SDO requested object ID.
  uint16_t EMD_SDO_ReqObjectId;             //      Bits=16.  [ 0     , 0      ]  Unit:''     

  // CANopen SDO requested sub index.
  uint8_t EMD_SDO_ReqSubindex;              //      Bits=08.  [ 0     , 0      ]  Unit:''     

  // CANopen SDO requested data.
  uint32_t EMD_SDO_ReqData;                 //      Bits=32.  [ 0     , 0      ]  Unit:''     
} EMD_RxSDO_t;

// def @ECU_NMT_heart_beat CAN Message (1793)
#define ECU_NMT_heart_beat_IDE (0U)
#define ECU_NMT_heart_beat_DLC (1U)
#define ECU_NMT_heart_beat_CANID (0x701U)
#define ECU_NMT_heart_beat_CYC (500U)
// -- ECU must request message from BRC through an RTR
typedef struct
{

  // Unused signal. Just used to allow mapping to receive nodes.
  uint8_t ECU_NMT_HeartBeatDummy;           //      Bits=08.  [ 0     , 0      ]  Unit:''     
} ECU_NMT_heart_beat_t;

// def @ECU_EMD_NMT_node_guarding CAN Message (1914)
#define ECU_EMD_NMT_node_guarding_IDE (0U)
#define ECU_EMD_NMT_node_guarding_DLC (1U)
#define ECU_EMD_NMT_node_guarding_CANID (0x77AU)
#define ECU_EMD_NMT_node_guarding_CYC (500U)
// -- ECU must request message from EMD through an RTR
typedef struct
{

  // CANopen node guard state.
  // 127 - "Pre-operational" 
  // 5 - "Operational" 
  // 4 - "Stopped" 
  // 1 - "Initialisation" 
  // 0 - "Boot-up" 

  uint8_t EMD_NMT_NodeGuardState;           //      Bits=07.  [ 0     , 127    ]  Unit:''     

  // Toggle this bit at each transmission of an node guarding response.
  uint8_t EMD_NMT_NodeGuardToggleBit;       //      Bits=01.  [ 0     , 1      ]  Unit:''     
} ECU_EMD_NMT_node_guarding_t;

uint32_t Unpack_ECU_NMT_command__DO_QUASAR_CANopen(ECU_NMT_command_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_ECU_NMT_command__DO_QUASAR_CANopen(const ECU_NMT_command_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_ECU_SYNC__DO_QUASAR_CANopen(ECU_SYNC_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_ECU_SYNC__DO_QUASAR_CANopen(const ECU_SYNC_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_TxPDO_5__DO_QUASAR_CANopen(EMD_TxPDO_5_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_TxPDO_5__DO_QUASAR_CANopen(const EMD_TxPDO_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_TxPDO_1__DO_QUASAR_CANopen(EMD_TxPDO_1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_TxPDO_1__DO_QUASAR_CANopen(const EMD_TxPDO_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_RxPDO_5__DO_QUASAR_CANopen(EMD_RxPDO_5_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_RxPDO_5__DO_QUASAR_CANopen(const EMD_RxPDO_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_RxPDO_1__DO_QUASAR_CANopen(EMD_RxPDO_1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_RxPDO_1__DO_QUASAR_CANopen(const EMD_RxPDO_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_TxPDO_2__DO_QUASAR_CANopen(EMD_TxPDO_2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_TxPDO_2__DO_QUASAR_CANopen(const EMD_TxPDO_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_RxPDO_2__DO_QUASAR_CANopen(EMD_RxPDO_2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_RxPDO_2__DO_QUASAR_CANopen(const EMD_RxPDO_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_TxPDO_3__DO_QUASAR_CANopen(EMD_TxPDO_3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_TxPDO_3__DO_QUASAR_CANopen(const EMD_TxPDO_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_RxPDO_3__DO_QUASAR_CANopen(EMD_RxPDO_3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_RxPDO_3__DO_QUASAR_CANopen(const EMD_RxPDO_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_TxPDO_4__DO_QUASAR_CANopen(EMD_TxPDO_4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_TxPDO_4__DO_QUASAR_CANopen(const EMD_TxPDO_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_RxPDO_4__DO_QUASAR_CANopen(EMD_RxPDO_4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_RxPDO_4__DO_QUASAR_CANopen(const EMD_RxPDO_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_TxSDO__DO_QUASAR_CANopen(EMD_TxSDO_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_TxSDO__DO_QUASAR_CANopen(const EMD_TxSDO_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_EMD_RxSDO__DO_QUASAR_CANopen(EMD_RxSDO_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_EMD_RxSDO__DO_QUASAR_CANopen(const EMD_RxSDO_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_ECU_NMT_heart_beat__DO_QUASAR_CANopen(ECU_NMT_heart_beat_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_ECU_NMT_heart_beat__DO_QUASAR_CANopen(const ECU_NMT_heart_beat_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_ECU_EMD_NMT_node_guarding__DO_QUASAR_CANopen(ECU_EMD_NMT_node_guarding_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_ECU_EMD_NMT_node_guarding__DO_QUASAR_CANopen(const ECU_EMD_NMT_node_guarding_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);

#ifdef __cplusplus
}
#endif

