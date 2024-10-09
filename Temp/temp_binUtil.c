
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "temp_binUtil.h"

#ifdef __DEF_TEMP__

Temp_rx_t Temp_rx;

#endif

uint32_t Temp_Receive(Temp_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id >= 0x2BAU && _id < 0x331U) {
  if (_id >= 0x2BAU && _id < 0x313U) {
   if (_id >= 0x2BAU && _id < 0x302U) {
    if (_id == 0x2BAU) {
     recid = Unpack_TS_ECU_ChargingStateTrigger_Temp(&(_m->TS_ECU_ChargingStateTrigger), _d, dlc_);
    } else if (_id == 0x301U) {
     recid = Unpack_TS_ECU_SYNC_RX1_Temp(&(_m->TS_ECU_SYNC_RX1), _d, dlc_);
    }
   } else {
    if (_id == 0x302U) {
     recid = Unpack_TS_ECU_SYNC_RX2_Temp(&(_m->TS_ECU_SYNC_RX2), _d, dlc_);
    } else {
     if (_id == 0x311U) {
      recid = Unpack_TS_ECU1_TX1_Temp(&(_m->TS_ECU1_TX1), _d, dlc_);
     } else if (_id == 0x312U) {
      recid = Unpack_TS_ECU1_TX2_Temp(&(_m->TS_ECU1_TX2), _d, dlc_);
     }
    }
   }
  } else {
   if (_id >= 0x313U && _id < 0x322U) {
    if (_id == 0x313U) {
     recid = Unpack_TS_ECU1_TX3_Temp(&(_m->TS_ECU1_TX3), _d, dlc_);
    } else {
     if (_id == 0x314U) {
      recid = Unpack_TS_ECU1_TX4_Temp(&(_m->TS_ECU1_TX4), _d, dlc_);
     } else if (_id == 0x321U) {
      recid = Unpack_TS_ECU2_TX1_Temp(&(_m->TS_ECU2_TX1), _d, dlc_);
     }
    }
   } else {
    if (_id == 0x322U) {
     recid = Unpack_TS_ECU2_TX2_Temp(&(_m->TS_ECU2_TX2), _d, dlc_);
    } else {
     if (_id == 0x323U) {
      recid = Unpack_TS_ECU2_TX3_Temp(&(_m->TS_ECU2_TX3), _d, dlc_);
     } else if (_id == 0x324U) {
      recid = Unpack_TS_ECU2_TX4_Temp(&(_m->TS_ECU2_TX4), _d, dlc_);
     }
    }
   }
  }
 } else {
  if (_id >= 0x331U && _id < 0x343U) {
   if (_id >= 0x331U && _id < 0x334U) {
    if (_id == 0x331U) {
     recid = Unpack_TS_ECU3_TX1_Temp(&(_m->TS_ECU3_TX1), _d, dlc_);
    } else {
     if (_id == 0x332U) {
      recid = Unpack_TS_ECU3_TX2_Temp(&(_m->TS_ECU3_TX2), _d, dlc_);
     } else if (_id == 0x333U) {
      recid = Unpack_TS_ECU3_TX3_Temp(&(_m->TS_ECU3_TX3), _d, dlc_);
     }
    }
   } else {
    if (_id == 0x334U) {
     recid = Unpack_TS_ECU3_TX4_Temp(&(_m->TS_ECU3_TX4), _d, dlc_);
    } else {
     if (_id == 0x341U) {
      recid = Unpack_TS_ECU4_TX1_Temp(&(_m->TS_ECU4_TX1), _d, dlc_);
     } else if (_id == 0x342U) {
      recid = Unpack_TS_ECU4_TX2_Temp(&(_m->TS_ECU4_TX2), _d, dlc_);
     }
    }
   }
  } else {
   if (_id >= 0x343U && _id < 0x352U) {
    if (_id == 0x343U) {
     recid = Unpack_TS_ECU4_TX3_Temp(&(_m->TS_ECU4_TX3), _d, dlc_);
    } else {
     if (_id == 0x344U) {
      recid = Unpack_TS_ECU4_TX4_Temp(&(_m->TS_ECU4_TX4), _d, dlc_);
     } else if (_id == 0x351U) {
      recid = Unpack_TS_ECU5_TX1_Temp(&(_m->TS_ECU5_TX1), _d, dlc_);
     }
    }
   } else {
    if (_id == 0x352U) {
     recid = Unpack_TS_ECU5_TX2_Temp(&(_m->TS_ECU5_TX2), _d, dlc_);
    } else {
     if (_id == 0x353U) {
      recid = Unpack_TS_ECU5_TX3_Temp(&(_m->TS_ECU5_TX3), _d, dlc_);
     } else if (_id == 0x354U) {
      recid = Unpack_TS_ECU5_TX4_Temp(&(_m->TS_ECU5_TX4), _d, dlc_);
     }
    }
   }
  }
 }

 return recid;
}

