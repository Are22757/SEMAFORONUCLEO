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

int semaforoActivo = 1; // Estado para controlar el semáforo
int ledsAzulesActivos = 0; // Estado para controlar los LEDs azules
int ledsBlancosActivos = 0; // Estado para controlar los LEDs blancos
int ledCounterAzul = 0; // Contador para LEDs azules
int ledCounterBlanco = 0; // Contador para LEDs blancos
int jugadorGanador = 0; // 0: ninguno, 1: jugador 1, 2: jugador 2
/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {
	  /* Sección del semáforo */
	          if (semaforoActivo) {
	              if (HAL_GPIO_ReadPin(BTNSEM_GPIO_Port, BTNSEM_Pin) == GPIO_PIN_RESET) {
	                  // Lógica del semáforo
	                  HAL_GPIO_WritePin(LEDROJO_GPIO_Port, LEDROJO_Pin, GPIO_PIN_SET);
	                  HAL_GPIO_WritePin(LEDAMA_GPIO_Port, LEDAMA_Pin, GPIO_PIN_RESET);
	                  HAL_GPIO_WritePin(LEDVER_GPIO_Port, LEDVER_Pin, GPIO_PIN_RESET);
	                  HAL_Delay(2000);

	                  HAL_GPIO_WritePin(LEDROJO_GPIO_Port, LEDROJO_Pin, GPIO_PIN_RESET);
	                  HAL_GPIO_WritePin(LEDAMA_GPIO_Port, LEDAMA_Pin, GPIO_PIN_SET);
	                  HAL_Delay(1500);

	                  HAL_GPIO_WritePin(LEDAMA_GPIO_Port, LEDAMA_Pin, GPIO_PIN_RESET);
	                  HAL_GPIO_WritePin(LEDVER_GPIO_Port, LEDVER_Pin, GPIO_PIN_SET);
	                  HAL_Delay(1500);
	                  HAL_GPIO_WritePin(LEDVER_GPIO_Port, LEDVER_Pin, GPIO_PIN_RESET);

	                  semaforoActivo = 0; // Después de la secuencia, desactivar semáforo
	                  ledsAzulesActivos = 0; // Activar lógica de LEDs azules
	                  ledCounterAzul = 0; // Reiniciar contador de LEDs azules
	                  ledsBlancosActivos = 0; // Activar lógica de LEDs azules
	           	      ledCounterBlanco = 0; // Reiniciar contador de LEDs azules*/
	              }
	              else{
	            	  HAL_GPIO_WritePin(LEDROJO_GPIO_Port, LEDROJO_Pin, GPIO_PIN_RESET);
	            	  HAL_GPIO_WritePin(LEDAMA_GPIO_Port, LEDAMA_Pin, GPIO_PIN_RESET);
	            	  HAL_GPIO_WritePin(LEDVER_GPIO_Port, LEDVER_Pin, GPIO_PIN_RESET);
	            	  HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL5_GPIO_Port, LEDAZUL5_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL6_GPIO_Port, LEDAZUL6_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL7_GPIO_Port, LEDAZUL7_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDAZUL8_GPIO_Port, LEDAZUL8_Pin, GPIO_PIN_RESET);HAL_GPIO_WritePin(LEDGAZUL_GPIO_Port, LEDGAZUL_Pin, GPIO_PIN_RESET);

	            	  HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO5_GPIO_Port, LEDBLANCO5_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO6_GPIO_Port, LEDBLANCO6_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO7_GPIO_Port, LEDBLANCO7_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(LEDBLANCO8_GPIO_Port, LEDBLANCO8_Pin, GPIO_PIN_RESET);HAL_GPIO_WritePin(LEDGBLANCO_GPIO_Port, LEDGBLANCO_Pin, GPIO_PIN_RESET);

	            	 /* ledsAzulesActivos = 0; // Activar lógica de LEDs azules
	            	  ledCounterAzul = 0; // Reiniciar contador de LEDs azules
	            	  ledsBlancosActivos = 0; // Activar lógica de LEDs azules
	            	  ledCounterBlanco = 0; // Reiniciar contador de LEDs azules*/
	              }
	          }

	          /* Sección de LEDs azules */
	          if (HAL_GPIO_ReadPin(BTNJ1_GPIO_Port, BTNJ1_Pin) == GPIO_PIN_RESET) {
	              HAL_Delay(200); // Para evitar rebotes
	              ledCounterAzul++;

	              // Límite máximo de LEDs encendidos
	              if (ledCounterAzul > 9) {
	                  ledCounterAzul = 9;
	              }

	              // Apagar todos los LEDs azules
	              HAL_GPIO_WritePin(GPIOB, LEDAZUL1_Pin|LEDAZUL2_Pin|LEDAZUL3_Pin|LEDAZUL4_Pin|LEDAZUL5_Pin|LEDAZUL6_Pin|LEDAZUL7_Pin|LEDAZUL8_Pin|LEDGAZUL_Pin, GPIO_PIN_RESET);

	              // Encender LEDs azules según ledCounterAzul
	              switch (ledCounterAzul) {
	                  case 1: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); break;
	                  case 2: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); break;
	                  case 3: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); break;
	                  case 4: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_SET); break;
	                  case 5: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL5_GPIO_Port, LEDAZUL5_Pin, GPIO_PIN_SET); break;
	                  case 6: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL5_GPIO_Port, LEDAZUL5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL6_GPIO_Port, LEDAZUL6_Pin, GPIO_PIN_SET); break;
	                  case 7: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL5_GPIO_Port, LEDAZUL5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL6_GPIO_Port, LEDAZUL6_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL7_GPIO_Port, LEDAZUL7_Pin, GPIO_PIN_SET); break;
	                  case 8: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL5_GPIO_Port, LEDAZUL5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL6_GPIO_Port, LEDAZUL6_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL7_GPIO_Port, LEDAZUL7_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL8_GPIO_Port, LEDAZUL8_Pin, GPIO_PIN_SET); break;
	                  case 9: HAL_GPIO_WritePin(LEDAZUL1_GPIO_Port, LEDAZUL1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL2_GPIO_Port, LEDAZUL2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL3_GPIO_Port, LEDAZUL3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL4_GPIO_Port, LEDAZUL4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL5_GPIO_Port, LEDAZUL5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL6_GPIO_Port, LEDAZUL6_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL7_GPIO_Port, LEDAZUL7_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDAZUL8_GPIO_Port, LEDAZUL8_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDGAZUL_GPIO_Port, LEDGAZUL_Pin, GPIO_PIN_SET);break;

	              }


	              // Esperar un tiempo antes de leer el botón nuevamente
	              HAL_Delay(200);
	          }

	          /* Sección de LEDs blancos */
	          if (HAL_GPIO_ReadPin(BTNJ2_GPIO_Port, BTNJ2_Pin) == GPIO_PIN_RESET) {
	              HAL_Delay(200); // Para evitar rebotes
	              ledCounterBlanco++;

	              // Límite máximo de LEDs encendidos
	              if (ledCounterBlanco > 9) {
	                  ledCounterBlanco = 9;
	              }

	              // Apagar todos los LEDs blancos
	              HAL_GPIO_WritePin(GPIOB, LEDBLANCO1_Pin|LEDBLANCO2_Pin|LEDBLANCO3_Pin|LEDBLANCO4_Pin|LEDBLANCO5_Pin|LEDBLANCO6_Pin|LEDBLANCO7_Pin|LEDBLANCO8_Pin|LEDGBLANCO_Pin, GPIO_PIN_RESET);

	              // Encender LEDs blancos según ledCounterBlanco
	              switch (ledCounterBlanco) {
	                  case 1: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); break;
	                  case 2: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); break;
	                  case 3: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); break;
	                  case 4: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_SET); break;
	                  case 5: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO5_GPIO_Port, LEDBLANCO5_Pin, GPIO_PIN_SET); break;
	                  case 6: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO5_GPIO_Port, LEDBLANCO5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO6_GPIO_Port, LEDBLANCO6_Pin, GPIO_PIN_SET); break;
	                  case 7: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO5_GPIO_Port, LEDBLANCO5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO6_GPIO_Port, LEDBLANCO6_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO7_GPIO_Port, LEDBLANCO7_Pin, GPIO_PIN_SET); break;
	                  case 8: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO5_GPIO_Port, LEDBLANCO5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO6_GPIO_Port, LEDBLANCO6_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO7_GPIO_Port, LEDBLANCO7_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO8_GPIO_Port, LEDBLANCO8_Pin, GPIO_PIN_SET); break;
	                  case 9: HAL_GPIO_WritePin(LEDBLANCO1_GPIO_Port, LEDBLANCO1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO2_GPIO_Port, LEDBLANCO2_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO3_GPIO_Port, LEDBLANCO3_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO4_GPIO_Port, LEDBLANCO4_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO5_GPIO_Port, LEDBLANCO5_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO6_GPIO_Port, LEDBLANCO6_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO7_GPIO_Port, LEDBLANCO7_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDBLANCO8_GPIO_Port, LEDBLANCO8_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(LEDGBLANCO_GPIO_Port, LEDGBLANCO_Pin, GPIO_PIN_SET); break;
	              }

	              // Esperar un tiempo antes de leer el botón nuevamente
	              HAL_Delay(200);
	          }

	      }
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  /* USER CODE END 3 */

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
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LEDAZUL1_Pin|LEDBLANCO3_Pin|LEDBLANCO5_Pin|LEDBLANCO4_Pin
                          |LEDAZUL3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LEDROJO_Pin|LEDAMA_Pin|LEDVER_Pin|LEDGAZUL_Pin
                          |LEDAZUL5_Pin|LEDAZUL6_Pin|LEDBLANCO1_Pin|LEDBLANCO2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LEDBLANCO6_Pin|LEDBLANCO7_Pin|LEDGBLANCO_Pin|LEDAZUL4_Pin
                          |LEDBLANCO8_Pin|LEDAZUL2_Pin|LEDAZUL7_Pin|LEDAZUL8_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BTNSEM_Pin BTNJ1_Pin */
  GPIO_InitStruct.Pin = BTNSEM_Pin|BTNJ1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LEDAZUL1_Pin LEDBLANCO3_Pin LEDBLANCO5_Pin LEDBLANCO4_Pin
                           LEDAZUL3_Pin */
  GPIO_InitStruct.Pin = LEDAZUL1_Pin|LEDBLANCO3_Pin|LEDBLANCO5_Pin|LEDBLANCO4_Pin
                          |LEDAZUL3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LEDROJO_Pin LEDAMA_Pin LEDVER_Pin LEDGAZUL_Pin
                           LEDAZUL5_Pin LEDAZUL6_Pin LEDBLANCO1_Pin LEDBLANCO2_Pin */
  GPIO_InitStruct.Pin = LEDROJO_Pin|LEDAMA_Pin|LEDVER_Pin|LEDGAZUL_Pin
                          |LEDAZUL5_Pin|LEDAZUL6_Pin|LEDBLANCO1_Pin|LEDBLANCO2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LEDBLANCO6_Pin LEDBLANCO7_Pin LEDGBLANCO_Pin LEDAZUL4_Pin
                           LEDBLANCO8_Pin LEDAZUL2_Pin LEDAZUL7_Pin LEDAZUL8_Pin */
  GPIO_InitStruct.Pin = LEDBLANCO6_Pin|LEDBLANCO7_Pin|LEDGBLANCO_Pin|LEDAZUL4_Pin
                          |LEDBLANCO8_Pin|LEDAZUL2_Pin|LEDAZUL7_Pin|LEDAZUL8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : BTNJ2_Pin */
  GPIO_InitStruct.Pin = BTNJ2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BTNJ2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
