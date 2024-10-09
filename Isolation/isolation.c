
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "isolation.h"

// --------------------------------------------------------------------------
uint32_t Unpack_IMD_Request_isolation(IMD_Request_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->IMD_Request_Command = (_d[0] & (0xFFU));
  _m->MG_IMC_MANUFACT_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MG_VIFC_POWER_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MC_VIFC_POWER_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MG_VIFC_VERSION_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MG_IMC_VERSION_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MG_IMC_EEPROM_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MC_VIFC_MEASURE_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MS_IMC_MEAN_FACTOR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MS_IMC_EEPROM_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MC_VIFC_LOCK_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IMD_Request_DataWord1 = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MS_IMC_R_ISO_WRN_THR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MC_IMC_CALIB_STEP = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MS_VIFC_HV_RELAIS = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MC_IMC_SELFTEST_SCR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MS_IMC_R_ISO_ERR_THR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->MS_IMC_EEPROM_DATA = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->MC_VIFC_LOCK_PWD = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IMD_Request_DataWord2 = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->MS_VIFC_HV_RELAIS_STATE = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  return IMD_Request_CANID;
}

uint32_t Pack_IMD_Request_isolation(const IMD_Request_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < IMD_Request_DLC; _d[i++] = 0);

  _d[0] |= (_m->IMD_Request_Command & (0xFFU));
  _d[1] |= (_m->MG_IMC_MANUFACT_INDEX & (0xFFU)) | (_m->MG_VIFC_POWER_MODE & (0xFFU)) | (_m->MC_VIFC_POWER_MODE & (0xFFU)) | (_m->MG_VIFC_VERSION_INDEX & (0xFFU)) | (_m->MG_IMC_VERSION_INDEX & (0xFFU)) | (_m->MG_IMC_EEPROM_INDEX & (0xFFU)) | (_m->MC_VIFC_MEASURE_MODE & (0xFFU)) | (_m->MS_IMC_MEAN_FACTOR & (0xFFU)) | (_m->MS_IMC_EEPROM_INDEX & (0xFFU)) | (_m->MC_VIFC_LOCK_MODE & (0xFFU)) | (_m->IMD_Request_DataWord1 & (0xFFU)) | (_m->MS_IMC_R_ISO_WRN_THR & (0xFFU)) | (_m->MC_IMC_CALIB_STEP & (0xFFU)) | (_m->MS_VIFC_HV_RELAIS & (0xFFU)) | (_m->MC_IMC_SELFTEST_SCR & (0xFFU)) | (_m->MS_IMC_R_ISO_ERR_THR & (0xFFU));
  _d[2] |= ((_m->MG_IMC_MANUFACT_INDEX >> 8) & (0xFFU)) | ((_m->MG_VIFC_POWER_MODE >> 8) & (0xFFU)) | ((_m->MC_VIFC_POWER_MODE >> 8) & (0xFFU)) | ((_m->MG_VIFC_VERSION_INDEX >> 8) & (0xFFU)) | ((_m->MG_IMC_VERSION_INDEX >> 8) & (0xFFU)) | ((_m->MG_IMC_EEPROM_INDEX >> 8) & (0xFFU)) | ((_m->MC_VIFC_MEASURE_MODE >> 8) & (0xFFU)) | ((_m->MS_IMC_MEAN_FACTOR >> 8) & (0xFFU)) | ((_m->MS_IMC_EEPROM_INDEX >> 8) & (0xFFU)) | ((_m->MC_VIFC_LOCK_MODE >> 8) & (0xFFU)) | ((_m->IMD_Request_DataWord1 >> 8) & (0xFFU)) | ((_m->MS_IMC_R_ISO_WRN_THR >> 8) & (0xFFU)) | ((_m->MC_IMC_CALIB_STEP >> 8) & (0xFFU)) | ((_m->MS_VIFC_HV_RELAIS >> 8) & (0xFFU)) | ((_m->MC_IMC_SELFTEST_SCR >> 8) & (0xFFU)) | ((_m->MS_IMC_R_ISO_ERR_THR >> 8) & (0xFFU));
  _d[3] |= (_m->MS_IMC_EEPROM_DATA & (0xFFU)) | (_m->MC_VIFC_LOCK_PWD & (0xFFU)) | (_m->IMD_Request_DataWord2 & (0xFFU)) | (_m->MS_VIFC_HV_RELAIS_STATE & (0xFFU));
  _d[4] |= ((_m->MS_IMC_EEPROM_DATA >> 8) & (0xFFU)) | ((_m->MC_VIFC_LOCK_PWD >> 8) & (0xFFU)) | ((_m->IMD_Request_DataWord2 >> 8) & (0xFFU)) | ((_m->MS_VIFC_HV_RELAIS_STATE >> 8) & (0xFFU));
  *_len = 5; *_ide = 0;
  return IMD_Request_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_IMD_Response_isolation(IMD_Response_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->IMD_Response_Command = (_d[0] & (0xFFU));
  _m->IG_IMC_MANUFACT_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_TEMP = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_IMC_ALIVE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_POWER_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IC_VIFC_POWER_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IS_IMC_MEAN_FACTOR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IS_IMC_EEPROM_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IC_IMC_CALIB_STEP = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IS_IMC_R_ISO_WRN_THR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IS_IMC_R_ISO_ERR_THR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IC_VIFC_MEASURE_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IC_VIFC_LOCK_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IS_VIFC_HV_RELAIS = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_EEPROM_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_MEAN_FACTOR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_LOCK_MODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_STATUS_00_IsoMeasurement = (_d[1] & (0x01U));
  _m->IG_VIFC_VERSION_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_HV_RELAIS = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_STATUS_00_IsoFailure = (_d[1] & (0x01U));
  _m->IG_IMD_ERROR_CODE = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_HV_2 = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_HV_1 = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_R_ISO_WRN_THR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_R_ISO_ERR_THR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_R_ISO = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IC_IMC_SELFTEST_SCR = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_TEST_CNT = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_IMC_VERSION_INDEX = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IMD_Response_DataWord1 = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->IG_VIFC_STATUS_01_IMCConnection = ((_d[1] >> 1) & (0x01U));
  _m->IG_IMC_STATUS_01_Ground = ((_d[1] >> 1) & (0x01U));
  _m->IG_VIFC_STATUS_02_IMC_Alive = ((_d[1] >> 2) & (0x01U));
  _m->IG_IMC_STATUS_02_System = ((_d[1] >> 2) & (0x01U));
  _m->IG_IMC_STATUS_03_Calibration = ((_d[1] >> 3) & (0x01U));
  _m->IG_IMC_STATUS_04_Selftest = ((_d[1] >> 4) & (0x01U));
  _m->IG_IMC_STATUS_05_IsoWarning = ((_d[1] >> 5) & (0x01U));
  _m->IG_VIFC_STATUS_08_Outdated = (_d[2] & (0x01U));
  _m->IG_VIFC_VERSION_MIN = (_d[3] & (0xFFU));
  _m->IG_IMC_VERSION_MIN = (_d[3] & (0xFFU));
  _m->IG_IMC_MANUFACT_DATA = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IG_IMC_R_ISO_BIAS = (_d[3] & (0xFFU));
  _m->IS_IMC_EEPROM_DATA = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IS_VIFC_HV_RELAIS_STATE = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IG_IMC_EEPROM_DATA = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IG_VIFC_HV_RELAIS_STATE = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IG_IMC_STATUS_EXT_00_Calibration = (_d[3] & (0x01U));
  _m->IG_IMD_FAILED_CMD = (_d[3] & (0xFFU));
  _m->IMD_Response_DataWord2 = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  _m->IG_IMC_STATUS_EXT_01_Hardware = ((_d[3] >> 1) & (0x01U));
  _m->IG_IMC_STATUS_EXT_02_EEPROM = ((_d[3] >> 2) & (0x01U));
  _m->IG_IMC_STATUS_EXT_03_Flash = ((_d[3] >> 3) & (0x01U));
  _m->IG_IMC_STATUS_EXT_04_RAM = ((_d[3] >> 4) & (0x01U));
  _m->IG_IMC_STATUS_EXT_05_Stack = ((_d[3] >> 5) & (0x01U));
  _m->IG_IMC_STATUS_EXT_06_Reserved = ((_d[3] >> 6) & (0x01U));
  _m->IG_IMC_STATUS_EXT_07_Parameter = ((_d[3] >> 7) & (0x01U));
  _m->IG_IMC_R_ISO_CNT = (_d[4] & (0xFFU));
  _m->IG_IMC_STATUS_EXT_08_TestPulse = (_d[4] & (0x01U));
  _m->IG_VIFC_VERSION_MAJ = (_d[4] & (0xFFU));
  _m->IG_IMC_VERSION_MAJ = (_d[4] & (0xFFU));
  _m->IG_IMC_STATUS_EXT_09_12V_POS = ((_d[4] >> 1) & (0x01U));
  _m->IG_IMC_STATUS_EXT_10_12V_NEG = ((_d[4] >> 2) & (0x01U));
  _m->IG_IMC_STATUS_EXT_11_FuseBits = ((_d[4] >> 3) & (0x01U));
  _m->IG_IMC_STATUS_EXT_12_HV1 = ((_d[4] >> 4) & (0x01U));
  _m->IG_IMC_STATUS_EXT_13_HV2 = ((_d[4] >> 5) & (0x01U));
  _m->IG_IMC_STATUS_EXT_14_IDString = ((_d[4] >> 6) & (0x01U));
  _m->IG_IMC_STATUS_EXT_15_Reserved = ((_d[4] >> 7) & (0x01U));
  return IMD_Response_CANID;
}

