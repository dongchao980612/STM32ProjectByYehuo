#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"
#include <stdio.h>

int main(void)
{
	 /* 初始化USART 配置模式为115200 8-N-1，中断接收*/
	USART_Config();
	
		// 一个字节
	Usart_SendByte(USARTx,0x64);  //  100
	Usart_SendByte(USARTx,'\n');
	
	// 字符
	Usart_SendByte(USARTx,'A');
	Usart_SendByte(USARTx,'\n');
	
		// 两个字节
	Usart_SendHalfWord(USARTx,0xFF56);
	Usart_SendByte(USARTx,'\n');
	
	// 字节数组
	uint8_t array[10]={0x64,1,2,3,4,5,6,7,8,9};
	Usart_SendArray(USARTx,array,10);
	Usart_SendByte(USARTx,'\n');
	
	//字符串
	Usart_SendString(USARTx,(uint8_t*)"这是一个串口打印字符串实验\n");
	printf("这是一个串口printf测试\n");
	 while (1){

	 }

}
