
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



// def @TS_ECU_ChargingStateTrigger CAN Message (698)
#define TS_ECU_ChargingStateTrigger_IDE (0U)
#define TS_ECU_ChargingStateTrigger_DLC (1U)
#define TS_ECU_ChargingStateTrigger_CANID (0x2BAU)
typedef struct
{

  uint8_t Orion_2_ChargePowerState;         //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t Orion_2_ChargeSafetyState;        //      Bits=01.  [ 0     , 1      ]  Unit:''     
} TS_ECU_ChargingStateTrigger_t;

// def @TS_ECU_SYNC_RX1 CAN Message (769)
#define TS_ECU_SYNC_RX1_IDE (0U)
#define TS_ECU_SYNC_RX1_DLC (1U)
#define TS_ECU_SYNC_RX1_CANID (0x301U)
typedef struct
{

  uint8_t TS_ECU_SYNC_COUNTER;              //      Bits=08.  [ 0     , 255    ]  Unit:''     
} TS_ECU_SYNC_RX1_t;

// def @TS_ECU_SYNC_RX2 CAN Message (770)
#define TS_ECU_SYNC_RX2_IDE (0U)
#define TS_ECU_SYNC_RX2_DLC (1U)
#define TS_ECU_SYNC_RX2_CANID (0x302U)
typedef struct
{

  uint8_t TS_ECU_SYNC_COUNTER;              //      Bits=08.  [ 0     , 255    ]  Unit:''     
} TS_ECU_SYNC_RX2_t;

// def @TS_ECU1_TX1 CAN Message (785)
#define TS_ECU1_TX1_IDE (0U)
#define TS_ECU1_TX1_DLC (5U)
#define TS_ECU1_TX1_CANID (0x311U)
// signal: @TS_ECU_MaxSegmentTemperature
#define TS_ECU1_TX1_TS_ECU_MaxSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX1_TS_ECU_MaxSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX1_TS_ECU_MaxSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_MinSegmentTemperature
#define TS_ECU1_TX1_TS_ECU_MinSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX1_TS_ECU_MinSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX1_TS_ECU_MinSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_AverageSegmentTemp
#define TS_ECU1_TX1_TS_ECU_AverageSegmentTemp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX1_TS_ECU_AverageSegmentTemp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX1_TS_ECU_AverageSegmentTemp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_MaxSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_MinSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:''      Offset= -40      

  int16_t TS_ECU_AverageSegmentTemp;           //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  uint8_t TS_ECU_MaxTemperatureCellCount;      //      Bits=08.  [ 0     , 63     ]  Unit:''     

  uint8_t TS_ECU_FaultInState;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_FaultOutState;                //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_TempThresholdFault;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_OpenCircuitFault;             //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t FAN_ECU_ShortToGroundFault;          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_CurrentState;                 //      Bits=03.  [ 0     , 1      ]  Unit:''     
} TS_ECU1_TX1_t;

// def @TS_ECU1_TX2 CAN Message (786)
#define TS_ECU1_TX2_IDE (0U)
#define TS_ECU1_TX2_DLC (8U)
#define TS_ECU1_TX2_CANID (0x312U)
// signal: @TS_ECU_Segment_Module1_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module1_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module1_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module1_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module2_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module2_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module2_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module2_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module3_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module3_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module3_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module3_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module4_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module4_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module4_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module4_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module5_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module5_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module5_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module5_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module6_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module6_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module6_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module6_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module7_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module7_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module7_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module7_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module8_Temp
#define TS_ECU1_TX2_TS_ECU_Segment_Module8_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module8_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX2_TS_ECU_Segment_Module8_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module1_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module2_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module3_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module4_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module5_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module6_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module7_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module8_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU1_TX2_t;

// def @TS_ECU1_TX3 CAN Message (787)
#define TS_ECU1_TX3_IDE (0U)
#define TS_ECU1_TX3_DLC (8U)
#define TS_ECU1_TX3_CANID (0x313U)
// signal: @TS_ECU_Segment_Module9_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module9_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module9_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module9_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module10_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module10_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module10_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module10_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module12_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module12_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module12_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module12_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module13_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module13_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module13_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module13_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module14_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module14_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module14_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module14_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module15_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module15_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module15_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module15_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module16_Temp
#define TS_ECU1_TX3_TS_ECU_Segment_Module16_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module16_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX3_TS_ECU_Segment_Module16_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module9_Temp;       //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module10_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  uint8_t TS_ECU_Segment_Module11_Temp;      //      Bits=08.  [ 0     , 255    ]  Unit:'?C'   

  int16_t TS_ECU_Segment_Module12_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module13_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module14_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module15_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module16_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU1_TX3_t;

