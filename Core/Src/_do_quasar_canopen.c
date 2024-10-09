
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "_do_quasar_canopen.h"

// --------------------------------------------------------------------------
uint32_t Unpack_ECU_NMT_command__DO_QUASAR_CANopen(ECU_NMT_command_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ECU_NMT_CommandSpecifier = (_d[0] & (0xFFU));
  _m->ECU_NMT_NodeId = (_d[1] & (0xFFU));
  return ECU_NMT_command_CANID;
}

uint32_t Pack_ECU_NMT_command__DO_QUASAR_CANopen(const ECU_NMT_command_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < ECU_NMT_command_DLC; _d[i++] = 0);

  _d[0] |= (_m->ECU_NMT_CommandSpecifier & (0xFFU));
  _d[1] |= (_m->ECU_NMT_NodeId & (0xFFU));
  *_len = 2; *_ide = 0;
  return ECU_NMT_command_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_ECU_SYNC__DO_QUASAR_CANopen(ECU_SYNC_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ECU_SYNCH_Counter = (_d[0] & (0xFFU));
  return ECU_SYNC_CANID;
}

uint32_t Pack_ECU_SYNC__DO_QUASAR_CANopen(const ECU_SYNC_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < ECU_SYNC_DLC; _d[i++] = 0);

  _d[0] |= (_m->ECU_SYNCH_Counter & (0xFFU));
  *_len = 1; *_ide = 0;
  return ECU_SYNC_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_TxPDO_5__DO_QUASAR_CANopen(EMD_TxPDO_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_ACT_MaxJunctionTemp = ((_d[0] & (0xFFU))) - 40;
  _m->EMD_ACT_MotorTemperature = ((_d[1] & (0xFFU))) - 40;
  _m->EMD_ACT_ControlStrategy = (_d[2] & (0x07U));
  _m->EMD_ACT_MotorTemperature_VAL = ((_d[2] >> 3) & (0x03U));
  _m->EMD_ACT_MaxJunctionTemp_VAL = ((_d[2] >> 5) & (0x03U));
  _m->EMD_MSGCNT_TxPDO5 = (_d[3] & (0x0FU));
  return EMD_TxPDO_5_CANID;
}

uint32_t Pack_EMD_TxPDO_5__DO_QUASAR_CANopen(const EMD_TxPDO_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_TxPDO_5_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_ACT_MaxJunctionTemp & (0xFFU));
  _d[1] |= (_m->EMD_ACT_MotorTemperature & (0xFFU));
  _d[2] |= (_m->EMD_ACT_ControlStrategy & (0x07U)) | ((_m->EMD_ACT_MotorTemperature_VAL & (0x03U)) << 3) | ((_m->EMD_ACT_MaxJunctionTemp_VAL & (0x03U)) << 5);
  _d[3] |= (_m->EMD_MSGCNT_TxPDO5 & (0x0FU));
  *_len = 4; *_ide = 0;
  return EMD_TxPDO_5_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_TxPDO_1__DO_QUASAR_CANopen(EMD_TxPDO_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_ACT_InverterLosses = ((_d[1] & (0x0FU)) << 8) | (_d[0] & (0xFFU));
  _m->EMD_ACT_InverterState = ((_d[1] >> 4) & (0x0FU));
  _m->EMD_ACT_MotorLosses = ((_d[3] & (0x0FU)) << 8) | (_d[2] & (0xFFU));
  _m->EMD_MSGCNT_TxPDO1 = ((_d[3] >> 4) & (0x0FU));
  _m->EMD_ACT_LastError = ((_d[5] & (0x03U)) << 8) | (_d[4] & (0xFFU));
  _m->EMD_ACT_InverterLosses_VAL = ((_d[5] >> 2) & (0x03U));
  _m->EMD_ACT_MotorLosses_VAL = ((_d[5] >> 4) & (0x03U));
  _m->EMD_ACT_DigitalOutput1 = ((_d[5] >> 6) & (0x01U));
  _m->EMD_ACT_DigitalOutput2 = ((_d[5] >> 7) & (0x01U));
  _m->EMD_ACT_CausingError = ((_d[7] & (0x03U)) << 8) | (_d[6] & (0xFFU));
  _m->EMD_ACT_DigitalInput1 = ((_d[7] >> 2) & (0x01U));
  _m->EMD_ACT_DigitalInput2 = ((_d[7] >> 3) & (0x01U));
  _m->EMD_ACT_LimitationMode = ((_d[7] >> 4) & (0x01U));
  _m->EMD_ACT_ASCState = ((_d[7] >> 5) & (0x01U));
  _m->EMD_ACT_DischargeState = ((_d[7] >> 6) & (0x01U));
  _m->EMD_ACT_SpoInput = ((_d[7] >> 7) & (0x01U));
  return EMD_TxPDO_1_CANID;
}

