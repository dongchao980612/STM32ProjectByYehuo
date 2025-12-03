#include "stm32f10x.h"                  // Device header

#include "stm32f10x_conf.h"


void  SystemInit(void);

/*
	置位:		|=
	清零: 	&=~
*/

#define LED_CLK	RCC_APB2Periph_GPIOE
#define LED_PORT	GPIOE
#define LED_PIN		GPIO_Pin_5

int main()
{

    // 6.3.7 APB2外设时钟使能寄存器(RCC_APB2ENR)
    // 起始地址：0x40021000  偏移地址：0x18
    // 开启时钟B  3
    // 开启时钟E  6


    // *( unsigned int * )(0x40021000+0x18) |= ( 1 << 3 );
    // RCC_APB2ENR |= ( 1 << 3 );
    // RCC->APB2ENR |= ( 1 << 3 );
    // RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		RCC_APB2PeriphClockCmd(LED_CLK, ENABLE);
	
	
    // 8.2.1 端口配置低寄存器(GPIOx_CRL)
    // GPIO端口B起始地址：0x40010C00
    // 配置输出模式
    // 地址偏移：0x00

    // *( unsigned int * )(0x40010C00) &= ~( 0x0f << (4 * 5) );
    // *( unsigned int * )(0x40010C00) |= ( 1 << (4 * 5) );

    // GPIOB_CRL &= ~(0x0f << (4 * 5));
    // GPIOB_CRL |= (1 << (4 * 5));

    // GPIOB->CRL &= ~(0x0f << (4 * 5));
    // GPIOB->CRL |= (1 << (4 * 5));

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    // GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
		GPIO_InitStruct.GPIO_Pin = LED_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    // GPIO_Init(GPIOB, &GPIO_InitStruct);
		GPIO_Init(LED_PORT, &GPIO_InitStruct);

    // 8.2.4 端口输出数据寄存器(GPIOx_ODR)
    // 偏移地址：0x0C
    // 控制PB5   1 << 5 地址偏移5

    // *( unsigned int * )(0x40010C00+0x0C) &= ~( 1 << 5 ); // 打开
    // *( unsigned int * )(0x40010C00+0x0C) |= ( 1 << 5 );  // 关闭

    // GPIOB_ODR &= ~( 1 << 5 ); // 打开
    // GPIOB_ODR |= ( 1 << 5 ); // 关闭

    // GPIOB->ODR &= ~( 1 << 5 ); // 打开
    // GPIOB->ODR |= ( 1 << 5 ); // 关闭
		
		GPIO_ResetBits(LED_PORT, GPIO_Pin_5);// 打开
    // GPIO_SetBits(GPIOB, GPIO_Pin_5);  // 关闭


}

void  SystemInit(void)
{

}
