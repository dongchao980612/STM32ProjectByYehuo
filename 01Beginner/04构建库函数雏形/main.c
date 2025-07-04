#include "stm32f10x.h"                  // Device header
#include "stm32f10x_conf.h"


void  SystemInit(void);
	
/*
置位:		|=
清零: 	&=~
*/

int main(){
#if 0
	// 6.3.7 APB2外设时钟使能寄存器(RCC_APB2ENR)
	RCC->APB2ENR |= ( 1 << 3 );

	// 8.2.1 端口配置低寄存器(GPIOx_CRL)
	GPIOB->CRL &= ~(0x0f << 0);
	GPIOB->CRL |= (1 << 0);
	
	// 8.2.4 端口输出数据寄存器(GPIOx_ODR)
	GPIOB->ODR &= ~( 1 << 0 ); // 打开
#elif 1
		// 6.3.7 APB2外设时钟使能寄存器(RCC_APB2ENR)
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	// 8.2.1 端口配置低寄存器(GPIOx_CRL)
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	// 8.2.4 端口输出数据寄存器(GPIOx_ODR)
	GPIO_SetBits(GPIOB,GPIO_Pin_0);


#endif
	
}

void  SystemInit(void){
	
}
