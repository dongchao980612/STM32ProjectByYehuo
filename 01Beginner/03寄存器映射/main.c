#include "stm32f10x.h"                  // Device header


void  SystemInit(void);
	
/*
置位:		|=
清零: 	&=~
*/

int main(){
	
	// 6.3.7 APB2外设时钟使能寄存器(RCC_APB2ENR)
	// 偏移地址：0x18
	RCC_APB2ENR |= ( 1 << 3 );
	
	// 8.2.1 端口配置低寄存器(GPIOx_CRL)
	// 偏移地址：0x00
	GPIOB_CRL &= ~(0x0f << 0);
	GPIOB_CRL |= (1 << 0);
	
	// 8.2.4 端口输出数据寄存器(GPIOx_ODR)
	// 地址偏移：0Ch，h表示十六进制
	GPIOB_ODR &= ~( 1 << 0 ); // 打开

	
}

void  SystemInit(void){
	
}
