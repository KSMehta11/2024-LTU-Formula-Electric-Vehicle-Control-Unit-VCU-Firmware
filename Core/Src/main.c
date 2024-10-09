/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "CAN.h"
#include "string.h"
#include "isolation.h"
#include "temp.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

// Creates a boolean variable type
typedef enum
{

	true = 1,
	false = 0

} bool;

// Creates a CAN message typedef for queue
typedef struct
{
	uint8_t data[8];
	uint32_t StdID;
	uint32_t RTR;

} CAN_MsgHeaderTypedef;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define IGNITION_BUTTON_THRESHOLD 200
#define THROTTLE_DEVIATION_THRESHOLD 10

#define ADC_SAMPLE_COUNT 15
#define ADC_MAX_LIMIT 1023
#define ADC_MIN_LIMIT 0

#define NODE_GUARDING_PERIOD 100
#define TORQUE_CONTROL_PERIOD 10
#define SYNC_PERIOD 150

#define CAN_HIGH_PRIORITY_FIFO CAN_FILTER_FIFO1
#define CAN_LOW_PRIORITY_FIFO CAN_FilterFIFO0

#define INVERTER_TEMP_THRESHOLD 20

#define BMS_CAN_ID (0x6B0U)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim8;

/* USER CODE BEGIN PV */

/******************** GPIO Pin Definitions ********************/
// CAN Fault
GPIO_TypeDef* CAN_FAULT_PORT = GPIOA;
const uint16_t CAN_FAULT_PIN = GPIO_PIN_4;
GPIO_TypeDef* TEMP_SENSE_CAN_FAULT_PORT = GPIOA;
const uint16_t TEMP_SENSE_CAN_FAULT_PIN = GPIO_PIN_5;
const GPIO_PinState NO_FAULT_STATE = GPIO_PIN_SET;
const GPIO_PinState FAULT_STATE = GPIO_PIN_RESET;

// CAN Transreceiver
GPIO_TypeDef* CAN_ENABLE_1_PORT = GPIOA;
const uint16_t CAN_ENABLE_1_PIN = GPIO_PIN_10;
const GPIO_PinState CAN_ENABLE = GPIO_PIN_RESET;
const GPIO_PinState CAN_DISABLE = GPIO_PIN_SET;

// Ready to Drive(RTD) Speaker
GPIO_TypeDef* RTD_PIN_PORT = GPIOB;
const uint16_t RTD_PIN = GPIO_PIN_15;
const GPIO_PinState RTD_ACTIVE = GPIO_PIN_SET;
const GPIO_PinState RTD_DISABLE = GPIO_PIN_RESET;

// Ignition
GPIO_TypeDef* IGNITION_PORT = GPIOD;
const uint16_t IGNITION_PIN = GPIO_PIN_10;
const GPIO_PinState IGNITION_ACTIVE = GPIO_PIN_RESET;
const GPIO_PinState IGNITION_INACTIVE = GPIO_PIN_SET;
GPIO_TypeDef* IGNITION_ENABLE_PORT = GPIOA;
const uint16_t IGNITION_ENABLE_PIN = GPIO_PIN_6;
const GPIO_PinState IGNITION_ACTIVE_STATE = GPIO_PIN_RESET;

/******************** Timer Definitions ********************/
TIM_HandleTypeDef* OUTPUT_CAPTURE = &htim1;
const uint32_t IGNITION_OUPUT_CAPTURE = TIM_CHANNEL_1;

/******************** Ignition ********************/
GPIO_PinState buttonState, lastButtonState = IGNITION_INACTIVE;
bool enableCar = false;
unsigned long buttonPressTime = 0;

/******************** Torque Control ********************/
static ADC_ChannelConfTypeDef sConfig;
const uint32_t PRIMARY_THROTTLE_CHANNEL = ADC_CHANNEL_0;
const uint32_t SECONDARY_THROTTLE_CHANNEL = ADC_CHANNEL_1;
const uint32_t PRIMARY_BRAKE_CHANNEL = ADC_CHANNEL_2;
const uint32_t SECONDARY_BRAKE_CHANNEL = ADC_CHANNEL_3;