uint32_t Pack_EMD_TxPDO_1__DO_QUASAR_CANopen(const EMD_TxPDO_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_TxPDO_1_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_ACT_InverterLosses & (0xFFU));
  _d[1] |= ((_m->EMD_ACT_InverterLosses >> 8) & (0x0FU)) | ((_m->EMD_ACT_InverterState & (0x0FU)) << 4);
  _d[2] |= (_m->EMD_ACT_MotorLosses & (0xFFU));
  _d[3] |= ((_m->EMD_ACT_MotorLosses >> 8) & (0x0FU)) | ((_m->EMD_MSGCNT_TxPDO1 & (0x0FU)) << 4);
  _d[4] |= (_m->EMD_ACT_LastError & (0xFFU));
  _d[5] |= ((_m->EMD_ACT_LastError >> 8) & (0x03U)) | ((_m->EMD_ACT_InverterLosses_VAL & (0x03U)) << 2) | ((_m->EMD_ACT_MotorLosses_VAL & (0x03U)) << 4) | ((_m->EMD_ACT_DigitalOutput1 & (0x01U)) << 6) | ((_m->EMD_ACT_DigitalOutput2 & (0x01U)) << 7);
  _d[6] |= (_m->EMD_ACT_CausingError & (0xFFU));
  _d[7] |= ((_m->EMD_ACT_CausingError >> 8) & (0x03U)) | ((_m->EMD_ACT_DigitalInput1 & (0x01U)) << 2) | ((_m->EMD_ACT_DigitalInput2 & (0x01U)) << 3) | ((_m->EMD_ACT_LimitationMode & (0x01U)) << 4) | ((_m->EMD_ACT_ASCState & (0x01U)) << 5) | ((_m->EMD_ACT_DischargeState & (0x01U)) << 6) | ((_m->EMD_ACT_SpoInput & (0x01U)) << 7);
  *_len = 8; *_ide = 0;
  return EMD_TxPDO_1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_RxPDO_5__DO_QUASAR_CANopen(EMD_RxPDO_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_CMD_SpeedLimitHigh = (((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU))) - 32768;
  _m->EMD_CMD_SpeedLimitLow = (((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU))) - 32768;
  _m->EMD_CMD_SpeedLimitHigh_VAL = (_d[4] & (0x03U));
  _m->EMD_CMD_SpeedLimitLow_VAL = ((_d[4] >> 2) & (0x03U));
  _m->EMD_MSGCNT_RxPDO5 = ((_d[4] >> 4) & (0x0FU));
  return EMD_RxPDO_5_CANID;
}

uint32_t Pack_EMD_RxPDO_5__DO_QUASAR_CANopen(const EMD_RxPDO_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_RxPDO_5_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_CMD_SpeedLimitHigh & (0xFFU));
  _d[1] |= ((_m->EMD_CMD_SpeedLimitHigh >> 8) & (0xFFU));
  _d[2] |= (_m->EMD_CMD_SpeedLimitLow & (0xFFU));
  _d[3] |= ((_m->EMD_CMD_SpeedLimitLow >> 8) & (0xFFU));
  _d[4] |= (_m->EMD_CMD_SpeedLimitHigh_VAL & (0x03U)) | ((_m->EMD_CMD_SpeedLimitLow_VAL & (0x03U)) << 2) | ((_m->EMD_MSGCNT_RxPDO5 & (0x0FU)) << 4);
  *_len = 5; *_ide = 0;
  return EMD_RxPDO_5_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_RxPDO_1__DO_QUASAR_CANopen(EMD_RxPDO_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_CMD_IdCurrentTest = (((_d[1] & (0x0FU)) << 8) | (_d[0] & (0xFFU))) - 2048;
  _m->EMD_CMD_IdCurrentTest_VAL = ((_d[1] >> 4) & (0x03U));
  _m->EMD_CMD_IqCurrentTest_VAL = ((_d[1] >> 6) & (0x03U));
  _m->EMD_CMD_IqCurrentTest = (((_d[3] & (0x0FU)) << 8) | (_d[2] & (0xFFU))) - 2048;
  _m->EMD_MSGCNT_RxPDO1 = ((_d[3] >> 4) & (0x0FU));
  _m->EMD_CMD_StatorFrequencyTest = ((_d[5] & (0x3FU)) << 8) | (_d[4] & (0xFFU));
  _m->EMD_CMD_StatorFrequencyTest_VAL = ((_d[5] >> 6) & (0x03U));
  return EMD_RxPDO_1_CANID;
}

