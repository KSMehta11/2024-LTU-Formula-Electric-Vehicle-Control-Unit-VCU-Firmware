
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "temp.h"

// @dbccodeconf.h file should be placed in inc folder. If the user wants
// to allocate big DBC struct inside the driver - appropriate define (__DEF_xxxxx__)
// should be placed in this file
#include "dbccodeconf.h"

typedef struct
{
  TS_ECU_ChargingStateTrigger_t TS_ECU_ChargingStateTrigger;   // TX [Orion_2_BMS].RX [TS_ECU1 TS_ECU2 TS_ECU3 TS_ECU4 TS_ECU5 ].
  TS_ECU_SYNC_RX1_t TS_ECU_SYNC_RX1;                           // TX [TS_Fan_ECU].RX [TS_ECU1 TS_ECU2 TS_ECU3 TS_ECU4 TS_ECU5 ].
  TS_ECU_SYNC_RX2_t TS_ECU_SYNC_RX2;                           // TX [Client].  RX [TS_ECU1 TS_ECU2 TS_ECU3 TS_ECU4 TS_ECU5 ].
  TS_ECU1_TX1_t TS_ECU1_TX1;                                   // TX [TS_ECU1]. RX [].
  TS_ECU1_TX2_t TS_ECU1_TX2;                                   // TX [TS_ECU1]. RX [Client ].
  TS_ECU1_TX3_t TS_ECU1_TX3;                                   // TX [TS_ECU1]. RX [Client ].
  TS_ECU1_TX4_t TS_ECU1_TX4;                                   // TX [TS_ECU1]. RX [Client ].
  TS_ECU2_TX1_t TS_ECU2_TX1;                                   // TX [TS_ECU2]. RX [Client TS_Fan_ECU VCU Vector__XXX ].
  TS_ECU2_TX2_t TS_ECU2_TX2;                                   // TX [TS_ECU2]. RX [Client ].
  TS_ECU2_TX3_t TS_ECU2_TX3;                                   // TX [TS_ECU2]. RX [Client ].
  TS_ECU2_TX4_t TS_ECU2_TX4;                                   // TX [TS_ECU2]. RX [Client ].
  TS_ECU3_TX1_t TS_ECU3_TX1;                                   // TX [TS_ECU3]. RX [Client TS_Fan_ECU VCU Vector__XXX ].
  TS_ECU3_TX2_t TS_ECU3_TX2;                                   // TX [TS_ECU3]. RX [Client ].
  TS_ECU3_TX3_t TS_ECU3_TX3;                                   // TX [TS_ECU3]. RX [Client ].
  TS_ECU3_TX4_t TS_ECU3_TX4;                                   // TX [TS_ECU3]. RX [Client ].
  TS_ECU4_TX1_t TS_ECU4_TX1;                                   // TX [TS_ECU4]. RX [Client TS_Fan_ECU VCU Vector__XXX ].
  TS_ECU4_TX2_t TS_ECU4_TX2;                                   // TX [TS_ECU4]. RX [Client ].
  TS_ECU4_TX3_t TS_ECU4_TX3;                                   // TX [TS_ECU4]. RX [Client ].
  TS_ECU4_TX4_t TS_ECU4_TX4;                                   // TX [TS_ECU4]. RX [Client ].
  TS_ECU5_TX1_t TS_ECU5_TX1;                                   // TX [TS_ECU5]. RX [Client TS_Fan_ECU VCU Vector__XXX ].
  TS_ECU5_TX2_t TS_ECU5_TX2;                                   // TX [TS_ECU5]. RX [Client ].
  TS_ECU5_TX3_t TS_ECU5_TX3;                                   // TX [TS_ECU5]. RX [Client ].
  TS_ECU5_TX4_t TS_ECU5_TX4;                                   // TX [TS_ECU5]. RX [Client ].
} Temp_rx_t;

// There is no any message detected with tx direction.

uint32_t Temp_Receive(Temp_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


// define @__DEF_TEMP__ in the @dbccodeconf.h file for allocation in utility source code.
#ifdef __DEF_TEMP__

extern Temp_rx_t Temp_rx;

#endif


#ifdef __cplusplus
}
#endif