int max = 0, min = 0;
int maxIndex = 0, minIndex = 0;
uint32_t adcBuffer[ADC_SAMPLE_COUNT] = { 0 };
uint32_t sum = 0, average = 0;

int percentageDeviation = 0;

uint32_t primaryPotValue = 0, secondaryPotValue = 0;
int torqueRefLimit = 5000;

const int SPEED_REF_LIMIT = (6500 + 32768); // RPM' = (Actual RPM + 32768)

// Obtained from throttle mapping (Should be tuned for the system being used)
const uint32_t PRIMARY_THROTTLE_POSITION_MAX = 635;
const uint32_t PRIMARY_THROTTLE_POSITION_MIN = 570;

const uint32_t SECONDARY_THROTTLE_POSITION_MAX = 320;
const uint32_t SECONDARY_THROTTLE_POSITION_MIN = 145;

const uint32_t PRIMARY_THROTTLE_RANGE_MAX = 750;
const uint32_t PRIMARY_THROTTLE_RANGE_MIN = 500;

const uint32_t SECONDARY_THROTTLE_RANGE_MAX = 400;
const uint32_t SECONDARY_THROTTLE_RANGE_MIN = 100;
// Obtained from throttle mapping

// Obtained from brake pedal mapping (Should be tuned for the system being used)
const uint32_t PRIMARY_BRAKE_POSITION_MAX = 1023;
const uint32_t PRIMARY_BRAKE_POSITION_MIN = 0;

const uint32_t SECONDARY_BRAKE_POSITION_MAX = 1023;
const uint32_t SECONDARY_BRAKE_POSITION_MIN = 0;

const uint32_t PRIMARY_BRAKE_RANGE_MAX = 1023;
const uint32_t PRIMARY_BRAKE_RANGE_MIN = 0;

const uint32_t SECONDARY_BRAKE_RANGE_MAX = 1023;
const uint32_t SECONDARY_BRAKE_RANGE_MIN = 0;
// Obtained from brake pedal mapping

// Motor Torque Limits
const int TORQUE_REF_LIMIT_MAX = 8750; // Torque' = (%Torque + 100) / 0.02 Eg. (90%+100) / 0.02 = 9500
const int TORQUE_REF_LIMIT_MIN = 5000; // Torque' = (0 + 100) / 0.02 = 5000

/******************** Error Detection ********************/
bool errorSet[5] = { false };

/******************** IMD Data ********************/
IMD_Info_t imdInfo;

/******************** Temp Sense Data ********************/
TS_ECU1_TX1_t ecu1TX1;
TS_ECU2_TX1_t ecu2TX1;
TS_ECU3_TX1_t ecu3TX1;
TS_ECU4_TX1_t ecu4TX1;
TS_ECU5_TX1_t ecu5TX1;

/******************** Inverter and Motor Data ********************/
EMD_TxPDO_3_t txpdo_3;
EMD_TxPDO_5_t txpdo_5;
int motorRpm = 0;
int motorTemp = 0, inverterTemp = 0;

/******************** TPS Data ********************/
VCU_TPS_CurrentValue_t tpsCurrentValues;
VCU_TPS_Limits_t tpsLimits;

/******************** BMS Data ********************/
int packSOC = 0;

// Index for error set array
const int PRIM_THROTTLE_SENS_ERR = 0;
const int SECOND_THROTTLE_SENS_ERR = 1;
const int THROTTLE_OFFSET_ERROR = 2;
const int PRIMARY_BRK_SENS_ERROR = 3;
const int SECONDARY_BRK_SENS_ERROR = 4;

/******************** Ready to Drive Detection ********************/
bool readyToIgnition = false;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_CAN1_Init(void);
static void MX_CAN2_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM8_Init(void);
/* USER CODE BEGIN PFP */

