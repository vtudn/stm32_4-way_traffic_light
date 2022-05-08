/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "timer.h"
#include "7segclock.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
/*  // exercise 5
  uint8_t hour = 15, minute = 8, second = 50;*/

/*  // exercise 6
  setTimer0(10);*/

  // exercise 7 & 8
  uint8_t index_clk = 0;
  uint8_t hour = 15, minute = 8, second = 50;
  Buffer_Update_7seg(0, hour/10);
  Buffer_Update_7seg(1, hour%10);
  Buffer_Update_7seg(2, minute/10);
  Buffer_Update_7seg(3, minute%10);
  timer_set(0, 10);
  timer_set(1, 10);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
/*	  // exercise 5
	  second++;
	  if (second >= 60) {
	  	second = 0;
	  	minute++;
	  }
	  if (minute >= 60) {
	  	minute = 0;
	 		hour++;
	  }
	  if (hour >= 24) {
	  	hour = 0;
	  }
	  // update hour
	  Buffer_Update_7seg(0, hour/10);
	  Driver_7seg(0);
	  HAL_Delay(100);
	  Buffer_Update_7seg(1, hour%10);
	  Driver_7seg(1);
	  HAL_Delay(100);

	  // update minute
	  Buffer_Update_7seg(2, minute/10);
	  Driver_7seg(2);
	  HAL_Delay(100);
	  Buffer_Update_7seg(3, minute%10);
	  Driver_7seg(3);
	  HAL_Delay(100);

	  // halt
	  Buffer_Update_7seg(4, 99);
	  HAL_Delay(100);

	  HAL_Delay(500);*/

/*	  // exercise 6
	  if (timer0_flag == 1){
		  HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
		  setTimer0(2000);
	  }*/

	  // exercise 7 & 8
	  if (timer_flag[0] == 1){
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		  second++;
		  if (second >= 60) {
		  	second = 0;
		  	minute++;
		  }
		  if (minute >= 60) {
		  	minute = 0;
		 		hour++;
		  }
		  if (hour >= 24) {
		  	hour = 0;
		  }
		  // update hour & minute
		  Buffer_Update_7seg(0, hour/10);
		  Buffer_Update_7seg(1, hour%10);
		  Buffer_Update_7seg(2, minute/10);
		  Buffer_Update_7seg(3, minute%10);
		  // delay
		  timer_set(0, 1000);
	  }

	  if (timer_flag[1] == 1){
		  // display
		  Driver_7seg(index_clk++);
		  if (index_clk > 3) index_clk = 0;
		  // delay
		  timer_set(1, 250);
	  }
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 8000 - 1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10 - 1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|RED_LED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                          |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin RED_LED_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|RED_LED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin SEG3_Pin
                           SEG4_Pin SEG5_Pin SEG6_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                          |SEG4_Pin|SEG5_Pin|SEG6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/*// test
int counter = 1;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	if (counter <= 0){
		counter = 1;
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
	}
}*/

/*// exercise 1
uint8_t led_cnt = 50;
uint8_t cnt = 50;
uint8_t sw_clk = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	led_cnt--;
	cnt--;
	if (led_cnt == 0){
		led_cnt = 50;
		HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
	}
	if (cnt == 0){
		cnt = 50;
		Buffer_Update_7seg(sw_clk, sw_clk + 1);
		Driver_7seg(sw_clk++);
		if (sw_clk == 2) sw_clk = 0;
	}
}*/

/*// exercise 2
uint8_t led_cnt = 100;
uint8_t cnt = 50;
uint8_t sw_clk = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	led_cnt--;
	cnt--;
	if (led_cnt == 0){
		led_cnt = 100;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	if (cnt == 0){
		cnt = 50;
		if (sw_clk == 0) {
			Buffer_Update_7seg(sw_clk, 1);
			Driver_7seg(sw_clk);
		}
		if (sw_clk == 1) {
			Buffer_Update_7seg(sw_clk, 2);
			Driver_7seg(sw_clk);
		}
		if (sw_clk == 2) {
			Buffer_Update_7seg(sw_clk, 3);
			Driver_7seg(sw_clk);
		}
		if (sw_clk == 3) {
			Buffer_Update_7seg(sw_clk, 0);
			Driver_7seg(sw_clk);
		}
		sw_clk++;
		if (sw_clk == 4) sw_clk = 0;
	}
}*/

/*// exercise 3
uint8_t led_cnt = 100;
uint8_t cnt = 50;
uint8_t sw_clk = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	led_cnt--;
	cnt--;
	if (led_cnt == 0){
		led_cnt = 100;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	if (cnt == 0){
		cnt = 50;
		Buffer_Update_7seg(sw_clk, sw_clk + 1);
		Driver_7seg(sw_clk++);
		if (sw_clk == 4) sw_clk = 0;
	}
}*/

/*// exercise 4
uint8_t led_cnt = 100;
uint8_t cnt = 25;
uint8_t sw_clk = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	led_cnt--;
	cnt--;
	if (led_cnt == 0){
		led_cnt = 100;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	if (cnt == 0){
		cnt = 25;
		Buffer_Update_7seg(sw_clk, sw_clk + 1);
		Driver_7seg(sw_clk++);
		if (sw_clk == 4) sw_clk = 0;
	}
}*/

// exercise 5 (in the while loop)

// exercise 6, 7 & 8 (timer.c & timer.h)

/* USER CODE END 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
