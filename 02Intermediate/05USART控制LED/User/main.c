#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"
#include <stdio.h>
void showMessage(){
	printf("串口控制LED亮灭【1:亮    0:灭】\n");
	printf("使用USART 参数为：%d 8-N-1 \n",USART_BAUDRATE);
}

int main(void)
{
	uint8_t ch=0;
	
	/* 初始化USART 配置模式为115200 8-N-1，中断接收*/
	USART_Config();
	LED_GPIO_Config();

	showMessage();
	 while (1){
			ch = getchar();
			printf("ch = %c \n",ch);
			switch(ch){
				case '1':
					printf("开灯\n");
					LED_ON();
					break;
				case '0':
					printf("关灯\n");
					LED_OFF();
					break;
				default :
					showMessage();
					break;
			}
	 }	

}
