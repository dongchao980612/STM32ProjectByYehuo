#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"    

#define KEY_GPIO_PIN		GPIO_Pin_2
#define KEY_GPIO_PORT		GPIOC
#define KEY_GPIO_CLK		RCC_APB2Periph_GPIOC

#define  KEY_UP		0
#define  KEY_DOWN		1
typedef unsigned          char key_t;

void Key_Init(void);
key_t Get_Key_Value(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* __KEY_H */
