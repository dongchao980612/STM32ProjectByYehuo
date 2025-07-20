#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"

// output
#define GPIOC_ODR_Addr  (GPIOC_BASE+0x0C)
#define PCout(n)  *(uint32_t*)((GPIOC_ODR_Addr & 0xF0000000)+0x02000000+((GPIOC_ODR_Addr &0x00FFFFFF)<<5)+(n<<2)) 

// iutput
#define GPIOC_IDR_Addr  (GPIOC_BASE+0x08)
#define PCint(n)  *(uint32_t*)((GPIOC_IDR_Addr & 0xF0000000)+0x02000000+((GPIOC_IDR_Addr &0x00FFFFFF)<<5)+(n<<2)) 

#define GPIO_PIN_OUT 13
#define GPIO_PIN_IN 14

int main(void)
{
	
	LED_GPIO_Config();
	KEY_GPIO_Config();
	#if 0
	while (1)
		{
			// LED_ON();
			// LED(ON);
			PCout(GPIO_PIN_OUT)=1;
			Delay(0xFFFFF);
			
			// LED_OFF();
			// LED(OFF);
			PCout(GPIO_PIN_OUT)=0;
			Delay(0xFFFFF);
    }
		#else
		while (1)
		{
			if(PCint(GPIO_PIN_IN) == KEY_UP)
			{
				
				while(PCint(GPIO_PIN_IN) == KEY_UP);
				LED_Trun();
			}
    }
		#endif
}
