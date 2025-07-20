#include "stm32f10x.h"                  // Device header
#include "key.h"
#include "led.h"
#include "exti.h"

int main(void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	EXTI_Config();

	while (1)
		{

    }
}

