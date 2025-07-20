#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"                  // Device header

#include "led.h"
#include "key.h"
#include "delay.h"


#define EXTI_CLK									RCC_APB2Periph_AFIO
#define EXTI_PORTSOURCE 					GPIO_PortSourceGPIOC  
#define EXTI_PORTSOURCE_PIN 			GPIO_PinSource14
#define EXTI_LINE 								EXTI_Line14

#define NVIC_PRIORITYGROUP   			NVIC_PriorityGroup_2
#define NVIC_IRQN					  			EXTI15_10_IRQn

void EXTI_Config(void);


#endif /* __EXTI_H */
