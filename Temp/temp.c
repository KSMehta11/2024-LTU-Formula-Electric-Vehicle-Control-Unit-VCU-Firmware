
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "temp.h"

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU_ChargingStateTrigger_Temp(TS_ECU_ChargingStateTrigger_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->Orion_2_ChargePowerState = (_d[0] & (0x01U));
  _m->Orion_2_ChargeSafetyState = ((_d[0] >> 1) & (0x01U));
  return TS_ECU_ChargingStateTrigger_CANID;
}

uint32_t Pack_TS_ECU_ChargingStateTrigger_Temp(const TS_ECU_ChargingStateTrigger_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU_ChargingStateTrigger_DLC; _d[i++] = 0);

  _d[0] |= (_m->Orion_2_ChargePowerState & (0x01U)) | ((_m->Orion_2_ChargeSafetyState & (0x01U)) << 1);
  *_len = 1; *_ide = 0;
  return TS_ECU_ChargingStateTrigger_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU_SYNC_RX1_Temp(TS_ECU_SYNC_RX1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_SYNC_COUNTER = (_d[0] & (0xFFU));
  return TS_ECU_SYNC_RX1_CANID;
}

uint32_t Pack_TS_ECU_SYNC_RX1_Temp(const TS_ECU_SYNC_RX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU_SYNC_RX1_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_SYNC_COUNTER & (0xFFU));
  *_len = 1; *_ide = 0;
  return TS_ECU_SYNC_RX1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU_SYNC_RX2_Temp(TS_ECU_SYNC_RX2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_SYNC_COUNTER = (_d[0] & (0xFFU));
  return TS_ECU_SYNC_RX2_CANID;
}

uint32_t Pack_TS_ECU_SYNC_RX2_Temp(const TS_ECU_SYNC_RX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU_SYNC_RX2_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_SYNC_COUNTER & (0xFFU));
  *_len = 1; *_ide = 0;
  return TS_ECU_SYNC_RX2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU1_TX1_Temp(TS_ECU1_TX1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_MaxSegmentTemperature = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_MinSegmentTemperature = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_AverageSegmentTemp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_MaxTemperatureCellCount = (_d[3] & (0xFFU));
  _m->TS_ECU_FaultInState = (_d[4] & (0x01U));
  _m->TS_ECU_FaultOutState = ((_d[4] >> 1) & (0x01U));
  _m->TS_ECU_TempThresholdFault = ((_d[4] >> 2) & (0x01U));
  _m->TS_ECU_OpenCircuitFault = ((_d[4] >> 3) & (0x01U));
  _m->FAN_ECU_ShortToGroundFault = ((_d[4] >> 4) & (0x01U));
  _m->TS_ECU_CurrentState = ((_d[4] >> 5) & (0x07U));
  return TS_ECU1_TX1_CANID;
}

uint32_t Pack_TS_ECU1_TX1_Temp(const TS_ECU1_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU1_TX1_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_MaxSegmentTemperature & (0xFFU));
  _d[1] |= (_m->TS_ECU_MinSegmentTemperature & (0xFFU));
  _d[2] |= (_m->TS_ECU_AverageSegmentTemp & (0xFFU));
  _d[3] |= (_m->TS_ECU_MaxTemperatureCellCount & (0xFFU));
  _d[4] |= (_m->TS_ECU_FaultInState & (0x01U)) | ((_m->TS_ECU_FaultOutState & (0x01U)) << 1) | ((_m->TS_ECU_TempThresholdFault & (0x01U)) << 2) | ((_m->TS_ECU_OpenCircuitFault & (0x01U)) << 3) | ((_m->FAN_ECU_ShortToGroundFault & (0x01U)) << 4) | ((_m->TS_ECU_CurrentState & (0x07U)) << 5);
  *_len = 5; *_ide = 0;
  return TS_ECU1_TX1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU1_TX2_Temp(TS_ECU1_TX2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module1_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module2_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module3_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module4_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module5_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module6_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module7_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module8_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU1_TX2_CANID;
}

