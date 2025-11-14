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
	printf("这是一个串口中断接收回显实验\n");
	

	 while (1){

	 }

}
