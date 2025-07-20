#include "exti.h"

static void EXTI_NVIC_Config(void){
	
		/*NVIC�жϷ���*/
	NVIC_PriorityGroupConfig(NVIC_PRIORITYGROUP);				//����NVICΪ����2

	
	/*NVIC����*/
	NVIC_InitTypeDef NVIC_InitStructure;						//����ṹ�����
	NVIC_InitStructure.NVIC_IRQChannel = NVIC_IRQN;		//ѡ������NVIC��EXTI0��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ָ��NVIC��·ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//ָ��NVIC��·����ռ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//ָ��NVIC��·����Ӧ���ȼ�Ϊ1
	NVIC_Init(&NVIC_InitStructure);	
}

void EXTI_Config(void)
{
	// EXTI����
	RCC_APB2PeriphClockCmd(EXTI_CLK, ENABLE);		//����AFIO��ʱ�ӣ��ⲿ�жϱ��뿪��AFIO��ʱ��
		
	/*AFIOѡ���ж����� PC14 */
	GPIO_EXTILineConfig(EXTI_PORTSOURCE, EXTI_PORTSOURCE_PIN);// ѡ��PB0Ϊ�ⲿ�ж�����
	
	/*EXTI��ʼ��*/
	EXTI_InitTypeDef EXTI_InitStructure;						//����ṹ�����
	EXTI_InitStructure.EXTI_Line = EXTI_LINE;		//ѡ�������ⲿ�жϵ�0/1����
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//ָ���ⲿ�ж���Ϊ�½��ش���
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;			//ָ���ⲿ�ж���Ϊ�ж�ģʽ
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;					//ָ���ⲿ�ж���ʹ��
	EXTI_Init(&EXTI_InitStructure);								//���ṹ���������EXTI_Init������EXTI����
	

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