uint32_t Pack_TS_ECU1_TX2_Temp(const TS_ECU1_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU1_TX2_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module1_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module2_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module3_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module4_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module5_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module6_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module7_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module8_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU1_TX2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU1_TX3_Temp(TS_ECU1_TX3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module9_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module10_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module11_Temp = (_d[2] & (0xFFU));
  _m->TS_ECU_Segment_Module12_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module13_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module14_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module15_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module16_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU1_TX3_CANID;
}

uint32_t Pack_TS_ECU1_TX3_Temp(const TS_ECU1_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU1_TX3_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module9_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module10_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module11_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module12_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module13_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module14_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module15_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module16_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU1_TX3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU1_TX4_Temp(TS_ECU1_TX4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module17_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module18_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module19_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module20_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module21_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module22_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module23_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module24_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU1_TX4_CANID;
}

uint32_t Pack_TS_ECU1_TX4_Temp(const TS_ECU1_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU1_TX4_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module17_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module18_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module19_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module20_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module21_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module22_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module23_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module24_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU1_TX4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU2_TX1_Temp(TS_ECU2_TX1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_MaxSegmentTemperature = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_MinSegmentTemperature = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_AverageSegmentTemp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_MaxTemperatureCellCount = (_d[3] & (0xFFU));
  _m->TS_ECU_FaultInState = (_d[4] & (0x01U));
  _m->TS_ECU_FaultOutState = ((_d[4] >> 1) & (0x01U));
  _m->TS_ECU_TempThresholdFault = ((_d[4] >> 2) & (0x01U));
  _m->TS_ECU_OpenCircuitFault = ((_d[4] >> 3) & (0x01U));
  _m->FAN_ECU_ShortToGroundFault = ((_d[4] >> 4) & (0x01U));
  _m->TS_ECU_CurrentState = ((_d[4] >> 5) & (0x07U));
  return TS_ECU2_TX1_CANID;
}

uint32_t Pack_TS_ECU2_TX1_Temp(const TS_ECU2_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU2_TX1_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_MaxSegmentTemperature & (0xFFU));
  _d[1] |= (_m->TS_ECU_MinSegmentTemperature & (0xFFU));
  _d[2] |= (_m->TS_ECU_AverageSegmentTemp & (0xFFU));
  _d[3] |= (_m->TS_ECU_MaxTemperatureCellCount & (0xFFU));
  _d[4] |= (_m->TS_ECU_FaultInState & (0x01U)) | ((_m->TS_ECU_FaultOutState & (0x01U)) << 1) | ((_m->TS_ECU_TempThresholdFault & (0x01U)) << 2) | ((_m->TS_ECU_OpenCircuitFault & (0x01U)) << 3) | ((_m->FAN_ECU_ShortToGroundFault & (0x01U)) << 4) | ((_m->TS_ECU_CurrentState & (0x07U)) << 5);
  *_len = 5; *_ide = 0;
  return TS_ECU2_TX1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU2_TX2_Temp(TS_ECU2_TX2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module1_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module2_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module3_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module4_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module5_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module6_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module7_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module8_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU2_TX2_CANID;
}

uint32_t Pack_TS_ECU2_TX2_Temp(const TS_ECU2_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU2_TX2_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module1_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module2_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module3_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module4_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module5_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module6_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module7_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module8_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU2_TX2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU2_TX3_Temp(TS_ECU2_TX3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module9_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module10_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module11_Temp = (_d[2] & (0xFFU));
  _m->TS_ECU_Segment_Module12_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module13_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module14_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module15_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module16_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU2_TX3_CANID;
}

uint32_t Pack_TS_ECU2_TX3_Temp(const TS_ECU2_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU2_TX3_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module9_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module10_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module11_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module12_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module13_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module14_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module15_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module16_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU2_TX3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU2_TX4_Temp(TS_ECU2_TX4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module17_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module18_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module19_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module20_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module21_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module22_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module23_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module24_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU2_TX4_CANID;
}

uint32_t Pack_TS_ECU2_TX4_Temp(const TS_ECU2_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU2_TX4_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module17_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module18_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module19_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module20_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module21_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module22_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module23_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module24_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU2_TX4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU3_TX1_Temp(TS_ECU3_TX1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_MaxSegmentTemperature = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_MinSegmentTemperature = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_AverageSegmentTemp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_MaxTemperatureCellCount = (_d[3] & (0xFFU));
  _m->TS_ECU_FaultInState = (_d[4] & (0x01U));
  _m->TS_ECU_FaultOutState = ((_d[4] >> 1) & (0x01U));
  _m->TS_ECU_TempThresholdFault = ((_d[4] >> 2) & (0x01U));
  _m->TS_ECU_OpenCircuitFault = ((_d[4] >> 3) & (0x01U));
  _m->FAN_ECU_ShortToGroundFault = ((_d[4] >> 4) & (0x01U));
  _m->TS_ECU_CurrentState = ((_d[4] >> 5) & (0x07U));
  return TS_ECU3_TX1_CANID;
}

uint32_t Pack_TS_ECU3_TX1_Temp(const TS_ECU3_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU3_TX1_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_MaxSegmentTemperature & (0xFFU));
  _d[1] |= (_m->TS_ECU_MinSegmentTemperature & (0xFFU));
  _d[2] |= (_m->TS_ECU_AverageSegmentTemp & (0xFFU));
  _d[3] |= (_m->TS_ECU_MaxTemperatureCellCount & (0xFFU));
  _d[4] |= (_m->TS_ECU_FaultInState & (0x01U)) | ((_m->TS_ECU_FaultOutState & (0x01U)) << 1) | ((_m->TS_ECU_TempThresholdFault & (0x01U)) << 2) | ((_m->TS_ECU_OpenCircuitFault & (0x01U)) << 3) | ((_m->FAN_ECU_ShortToGroundFault & (0x01U)) << 4) | ((_m->TS_ECU_CurrentState & (0x07U)) << 5);
  *_len = 5; *_ide = 0;
  return TS_ECU3_TX1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU3_TX2_Temp(TS_ECU3_TX2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module1_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module2_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module3_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module4_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module5_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module6_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module7_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module8_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU3_TX2_CANID;
}

uint32_t Pack_TS_ECU3_TX2_Temp(const TS_ECU3_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU3_TX2_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module1_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module2_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module3_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module4_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module5_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module6_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module7_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module8_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU3_TX2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU3_TX3_Temp(TS_ECU3_TX3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module9_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module10_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module11_Temp = (_d[2] & (0xFFU));
  _m->TS_ECU_Segment_Module12_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module13_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module14_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module15_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module16_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU3_TX3_CANID;
}

uint32_t Pack_TS_ECU3_TX3_Temp(const TS_ECU3_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU3_TX3_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module9_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module10_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module11_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module12_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module13_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module14_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module15_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module16_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU3_TX3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU3_TX4_Temp(TS_ECU3_TX4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module17_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module18_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module19_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module20_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module21_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module22_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module23_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module24_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU3_TX4_CANID;
}

uint32_t Pack_TS_ECU3_TX4_Temp(const TS_ECU3_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU3_TX4_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module17_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module18_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module19_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module20_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module21_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module22_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module23_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module24_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU3_TX4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU4_TX1_Temp(TS_ECU4_TX1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_MaxSegmentTemperature = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_MinSegmentTemperature = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_AverageSegmentTemp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_MaxTemperatureCellCount = (_d[3] & (0xFFU));
  _m->TS_ECU_FaultInState = (_d[4] & (0x01U));
  _m->TS_ECU_FaultOutState = ((_d[4] >> 1) & (0x01U));
  _m->TS_ECU_TempThresholdFault = ((_d[4] >> 2) & (0x01U));
  _m->TS_ECU_OpenCircuitFault = ((_d[4] >> 3) & (0x01U));
  _m->FAN_ECU_ShortToGroundFault = ((_d[4] >> 4) & (0x01U));
  _m->TS_ECU_CurrentState = ((_d[4] >> 5) & (0x07U));
  return TS_ECU4_TX1_CANID;
}

uint32_t Pack_TS_ECU4_TX1_Temp(const TS_ECU4_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU4_TX1_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_MaxSegmentTemperature & (0xFFU));
  _d[1] |= (_m->TS_ECU_MinSegmentTemperature & (0xFFU));
  _d[2] |= (_m->TS_ECU_AverageSegmentTemp & (0xFFU));
  _d[3] |= (_m->TS_ECU_MaxTemperatureCellCount & (0xFFU));
  _d[4] |= (_m->TS_ECU_FaultInState & (0x01U)) | ((_m->TS_ECU_FaultOutState & (0x01U)) << 1) | ((_m->TS_ECU_TempThresholdFault & (0x01U)) << 2) | ((_m->TS_ECU_OpenCircuitFault & (0x01U)) << 3) | ((_m->FAN_ECU_ShortToGroundFault & (0x01U)) << 4) | ((_m->TS_ECU_CurrentState & (0x07U)) << 5);
  *_len = 5; *_ide = 0;
  return TS_ECU4_TX1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU4_TX2_Temp(TS_ECU4_TX2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module1_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module2_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module3_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module4_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module5_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module6_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module7_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module8_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU4_TX2_CANID;
}

uint32_t Pack_TS_ECU4_TX2_Temp(const TS_ECU4_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU4_TX2_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module1_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module2_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module3_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module4_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module5_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module6_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module7_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module8_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU4_TX2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU4_TX3_Temp(TS_ECU4_TX3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module9_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module10_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module11_Temp = (_d[2] & (0xFFU));
  _m->TS_ECU_Segment_Module12_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module13_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module14_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module15_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module16_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU4_TX3_CANID;
}

uint32_t Pack_TS_ECU4_TX3_Temp(const TS_ECU4_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU4_TX3_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module9_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module10_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module11_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module12_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module13_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module14_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module15_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module16_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU4_TX3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU4_TX4_Temp(TS_ECU4_TX4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module17_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module18_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module19_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module20_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module21_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module22_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module23_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module24_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU4_TX4_CANID;
}

uint32_t Pack_TS_ECU4_TX4_Temp(const TS_ECU4_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU4_TX4_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module17_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module18_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module19_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module20_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module21_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module22_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module23_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module24_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU4_TX4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU5_TX1_Temp(TS_ECU5_TX1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_MaxSegmentTemperature = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_MinSegmentTemperature = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_AverageSegmentTemp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_MaxTemperatureCellCount = (_d[3] & (0xFFU));
  _m->TS_ECU_FaultInState = (_d[4] & (0x01U));
  _m->TS_ECU_FaultOutState = ((_d[4] >> 1) & (0x01U));
  _m->TS_ECU_TempThresholdFault = ((_d[4] >> 2) & (0x01U));
  _m->TS_ECU_OpenCircuitFault = ((_d[4] >> 3) & (0x01U));
  _m->FAN_ECU_ShortToGroundFault = ((_d[4] >> 4) & (0x01U));
  _m->TS_ECU_CurrentState = ((_d[4] >> 5) & (0x07U));
  return TS_ECU5_TX1_CANID;
}

uint32_t Pack_TS_ECU5_TX1_Temp(const TS_ECU5_TX1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU5_TX1_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_MaxSegmentTemperature & (0xFFU));
  _d[1] |= (_m->TS_ECU_MinSegmentTemperature & (0xFFU));
  _d[2] |= (_m->TS_ECU_AverageSegmentTemp & (0xFFU));
  _d[3] |= (_m->TS_ECU_MaxTemperatureCellCount & (0xFFU));
  _d[4] |= (_m->TS_ECU_FaultInState & (0x01U)) | ((_m->TS_ECU_FaultOutState & (0x01U)) << 1) | ((_m->TS_ECU_TempThresholdFault & (0x01U)) << 2) | ((_m->TS_ECU_OpenCircuitFault & (0x01U)) << 3) | ((_m->FAN_ECU_ShortToGroundFault & (0x01U)) << 4) | ((_m->TS_ECU_CurrentState & (0x07U)) << 5);
  *_len = 5; *_ide = 0;
  return TS_ECU5_TX1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU5_TX2_Temp(TS_ECU5_TX2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module1_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module2_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module3_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module4_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module5_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module6_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module7_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module8_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU5_TX2_CANID;
}

uint32_t Pack_TS_ECU5_TX2_Temp(const TS_ECU5_TX2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU5_TX2_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module1_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module2_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module3_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module4_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module5_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module6_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module7_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module8_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU5_TX2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU5_TX3_Temp(TS_ECU5_TX3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module9_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module10_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module11_Temp = (_d[2] & (0xFFU));
  _m->TS_ECU_Segment_Module12_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module13_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module14_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module15_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module16_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU5_TX3_CANID;
}

uint32_t Pack_TS_ECU5_TX3_Temp(const TS_ECU5_TX3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU5_TX3_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module9_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module10_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module11_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module12_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module13_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module14_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module15_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module16_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU5_TX3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TS_ECU5_TX4_Temp(TS_ECU5_TX4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->TS_ECU_Segment_Module17_Temp = ((_d[0] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module18_Temp = ((_d[1] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module19_Temp = ((_d[2] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module20_Temp = ((_d[3] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module21_Temp = ((_d[4] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module22_Temp = ((_d[5] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module23_Temp = ((_d[6] & (0xFFU))) - 40;
  _m->TS_ECU_Segment_Module24_Temp = ((_d[7] & (0xFFU))) - 40;
  return TS_ECU5_TX4_CANID;
}

uint32_t Pack_TS_ECU5_TX4_Temp(const TS_ECU5_TX4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < TS_ECU5_TX4_DLC; _d[i++] = 0);

  _d[0] |= (_m->TS_ECU_Segment_Module17_Temp & (0xFFU));
  _d[1] |= (_m->TS_ECU_Segment_Module18_Temp & (0xFFU));
  _d[2] |= (_m->TS_ECU_Segment_Module19_Temp & (0xFFU));
  _d[3] |= (_m->TS_ECU_Segment_Module20_Temp & (0xFFU));
  _d[4] |= (_m->TS_ECU_Segment_Module21_Temp & (0xFFU));
  _d[5] |= (_m->TS_ECU_Segment_Module22_Temp & (0xFFU));
  _d[6] |= (_m->TS_ECU_Segment_Module23_Temp & (0xFFU));
  _d[7] |= (_m->TS_ECU_Segment_Module24_Temp & (0xFFU));
  *_len = 8; *_ide = 0;
  return TS_ECU5_TX4_CANID;
}