// def @TS_ECU1_TX4 CAN Message (788)
#define TS_ECU1_TX4_IDE (0U)
#define TS_ECU1_TX4_DLC (8U)
#define TS_ECU1_TX4_CANID (0x314U)
// signal: @TS_ECU_Segment_Module17_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module17_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module17_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module17_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module18_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module18_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module18_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module18_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module19_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module19_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module19_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module19_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module20_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module20_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module20_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module20_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module21_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module21_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module21_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module21_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module22_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module22_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module22_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module22_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module23_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module23_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module23_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module23_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module24_Temp
#define TS_ECU1_TX4_TS_ECU_Segment_Module24_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module24_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU1_TX4_TS_ECU_Segment_Module24_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module17_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module18_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module19_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module20_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module21_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module22_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module23_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module24_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      
} TS_ECU1_TX4_t;

// def @TS_ECU2_TX1 CAN Message (801)
#define TS_ECU2_TX1_IDE (0U)
#define TS_ECU2_TX1_DLC (5U)
#define TS_ECU2_TX1_CANID (0x321U)
// signal: @TS_ECU_MaxSegmentTemperature
#define TS_ECU2_TX1_TS_ECU_MaxSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX1_TS_ECU_MaxSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX1_TS_ECU_MaxSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_MinSegmentTemperature
#define TS_ECU2_TX1_TS_ECU_MinSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX1_TS_ECU_MinSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX1_TS_ECU_MinSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_AverageSegmentTemp
#define TS_ECU2_TX1_TS_ECU_AverageSegmentTemp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX1_TS_ECU_AverageSegmentTemp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX1_TS_ECU_AverageSegmentTemp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_MaxSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_MinSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:''      Offset= -40      

  int16_t TS_ECU_AverageSegmentTemp;           //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  uint8_t TS_ECU_MaxTemperatureCellCount;      //      Bits=08.  [ 0     , 63     ]  Unit:''     

  uint8_t TS_ECU_FaultInState;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_FaultOutState;                //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_TempThresholdFault;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_OpenCircuitFault;             //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t FAN_ECU_ShortToGroundFault;          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_CurrentState;                 //      Bits=03.  [ 0     , 1      ]  Unit:''     
} TS_ECU2_TX1_t;

// def @TS_ECU2_TX2 CAN Message (802)
#define TS_ECU2_TX2_IDE (0U)
#define TS_ECU2_TX2_DLC (8U)
#define TS_ECU2_TX2_CANID (0x322U)
// signal: @TS_ECU_Segment_Module1_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module1_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module1_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module1_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module2_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module2_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module2_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module2_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module3_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module3_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module3_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module3_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module4_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module4_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module4_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module4_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module5_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module5_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module5_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module5_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module6_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module6_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module6_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module6_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module7_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module7_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module7_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module7_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module8_Temp
#define TS_ECU2_TX2_TS_ECU_Segment_Module8_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module8_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX2_TS_ECU_Segment_Module8_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module1_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module2_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module3_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module4_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module5_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module6_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module7_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module8_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU2_TX2_t;

// def @TS_ECU2_TX3 CAN Message (803)
#define TS_ECU2_TX3_IDE (0U)
#define TS_ECU2_TX3_DLC (8U)
#define TS_ECU2_TX3_CANID (0x323U)
// signal: @TS_ECU_Segment_Module9_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module9_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module9_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module9_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module10_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module10_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module10_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module10_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module12_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module12_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module12_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module12_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module13_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module13_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module13_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module13_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module14_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module14_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module14_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module14_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module15_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module15_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module15_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module15_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module16_Temp
#define TS_ECU2_TX3_TS_ECU_Segment_Module16_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module16_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX3_TS_ECU_Segment_Module16_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module9_Temp;       //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module10_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  uint8_t TS_ECU_Segment_Module11_Temp;      //      Bits=08.  [ 0     , 255    ]  Unit:'?C'   

  int16_t TS_ECU_Segment_Module12_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module13_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module14_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module15_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module16_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU2_TX3_t;

