#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"

int main(void)
{
	
	Led_Init();
	Key_Init();
	while (1)
		{
			if(Get_Key_Value(KEY_GPIO_PORT,KEY_GPIO_PIN) == KEY_UP){
				LED_Trun();
			}
    }
}
