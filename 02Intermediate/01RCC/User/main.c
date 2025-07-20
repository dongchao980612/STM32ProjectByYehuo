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
  /* ʹ�� HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* �ȴ�HSE����������ʱ���� */
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

	// ���HSE�����ɹ������½���
  if (HSEStatus == (uint32_t)0x01)
  {
    // ʹ��FLASH Ԥ��ȡ������
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    // SYSCLK�������������ʱ��ı������ã�����ͳһ���ó�2
		// ���ó�2��ʱ��SYSCLK ����48M Ҳ���Թ�����������ó�0����1��ʱ��
		// ������õ�SYSCLK�����˷�Χ�Ļ���������Ӳ�����󣬳��������
		// 0��0 < SYSCLK <= 24M
		// 1��24< SYSCLK <= 48M
		// 2��48< SYSCLK <= 72M 
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    

 
    // HCLK = SYSCLK
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    //PCLK2 = HCLK
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    //PCLK1 = HCLK/2
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;


    //  ����PLLʱ����Դ������PLL��Ƶ���ӣ�PLLCLK = HSE * 9 = 72 MHz
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
                                        RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);


    // ʹ��PLL
    RCC->CR |= RCC_CR_PLLON;

    // �ȴ�PLL�ȶ�
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }
    
    // ѡ��PLL��Ϊϵͳʱ����Դ
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    // ��ȡʱ���л�״̬λ��ȷ��PLLCLK ��ѡΪϵͳʱ��
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { 
		// ���HSE����ʧ�ܣ��û�������������Ӵ���������  
  }
}
#endif
