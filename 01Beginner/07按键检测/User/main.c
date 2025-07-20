#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"

int main(void)
{
	
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	while (1)
		{
			if(Get_Key_Value(KEY_GPIO_PORT,KEY_GPIO_PIN) == KEY_UP){
				LED_Trun();
			}
    }
}
