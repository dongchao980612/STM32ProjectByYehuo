#ifndef __STM32F10x_RCC_H
#define __STM32F10x_RCC_H

#include "stm32f10x.h"

#define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOE             ((uint32_t)0x00000040)

void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

#endif /* __STM32F10x_RCC_H */