uint32_t Pack_EMD_RxPDO_1__DO_QUASAR_CANopen(const EMD_RxPDO_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_RxPDO_1_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_CMD_IdCurrentTest & (0xFFU));
  _d[1] |= ((_m->EMD_CMD_IdCurrentTest >> 8) & (0x0FU)) | ((_m->EMD_CMD_IdCurrentTest_VAL & (0x03U)) << 4) | ((_m->EMD_CMD_IqCurrentTest_VAL & (0x03U)) << 6);
  _d[2] |= (_m->EMD_CMD_IqCurrentTest & (0xFFU));
  _d[3] |= ((_m->EMD_CMD_IqCurrentTest >> 8) & (0x0FU)) | ((_m->EMD_MSGCNT_RxPDO1 & (0x0FU)) << 4);
  _d[4] |= (_m->EMD_CMD_StatorFrequencyTest & (0xFFU));
  _d[5] |= ((_m->EMD_CMD_StatorFrequencyTest >> 8) & (0x3FU)) | ((_m->EMD_CMD_StatorFrequencyTest_VAL & (0x03U)) << 6);
  *_len = 6; *_ide = 0;
  return EMD_RxPDO_1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_TxPDO_2__DO_QUASAR_CANopen(EMD_TxPDO_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_ACT_ReferenceTorqueLim = (((_d[1] & (0x3FU)) << 8) | (_d[0] & (0xFFU))) - 5000;
  _m->EMD_ACT_ReferenceTorqueLim_VAL = ((_d[1] >> 6) & (0x03U));
  _m->EMD_ACT_MaxAvailableTorque = ((_d[3] & (0x3FU)) << 8) | (_d[2] & (0xFFU));
  _m->EMD_ACT_MaxAvailableTorque_VAL = ((_d[3] >> 6) & (0x03U));
  _m->EMD_ACT_CutbackNumber = (_d[4] & (0xFFU));
  _m->EMD_ACT_Torque = (((_d[6] & (0x3FU)) << 8) | (_d[5] & (0xFFU))) - 5000;
  _m->EMD_ACT_Torque_VAL = ((_d[6] >> 6) & (0x03U));
  _m->EMD_MSGCNT_TxPDO2 = (_d[7] & (0x0FU));
  return EMD_TxPDO_2_CANID;
}

uint32_t Pack_EMD_TxPDO_2__DO_QUASAR_CANopen(const EMD_TxPDO_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_TxPDO_2_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_ACT_ReferenceTorqueLim & (0xFFU));
  _d[1] |= ((_m->EMD_ACT_ReferenceTorqueLim >> 8) & (0x3FU)) | ((_m->EMD_ACT_ReferenceTorqueLim_VAL & (0x03U)) << 6);
  _d[2] |= (_m->EMD_ACT_MaxAvailableTorque & (0xFFU));
  _d[3] |= ((_m->EMD_ACT_MaxAvailableTorque >> 8) & (0x3FU)) | ((_m->EMD_ACT_MaxAvailableTorque_VAL & (0x03U)) << 6);
  _d[4] |= (_m->EMD_ACT_CutbackNumber & (0xFFU));
  _d[5] |= (_m->EMD_ACT_Torque & (0xFFU));
  _d[6] |= ((_m->EMD_ACT_Torque >> 8) & (0x3FU)) | ((_m->EMD_ACT_Torque_VAL & (0x03U)) << 6);
  _d[7] |= (_m->EMD_MSGCNT_TxPDO2 & (0x0FU));
  *_len = 8; *_ide = 0;
  return EMD_TxPDO_2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_RxPDO_2__DO_QUASAR_CANopen(EMD_RxPDO_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_CMD_PowerLimitGenerating = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->EMD_CMD_PowerLimitMotoring = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->EMD_CMD_PowerLimitGenerating_VAL = (_d[4] & (0x03U));
  _m->EMD_CMD_PowerLimitMotoring_VAL = ((_d[4] >> 2) & (0x03U));
  _m->EMD_MSGCNT_RxPDO2 = ((_d[4] >> 4) & (0x0FU));
  return EMD_RxPDO_2_CANID;
}

