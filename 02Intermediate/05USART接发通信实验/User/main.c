#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"
#include <stdio.h>



 
 
int main(void)
{
	char ch;
	
	Led_Init();
	 /* 初始化USART 配置模式为115200 8-N-1，中断接收*/
	USART_Config();

	// Usart_SendString( DEBUG_USARTx,"这是一个串口中断接收回显实验\n");
	Show_Message();
	while (1){
		/* 获取字符指令*/
		ch=getchar();
		printf("接收到字符：%c\n",ch);
		
		/* 根据字符指令控制RGB 彩灯颜色*/
		switch (ch)
			{
			case '1':
				LED(ON);
				break;
		case '2':
			LED(OFF);
			break;
		default:
			/* 如果不是指定指令字符，打印提示信息*/
			Show_Message();
			break;
	 }
	}
}


