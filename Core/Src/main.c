/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "7segdecoder.h"			//Giải mã led 7-seg
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
/// Hàng đơn vị của số cần hiển thị, phạm vi [0..9]
unsigned char unit_num;
/// Hàng chục của số cần hiển thị, phạm vi [0..9]
unsigned char ten_num;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/**
 * @brief	Thiết lập giá trị hiển thị cho các đoạn trên led 7-seg,
 * @note    Cần tắt toàn bộ led 7-seg trước khi sử dụng hàm
 * @param[in]  val 	Giá trị cần hiển thị
 *
 */
void Setup7Seg(unsigned char val){
	/// Giá trị các chân 7 đoạn
	static bool a,b,c,d,e,f,g;

	  /// Chuyển thành số nguyên thành giá trị các thanh led 7 đoạn
	  NumberTo7seg(val, &a, &b, &c, &d, &e, &f, &g);

	  /// Tuần tự thiết lập tắt bật của từng đoạn led.
	  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, a);
	  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, b);
	  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, c);
	  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, d);
	  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, e);
	  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, f);
	  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, g);

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
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);

  ///Cho phép led 7-seg màu Ping sáng, bằng cách đưa logic 1 vào chân Base của transistor 2N2222, làm cực cathod của đèn nối liền với GND, thông mạch.
  HAL_GPIO_WritePin(PING_ENABLED_GPIO_Port, PING_ENABLED_Pin, GPIO_PIN_SET);
  HAL_Delay(1000);
  HAL_GPIO_WritePin(BLUE_ENABLED_GPIO_Port, BLUE_ENABLED_Pin, GPIO_PIN_SET);
  HAL_Delay(1000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  /// Giá trị đếm tăng dần để hiển thị, xoay vòng từ 0 --> 99.
  int count = 0;

  /// Giá trị đếm để quét hiển thị giữa 2 led 7 seg
  int scan_count = 0;


  while (1)
  {
	  /// Xác định giá trị cần hiển thị cho mỗi đèn led
	  unit_num = count % 10;
	  ten_num = (int)(count / 10);


	  {//-----------LED PING hiển thị------------------------
		  /// Bước 1. Tắt tất cả các led. Như vậy qua trình tắt/bật từng thanh led sẽ không bị nhìn thấy.
		  /// Lưu ý: Lệnh tắt này tác động lên cả 2 chân PING_ENABLED_Pin và BLUE_ENABLED_Pin cùng lúc, đòi hỏi cả 2 pin này phải cùng một Group Port.
		  HAL_GPIO_WritePin(PING_ENABLED_GPIO_Port, PING_ENABLED_Pin | BLUE_ENABLED_Pin, GPIO_PIN_RESET);

		  /// Bước 2: Chuẩn bị nội dung hiển thị trên 7 đoạn led 1
		  Setup7Seg(ten_num);

		  /// Bước 3. Chỉ bật đúng led 7-seg mong muôn
		  HAL_GPIO_WritePin(PING_ENABLED_GPIO_Port, PING_ENABLED_Pin, GPIO_PIN_SET);
	  }
	  HAL_Delay(20);
	  {//-----------LED BLUE hiển thị------------------------
		  /// Bước 1. Tắt tất cả các led. Như vậy qua trình tắt/bật từng thanh led sẽ không bị nhìn thấy.
		  /// Lưu ý: Lệnh tắt này tác động lên cả 2 chân PING_ENABLED_Pin và BLUE_ENABLED_Pin cùng lúc, đòi hỏi cả 2 pin này phải cùng một Group Port.
		  HAL_GPIO_WritePin(PING_ENABLED_GPIO_Port, PING_ENABLED_Pin | BLUE_ENABLED_Pin, GPIO_PIN_RESET);

		  /// Bước 2: Chuẩn bị nội dung hiển thị trên 7 đoạn led 2
		  Setup7Seg(unit_num);

		  /// Bước 3. Chỉ bật đúng led 7-seg mong muôn
		  HAL_GPIO_WritePin(BLUE_ENABLED_GPIO_Port, BLUE_ENABLED_Pin, GPIO_PIN_SET);
	  }

	  ///Chuẩn bị cho bước tiếp theo. Đếm xoay vòng
	  scan_count++;
	  if (scan_count > 10000) {
		  scan_count = 0;
		  //Tăng và xoay vòng giá trị cần hiển thị
		  count++;
		  if (count > 99) {
			  count = 0;
		  }
	  }
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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, BLUE_ENABLED_Pin|PING_ENABLED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin D_Pin
                           E_Pin F_Pin G_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : BLUE_ENABLED_Pin PING_ENABLED_Pin */
  GPIO_InitStruct.Pin = BLUE_ENABLED_Pin|PING_ENABLED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

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
