
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



// def @VCU_TPS_Limits CAN Message (772)
#define VCU_TPS_Limits_IDE (0U)
#define VCU_TPS_Limits_DLC (8U)
#define VCU_TPS_Limits_CANID (0x304U)
typedef struct
{

  uint16_t TPS_PrimaryMaxLimit;             //      Bits=16.  [ 0     , 65535  ]  Unit:''     

  uint16_t TPS_PrimaryMinLimit;             //      Bits=16.  [ 0     , 65535  ]  Unit:''     

  uint16_t TPS_SecondaryMaxLimit;           //      Bits=16.  [ 0     , 65535  ]  Unit:''     

  uint16_t TPS_SecondaryMinLimit;           //      Bits=16.  [ 0     , 65535  ]  Unit:''     
} VCU_TPS_Limits_t;

// def @VCU_TPS_CurrentValue CAN Message (773)
#define VCU_TPS_CurrentValue_IDE (0U)
#define VCU_TPS_CurrentValue_DLC (4U)
#define VCU_TPS_CurrentValue_CANID (0x305U)
typedef struct
{

  uint16_t TPS_PrimaryCurrentVal;           //      Bits=16.  [ 0     , 65535  ]  Unit:''     

  uint16_t TPS_SecondaryCurrentVal;         //      Bits=16.  [ 0     , 65535  ]  Unit:''     
} VCU_TPS_CurrentValue_t;

uint32_t Unpack_VCU_TPS_Limits_TPS(VCU_TPS_Limits_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_VCU_TPS_Limits_TPS(const VCU_TPS_Limits_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
uint32_t Unpack_VCU_TPS_CurrentValue_TPS(VCU_TPS_CurrentValue_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_VCU_TPS_CurrentValue_TPS(const VCU_TPS_CurrentValue_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);

#ifdef __cplusplus
}
#endif

