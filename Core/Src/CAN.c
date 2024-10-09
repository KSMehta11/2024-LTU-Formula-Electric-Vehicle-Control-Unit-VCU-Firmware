
/*
 * CAN.c
 *
 *  Created on: Mar 17, 2024
 *      Author: kmehta
 */

#include "CAN.h"

void initializeCAN(CAN_HandleTypeDef* hcan)
{
	if (HAL_CAN_Start(hcan) != HAL_OK)
	{
		Error_Handler();
	}

	configAMSCANFilter(hcan);

	configIMDCANFilter(hcan);

	configInverterRPMCANFilter(hcan);

	configInverterTempCANFilter(hcan);

	configBMSDataFilter(hcan);

	if (HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO1_MSG_PENDING) != HAL_OK)
	{
		Error_Handler();
	}
}

void sendSync(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[1] = { (0x00U) };
	uint32_t mailbox;
	ECU_SYNC_t sync;
	uint8_t len, ide;


	txHeader.DLC = ECU_SYNC_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ECU_SYNC_IDE;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = ECU_SYNC_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	sync.ECU_SYNCH_Counter = (0x00U);

	Pack_ECU_SYNC__DO_QUASAR_CANopen(&sync, data, &len, &ide);

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));
}

void nodeGuarding(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[1] = { (0x00U) };
	uint32_t mailbox;

	txHeader.DLC = ECU_EMD_NMT_node_guarding_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = CAN_ID_STD;
	txHeader.RTR = CAN_RTR_REMOTE;
	txHeader.StdId = ECU_EMD_NMT_node_guarding_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void startNode(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	ECU_NMT_command_t nmt_t;
	uint8_t len, ide;

	nmt_t.ECU_NMT_CommandSpecifier = (0x01U);
	nmt_t.ECU_NMT_NodeId = (0x7AU);

	Pack_ECU_NMT_command__DO_QUASAR_CANopen(&nmt_t, data, &len, &ide);

	txHeader.DLC = ECU_NMT_command_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = ECU_NMT_command_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void clearErrors(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x04U), (0x00U), (0x00U) };
	uint32_t mailbox;
	EMD_RxPDO_3_t rxPDO3;
	uint8_t len, ide;

	rxPDO3.EMD_CMD_ActiveDischarge = 0;
	rxPDO3.EMD_CMD_ClearErrors = (0x01U);
	rxPDO3.EMD_CMD_ControlMode = 0;
	rxPDO3.EMD_CMD_DigitalOutput1 = 0;
	rxPDO3.EMD_CMD_DigitalOutput2 = 0;
	rxPDO3.EMD_CMD_LimitationMode = 0;
	rxPDO3.EMD_CMD_RestartRequest = 0;
	rxPDO3.EMD_CMD_SpeedRefLim = 0;
	rxPDO3.EMD_CMD_SpeedRefLim_VAL = 0;
	rxPDO3.EMD_CMD_TorqueRefLim = 0;
	rxPDO3.EMD_CMD_TorqueRefLim_VAL = 0;
	rxPDO3.EMD_MSGCNT_RxPDO3 = 0;

	Pack_EMD_RxPDO_3__DO_QUASAR_CANopen(&rxPDO3, data, &len, &ide);

	txHeader.DLC = len;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = EMD_RxPDO_3_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void torqueControlMessage(CAN_HandleTypeDef* hcan, int _speedRefLimit, int* _torqueRefLimit)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	EMD_RxPDO_3_t rxPDO3;
	uint8_t len, ide;

	rxPDO3.EMD_CMD_ActiveDischarge = 0;
	rxPDO3.EMD_CMD_ClearErrors = 0;
	rxPDO3.EMD_CMD_ControlMode = (0x01U);
	rxPDO3.EMD_CMD_DigitalOutput1 = 0;
	rxPDO3.EMD_CMD_DigitalOutput2 = 0;
	rxPDO3.EMD_CMD_LimitationMode = 0;
	rxPDO3.EMD_CMD_RestartRequest = 0;
	rxPDO3.EMD_CMD_SpeedRefLim = _speedRefLimit;
	rxPDO3.EMD_CMD_SpeedRefLim_VAL = 0;
	rxPDO3.EMD_CMD_TorqueRefLim = *_torqueRefLimit;
	rxPDO3.EMD_CMD_TorqueRefLim_VAL = 0;
	rxPDO3.EMD_MSGCNT_RxPDO3 = 0;

	Pack_EMD_RxPDO_3__DO_QUASAR_CANopen(&rxPDO3, data, &len, &ide);

	txHeader.DLC = EMD_RxPDO_3_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = EMD_RxPDO_3_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void configAMSCANFilter(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef filter;

	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.FilterBank = 0;
	filter.FilterFIFOAssignment = CAN_LOW_PRIORITY_FIFO;
	filter.FilterIdHigh = ((0x301U)<<5);
	filter.FilterIdLow = (0x000U);
	filter.FilterMaskIdHigh = ((0x301U)<<5);
	filter.FilterMaskIdLow = (0x000U);
	filter.FilterMode = CAN_FILTERMODE_IDMASK;
	filter.FilterScale = CAN_FILTERSCALE_32BIT;
	filter.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &filter) != HAL_OK)
	{
		Error_Handler();
	}
}

