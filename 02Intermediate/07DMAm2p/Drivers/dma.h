#ifndef __DMA_H
#define __DMA_H

#include "stm32f10x.h"                  // Device header


#define DMA_CHANNEL DMA1_Channel4
#define DMA_CLOCK RCC_AHBPeriph_DMA1 

// 传输完成标志
#define DMA_FLAG_TC DMA1_FLAG_TC14


// 串口对应的DMA 请求通道
#define USART_TX_DMA_CHANNEL DMA1_Channel4
 
// 外设寄存器地址
#define USART_DR_ADDRESS (USART1_BASE+0x04)

// 一次发送的数据量
#define SENDBUFF_SIZE 50
extern uint8_t SendBuff[SENDBUFF_SIZE];  // 声名

void DMA_Config(void);



#endif /* __DMA_H */
