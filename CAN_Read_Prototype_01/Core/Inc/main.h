/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define Joulieled_Pin GPIO_PIN_1
#define Joulieled_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define Vx 0x0D //vitesse du veichule
#define carbu 0x2F // en prcent
#define dist 0x21 //distance parcourue depuis l'allumage
#define demar_moteur 0x1F // durée depuis le démarrage du moteur
#define carbu_typ 0x51 // type de carburant
#define conso 0x5E  // carburant consommé en L/h
#define temper_eau 0x67 // celsius
#define temp_huil 0x5C // celsius
#define pos_pdle 0x5A //accélérateur
#define temper_liq 0x05// celsius
typedef struct tablo{
	char * lettr;
	uint16_t PID;
}tablo_typedef;


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
