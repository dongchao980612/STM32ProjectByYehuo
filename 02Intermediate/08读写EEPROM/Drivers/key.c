#include "key.h"



void  KEY_GPIO_Config(void){
	
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK,ENABLE);
	
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=KEY_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(KEY_GPIO_PORT,&GPIO_InitStruct);
}

key_t Get_Key_Value(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_UP)
		{
			// À… ÷ºÏ≤‚
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_UP){
				// ø’—≠ª∑
			};
				return KEY_UP;
		}
	else	
		{
			return KEY_DOWN;
		}
}
