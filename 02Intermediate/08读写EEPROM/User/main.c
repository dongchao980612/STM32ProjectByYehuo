#include "stm32f10x.h"                  // Device header
#include "iic.h"
#include "led.h"
#include "usart.h"
#include "delay.h"

uint8_t readData[10]={0};
int main(void)
{
	LED_GPIO_Config();
	USART_Config();
	I2C_EE_Config();
	
	I2C_EE_ByteWrite(11,0x55);
	I2C_EE_BufferRead(11, readData,1);
	
	while (1)
		{
				LED_ON();
				Delay_ms(100);
			
				LED_OFF();
				Delay_ms(100);
    }
}