/******************** Task Handler Initializations ********************/
void vApplicationIdleHook(void);
void Task1_Handler(void* pvParameters);
void Task2_Handler(void* pvParameters);
void Task3_Handler(void* pvParameters);
void Task4_Handler(void* pvParameters);
void Task5_Handler(void* pvParameters);
void Task6_Handler(void* pvParameters);

/******************** Function Initializations ********************/

// Used to map throttle position
long map(long x, long in_min, long in_max, long out_min, long out_max);

// General Purpose constrain function
long constrain(long x, long out_min, long out_max);

// Handle Vehicle Ignition
void ignitionTask();

// Handles ADC Channel Selection
void setADCChannel(ADC_ChannelConfTypeDef* adcChConfig, uint32_t adcChannel);

// Returns the ADC dynamic averaging value (Eliminates induced noise and spikes in signal)
uint32_t getADCAverage(ADC_ChannelConfTypeDef* adcChConfig, uint32_t adcChannel);
uint32_t getPrimaryThrottlePosition(ADC_ChannelConfTypeDef* adcChConfig);
uint32_t getSecondaryThrottlePosition(ADC_ChannelConfTypeDef* adcChConfig);

// Checks for throttle position range/short-to-ground/open-circuit errors
bool primaryThrottleSensorErrorCheck();
bool secondaryThrottleSensorErrorCheck();

// Checks if both sensors are within a threshold range of each other
bool throttleSensorDeviationCheck();

// Requests Torque from the inverter
void torqueRequest(void);


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// Task Error
BaseType_t xReturned;

// Task Handles
TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;
TaskHandle_t task3Handle = NULL;
TaskHandle_t task4Handle = NULL;
TaskHandle_t task5Handle = NULL;
TaskHandle_t task6Handle = NULL;

// Queue Handlers
QueueHandle_t lowPriorityQueue;
QueueHandle_t highPriorityQueue;

// Software Timer Handlers
TimerHandle_t xTimer;

// RTD Speaker ISR
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED(htim);

	HAL_GPIO_WritePin(RTD_PIN_PORT, RTD_PIN, RTD_DISABLE);

	HAL_TIM_OC_Stop_IT(&htim1, IGNITION_OUPUT_CAPTURE);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_OC_DelayElapsedCallback could be implemented in the user file
   */
}

