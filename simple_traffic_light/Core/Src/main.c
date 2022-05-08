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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*// for exercise 4
uint8_t counter = 0;*/

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
  /* USER CODE BEGIN 2 */
/*  uint8_t counter = 0;*/
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
/*	  // sample
	  HAL_GPIO_TogglePin(RED_LED_GPIO_Port, RED_LED_Pin);
	  HAL_Delay(1000);*/

/*	  // exercise 1
	  // 1
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_Delay(2000);
	  // 2
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET);
	  HAL_Delay(2000);*/

/*	  // exercise 2
	  // 1
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	  HAL_Delay(5000);
	  // 2
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	  HAL_Delay(2000);
	  // 3
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);
	  HAL_Delay(3000);*/

/*	  // exercise 3
	  // 1
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	  // 1.2
	  HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, GPIO_PIN_SET);
	  // delay
	  HAL_Delay(5000);

	  // 2
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	  // 2.2
	  HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, GPIO_PIN_SET);
	  // delay
	  HAL_Delay(2000);

	  // 3
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);
	  // 3.2
	  HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, GPIO_PIN_RESET);
	  // delay
	  HAL_Delay(3000);*/

/*	  // exercise 4
	  counter = (counter + 1)%10;
	  Buffer_Update_7seg(counter, 0);
	  Driver_7seg(0);
	  HAL_Delay(1000);*/


	  // exercise 5

	  // phase 1

	  // 1.1 horizontal red on
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
	  // 1.2 vertical green on
	  HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, GPIO_PIN_RESET);
	  // clock
	  for (uint8_t cnt_red_1 = 9; cnt_red_1 > 0; cnt_red_1--) {
		  // red 9s
		  Buffer_Update_7seg(cnt_red_1, 0);
		  Driver_7seg(0);

		  // green 6s
		  uint8_t cnt_gre_2 = cnt_red_1 - 3;
		  if (cnt_gre_2 > 0) {
			  Buffer_Update_7seg(cnt_gre_2, 1);
			  Driver_7seg(1);
		  }

		  // yellow on
		  if (cnt_red_1 <= 3){
			  uint8_t cnt_yel_2 = cnt_red_1;
			  HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, GPIO_PIN_SET);
			  Buffer_Update_7seg(cnt_yel_2, 1);
			  Driver_7seg(1);
		  }
		  // delay
		  HAL_Delay(500);
	  }

	  // phase 2

	  // 2.1 horizontal green on
	  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);
	  // 2.2 vertical red on
	  HAL_GPIO_WritePin(RED2_LED_GPIO_Port, RED2_LED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(YELLOW2_LED_GPIO_Port, YELLOW2_LED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GREEN2_LED_GPIO_Port, GREEN2_LED_Pin, GPIO_PIN_SET);
	  // clock
	  for (int cnt_red_2 = 9; cnt_red_2 > 0; cnt_red_2--) {
		  // red 9s
		  Buffer_Update_7seg(cnt_red_2, 1);
		  Driver_7seg(1);

		  // green 6s
		  uint8_t cnt_gre_1 = cnt_red_2 - 3;
		  if (cnt_gre_1 > 0) {
			  Buffer_Update_7seg(cnt_gre_1, 0);
			  Driver_7seg(0);
		  }

		  // yellow on
		  if (cnt_red_2 <= 3){
			  uint8_t cnt_yel_1 = cnt_red_2;
			  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
			  Buffer_Update_7seg(cnt_yel_1, 0);
			  Driver_7seg(0);
		  }
		  // delay
		  HAL_Delay(500);
	  }


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
  HAL_GPIO_WritePin(GPIOA, RED_LED_Pin|YELLOW_LED_Pin|GREEN_LED_Pin|GREEN2_LED_Pin
                          |YELLOW2_LED_Pin|RED2_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin|B_7SEG_Pin|C_7SEG_Pin|C2_7SEG_Pin
                          |D2_7SEG_Pin|E2_7SEG_Pin|F2_7SEG_Pin|G2_7SEG_Pin
                          |D_7SEG_Pin|E_7SEG_Pin|F_7SEG_Pin|G_7SEG_Pin
                          |A2_7SEG_Pin|B2_7SEG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED_LED_Pin YELLOW_LED_Pin GREEN_LED_Pin GREEN2_LED_Pin
                           YELLOW2_LED_Pin RED2_LED_Pin */
  GPIO_InitStruct.Pin = RED_LED_Pin|YELLOW_LED_Pin|GREEN_LED_Pin|GREEN2_LED_Pin
                          |YELLOW2_LED_Pin|RED2_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_7SEG_Pin B_7SEG_Pin C_7SEG_Pin C2_7SEG_Pin
                           D2_7SEG_Pin E2_7SEG_Pin F2_7SEG_Pin G2_7SEG_Pin
                           D_7SEG_Pin E_7SEG_Pin F_7SEG_Pin G_7SEG_Pin
                           A2_7SEG_Pin B2_7SEG_Pin */
  GPIO_InitStruct.Pin = A_7SEG_Pin|B_7SEG_Pin|C_7SEG_Pin|C2_7SEG_Pin
                          |D2_7SEG_Pin|E2_7SEG_Pin|F2_7SEG_Pin|G2_7SEG_Pin
                          |D_7SEG_Pin|E_7SEG_Pin|F_7SEG_Pin|G_7SEG_Pin
                          |A2_7SEG_Pin|B2_7SEG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