// def @TS_ECU2_TX4 CAN Message (804)
#define TS_ECU2_TX4_IDE (0U)
#define TS_ECU2_TX4_DLC (8U)
#define TS_ECU2_TX4_CANID (0x324U)
// signal: @TS_ECU_Segment_Module17_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module17_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module17_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module17_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module18_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module18_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module18_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module18_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module19_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module19_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module19_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module19_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module20_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module20_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module20_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module20_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module21_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module21_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module21_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module21_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module22_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module22_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module22_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module22_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module23_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module23_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module23_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module23_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module24_Temp
#define TS_ECU2_TX4_TS_ECU_Segment_Module24_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module24_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU2_TX4_TS_ECU_Segment_Module24_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module17_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module18_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module19_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module20_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module21_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module22_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module23_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module24_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      
} TS_ECU2_TX4_t;

// def @TS_ECU3_TX1 CAN Message (817)
#define TS_ECU3_TX1_IDE (0U)
#define TS_ECU3_TX1_DLC (5U)
#define TS_ECU3_TX1_CANID (0x331U)
// signal: @TS_ECU_MaxSegmentTemperature
#define TS_ECU3_TX1_TS_ECU_MaxSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX1_TS_ECU_MaxSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX1_TS_ECU_MaxSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_MinSegmentTemperature
#define TS_ECU3_TX1_TS_ECU_MinSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX1_TS_ECU_MinSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX1_TS_ECU_MinSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_AverageSegmentTemp
#define TS_ECU3_TX1_TS_ECU_AverageSegmentTemp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX1_TS_ECU_AverageSegmentTemp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX1_TS_ECU_AverageSegmentTemp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_MaxSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_MinSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:''      Offset= -40      

  int16_t TS_ECU_AverageSegmentTemp;           //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  uint8_t TS_ECU_MaxTemperatureCellCount;      //      Bits=08.  [ 0     , 63     ]  Unit:''     

  uint8_t TS_ECU_FaultInState;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_FaultOutState;                //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_TempThresholdFault;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_OpenCircuitFault;             //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t FAN_ECU_ShortToGroundFault;          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_CurrentState;                 //      Bits=03.  [ 0     , 1      ]  Unit:''     
} TS_ECU3_TX1_t;

// def @TS_ECU3_TX2 CAN Message (818)
#define TS_ECU3_TX2_IDE (0U)
#define TS_ECU3_TX2_DLC (8U)
#define TS_ECU3_TX2_CANID (0x332U)
// signal: @TS_ECU_Segment_Module1_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module1_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module1_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module1_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module2_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module2_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module2_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module2_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module3_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module3_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module3_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module3_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module4_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module4_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module4_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module4_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module5_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module5_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module5_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module5_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module6_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module6_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module6_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module6_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module7_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module7_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module7_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module7_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module8_Temp
#define TS_ECU3_TX2_TS_ECU_Segment_Module8_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module8_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX2_TS_ECU_Segment_Module8_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module1_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module2_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module3_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module4_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module5_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module6_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module7_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module8_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU3_TX2_t;

// def @TS_ECU3_TX3 CAN Message (819)
#define TS_ECU3_TX3_IDE (0U)
#define TS_ECU3_TX3_DLC (8U)
#define TS_ECU3_TX3_CANID (0x333U)
// signal: @TS_ECU_Segment_Module9_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module9_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module9_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module9_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module10_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module10_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module10_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module10_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module12_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module12_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module12_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module12_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module13_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module13_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module13_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module13_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module14_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module14_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module14_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module14_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module15_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module15_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module15_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module15_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module16_Temp
#define TS_ECU3_TX3_TS_ECU_Segment_Module16_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module16_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX3_TS_ECU_Segment_Module16_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module9_Temp;       //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module10_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  uint8_t TS_ECU_Segment_Module11_Temp;      //      Bits=08.  [ 0     , 255    ]  Unit:'?C'   

  int16_t TS_ECU_Segment_Module12_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module13_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module14_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module15_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module16_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU3_TX3_t;

