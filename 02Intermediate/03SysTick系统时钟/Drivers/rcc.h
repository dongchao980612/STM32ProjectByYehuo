#ifndef __RCC_H
#define __RCC_H

#include "stm32f10x.h"

#define MCO_PIN		GPIO_Pin_8
#define MCO_PORT	GPIOA
#define MCO_CLK		RCC_APB2Periph_GPIOA


void HSE_SetSysClockTo72(uint32_t pllmul);
void HSI_SetSysClockTo72(uint32_t pllmul);
/*
��ʼ��MCO ����PA8
��F103 ϵ����MCO ����ֻ��һ������PA8����F4 ϵ���У�MCO ����������
*/
void MCO_GPIO_Config(void);


#endif /* __RCC_H */
