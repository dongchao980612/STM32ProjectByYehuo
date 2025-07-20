#include "stm32f10x.h"                  // Device header
#include "rcc.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	// HSE_SetSysClockTo72(RCC_PLLMul_16);
	
	MCO_GPIO_Config();
	RCC_MCOConfig(RCC_MCO_SYSCLK);
	
	
	LED_GPIO_Config();
	
	while (1)
		{
			// LED_ON();
			LED(ON);
			Delay(0xFFFFF);
			
			// LED_OFF();
			LED(OFF);
			Delay(0xFFFFF);
    }

}

#if 0

static void SetSysClockTo72(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/    
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待HSE就绪并作超时处理 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

	// 如果HSE启动成功，向下进行
  if (HSEStatus == (uint32_t)0x01)
  {
    // 使能FLASH 预存取缓冲区
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    // SYSCLK周期与闪存访问时间的比例设置，这里统一设置成2
		// 设置成2的时候，SYSCLK 低于48M 也可以工作，如果设置成0或者1的时候，
		// 如果配置的SYSCLK超出了范围的话，则会进入硬件错误，程序就死了
		// 0：0 < SYSCLK <= 24M
		// 1：24< SYSCLK <= 48M
		// 2：48< SYSCLK <= 72M 
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    

 
    // HCLK = SYSCLK
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    //PCLK2 = HCLK
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    //PCLK1 = HCLK/2
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;


    //  设置PLL时钟来源，设置PLL倍频因子，PLLCLK = HSE * 9 = 72 MHz
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
                                        RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);


    // 使能PLL
    RCC->CR |= RCC_CR_PLLON;

    // 等待PLL稳定
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }
    
    // 选择PLL作为系统时钟来源
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    // 读取时钟切换状态位，确保PLLCLK 被选为系统时钟
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { 
		// 如果HSE启动失败，用户可以在这里添加错误代码出来  
  }
}
#endif
