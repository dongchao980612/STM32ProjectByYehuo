#include "stm32f10x.h"                  // Device header

#include "led.h"
#include "delay.h"

int main(void)
{
	LED_GPIO_Config();

	while (1)
		{
				LED_ON();
				Delay_ms(100);
			
				LED_OFF();
				Delay_ms(100);
    }
}
