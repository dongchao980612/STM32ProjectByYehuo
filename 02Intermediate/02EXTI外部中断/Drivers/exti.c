#include "exti.h"

static void EXTI_NVIC_Config(void){
	
		/*NVIC中断分组*/
	NVIC_PriorityGroupConfig(NVIC_PRIORITYGROUP);				//配置NVIC为分组2

	
	/*NVIC配置*/
	NVIC_InitTypeDef NVIC_InitStructure;						//定义结构体变量
	NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQN;		//选择配置NVIC的EXTI0线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//指定NVIC线路使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//指定NVIC线路的抢占优先级为1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//指定NVIC线路的响应优先级为1
	NVIC_Init(&NVIC_InitStructure);	
}

void EXTI_Config(void)
{
	// EXTI配置
	RCC_APB2PeriphClockCmd(EXTI_CLK, ENABLE);		//开启AFIO的时钟，外部中断必须开启AFIO的时钟
		
	/*AFIO选择中断引脚 PC14 */
	GPIO_EXTILineConfig(EXTI_PORTSOURCE, EXTI_PORTSOURCE_PIN);// 选择PB0为外部中断引脚
	
	/*EXTI初始化*/
	EXTI_InitTypeDef EXTI_InitStructure;						//定义结构体变量
	EXTI_InitStructure.EXTI_Line = EXTI_LINE;		//选择配置外部中断的0/1号线
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//指定外部中断线为下降沿触发
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//指定外部中断线为中断模式
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;					//指定外部中断线使能
	EXTI_Init(&EXTI_InitStructure);								//将结构体变量交给EXTI_Init，配置EXTI外设
	

	EXTI_NVIC_Config();
}


void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_LINE)==SET)
	{
		if(GPIO_ReadInputDataBit(KEY_GPIO_PORT,KEY_GPIO_PIN)==0)
		{
			LED_Trun();
		}
		EXTI_ClearITPendingBit(EXTI_LINE);
	}	
}