uint32_t Pack_EMD_RxPDO_2__DO_QUASAR_CANopen(const EMD_RxPDO_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_RxPDO_2_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_CMD_PowerLimitGenerating & (0xFFU));
  _d[1] |= ((_m->EMD_CMD_PowerLimitGenerating >> 8) & (0xFFU));
  _d[2] |= (_m->EMD_CMD_PowerLimitMotoring & (0xFFU));
  _d[3] |= ((_m->EMD_CMD_PowerLimitMotoring >> 8) & (0xFFU));
  _d[4] |= (_m->EMD_CMD_PowerLimitGenerating_VAL & (0x03U)) | ((_m->EMD_CMD_PowerLimitMotoring_VAL & (0x03U)) << 2) | ((_m->EMD_MSGCNT_RxPDO2 & (0x0FU)) << 4);
  *_len = 5; *_ide = 0;
  return EMD_RxPDO_2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_TxPDO_3__DO_QUASAR_CANopen(EMD_TxPDO_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_ACT_MotorSpeed = (((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU))) - 32768;
  _m->EMD_ACT_MechanicPower = (((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU))) - 32768;
  _m->EMD_ACT_DcLinkPower = (((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU))) - 32768;
  _m->EMD_MSGCNT_TxPDO3 = (_d[6] & (0x0FU));
  _m->EMD_ACT_MechanicPower_VAL = ((_d[6] >> 4) & (0x03U));
  _m->EMD_ACT_MotorSpeed_VAL = ((_d[6] >> 6) & (0x03U));
  _m->EMD_ACT_DcLinkPower_VAL = (_d[7] & (0x03U));
  return EMD_TxPDO_3_CANID;
}

uint32_t Pack_EMD_TxPDO_3__DO_QUASAR_CANopen(const EMD_TxPDO_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_TxPDO_3_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_ACT_MotorSpeed & (0xFFU));
  _d[1] |= ((_m->EMD_ACT_MotorSpeed >> 8) & (0xFFU));
  _d[2] |= (_m->EMD_ACT_MechanicPower & (0xFFU));
  _d[3] |= ((_m->EMD_ACT_MechanicPower >> 8) & (0xFFU));
  _d[4] |= (_m->EMD_ACT_DcLinkPower & (0xFFU));
  _d[5] |= ((_m->EMD_ACT_DcLinkPower >> 8) & (0xFFU));
  _d[6] |= (_m->EMD_MSGCNT_TxPDO3 & (0x0FU)) | ((_m->EMD_ACT_MechanicPower_VAL & (0x03U)) << 4) | ((_m->EMD_ACT_MotorSpeed_VAL & (0x03U)) << 6);
  _d[7] |= (_m->EMD_ACT_DcLinkPower_VAL & (0x03U));
  *_len = 8; *_ide = 0;
  return EMD_TxPDO_3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_RxPDO_3__DO_QUASAR_CANopen(EMD_RxPDO_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_CMD_TorqueRefLim = (((_d[1] & (0x3FU)) << 8) | (_d[0] & (0xFFU))) - 5000;
  _m->EMD_CMD_TorqueRefLim_VAL = ((_d[1] >> 6) & (0x03U));
  _m->EMD_CMD_SpeedRefLim = (((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU))) - 32768;
  _m->EMD_CMD_ControlMode = (_d[4] & (0x0FU));
  _m->EMD_MSGCNT_RxPDO3 = ((_d[4] >> 4) & (0x0FU));
  _m->EMD_CMD_SpeedRefLim_VAL = (_d[5] & (0x03U));
  _m->EMD_CMD_ClearErrors = ((_d[5] >> 2) & (0x01U));
  _m->EMD_CMD_RestartRequest = ((_d[5] >> 3) & (0x01U));
  _m->EMD_CMD_ActiveDischarge = ((_d[5] >> 4) & (0x01U));
  _m->EMD_CMD_LimitationMode = ((_d[5] >> 5) & (0x01U));
  _m->EMD_CMD_DigitalOutput2 = ((_d[5] >> 6) & (0x01U));
  _m->EMD_CMD_DigitalOutput1 = ((_d[5] >> 7) & (0x01U));
  return EMD_RxPDO_3_CANID;
}