uint32_t Pack_IMD_Response_isolation(const IMD_Response_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < IMD_Response_DLC; _d[i++] = 0);

  _d[0] |= (_m->IMD_Response_Command & (0xFFU));
  _d[1] |= (_m->IG_IMC_MANUFACT_INDEX & (0xFFU)) | (_m->IG_VIFC_TEMP & (0xFFU)) | (_m->IG_VIFC_IMC_ALIVE & (0xFFU)) | (_m->IG_VIFC_POWER_MODE & (0xFFU)) | (_m->IC_VIFC_POWER_MODE & (0xFFU)) | (_m->IS_IMC_MEAN_FACTOR & (0xFFU)) | (_m->IS_IMC_EEPROM_INDEX & (0xFFU)) | (_m->IC_IMC_CALIB_STEP & (0xFFU)) | (_m->IS_IMC_R_ISO_WRN_THR & (0xFFU)) | (_m->IS_IMC_R_ISO_ERR_THR & (0xFFU)) | (_m->IC_VIFC_MEASURE_MODE & (0xFFU)) | (_m->IC_VIFC_LOCK_MODE & (0xFFU)) | (_m->IS_VIFC_HV_RELAIS & (0xFFU)) | (_m->IG_IMC_EEPROM_INDEX & (0xFFU)) | (_m->IG_IMC_MEAN_FACTOR & (0xFFU)) | (_m->IG_VIFC_LOCK_MODE & (0xFFU)) | (_m->IG_VIFC_STATUS_00_IsoMeasurement & (0x01U)) | (_m->IG_VIFC_VERSION_INDEX & (0xFFU)) | (_m->IG_VIFC_HV_RELAIS & (0xFFU)) | (_m->IG_IMC_STATUS_00_IsoFailure & (0x01U)) | (_m->IG_IMD_ERROR_CODE & (0xFFU)) | (_m->IG_IMC_HV_2 & (0xFFU)) | (_m->IG_IMC_HV_1 & (0xFFU)) | (_m->IG_IMC_R_ISO_WRN_THR & (0xFFU)) | (_m->IG_IMC_R_ISO_ERR_THR & (0xFFU)) | (_m->IG_IMC_R_ISO & (0xFFU)) | (_m->IC_IMC_SELFTEST_SCR & (0xFFU)) | (_m->IG_IMC_TEST_CNT & (0xFFU)) | (_m->IG_IMC_VERSION_INDEX & (0xFFU)) | (_m->IMD_Response_DataWord1 & (0xFFU)) | ((_m->IG_VIFC_STATUS_01_IMCConnection & (0x01U)) << 1) | ((_m->IG_IMC_STATUS_01_Ground & (0x01U)) << 1) | ((_m->IG_VIFC_STATUS_02_IMC_Alive & (0x01U)) << 2) | ((_m->IG_IMC_STATUS_02_System & (0x01U)) << 2) | ((_m->IG_IMC_STATUS_03_Calibration & (0x01U)) << 3) | ((_m->IG_IMC_STATUS_04_Selftest & (0x01U)) << 4) | ((_m->IG_IMC_STATUS_05_IsoWarning & (0x01U)) << 5);
  _d[2] |= ((_m->IG_IMC_MANUFACT_INDEX >> 8) & (0xFFU)) | ((_m->IG_VIFC_TEMP >> 8) & (0xFFU)) | ((_m->IG_VIFC_IMC_ALIVE >> 8) & (0xFFU)) | ((_m->IG_VIFC_POWER_MODE >> 8) & (0xFFU)) | ((_m->IC_VIFC_POWER_MODE >> 8) & (0xFFU)) | ((_m->IS_IMC_MEAN_FACTOR >> 8) & (0xFFU)) | ((_m->IS_IMC_EEPROM_INDEX >> 8) & (0xFFU)) | ((_m->IC_IMC_CALIB_STEP >> 8) & (0xFFU)) | ((_m->IS_IMC_R_ISO_WRN_THR >> 8) & (0xFFU)) | ((_m->IS_IMC_R_ISO_ERR_THR >> 8) & (0xFFU)) | ((_m->IC_VIFC_MEASURE_MODE >> 8) & (0xFFU)) | ((_m->IC_VIFC_LOCK_MODE >> 8) & (0xFFU)) | ((_m->IS_VIFC_HV_RELAIS >> 8) & (0xFFU)) | ((_m->IG_IMC_EEPROM_INDEX >> 8) & (0xFFU)) | ((_m->IG_IMC_MEAN_FACTOR >> 8) & (0xFFU)) | ((_m->IG_VIFC_LOCK_MODE >> 8) & (0xFFU)) | ((_m->IG_VIFC_VERSION_INDEX >> 8) & (0xFFU)) | ((_m->IG_VIFC_HV_RELAIS >> 8) & (0xFFU)) | ((_m->IG_IMD_ERROR_CODE >> 8) & (0xFFU)) | ((_m->IG_IMC_HV_2 >> 8) & (0xFFU)) | ((_m->IG_IMC_HV_1 >> 8) & (0xFFU)) | ((_m->IG_IMC_R_ISO_WRN_THR >> 8) & (0xFFU)) | ((_m->IG_IMC_R_ISO_ERR_THR >> 8) & (0xFFU)) | ((_m->IG_IMC_R_ISO >> 8) & (0xFFU)) | ((_m->IC_IMC_SELFTEST_SCR >> 8) & (0xFFU)) | ((_m->IG_IMC_TEST_CNT >> 8) & (0xFFU)) | ((_m->IG_IMC_VERSION_INDEX >> 8) & (0xFFU)) | ((_m->IMD_Response_DataWord1 >> 8) & (0xFFU)) | (_m->IG_VIFC_STATUS_08_Outdated & (0x01U));
  _d[3] |= (_m->IG_VIFC_VERSION_MIN & (0xFFU)) | (_m->IG_IMC_VERSION_MIN & (0xFFU)) | (_m->IG_IMC_MANUFACT_DATA & (0xFFU)) | (_m->IG_IMC_R_ISO_BIAS & (0xFFU)) | (_m->IS_IMC_EEPROM_DATA & (0xFFU)) | (_m->IS_VIFC_HV_RELAIS_STATE & (0xFFU)) | (_m->IG_IMC_EEPROM_DATA & (0xFFU)) | (_m->IG_VIFC_HV_RELAIS_STATE & (0xFFU)) | (_m->IG_IMC_STATUS_EXT_00_Calibration & (0x01U)) | (_m->IG_IMD_FAILED_CMD & (0xFFU)) | (_m->IMD_Response_DataWord2 & (0xFFU)) | ((_m->IG_IMC_STATUS_EXT_01_Hardware & (0x01U)) << 1) | ((_m->IG_IMC_STATUS_EXT_02_EEPROM & (0x01U)) << 2) | ((_m->IG_IMC_STATUS_EXT_03_Flash & (0x01U)) << 3) | ((_m->IG_IMC_STATUS_EXT_04_RAM & (0x01U)) << 4) | ((_m->IG_IMC_STATUS_EXT_05_Stack & (0x01U)) << 5) | ((_m->IG_IMC_STATUS_EXT_06_Reserved & (0x01U)) << 6) | ((_m->IG_IMC_STATUS_EXT_07_Parameter & (0x01U)) << 7);
  _d[4] |= ((_m->IG_IMC_MANUFACT_DATA >> 8) & (0xFFU)) | ((_m->IS_IMC_EEPROM_DATA >> 8) & (0xFFU)) | ((_m->IS_VIFC_HV_RELAIS_STATE >> 8) & (0xFFU)) | ((_m->IG_IMC_EEPROM_DATA >> 8) & (0xFFU)) | ((_m->IG_VIFC_HV_RELAIS_STATE >> 8) & (0xFFU)) | ((_m->IMD_Response_DataWord2 >> 8) & (0xFFU)) | (_m->IG_IMC_R_ISO_CNT & (0xFFU)) | (_m->IG_IMC_STATUS_EXT_08_TestPulse & (0x01U)) | (_m->IG_VIFC_VERSION_MAJ & (0xFFU)) | (_m->IG_IMC_VERSION_MAJ & (0xFFU)) | ((_m->IG_IMC_STATUS_EXT_09_12V_POS & (0x01U)) << 1) | ((_m->IG_IMC_STATUS_EXT_10_12V_NEG & (0x01U)) << 2) | ((_m->IG_IMC_STATUS_EXT_11_FuseBits & (0x01U)) << 3) | ((_m->IG_IMC_STATUS_EXT_12_HV1 & (0x01U)) << 4) | ((_m->IG_IMC_STATUS_EXT_13_HV2 & (0x01U)) << 5) | ((_m->IG_IMC_STATUS_EXT_14_IDString & (0x01U)) << 6) | ((_m->IG_IMC_STATUS_EXT_15_Reserved & (0x01U)) << 7);
  *_len = 5; *_ide = 0;
  return IMD_Response_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_IMD_Info_isolation(IMD_Info_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->II_IMC_R_ISO = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->II_IMC_STATUS_00_IsoFailure = (_d[2] & (0x01U));
  _m->II_IMC_STATUS_01_Ground = ((_d[2] >> 1) & (0x01U));
  _m->II_IMC_STATUS_02_System = ((_d[2] >> 2) & (0x01U));
  _m->II_IMC_STATUS_03_Calibration = ((_d[2] >> 3) & (0x01U));
  _m->II_IMC_STATUS_04_Selftest = ((_d[2] >> 4) & (0x01U));
  _m->II_IMC_STATUS_05_IsoWarning = ((_d[2] >> 5) & (0x01U));
  _m->II_VIFC_STATUS_00_IsoMeasurement = (_d[4] & (0x01U));
  _m->II_VIFC_STATUS_01_IMC_Connection = ((_d[4] >> 1) & (0x01U));
  _m->II_VIFC_STATUS_02_IMC_Alive = ((_d[4] >> 2) & (0x01U));
  _m->II_VIFC_STATUS_08_Outdated = (_d[5] & (0x01U));
  return IMD_Info_CANID;
}

