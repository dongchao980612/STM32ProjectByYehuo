#include "delay.h"

void Delay_us(uint32_t us)
{
	
	SysTick_Config(SystemCoreClock/1000000);

	for (uint32_t i=0; i<us; i++) {
		// ����������ֵ��С��0��ʱ��CRTL�Ĵ�����λ16����1
		while ( !((SysTick->CTRL)&(1<<16)) ){};
	}
	
	// �ر�SysTick ��ʱ��
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}
void Delay_ms(uint32_t ms){
	while(ms--)
	{
		Delay_us(1000);
	}
}

void Delay_s(uint32_t s)
{
	while (s--)
  {
		Delay_ms(1000);     // 1 s = 1000 ms
		
	}
	
}
