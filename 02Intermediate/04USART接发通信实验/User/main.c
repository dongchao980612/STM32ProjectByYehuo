#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"

int main(void)
{
	 /* ��ʼ��USART ����ģʽΪ115200 8-N-1���жϽ���*/
	USART_Config();

	Usart_SendString( DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\n");

 while (1){

 }

}
