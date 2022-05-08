/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_LED_Pin GPIO_PIN_5
#define RED_LED_GPIO_Port GPIOA
#define YELLOW_LED_Pin GPIO_PIN_6
#define YELLOW_LED_GPIO_Port GPIOA
#define GREEN_LED_Pin GPIO_PIN_7
#define GREEN_LED_GPIO_Port GPIOA
#define A_7SEG_Pin GPIO_PIN_0
#define A_7SEG_GPIO_Port GPIOB
#define B_7SEG_Pin GPIO_PIN_1
#define B_7SEG_GPIO_Port GPIOB
#define C_7SEG_Pin GPIO_PIN_2
#define C_7SEG_GPIO_Port GPIOB
#define C2_7SEG_Pin GPIO_PIN_10
#define C2_7SEG_GPIO_Port GPIOB
#define D2_7SEG_Pin GPIO_PIN_11
#define D2_7SEG_GPIO_Port GPIOB
#define E2_7SEG_Pin GPIO_PIN_12
#define E2_7SEG_GPIO_Port GPIOB
#define F2_7SEG_Pin GPIO_PIN_13
#define F2_7SEG_GPIO_Port GPIOB
#define G2_7SEG_Pin GPIO_PIN_14
#define G2_7SEG_GPIO_Port GPIOB
#define GREEN2_LED_Pin GPIO_PIN_8
#define GREEN2_LED_GPIO_Port GPIOA
#define YELLOW2_LED_Pin GPIO_PIN_9
#define YELLOW2_LED_GPIO_Port GPIOA
#define RED2_LED_Pin GPIO_PIN_10
#define RED2_LED_GPIO_Port GPIOA
#define D_7SEG_Pin GPIO_PIN_3
#define D_7SEG_GPIO_Port GPIOB
#define E_7SEG_Pin GPIO_PIN_4
#define E_7SEG_GPIO_Port GPIOB
#define F_7SEG_Pin GPIO_PIN_5
#define F_7SEG_GPIO_Port GPIOB
#define G_7SEG_Pin GPIO_PIN_6
#define G_7SEG_GPIO_Port GPIOB
#define A2_7SEG_Pin GPIO_PIN_8
#define A2_7SEG_GPIO_Port GPIOB
#define B2_7SEG_Pin GPIO_PIN_9
#define B2_7SEG_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