// CAN ISR
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED(hcan);

	CAN_RxHeaderTypeDef rxHeaderFIFO0;
	uint8_t dataFIFO0[8];
	CAN_MsgHeaderTypedef msgFIFO0;

	if (hcan->Instance == CAN1)
	{
		if (HAL_CAN_GetRxMessage(hcan, CAN_LOW_PRIORITY_FIFO, &rxHeaderFIFO0, dataFIFO0) == HAL_OK)
		{
			msgFIFO0.StdID = rxHeaderFIFO0.StdId;
			msgFIFO0.RTR = rxHeaderFIFO0.RTR;

			memcpy(msgFIFO0.data, dataFIFO0, 8);

			BaseType_t xHigherPriorityTaskWoken = pdFALSE;
			xQueueSendFromISR(lowPriorityQueue, &msgFIFO0, &xHigherPriorityTaskWoken);
			portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
	}

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_CAN_RxFifo0MsgPendingCallback could be implemented in the
            user file
   */
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED(hcan);

	CAN_RxHeaderTypeDef rxHeaderFIFO1;
	uint8_t dataFIFO1[8];
	CAN_MsgHeaderTypedef msgFIFO1;

	if (hcan->Instance == CAN1)
	{
		if (HAL_CAN_GetRxMessage(hcan, CAN_HIGH_PRIORITY_FIFO, &rxHeaderFIFO1, dataFIFO1) == HAL_OK)
		{
			msgFIFO1.StdID = rxHeaderFIFO1.StdId;
			msgFIFO1.RTR = rxHeaderFIFO1.RTR;

			memcpy(msgFIFO1.data, dataFIFO1, 8);

			BaseType_t xHigherPriorityTaskWoken = pdFALSE;
			xQueueSendFromISR(highPriorityQueue, &msgFIFO1, &xHigherPriorityTaskWoken);
			portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
	}

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_CAN_RxFifo1MsgPendingCallback could be implemented in the
            user file
   */
}

/***************************** Timer Callback Request Inverter Data *****************************/
void vTimerCallback(xTimerHandle xTimer)
{
	// Inverter Sync Message
	sendSync(&hcan1);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_CAN1_Init();
  MX_CAN2_Init();
  MX_TIM1_Init();
  MX_TIM8_Init();
  /* USER CODE BEGIN 2 */

  // Initialize tps limits
  tpsLimits.TPS_PrimaryMaxLimit = PRIMARY_THROTTLE_POSITION_MAX;
  tpsLimits.TPS_PrimaryMinLimit = PRIMARY_THROTTLE_POSITION_MIN;
  tpsLimits.TPS_SecondaryMaxLimit = SECONDARY_THROTTLE_POSITION_MAX;
  tpsLimits.TPS_SecondaryMinLimit = SECONDARY_THROTTLE_POSITION_MIN;

  // Initialize CAN1
  initializeCAN(&hcan1);

  // CAN FAULT State -> Good
  HAL_GPIO_WritePin(CAN_FAULT_PORT, CAN_FAULT_PIN, NO_FAULT_STATE);

  HAL_GPIO_WritePin(TEMP_SENSE_CAN_FAULT_PORT, TEMP_SENSE_CAN_FAULT_PIN, NO_FAULT_STATE);

  // Enable CAN 1 Transreceiver
  HAL_GPIO_WritePin(CAN_ENABLE_1_PORT, CAN_ENABLE_1_PIN, CAN_ENABLE);

  // TPS Limits Message
  sendTPSLimits(&hcan1, &tpsLimits);

  /***************************** Queue Creation *****************************/

  lowPriorityQueue = xQueueCreate(7, sizeof(CAN_MsgHeaderTypedef));

  if (lowPriorityQueue == NULL)
  {
	  Error_Handler();
  }

  highPriorityQueue = xQueueCreate(2, sizeof(CAN_MsgHeaderTypedef));

  if (highPriorityQueue == NULL)
  {
	  Error_Handler();
  }

  /***************************** Timer Creation *****************************/
  xTimer = xTimerCreate("Sync_Timer", pdMS_TO_TICKS(SYNC_PERIOD), pdTRUE, (void*)0, vTimerCallback);

  xTimerStart(xTimer, 0);

  /***************************** Task Creation *****************************/

  xReturned = xTaskCreate(Task1_Handler, "Node_Guarding", 200, NULL, tskIDLE_PRIORITY + 3, &task1Handle);
  configASSERT(xReturned == pdPASS);

  xReturned = xTaskCreate(Task2_Handler, "Torque_Control", 200, NULL, tskIDLE_PRIORITY + 2, &task2Handle);
  configASSERT(xReturned == pdPASS);

  xReturned = xTaskCreate(Task3_Handler, "Ignition", 200, NULL, tskIDLE_PRIORITY + 1, &task3Handle);
  configASSERT(xReturned == pdPASS);

  xReturned = xTaskCreate(Task4_Handler, "Process_CAN_Data", 200, NULL, tskIDLE_PRIORITY + 1, &task4Handle);
  configASSERT(xReturned == pdPASS);

  xReturned = xTaskCreate(Task5_Handler, "Safety_System_Check", 200, NULL, tskIDLE_PRIORITY + 1, &task5Handle);
  configASSERT(xReturned == pdPASS);

  xReturned = xTaskCreate(Task6_Handler, "Torque_Derate", 200, NULL, tskIDLE_PRIORITY + 1, &task6Handle);
  configASSERT(xReturned == pdPASS);

  vTaskStartScheduler();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
  hadc1.Init.Resolution = ADC_RESOLUTION_10B;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 4;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 5;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_15TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CAN2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */

  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 5;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_15TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = DISABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */

  /* USER CODE END CAN2_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 18000-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 10000-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_OC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  sConfigOC.Pulse = 10000-1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_OC_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM8 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM8_Init(void)
{

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 36-1;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 100-1;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */
  HAL_TIM_MspPostInit(&htim8);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 PA5 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PD10 */
  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC9 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/***************************** Idle Task *****************************/
void vApplicationIdleHook(void)
{

}

/***************************** Node Guarding Task *****************************/
void Task1_Handler(void* pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = NODE_GUARDING_PERIOD;

	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		// Suspend task until period
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

		// Inverter Node Guarding Frame
		nodeGuarding(&hcan1);
	}
}

/***************************** Torque Control Task *****************************/
void Task2_Handler(void* pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = TORQUE_CONTROL_PERIOD;

	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		// Suspend task until period
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

		// Throttle Sensor Error Checks
		errorSet[PRIM_THROTTLE_SENS_ERR] = primaryThrottleSensorErrorCheck();

		errorSet[SECOND_THROTTLE_SENS_ERR] = secondaryThrottleSensorErrorCheck();

		errorSet[THROTTLE_OFFSET_ERROR] = throttleSensorDeviationCheck();

		// Torque Request
		torqueRequest();
	}
}

