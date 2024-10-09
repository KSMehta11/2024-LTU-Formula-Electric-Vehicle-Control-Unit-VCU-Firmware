
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "tps.h"

// --------------------------------------------------------------------------
uint32_t Unpack_VCU_TPS_Limits_TPS(VCU_TPS_Limits_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TPS_PrimaryMaxLimit = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->TPS_PrimaryMinLimit = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->TPS_SecondaryMaxLimit = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->TPS_SecondaryMinLimit = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return VCU_TPS_Limits_CANID;
}

uint32_t Pack_VCU_TPS_Limits_TPS(const VCU_TPS_Limits_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < VCU_TPS_Limits_DLC; _d[i++] = 0);

  _d[0] |= (_m->TPS_PrimaryMaxLimit & (0xFFU));
  _d[1] |= ((_m->TPS_PrimaryMaxLimit >> 8) & (0xFFU));
  _d[2] |= (_m->TPS_PrimaryMinLimit & (0xFFU));
  _d[3] |= ((_m->TPS_PrimaryMinLimit >> 8) & (0xFFU));
  _d[4] |= (_m->TPS_SecondaryMaxLimit & (0xFFU));
  _d[5] |= ((_m->TPS_SecondaryMaxLimit >> 8) & (0xFFU));
  _d[6] |= (_m->TPS_SecondaryMinLimit & (0xFFU));
  _d[7] |= ((_m->TPS_SecondaryMinLimit >> 8) & (0xFFU));
  *_len = 8; *_ide = 0;
  return VCU_TPS_Limits_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_VCU_TPS_CurrentValue_TPS(VCU_TPS_CurrentValue_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TPS_PrimaryCurrentVal = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->TPS_SecondaryCurrentVal = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  return VCU_TPS_CurrentValue_CANID;
}

uint32_t Pack_VCU_TPS_CurrentValue_TPS(const VCU_TPS_CurrentValue_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < VCU_TPS_CurrentValue_DLC; _d[i++] = 0);

  _d[0] |= (_m->TPS_PrimaryCurrentVal & (0xFFU));
  _d[1] |= ((_m->TPS_PrimaryCurrentVal >> 8) & (0xFFU));
  _d[2] |= (_m->TPS_SecondaryCurrentVal & (0xFFU));
  _d[3] |= ((_m->TPS_SecondaryCurrentVal >> 8) & (0xFFU));
  *_len = 4; *_ide = 0;
  return VCU_TPS_CurrentValue_CANID;
}

