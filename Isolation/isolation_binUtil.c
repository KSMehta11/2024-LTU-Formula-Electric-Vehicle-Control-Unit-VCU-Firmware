
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "isolation_binUtil.h"

#ifdef __DEF_ISOLATION__

isolation_rx_t isolation_rx;

#endif

uint32_t isolation_Receive(isolation_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id >= 0x22U && _id < 0x37U) {
  if (_id == 0x22U) {
   recid = Unpack_IMD_Request_isolation(&(_m->IMD_Request), _d, dlc_);
  } else if (_id == 0x23U) {
   recid = Unpack_IMD_Response_isolation(&(_m->IMD_Response), _d, dlc_);
  }
 } else {
  if (_id == 0x37U) {
   recid = Unpack_IMD_Info_isolation(&(_m->IMD_Info), _d, dlc_);
  } else {
   if (_id == 0x70EU) {
    recid = Unpack_UDS_IMD_FLASH_REQ_isolation(&(_m->UDS_IMD_FLASH_REQ), _d, dlc_);
   } else if (_id == 0x778U) {
    recid = Unpack_UDS_IMD_FLASH_RESP_isolation(&(_m->UDS_IMD_FLASH_RESP), _d, dlc_);
   }
  }
 }

 return recid;
}

