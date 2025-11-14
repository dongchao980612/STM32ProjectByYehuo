#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"                  // Device header
#include <stdio.h>


// 串口1-USART1
#define USARTx 										USART1
#define USART_CLK 								RCC_APB2Periph_USART1
#define USART_APBxClkCmd 					RCC_APB2PeriphClockCmd
#define USART_BAUDRATE 						115200


// USART GPIO 引脚宏定义

#define USART_GPIO_CLK 						RCC_APB2Periph_GPIOA
#define USART_GPIO_APBxClkCmd 		RCC_APB2PeriphClockCmd

#define USART_TX_GPIO_PORT 			GPIOA
#define USART_TX_GPIO_PIN 			GPIO_Pin_9
#define USART_RX_GPIO_PORT 			GPIOA
#define USART_RX_GPIO_PIN 			GPIO_Pin_10



#define USART_IRQN							USART1_IRQn
#define USART_IPRIORITYGROUP   	NVIC_PriorityGroup_2
#define USART_IRQHandler        USART1_IRQHandler



static void USART_NVIC_Config(void);
void USART_Config(void);
void Usart_SendByte(USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendHalfWord(USART_TypeDef * pUSARTx, uint16_t data);
void Usart_SendArray(USART_TypeDef * pUSARTx, uint8_t* array,uint8_t num);
void Usart_SendString(USART_TypeDef * pUSARTx, uint8_t *str);

#endif /* __USART_H */