// def @TS_ECU3_TX4 CAN Message (820)
#define TS_ECU3_TX4_IDE (0U)
#define TS_ECU3_TX4_DLC (8U)
#define TS_ECU3_TX4_CANID (0x334U)
// signal: @TS_ECU_Segment_Module17_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module17_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module17_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module17_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module18_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module18_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module18_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module18_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module19_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module19_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module19_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module19_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module20_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module20_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module20_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module20_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module21_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module21_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module21_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module21_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module22_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module22_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module22_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module22_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module23_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module23_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module23_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module23_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module24_Temp
#define TS_ECU3_TX4_TS_ECU_Segment_Module24_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module24_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU3_TX4_TS_ECU_Segment_Module24_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module17_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module18_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module19_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module20_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module21_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module22_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module23_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module24_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      
} TS_ECU3_TX4_t;

// def @TS_ECU4_TX1 CAN Message (833)
#define TS_ECU4_TX1_IDE (0U)
#define TS_ECU4_TX1_DLC (5U)
#define TS_ECU4_TX1_CANID (0x341U)
// signal: @TS_ECU_MaxSegmentTemperature
#define TS_ECU4_TX1_TS_ECU_MaxSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX1_TS_ECU_MaxSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX1_TS_ECU_MaxSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_MinSegmentTemperature
#define TS_ECU4_TX1_TS_ECU_MinSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX1_TS_ECU_MinSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX1_TS_ECU_MinSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_AverageSegmentTemp
#define TS_ECU4_TX1_TS_ECU_AverageSegmentTemp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX1_TS_ECU_AverageSegmentTemp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX1_TS_ECU_AverageSegmentTemp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_MaxSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_MinSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:''      Offset= -40      

  int16_t TS_ECU_AverageSegmentTemp;           //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  uint8_t TS_ECU_MaxTemperatureCellCount;      //      Bits=08.  [ 0     , 63     ]  Unit:''     

  uint8_t TS_ECU_FaultInState;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_FaultOutState;                //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_TempThresholdFault;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_OpenCircuitFault;             //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t FAN_ECU_ShortToGroundFault;          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_CurrentState;                 //      Bits=03.  [ 0     , 1      ]  Unit:''     
} TS_ECU4_TX1_t;

// def @TS_ECU4_TX2 CAN Message (834)
#define TS_ECU4_TX2_IDE (0U)
#define TS_ECU4_TX2_DLC (8U)
#define TS_ECU4_TX2_CANID (0x342U)
// signal: @TS_ECU_Segment_Module1_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module1_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module1_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module1_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module2_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module2_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module2_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module2_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module3_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module3_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module3_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module3_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module4_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module4_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module4_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module4_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module5_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module5_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module5_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module5_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module6_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module6_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module6_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module6_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module7_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module7_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module7_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module7_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module8_Temp
#define TS_ECU4_TX2_TS_ECU_Segment_Module8_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module8_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX2_TS_ECU_Segment_Module8_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module1_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module2_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module3_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module4_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module5_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module6_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module7_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module8_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU4_TX2_t;

// def @TS_ECU4_TX3 CAN Message (835)
#define TS_ECU4_TX3_IDE (0U)
#define TS_ECU4_TX3_DLC (8U)
#define TS_ECU4_TX3_CANID (0x343U)
// signal: @TS_ECU_Segment_Module9_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module9_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module9_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module9_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module10_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module10_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module10_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module10_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module12_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module12_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module12_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module12_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module13_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module13_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module13_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module13_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module14_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module14_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module14_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module14_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module15_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module15_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module15_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module15_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module16_Temp
#define TS_ECU4_TX3_TS_ECU_Segment_Module16_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module16_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX3_TS_ECU_Segment_Module16_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module9_Temp;       //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module10_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  uint8_t TS_ECU_Segment_Module11_Temp;      //      Bits=08.  [ 0     , 255    ]  Unit:'?C'   

  int16_t TS_ECU_Segment_Module12_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module13_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module14_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module15_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module16_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU4_TX3_t;

