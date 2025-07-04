#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"


int main(void)
{
	
	Led_Init();
	
	while (1)
		{
			// LED_ON();
			LED(ON);
			Delay(0xFFFFF);
			
			// LED_OFF();
			LED(OFF);
			Delay(0xFFFFF);
    }
}
