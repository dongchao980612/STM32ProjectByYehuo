#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "dma.h"
#include <stdio.h>


int main(void)
{

	uint16_t i;

	
	LED_GPIO_Config();
	USART_Config();
	DMA_Config();

	
	
	for (i=0; i<SENDBUFF_SIZE; i++)
	{ 
		SendBuff[i] = 'P';
	}
	
	/* USART1 向DMA 发出TX 请求*/
	USART_DMACmd(USARTx, USART_DMAReq_Tx, ENABLE);
	
	while (1)
	{
		LED_Trun();
		
	}
}