// def @TS_ECU4_TX4 CAN Message (836)
#define TS_ECU4_TX4_IDE (0U)
#define TS_ECU4_TX4_DLC (8U)
#define TS_ECU4_TX4_CANID (0x344U)
// signal: @TS_ECU_Segment_Module17_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module17_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module17_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module17_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module18_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module18_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module18_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module18_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module19_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module19_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module19_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module19_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module20_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module20_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module20_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module20_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module21_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module21_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module21_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module21_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module22_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module22_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module22_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module22_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module23_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module23_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module23_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module23_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module24_Temp
#define TS_ECU4_TX4_TS_ECU_Segment_Module24_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module24_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU4_TX4_TS_ECU_Segment_Module24_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module17_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module18_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module19_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module20_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module21_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module22_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module23_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module24_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      
} TS_ECU4_TX4_t;

// def @TS_ECU5_TX1 CAN Message (849)
#define TS_ECU5_TX1_IDE (0U)
#define TS_ECU5_TX1_DLC (5U)
#define TS_ECU5_TX1_CANID (0x351U)
// signal: @TS_ECU_MaxSegmentTemperature
#define TS_ECU5_TX1_TS_ECU_MaxSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX1_TS_ECU_MaxSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX1_TS_ECU_MaxSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_MinSegmentTemperature
#define TS_ECU5_TX1_TS_ECU_MinSegmentTemperature_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX1_TS_ECU_MinSegmentTemperature_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX1_TS_ECU_MinSegmentTemperature_fromS(x) ((x))

// signal: @TS_ECU_AverageSegmentTemp
#define TS_ECU5_TX1_TS_ECU_AverageSegmentTemp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX1_TS_ECU_AverageSegmentTemp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX1_TS_ECU_AverageSegmentTemp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_MaxSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_MinSegmentTemperature;        //      Bits=08.  [ -40   , 215    ]  Unit:''      Offset= -40      

  int16_t TS_ECU_AverageSegmentTemp;           //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  uint8_t TS_ECU_MaxTemperatureCellCount;      //      Bits=08.  [ 0     , 63     ]  Unit:''     

  uint8_t TS_ECU_FaultInState;                 //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_FaultOutState;                //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_TempThresholdFault;           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_OpenCircuitFault;             //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t FAN_ECU_ShortToGroundFault;          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t TS_ECU_CurrentState;                 //      Bits=03.  [ 0     , 1      ]  Unit:''     
} TS_ECU5_TX1_t;

// def @TS_ECU5_TX2 CAN Message (850)
#define TS_ECU5_TX2_IDE (0U)
#define TS_ECU5_TX2_DLC (8U)
#define TS_ECU5_TX2_CANID (0x352U)
// signal: @TS_ECU_Segment_Module1_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module1_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module1_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module1_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module2_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module2_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module2_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module2_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module3_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module3_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module3_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module3_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module4_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module4_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module4_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module4_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module5_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module5_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module5_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module5_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module6_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module6_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module6_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module6_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module7_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module7_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module7_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module7_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module8_Temp
#define TS_ECU5_TX2_TS_ECU_Segment_Module8_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module8_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX2_TS_ECU_Segment_Module8_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module1_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module2_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module3_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module4_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module5_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module6_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module7_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module8_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU5_TX2_t;

// def @TS_ECU5_TX3 CAN Message (851)
#define TS_ECU5_TX3_IDE (0U)
#define TS_ECU5_TX3_DLC (8U)
#define TS_ECU5_TX3_CANID (0x353U)
// signal: @TS_ECU_Segment_Module9_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module9_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module9_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module9_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module10_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module10_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module10_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module10_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module12_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module12_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module12_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module12_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module13_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module13_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module13_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module13_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module14_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module14_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module14_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module14_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module15_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module15_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module15_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module15_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module16_Temp
#define TS_ECU5_TX3_TS_ECU_Segment_Module16_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module16_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX3_TS_ECU_Segment_Module16_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module9_Temp;       //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module10_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  uint8_t TS_ECU_Segment_Module11_Temp;      //      Bits=08.  [ 0     , 255    ]  Unit:'?C'   

  int16_t TS_ECU_Segment_Module12_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module13_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module14_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module15_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      

  int16_t TS_ECU_Segment_Module16_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:'?C'    Offset= -40      
} TS_ECU5_TX3_t;

