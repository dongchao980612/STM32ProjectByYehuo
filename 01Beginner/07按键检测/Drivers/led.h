#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"                  // Device header

#define LED_GPIO_PIN		GPIO_Pin_13
#define LED_GPIO_PORT		GPIOC
#define LED_GPIO_CLK		RCC_APB2Periph_GPIOC

#define		ON		1
#define		OFF		0

#define LED(a)  if(a) LED_ON(); else 	LED_OFF()

void LED_GPIO_Config(void);
void LED_ON(void);
void LED_OFF(void);
void LED_Trun(void);

#endif /* __LED_H */

