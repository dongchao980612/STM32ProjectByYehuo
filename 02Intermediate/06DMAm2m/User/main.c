#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "dma.h"
#include <stdio.h>


extern const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];
extern uint32_t aDST_Buffer[BUFFER_SIZE];


int main(void)
{

	/* 定义存放比较结果变量*/
	uint8_t TransferStatus;
	
	LED_GPIO_Config();
	USART_Config();
	DMA_Config();
	
	
	 /* 比较源数据与传输后数据*/
	TransferStatus=Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
	
	/* 等待DMA 传输完成*/
	while (DMA_GetFlagStatus(DMA_FLAG_TC)==RESET);

 

 
 /* 判断源数据与传输后数据比较结果*/
 if (TransferStatus==0)
 {
	printf("源数据与传输后数据不相等\n");
 }
 else
 {
	printf("源数据与传输后数据相等\n");
 }
 
	while (1)
	{
	
	}

}
