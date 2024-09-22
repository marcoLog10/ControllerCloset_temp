/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
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

#include <stdint.h>
#include <stm32g070xx.h>
#include <stm32g0xx.h>

#define DEBUG_RX_BUFFER_SIZE 255
uint32_t rxBuffer[DEBUG_RX_BUFFER_SIZE];

uint8_t useless;

void SystemClockInit(){
	/* HSI conf and activation */
	SET_BIT(RCC->CR, RCC_CR_HSION);
	while (!(READ_BIT(RCC->CR, RCC_CR_HSIRDY) == (RCC_CR_HSIRDY)));
	
	/* Set AHB prescaler*/
	MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, 0x00000000U);
	
	/* Sysclk activation on the HSI */
	MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, 0x00000000U);
	while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != 0x00000000U);

	/* Set APB1 prescaler*/
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE, 0x00000000U);
}

int main(void)
{
	SystemClockInit();
  // USART3 - RTS PD12 AF7 | TX PD8 AF7 | RX PD9 AF7 | CTS PB13 AF7
	// GPIO Config
	// RCC->IOPENR |= (1 << RCC_IOPENR_GPIOAEN RCC_AHB1ENR_GPIODEN_Pos) | (1 << RCC_AHB1ENR_GPIOBEN_Pos); // Enable clock GPIOD and GPIOB
	
	// GPIOD->MODER |= (0x2 << GPIO_MODER_MODE8_Pos) |
	// 				        (0x2 << GPIO_MODER_MODE9_Pos) | 
	// 				        (0x2 << GPIO_MODER_MODE12_Pos);
	// GPIOD->AFR[1]|= (0b0111 << GPIO_AFRH_AFSEL8_Pos) | 		// PD8
	// 				        (0b0111 << GPIO_AFRH_AFSEL9_Pos) |		// PD9
	// 				        (0b0111 << GPIO_AFRH_AFSEL12_Pos); 		// PD12

	// GPIOB->MODER |= (0x2 << GPIO_MODER_MODE13_Pos);
	// GPIOB->AFR[1]|= (0b0111 << GPIO_AFRH_AFSEL13_Pos); 		// PB13

	// // DMA config Stream 1 channel 4
	// DMA1_Stream4->NDTR 	= DEBUG_RX_BUFFER_SIZE;
	// DMA1_Stream4->PAR 	= (uint32_t)&(USART3->DR);
	// DMA1_Stream4->M0AR 	= (uint32_t)&rxBuffer;
	// DMA1_Stream4->CR 	=  (0b100 << DMA_SxCR_CHSEL_Pos) |
	// 				   	   DMA_SxCR_MINC 				 |
	// 					   DMA_SxCR_DIR_0			     |
	// 					   DMA_SxCR_TCIE;
	// // USART Config
	// RCC->APB1ENR 	|= (1 << RCC_APB1ENR_USART3EN_Pos);  		// Enable clock USART3
	// USART3->CR3  	|= (1 << USART_CR3_CTSE_Pos)			 |	// Enable CTS
	// 			  	   (1 << USART_CR3_RTSE_Pos);		    	// Enable RTS

	// // Brr = Mantissa + Fraction / Clock (16)
	// uint16_t uartdiv = 1600000 / 115200;
	// USART3->BRR  |= (
	// 	(( uartdiv / 16 ) << USART_BRR_DIV_Mantissa_Pos ) | ((uartdiv % 16 ) << USART_BRR_DIV_Fraction_Pos )
	// 				);

	// USART3->CR1  	 |= USART_CR1_UE			 	 |	// Enable USART
	// 			  		USART_CR1_TE			 	 |	// Enable Tx
	// 					USART_CR1_RE;			    	// Enable Rx

	// DMA1_Stream4->CR |= DMA_SxCR_EN;

	// NVIC_EnableIRQ(USART3_IRQn);
	// NVIC_SetPriority(USART3_IRQn, 3);
    /* Loop forever */
	for(;;);
}