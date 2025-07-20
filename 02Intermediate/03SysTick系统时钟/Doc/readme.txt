static __INLINE uint32_t SysTick_Config1(uint32_t ticks)
{ 
	//�����ܵ���װ��ֵ��������Χ
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
  
	// ������װ�ؼĴ���  
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
	
	// �����ж����ȼ�
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  
	// ���õ�ǰ��ֵ�Ĵ���
	SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
	
	// ����ϵͳ��ʱ����ʱ��ԴΪAHBCLK=72M
	// ʹ��ϵͳ��ʱ���ж�
	// ʹ�ܶ�ʱ��
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}
