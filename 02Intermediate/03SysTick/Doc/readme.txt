static __INLINE uint32_t SysTick_Config1(uint32_t ticks)
{ 
	//不可能的重装载值，超出范围
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
  
	// 设置重装载寄存器  
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
	
	// 设置中断优先级
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  
	// 设置当前数值寄存器
	SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
	
	// 设置系统定时器的时钟源为AHBCLK=72M
	// 使能系统定时器中断
	// 使能定时器
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}
