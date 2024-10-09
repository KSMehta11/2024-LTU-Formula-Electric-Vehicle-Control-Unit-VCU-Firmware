
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "isolation.h"

// @dbccodeconf.h file should be placed in inc folder. If the user wants
// to allocate big DBC struct inside the driver - appropriate define (__DEF_xxxxx__)
// should be placed in this file
#include "dbccodeconf.h"

typedef struct
{
  IMD_Request_t IMD_Request;                 // TX [Master].  RX [IMD_StandAlone ].
  IMD_Response_t IMD_Response;               // TX [IMD_StandAlone].RX [Master ].
  IMD_Info_t IMD_Info;                       // TX [IMD_StandAlone].RX [].
  UDS_IMD_FLASH_REQ_t UDS_IMD_FLASH_REQ;     // TX [Master].  RX [IMD_StandAlone ].
  UDS_IMD_FLASH_RESP_t UDS_IMD_FLASH_RESP;   // TX [IMD_StandAlone].RX [Master ].
} isolation_rx_t;

// There is no any message detected with tx direction.

uint32_t isolation_Receive(isolation_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


// define @__DEF_ISOLATION__ in the @dbccodeconf.h file for allocation in utility source code.
#ifdef __DEF_ISOLATION__

extern isolation_rx_t isolation_rx;

#endif


#ifdef __cplusplus
}
#endif