/***************************** Ignition Task *****************************/
void Task3_Handler(void* pvParameters)
{
	for (;;)
	{
		if (HAL_GPIO_ReadPin(IGNITION_ENABLE_PORT, IGNITION_ENABLE_PIN) == IGNITION_ACTIVE_STATE)
		{
			ignitionTask();
		}
	}
}

/***************************** CAN Data Processing Task *****************************/
void Task4_Handler(void* pvParameters)
{
	CAN_MsgHeaderTypedef msg;

	for (;;)
	{
		// Get Low Priority CAN Queue Data
		if (xQueueReceive(lowPriorityQueue, &msg, portMAX_DELAY) == pdPASS)
		{
			switch (msg.StdID)
			{
			case IMD_Info_CANID:
				Unpack_IMD_Info_isolation(&imdInfo, msg.data, IMD_Info_DLC);
				break;
			case TS_ECU1_TX1_CANID:
				Unpack_TS_ECU1_TX1_Temp(&ecu1TX1, msg.data, TS_ECU1_TX1_DLC);
				break;
			case TS_ECU2_TX1_CANID:
				Unpack_TS_ECU2_TX1_Temp(&ecu2TX1, msg.data, TS_ECU2_TX1_DLC);
				break;
			case TS_ECU3_TX1_CANID:
				Unpack_TS_ECU3_TX1_Temp(&ecu3TX1, msg.data, TS_ECU3_TX1_DLC);
				break;
			case TS_ECU4_TX1_CANID:
				Unpack_TS_ECU4_TX1_Temp(&ecu4TX1, msg.data, TS_ECU4_TX1_DLC);
				break;
			case TS_ECU5_TX1_CANID:
				Unpack_TS_ECU5_TX1_Temp(&ecu5TX1, msg.data, TS_ECU5_TX1_DLC);
				break;
			case EMD_TxPDO_5_CANID:
				Unpack_EMD_TxPDO_5__DO_QUASAR_CANopen(&txpdo_5, msg.data, EMD_TxPDO_3_DLC);
				break;
			default:
				break;
			}
		}
	}
}

/***************************** Safety Systems Check *****************************/
void Task5_Handler(void* pvParameters)
{
	for (;;)
	{
		motorTemp = txpdo_5.EMD_ACT_MotorTemperature;

		inverterTemp = txpdo_5.EMD_ACT_MaxJunctionTemp;

		if (inverterTemp > INVERTER_TEMP_THRESHOLD)
		{
		  // Enable Pump PWM
		  TIM8->CCR3 = 0;

		  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
		}
		else
		{
		  // Enable Pump PWM
		  TIM8->CCR3 = 0;

		  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
		}
	}
}