uint32_t Pack_IMD_Info_isolation(const IMD_Info_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < IMD_Info_DLC; _d[i++] = 0);

  _d[0] |= (_m->II_IMC_R_ISO & (0xFFU));
  _d[1] |= ((_m->II_IMC_R_ISO >> 8) & (0xFFU));
  _d[2] |= (_m->II_IMC_STATUS_00_IsoFailure & (0x01U)) | ((_m->II_IMC_STATUS_01_Ground & (0x01U)) << 1) | ((_m->II_IMC_STATUS_02_System & (0x01U)) << 2) | ((_m->II_IMC_STATUS_03_Calibration & (0x01U)) << 3) | ((_m->II_IMC_STATUS_04_Selftest & (0x01U)) << 4) | ((_m->II_IMC_STATUS_05_IsoWarning & (0x01U)) << 5);
  _d[4] |= (_m->II_VIFC_STATUS_00_IsoMeasurement & (0x01U)) | ((_m->II_VIFC_STATUS_01_IMC_Connection & (0x01U)) << 1) | ((_m->II_VIFC_STATUS_02_IMC_Alive & (0x01U)) << 2);
  _d[5] |= (_m->II_VIFC_STATUS_08_Outdated & (0x01U));
  *_len = 6; *_ide = 0;
  return IMD_Info_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_UDS_IMD_FLASH_REQ_isolation(UDS_IMD_FLASH_REQ_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->UDS_IMD_FLASH_REQ_B0 = (_d[0] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B1 = (_d[1] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B2 = (_d[2] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B3 = (_d[3] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B4 = (_d[4] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B5 = (_d[5] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B6 = (_d[6] & (0xFFU));
  _m->UDS_IMD_FLASH_REQ_B7 = (_d[7] & (0xFFU));
  return UDS_IMD_FLASH_REQ_CANID;
}

uint32_t Pack_UDS_IMD_FLASH_REQ_isolation(const UDS_IMD_FLASH_REQ_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < UDS_IMD_FLASH_REQ_DLC; _d[i++] = 0);

  _d[0] |= (_m->UDS_IMD_FLASH_REQ_B0 & (0xFFU));
  _d[1] |= (_m->UDS_IMD_FLASH_REQ_B1 & (0xFFU));
  _d[2] |= (_m->UDS_IMD_FLASH_REQ_B2 & (0xFFU));
  _d[3] |= (_m->UDS_IMD_FLASH_REQ_B3 & (0xFFU));
  _d[4] |= (_m->UDS_IMD_FLASH_REQ_B4 & (0xFFU));
  _d[5] |= (_m->UDS_IMD_FLASH_REQ_B5 & (0xFFU));
  _d[6] |= (_m->UDS_IMD_FLASH_REQ_B6 & (0xFFU));
  _d[7] |= (_m->UDS_IMD_FLASH_REQ_B7 & (0xFFU));
  *_len = 8; *_ide = 0;
  return UDS_IMD_FLASH_REQ_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_UDS_IMD_FLASH_RESP_isolation(UDS_IMD_FLASH_RESP_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->UDS_IMD_FLASH_RESP_B0 = (_d[0] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B1 = (_d[1] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B2 = (_d[2] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B3 = (_d[3] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B4 = (_d[4] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B5 = (_d[5] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B6 = (_d[6] & (0xFFU));
  _m->UDS_IMD_FLASH_RESP_B7 = (_d[7] & (0xFFU));
  return UDS_IMD_FLASH_RESP_CANID;
}

uint32_t Pack_UDS_IMD_FLASH_RESP_isolation(const UDS_IMD_FLASH_RESP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < UDS_IMD_FLASH_RESP_DLC; _d[i++] = 0);

  _d[0] |= (_m->UDS_IMD_FLASH_RESP_B0 & (0xFFU));
  _d[1] |= (_m->UDS_IMD_FLASH_RESP_B1 & (0xFFU));
  _d[2] |= (_m->UDS_IMD_FLASH_RESP_B2 & (0xFFU));
  _d[3] |= (_m->UDS_IMD_FLASH_RESP_B3 & (0xFFU));
  _d[4] |= (_m->UDS_IMD_FLASH_RESP_B4 & (0xFFU));
  _d[5] |= (_m->UDS_IMD_FLASH_RESP_B5 & (0xFFU));
  _d[6] |= (_m->UDS_IMD_FLASH_RESP_B6 & (0xFFU));
  _d[7] |= (_m->UDS_IMD_FLASH_RESP_B7 & (0xFFU));
  *_len = 8; *_ide = 0;
  return UDS_IMD_FLASH_RESP_CANID;
}