uint32_t Pack_EMD_RxPDO_3__DO_QUASAR_CANopen(const EMD_RxPDO_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_RxPDO_3_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_CMD_TorqueRefLim & (0xFFU));
  _d[1] |= ((_m->EMD_CMD_TorqueRefLim >> 8) & (0x3FU)) | ((_m->EMD_CMD_TorqueRefLim_VAL & (0x03U)) << 6);
  _d[2] |= (_m->EMD_CMD_SpeedRefLim & (0xFFU));
  _d[3] |= ((_m->EMD_CMD_SpeedRefLim >> 8) & (0xFFU));
  _d[4] |= (_m->EMD_CMD_ControlMode & (0x0FU)) | ((_m->EMD_MSGCNT_RxPDO3 & (0x0FU)) << 4);
  _d[5] |= (_m->EMD_CMD_SpeedRefLim_VAL & (0x03U)) | ((_m->EMD_CMD_ClearErrors & (0x01U)) << 2) | ((_m->EMD_CMD_RestartRequest & (0x01U)) << 3) | ((_m->EMD_CMD_ActiveDischarge & (0x01U)) << 4) | ((_m->EMD_CMD_LimitationMode & (0x01U)) << 5) | ((_m->EMD_CMD_DigitalOutput2 & (0x01U)) << 6) | ((_m->EMD_CMD_DigitalOutput1 & (0x01U)) << 7);
  *_len = 6; *_ide = 0;
  return EMD_RxPDO_3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_TxPDO_4__DO_QUASAR_CANopen(EMD_TxPDO_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_ACT_PhaseCurrent = ((_d[1] & (0x3FU)) << 8) | (_d[0] & (0xFFU));
  _m->EMD_ACT_PhaseCurrent_VAL = ((_d[1] >> 6) & (0x03U));
  _m->EMD_ACT_DcLinkVoltage = ((_d[3] & (0x3FU)) << 8) | (_d[2] & (0xFFU));
  _m->EMD_ACT_DcLinkVoltage_VAL = ((_d[3] >> 6) & (0x03U));
  _m->EMD_ACT_ControlMode = (_d[4] & (0x0FU));
  _m->EMD_MSGCNT_TxPDO4 = ((_d[4] >> 4) & (0x0FU));
  _m->EMD_ACT_SystemWarning = (_d[5] & (0xFFU));
  return EMD_TxPDO_4_CANID;
}

uint32_t Pack_EMD_TxPDO_4__DO_QUASAR_CANopen(const EMD_TxPDO_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_TxPDO_4_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_ACT_PhaseCurrent & (0xFFU));
  _d[1] |= ((_m->EMD_ACT_PhaseCurrent >> 8) & (0x3FU)) | ((_m->EMD_ACT_PhaseCurrent_VAL & (0x03U)) << 6);
  _d[2] |= (_m->EMD_ACT_DcLinkVoltage & (0xFFU));
  _d[3] |= ((_m->EMD_ACT_DcLinkVoltage >> 8) & (0x3FU)) | ((_m->EMD_ACT_DcLinkVoltage_VAL & (0x03U)) << 6);
  _d[4] |= (_m->EMD_ACT_ControlMode & (0x0FU)) | ((_m->EMD_MSGCNT_TxPDO4 & (0x0FU)) << 4);
  _d[5] |= (_m->EMD_ACT_SystemWarning & (0xFFU));
  *_len = 6; *_ide = 0;
  return EMD_TxPDO_4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_RxPDO_4__DO_QUASAR_CANopen(EMD_RxPDO_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_CMD_TorqueLimitHigh = (((_d[1] & (0x3FU)) << 8) | (_d[0] & (0xFFU))) - 5000;
  _m->EMD_CMD_TorqueLimitLow_VAL = ((_d[1] >> 6) & (0x03U));
  _m->EMD_CMD_TorqueLimitLow = (((_d[3] & (0x3FU)) << 8) | (_d[2] & (0xFFU))) - 5000;
  _m->EMD_CMD_TorqueLimitHigh_VAL = ((_d[3] >> 6) & (0x03U));
  _m->EMD_MSGCNT_RxPDO4 = (_d[4] & (0x0FU));
  return EMD_RxPDO_4_CANID;
}

