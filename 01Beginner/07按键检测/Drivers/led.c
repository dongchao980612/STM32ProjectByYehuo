#include "led.h"


void  LED_GPIO_Config(void){
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK,ENABLE);
	
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=LED_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN); 

	GPIO_Init(LED_GPIO_PORT,&GPIO_InitStruct);
}

void LED_ON(void){
	 GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
}

void LED_OFF(void){
	 GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
}

void LED_Trun(void){
	if(GPIO_ReadOutputDataBit(LED_GPIO_PORT,LED_GPIO_PIN)!=ON)
	{
		LED_OFF();
	}
	else{
		LED_ON();
	}
	
}
