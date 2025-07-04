#include "stm32f10x.h"                  // Device header


void  SystemInit(void);
	
/*
��λ:		|=
����: 	&=~
*/

int main(){
	
	// 6.3.7 APB2����ʱ��ʹ�ܼĴ���(RCC_APB2ENR)
	// ƫ�Ƶ�ַ��0x18
	RCC_APB2ENR |= ( 1 << 3 );
	
	// 8.2.1 �˿����õͼĴ���(GPIOx_CRL)
	// ƫ�Ƶ�ַ��0x00
	GPIOB_CRL &= ~(0x0f << 0);
	GPIOB_CRL |= (1 << 0);
	
	// 8.2.4 �˿�������ݼĴ���(GPIOx_ODR)
	// ��ַƫ�ƣ�0Ch��h��ʾʮ������
	GPIOB_ODR &= ~( 1 << 0 ); // ��

	
}

void  SystemInit(void){
	
}