// def @TS_ECU5_TX4 CAN Message (852)
#define TS_ECU5_TX4_IDE (0U)
#define TS_ECU5_TX4_DLC (8U)
#define TS_ECU5_TX4_CANID (0x354U)
// signal: @TS_ECU_Segment_Module17_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module17_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module17_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module17_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module18_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module18_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module18_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module18_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module19_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module19_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module19_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module19_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module20_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module20_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module20_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module20_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module21_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module21_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module21_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module21_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module22_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module22_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module22_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module22_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module23_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module23_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module23_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module23_Temp_fromS(x) ((x))

// signal: @TS_ECU_Segment_Module24_Temp
#define TS_ECU5_TX4_TS_ECU_Segment_Module24_Temp_CovFactor (1)
// conversion value to CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module24_Temp_toS(x) ((int16_t)((x) + 40))
// conversion value from CAN signal
#define TS_ECU5_TX4_TS_ECU_Segment_Module24_Temp_fromS(x) ((x))

typedef struct
{

  int16_t TS_ECU_Segment_Module17_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module18_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module19_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module20_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module21_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module22_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module23_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      

  int16_t TS_ECU_Segment_Module24_Temp;      //      Bits=08.  [ -40   , 215    ]  Unit:' ?C'   Offset= -40      
} TS_ECU5_TX4_t;

uint32_t Unpack_TS_ECU_ChargingStateTrigger_Temp(TS_ECU_ChargingStateTrigger_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU_ChargingStateTrigger_Temp(const TS_ECU_ChargingStateTrigger_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU_SYNC_RX1_Temp(TS_ECU_SYNC_RX1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU_SYNC_RX1_Temp(const TS_ECU_SYNC_RX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU_SYNC_RX2_Temp(TS_ECU_SYNC_RX2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU_SYNC_RX2_Temp(const TS_ECU_SYNC_RX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU1_TX1_Temp(TS_ECU1_TX1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU1_TX1_Temp(const TS_ECU1_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU1_TX2_Temp(TS_ECU1_TX2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU1_TX2_Temp(const TS_ECU1_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU1_TX3_Temp(TS_ECU1_TX3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU1_TX3_Temp(const TS_ECU1_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU1_TX4_Temp(TS_ECU1_TX4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU1_TX4_Temp(const TS_ECU1_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU2_TX1_Temp(TS_ECU2_TX1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU2_TX1_Temp(const TS_ECU2_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU2_TX2_Temp(TS_ECU2_TX2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU2_TX2_Temp(const TS_ECU2_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU2_TX3_Temp(TS_ECU2_TX3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU2_TX3_Temp(const TS_ECU2_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU2_TX4_Temp(TS_ECU2_TX4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU2_TX4_Temp(const TS_ECU2_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU3_TX1_Temp(TS_ECU3_TX1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU3_TX1_Temp(const TS_ECU3_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU3_TX2_Temp(TS_ECU3_TX2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU3_TX2_Temp(const TS_ECU3_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU3_TX3_Temp(TS_ECU3_TX3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU3_TX3_Temp(const TS_ECU3_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU3_TX4_Temp(TS_ECU3_TX4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU3_TX4_Temp(const TS_ECU3_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU4_TX1_Temp(TS_ECU4_TX1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU4_TX1_Temp(const TS_ECU4_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU4_TX2_Temp(TS_ECU4_TX2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU4_TX2_Temp(const TS_ECU4_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU4_TX3_Temp(TS_ECU4_TX3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU4_TX3_Temp(const TS_ECU4_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU4_TX4_Temp(TS_ECU4_TX4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU4_TX4_Temp(const TS_ECU4_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU5_TX1_Temp(TS_ECU5_TX1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU5_TX1_Temp(const TS_ECU5_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU5_TX2_Temp(TS_ECU5_TX2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU5_TX2_Temp(const TS_ECU5_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU5_TX3_Temp(TS_ECU5_TX3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU5_TX3_Temp(const TS_ECU5_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_TS_ECU5_TX4_Temp(TS_ECU5_TX4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_TS_ECU5_TX4_Temp(const TS_ECU5_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);

#ifdef __cplusplus
}
#endif

