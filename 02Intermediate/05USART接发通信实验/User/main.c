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
	 /* ��ʼ��USART ����ģʽΪ115200 8-N-1���жϽ���*/
	USART_Config();

	// Usart_SendString( DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\n");
	Show_Message();
	while (1){
		/* ��ȡ�ַ�ָ��*/
		ch=getchar();
		printf("���յ��ַ���%c\n",ch);
		
		/* �����ַ�ָ�����RGB �ʵ���ɫ*/
		switch (ch)
			{
			case '1':
				LED(ON);
				break;
		case '2':
			LED(OFF);
			break;
		default:
			/* �������ָ��ָ���ַ�����ӡ��ʾ��Ϣ*/
			Show_Message();
			break;
	 }
	}
}


