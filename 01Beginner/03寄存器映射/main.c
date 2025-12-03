#include "stm32f10x.h"                  // Device header


void  SystemInit(void);

/*
	置位:		|=
	清零: 	&=~
*/
int main(void)
{

    // 6.3.7 APB2外设时钟使能寄存器(RCC_APB2ENR)
    // 起始地址：0x40021000  偏移地址：0x18
    // 开启时钟B  3
    // 开启时钟E  6


    // *( unsigned int * )(0x40021000+0x18) |= ( 1 << 3 );
    RCC_APB2ENR |= ( 1 << 3 );



    // 8.2.1 端口配置低寄存器(GPIOx_CRL)
    // GPIO端口B起始地址：0x40010C00
    // 配置输出模式
    // 地址偏移：0x00

    // *( unsigned int * )(0x40010C00) &= ~( 0x0f << (4 * 5) );
    // *( unsigned int * )(0x40010C00) |= ( 1 << (4 * 5) );

    GPIOB_CRL &= ~(0x0f << (4 * 5));
    GPIOB_CRL |= (1 << (4 * 5));

    // 8.2.4 端口输出数据寄存器(GPIOx_ODR)
    // 偏移地址：0x0C
    // 控制PB5   1 << 5 地址偏移5

    // *( unsigned int * )(0x40010C00+0x0C) &= ~( 1 << 5 ); // 打开
    // *( unsigned int * )(0x40010C00+0x0C) |= ( 1 << 5 );  // 关闭
		
    GPIOB_ODR &= ~( 1 << 5 ); // 打开
    // GPIOB_ODR |= ( 1 << 5 ); // 关闭
}


void  SystemInit(void)
{

}