uint32_t Pack_EMD_RxPDO_4__DO_QUASAR_CANopen(const EMD_RxPDO_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_RxPDO_4_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_CMD_TorqueLimitHigh & (0xFFU));
  _d[1] |= ((_m->EMD_CMD_TorqueLimitHigh >> 8) & (0x3FU)) | ((_m->EMD_CMD_TorqueLimitLow_VAL & (0x03U)) << 6);
  _d[2] |= (_m->EMD_CMD_TorqueLimitLow & (0xFFU));
  _d[3] |= ((_m->EMD_CMD_TorqueLimitLow >> 8) & (0x3FU)) | ((_m->EMD_CMD_TorqueLimitHigh_VAL & (0x03U)) << 6);
  _d[4] |= (_m->EMD_MSGCNT_RxPDO4 & (0x0FU));
  *_len = 5; *_ide = 0;
  return EMD_RxPDO_4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_TxSDO__DO_QUASAR_CANopen(EMD_TxSDO_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_SDO_RespCmd = (_d[0] & (0xFFU));
  _m->EMD_SDO_RespObjectId = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->EMD_SDO_RespSubindex = (_d[3] & (0xFFU));
  _m->EMD_SDO_RespData = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return EMD_TxSDO_CANID;
}

uint32_t Pack_EMD_TxSDO__DO_QUASAR_CANopen(const EMD_TxSDO_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_TxSDO_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_SDO_RespCmd & (0xFFU));
  _d[1] |= (_m->EMD_SDO_RespObjectId & (0xFFU));
  _d[2] |= ((_m->EMD_SDO_RespObjectId >> 8) & (0xFFU));
  _d[3] |= (_m->EMD_SDO_RespSubindex & (0xFFU));
  _d[4] |= (_m->EMD_SDO_RespData & (0xFFU));
  _d[5] |= ((_m->EMD_SDO_RespData >> 8) & (0xFFU));
  _d[6] |= ((_m->EMD_SDO_RespData >> 16) & (0xFFU));
  _d[7] |= ((_m->EMD_SDO_RespData >> 24) & (0xFFU));
  *_len = 8; *_ide = 0;
  return EMD_TxSDO_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_EMD_RxSDO__DO_QUASAR_CANopen(EMD_RxSDO_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_SDO_ReqCmd = (_d[0] & (0xFFU));
  _m->EMD_SDO_ReqObjectId = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->EMD_SDO_ReqSubindex = (_d[3] & (0xFFU));
  _m->EMD_SDO_ReqData = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return EMD_RxSDO_CANID;
}

uint32_t Pack_EMD_RxSDO__DO_QUASAR_CANopen(const EMD_RxSDO_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < EMD_RxSDO_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_SDO_ReqCmd & (0xFFU));
  _d[1] |= (_m->EMD_SDO_ReqObjectId & (0xFFU));
  _d[2] |= ((_m->EMD_SDO_ReqObjectId >> 8) & (0xFFU));
  _d[3] |= (_m->EMD_SDO_ReqSubindex & (0xFFU));
  _d[4] |= (_m->EMD_SDO_ReqData & (0xFFU));
  _d[5] |= ((_m->EMD_SDO_ReqData >> 8) & (0xFFU));
  _d[6] |= ((_m->EMD_SDO_ReqData >> 16) & (0xFFU));
  _d[7] |= ((_m->EMD_SDO_ReqData >> 24) & (0xFFU));
  *_len = 8; *_ide = 0;
  return EMD_RxSDO_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_ECU_NMT_heart_beat__DO_QUASAR_CANopen(ECU_NMT_heart_beat_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ECU_NMT_HeartBeatDummy = (_d[0] & (0xFFU));
  return ECU_NMT_heart_beat_CANID;
}

uint32_t Pack_ECU_NMT_heart_beat__DO_QUASAR_CANopen(const ECU_NMT_heart_beat_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < ECU_NMT_heart_beat_DLC; _d[i++] = 0);

  _d[0] |= (_m->ECU_NMT_HeartBeatDummy & (0xFFU));
  *_len = 1; *_ide = 0;
  return ECU_NMT_heart_beat_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_ECU_EMD_NMT_node_guarding__DO_QUASAR_CANopen(ECU_EMD_NMT_node_guarding_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->EMD_NMT_NodeGuardState = (_d[0] & (0x7FU));
  _m->EMD_NMT_NodeGuardToggleBit = ((_d[0] >> 7) & (0x01U));
  return ECU_EMD_NMT_node_guarding_CANID;
}

uint32_t Pack_ECU_EMD_NMT_node_guarding__DO_QUASAR_CANopen(const ECU_EMD_NMT_node_guarding_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < ECU_EMD_NMT_node_guarding_DLC; _d[i++] = 0);

  _d[0] |= (_m->EMD_NMT_NodeGuardState & (0x7FU)) | ((_m->EMD_NMT_NodeGuardToggleBit & (0x01U)) << 7);
  *_len = 1; *_ide = 0;
  return ECU_EMD_NMT_node_guarding_CANID;
}