/***************************** Torque Derate *****************************/
void Task6_Handler(void* pvParameters)
{
	CAN_MsgHeaderTypedef msg;

	for (;;)
	{
		// Get Inverter Data
		if (xQueueReceive(highPriorityQueue, &msg, 100) == pdPASS)
		{
			switch(msg.StdID)
			{
			case EMD_TxPDO_3_CANID:
				Unpack_EMD_TxPDO_3__DO_QUASAR_CANopen(&txpdo_3, msg.data, EMD_TxPDO_3_DLC);

				motorRpm = txpdo_3.EMD_ACT_MotorSpeed;
				break;
			case BMS_CAN_ID:
				packSOC = (int)(msg.data[4] / 2);
				break;
			default:
				break;
			}
		}
	}
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

long constrain(long x, long out_min, long out_max)
{
	if (x < out_min)
	{
		return out_min;
	}

	if (x > out_max)
	{
		return out_max;
	}

	return x;
}

void ignitionTask(void)
{
	buttonState = HAL_GPIO_ReadPin(IGNITION_PORT, IGNITION_PIN);

	buttonPressTime = HAL_GetTick();

	while (buttonState == IGNITION_ACTIVE)
	{
		if (HAL_GetTick() - buttonPressTime > IGNITION_BUTTON_THRESHOLD)
		{
			startNode(&hcan1);
			clearErrors(&hcan1);

			HAL_GPIO_WritePin(RTD_PIN_PORT, RTD_PIN, RTD_ACTIVE);

			TIM1->CNT = 0;
			HAL_TIM_OC_Start_IT(&htim1, IGNITION_OUPUT_CAPTURE);

			enableCar = true;

			buttonPressTime = HAL_GetTick();
		}

		buttonState = HAL_GPIO_ReadPin(IGNITION_PORT, IGNITION_PIN);
	}

	return;
}

void setADCChannel(ADC_ChannelConfTypeDef* adcChConfig, uint32_t adcChannel)
{
	adcChConfig->Channel = adcChannel;
	adcChConfig->Rank = ADC_REGULAR_RANK_1;
	adcChConfig->SamplingTime = ADC_SAMPLETIME_56CYCLES;

	if (HAL_ADC_ConfigChannel(&hadc1, adcChConfig) != HAL_OK)
	{
		Error_Handler();
	}

	return;
}

uint32_t getADCAverage(ADC_ChannelConfTypeDef* adcChConfig, uint32_t adcChannel)
{
	setADCChannel(adcChConfig, adcChannel);

	sum = 0;

	for (int i = 0; i < ADC_SAMPLE_COUNT; i++)
	{
		HAL_ADC_Start(&hadc1);

		HAL_ADC_PollForConversion(&hadc1, (1U));

		adcBuffer[i] = HAL_ADC_GetValue(&hadc1);

		HAL_ADC_Stop(&hadc1);
	}

	max = adcBuffer[0];

	for (int i = 1; i < ADC_SAMPLE_COUNT; i++)
	{
		if (adcBuffer[i] > max)
		{
			max = adcBuffer[i];
			maxIndex = i;
		}
	}

	min = adcBuffer[0];

	for (int i = 1; i < ADC_SAMPLE_COUNT; i++)
	{
		if (adcBuffer[i] < min)
		{
			min = adcBuffer[i];
			minIndex = i;
		}
	}

	for (int i = 0; i < ADC_SAMPLE_COUNT; i++)
	{
		if (i == minIndex || i == maxIndex)
		{
			sum += 0;
		}
		else
		{
			sum += adcBuffer[i];
		}
	}

	average = sum / (ADC_SAMPLE_COUNT - 2);

	adcBuffer[maxIndex] = average;

	adcBuffer[minIndex] = average;

	sum = 0;

	for (int i = 0; i < ADC_SAMPLE_COUNT; i++)
	{
		sum += adcBuffer[i];
	}

	average = sum / ADC_SAMPLE_COUNT;

	return average;
}

uint32_t getPrimaryThrottlePosition(ADC_ChannelConfTypeDef* adcChConfig)
{
	return constrain(getADCAverage(adcChConfig, PRIMARY_THROTTLE_CHANNEL), ADC_MIN_LIMIT, ADC_MAX_LIMIT);
}

uint32_t getSecondaryThrottlePosition(ADC_ChannelConfTypeDef* adcChConfig)
{
	return constrain(getADCAverage(adcChConfig, SECONDARY_THROTTLE_CHANNEL), ADC_MIN_LIMIT, ADC_MAX_LIMIT);
}

bool primaryThrottleSensorErrorCheck()
{
	primaryPotValue = getPrimaryThrottlePosition(&sConfig);

	if (primaryPotValue <= PRIMARY_THROTTLE_RANGE_MIN || primaryPotValue >= PRIMARY_THROTTLE_RANGE_MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool secondaryThrottleSensorErrorCheck()
{
	secondaryPotValue = getSecondaryThrottlePosition(&sConfig);

	tpsCurrentValues.TPS_SecondaryCurrentVal = secondaryPotValue;

	if (secondaryPotValue <= SECONDARY_THROTTLE_RANGE_MIN || secondaryPotValue >= SECONDARY_THROTTLE_RANGE_MAX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool throttleSensorDeviationCheck()
{
	if (errorSet[PRIM_THROTTLE_SENS_ERR] == true || errorSet[SECOND_THROTTLE_SENS_ERR] == true)
	{
		return false;
	}
	else
	{
		primaryPotValue = getPrimaryThrottlePosition(&sConfig);

		secondaryPotValue = getSecondaryThrottlePosition(&sConfig);

		if (primaryPotValue == 0 || secondaryPotValue == 0)
		{
			percentageDeviation = 0;

			return true;
		}
		else
		{
			if (primaryPotValue > secondaryPotValue)
			{
				percentageDeviation = (((primaryPotValue - secondaryPotValue) / (float)primaryPotValue) * 100);
			}
			else if (secondaryPotValue > primaryPotValue)
			{
				percentageDeviation = (((secondaryPotValue - primaryPotValue) / (float)secondaryPotValue) * 100);
			}
			else
			{
				percentageDeviation = 0;
			}
		}

		if (percentageDeviation > THROTTLE_DEVIATION_THRESHOLD)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void torqueRequest(void)
{
	if (errorSet[PRIM_THROTTLE_SENS_ERR] == true || errorSet[SECOND_THROTTLE_SENS_ERR] == true || errorSet[THROTTLE_OFFSET_ERROR] == true)
	{
		torqueRefLimit = 5000;
	}
	else
	{
		primaryPotValue = getPrimaryThrottlePosition(&sConfig);

		torqueRefLimit = map(primaryPotValue, PRIMARY_THROTTLE_POSITION_MIN, PRIMARY_THROTTLE_POSITION_MAX, TORQUE_REF_LIMIT_MIN, TORQUE_REF_LIMIT_MAX);

		torqueRefLimit = constrain(torqueRefLimit, TORQUE_REF_LIMIT_MIN, TORQUE_REF_LIMIT_MAX);

		tpsCurrentValues.TPS_PrimaryCurrentVal = primaryPotValue;
	}

	torqueControlMessage(&hcan1, SPEED_REF_LIMIT, &torqueRefLimit);

	sendTPSCurrentValue(&hcan1, &tpsCurrentValues);

	return;
}


/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  HAL_GPIO_WritePin(CAN_FAULT_PORT, CAN_FAULT_PIN, FAULT_STATE);
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
