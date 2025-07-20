#include "rcc.h"


void HSE_SetSysClockTo72(uint32_t pllmul){
	
	uint32_t HSEStartUpStatus = 0;
	
	// 把RCC 外设初始化成复位状态
	RCC_DeInit();
	
	
	//使能HSE，开启外部晶振，野火STM32F103 系列开发板用的是8M
	RCC_HSEConfig(RCC_HSE_ON);
	
	// 等待HSE 启动稳定
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	// 只有HSE 稳定之后则继续往下执行
 if (HSEStartUpStatus == SUCCESS) 
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		
		// 如果配置的SYSCLK 超出了范围的话，则会进入硬件错误，程序就死了
		// 0：0 < SYSCLK <= 24M
		// 1：24< SYSCLK <= 48M
		// 2：48< SYSCLK <= 72M
		FLASH_SetLatency(FLASH_Latency_2);
		
		// AHB 预分频因子设置为1 分频，HCLK = SYSCLK
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		
		// APB2 预分频因子设置为1 分频，PCLK2 = HCLK
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		// APB1 预分频因子设置为1 分频，PCLK1 = HCLK/2
		RCC_PCLK1Config(RCC_HCLK_Div2);
		
		//-----------------设置各种频率主要就是在这里设置-------------------//
		// 设置PLL 时钟来源为HSE，设置PLL 倍频因子
		// PLLCLK = 8MHz * pllmul
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllmul);
		//-------------------------------------------------------------//
		
		// 开启PLL
		RCC_PLLCmd(ENABLE);
		
		// 等待PLL 稳定
	 while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {}
	 
	 // 当PLL 稳定之后，把PLL 时钟切换为系统时钟SYSCLK
	 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	 
	// 读取时钟切换状态位，确保PLLCLK 被选为系统时钟
	 while (RCC_GetSYSCLKSource() != 0x08) {}

 }
 else
	 {
			// 如果HSE 开启失败，那么程序就会来到这里，用户可在这里添加出错的代码处理
			// 当HSE 开启失败或者故障的时候，单片机会自动把HSI设置为系统时钟，
			// HSI 是内部的高速时钟，8MHZ
		 while (1) {}
	 }
	
}
void HSI_SetSysClockTo72(uint32_t pllmul)
{
	
	uint32_t HSIStartUpStatus = 0;
	
	// 把RCC 外设初始化成复位状态
	RCC_DeInit();
	
	//使能HSI
	RCC_HSICmd(ENABLE);
	
	// 等待HSI 就绪
	HSIStartUpStatus = RCC->CR & RCC_CR_HSIRDY;
	
	// 只有HSI 就绪之后则继续往下执行
	if (HSIStartUpStatus == RCC_CR_HSIRDY) {
		// 这两句是操作FLASH 闪存用到的，如果不操作FLASH，这两个注释掉也没影响
		// 使能FLASH 预存取缓冲区
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		// SYSCLK 周期与闪存访问时间的比例设置，这里统一设置成2
		// 设置成2 的时候，SYSCLK 低于48M 也可以工作，如果设置成0 或者1 的时候，
		// 如果配置的SYSCLK 超出了范围的话，则会进入硬件错误，程序就死了
		// 0：0 < SYSCLK <= 24M
		// 1：24< SYSCLK <= 48M
		// 2：48< SYSCLK <= 72M
		FLASH_SetLatency(FLASH_Latency_2);
		
		 // AHB 预分频因子设置为1 分频，HCLK = SYSCLK
		RCC_HCLKConfig(RCC_SYSCLK_Div1);

		// APB2 预分频因子设置为1 分频，PCLK2 = HCLK
		RCC_PCLK2Config(RCC_HCLK_Div1);

		// APB1 预分频因子设置为1 分频，PCLK1 = HCLK/2
		RCC_PCLK1Config(RCC_HCLK_Div2);

		//-----------设置各种频率主要就是在这里设置-------------------//
		// 设置PLL 时钟来源为HSI，设置PLL 倍频因子
		// PLLCLK = 4MHz * pllmul
		RCC_PLLConfig(RCC_PLLSource_HSI_Div2, pllmul);
		
		
		// 开启PLL
		RCC_PLLCmd(ENABLE);
		
		// 等待PLL 稳定
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {}
			
			
		// 当PLL 稳定之后，把PLL 时钟切换为系统时钟SYSCLK
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
			
		// 读取时钟切换状态位，确保PLLCLK 被选为系统时钟
		while (RCC_GetSYSCLKSource() != 0x08) {}
	}
	else {
		// 如果HSI 开启失败，那么程序就会来到这里，用户可在这里添加出错的代码处理
		while (1) {}
			
	}
	
	
}
void MCO_GPIO_Config(void)
{
	RCC_APB2PeriphClockCmd(MCO_PIN,ENABLE);
	
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin=MCO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(MCO_PORT,&GPIO_InitStruct);
	
	
}