void configIMDCANFilter(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef filter;

	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.FilterBank = 1;
	filter.FilterFIFOAssignment = CAN_LOW_PRIORITY_FIFO;
	filter.FilterIdHigh = ((0x007U)<<5);
	filter.FilterIdLow = (0x000U);
	filter.FilterMaskIdHigh = ((0x007U)<<5);
	filter.FilterMaskIdLow = (0x000U);
	filter.FilterMode = CAN_FILTERMODE_IDMASK;
	filter.FilterScale = CAN_FILTERSCALE_32BIT;
	filter.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &filter) != HAL_OK)
	{
		Error_Handler();
	}
}

void configInverterRPMCANFilter(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef filter;

	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.FilterBank = 2;
	filter.FilterFIFOAssignment = CAN_HIGH_PRIORITY_FIFO;
	filter.FilterIdHigh = ((0x3FAU)<<5);
	filter.FilterIdLow = (0x000U);
	filter.FilterMaskIdHigh = ((0x3FAU)<<5);
	filter.FilterMaskIdLow = (0x000U);
	filter.FilterMode = CAN_FILTERMODE_IDLIST;
	filter.FilterScale = CAN_FILTERSCALE_32BIT;
	filter.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &filter) != HAL_OK)
	{
		Error_Handler();
	}
}

void configInverterTempCANFilter(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef filter;

	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.FilterBank = 3;
	filter.FilterFIFOAssignment = CAN_LOW_PRIORITY_FIFO;
	filter.FilterIdHigh = ((0xBAU)<<5);
	filter.FilterIdLow = (0x000U);
	filter.FilterMaskIdHigh = ((0x0BAU)<<5);
	filter.FilterMaskIdLow = (0x000U);
	filter.FilterMode = CAN_FILTERMODE_IDMASK;
	filter.FilterScale = CAN_FILTERSCALE_32BIT;
	filter.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &filter) != HAL_OK)
	{
		Error_Handler();
	}
}

void configBMSDataFilter(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef filter;

	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.FilterBank = 4;
	filter.FilterFIFOAssignment = CAN_HIGH_PRIORITY_FIFO;
	filter.FilterIdHigh = ((0x6B0U)<<5);
	filter.FilterIdLow = (0x000U);
	filter.FilterMaskIdHigh = ((0x6B0U)<<5);
	filter.FilterMaskIdLow = (0x000U);
	filter.FilterMode = CAN_FILTERMODE_IDLIST;
	filter.FilterScale = CAN_FILTERSCALE_32BIT;
	filter.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &filter) != HAL_OK)
	{
		Error_Handler();
	}
}

void sendTPSLimits(CAN_HandleTypeDef* hcan, VCU_TPS_Limits_t* _tpsLimits)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	uint8_t len, ide;

	Pack_VCU_TPS_Limits_TPS(_tpsLimits, data, &len, &ide);

	txHeader.DLC = VCU_TPS_Limits_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = VCU_TPS_Limits_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void sendTPSCurrentValue(CAN_HandleTypeDef* hcan, VCU_TPS_CurrentValue_t* _tpsCurrentVal)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[4] = { (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	uint8_t len, ide;

	Pack_VCU_TPS_CurrentValue_TPS(_tpsCurrentVal, data, &len, &ide);

	txHeader.DLC = VCU_TPS_CurrentValue_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = VCU_TPS_CurrentValue_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}
