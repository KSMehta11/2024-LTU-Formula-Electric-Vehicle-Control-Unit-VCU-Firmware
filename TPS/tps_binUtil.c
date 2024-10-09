
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "tps_binUtil.h"

#ifdef __DEF_TPS__

TPS_rx_t TPS_rx;

#endif

uint32_t TPS_Receive(TPS_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id == 0x304U) {
  recid = Unpack_VCU_TPS_Limits_TPS(&(_m->VCU_TPS_Limits), _d, dlc_);
 } else if (_id == 0x305U) {
  recid = Unpack_VCU_TPS_CurrentValue_TPS(&(_m->VCU_TPS_CurrentValue), _d, dlc_);
 }

 return recid;
}

