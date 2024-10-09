
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "tps.h"

// @dbccodeconf.h file should be placed in inc folder. If the user wants
// to allocate big DBC struct inside the driver - appropriate define (__DEF_xxxxx__)
// should be placed in this file
#include "dbccodeconf.h"

typedef struct
{
  VCU_TPS_Limits_t VCU_TPS_Limits;               // TX [Vehicle_Control_Unit].RX [].
  VCU_TPS_CurrentValue_t VCU_TPS_CurrentValue;   // TX [Vehicle_Control_Unit].RX [Vector__XXX ].
} TPS_rx_t;

// There is no any message detected with tx direction.

uint32_t TPS_Receive(TPS_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


// define @__DEF_TPS__ in the @dbccodeconf.h file for allocation in utility source code.
#ifdef __DEF_TPS__

extern TPS_rx_t TPS_rx;

#endif


#ifdef __cplusplus
}
#endif

