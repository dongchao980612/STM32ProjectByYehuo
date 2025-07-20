#ifndef __RCC_H
#define __RCC_H

#include "stm32f10x.h"

#define MCO_PIN		GPIO_Pin_8
#define MCO_PORT	GPIOA
#define MCO_CLK		RCC_APB2Periph_GPIOA


void HSE_SetSysClockTo72(uint32_t pllmul);
void HSI_SetSysClockTo72(uint32_t pllmul);
/*
初始化MCO 引脚PA8
在F103 系列中MCO 引脚只有一个，即PA8，在F4 系列中，MCO 引脚有两个
*/
void MCO_GPIO_Config(void);


#endif /* __RCC_H */
