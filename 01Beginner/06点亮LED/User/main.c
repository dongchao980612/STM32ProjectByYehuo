#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"


int main(void)
{
	
	LED_GPIO_Config();
	
	// GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN); // �ر�LED
	// GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);// ��LED


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
	
