#include "usart.h"

static void USART_NVIC_Config(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* 嵌套向量中断控制器组选择*/
	NVIC_PriorityGroupConfig(USART_IPRIORITYGROUP);
	
	/* 配置USART 为中断源*/
	NVIC_InitStructure.NVIC_IRQChannel = USART_IRQN;
	
	/* 抢断优先级为1 */
	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	
	/* 子优先级为1 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	/* 使能中断*/
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	/* 初始化配置NVIC */
	NVIC_Init(&NVIC_InitStructure);
}
void USART_Config(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// 打开串口GPIO 的时钟
	USART_GPIO_APBxClkCmd(USART_GPIO_CLK, ENABLE);

	// 打开串口外设的时钟
	USART_APBxClkCmd(USART_CLK, ENABLE);

	// 将USART Tx 的GPIO 配置为推挽复用模式
	GPIO_InitStructure.GPIO_Pin = USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART_TX_GPIO_PORT, &GPIO_InitStructure);
	
	 // 将USART Rx 的GPIO 配置为浮空输入模式
	 GPIO_InitStructure.GPIO_Pin = USART_RX_GPIO_PIN;
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	 GPIO_Init(USART_RX_GPIO_PORT, &GPIO_InitStructure);

	 // 配置串口的工作参数
	 // 配置波特率
	 USART_InitStructure.USART_BaudRate = USART_BAUDRATE;
	 // 配置针数据字长
	 USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	 // 配置停止位
	 USART_InitStructure.USART_StopBits = USART_StopBits_1;
	 // 配置校验位
	 USART_InitStructure.USART_Parity = USART_Parity_No ;
	 // 配置硬件流控制
	 USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
	 // 配置工作模式，收发一起
	 USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	 // 完成串口的初始化配置
	 USART_Init(USARTx, &USART_InitStructure);

	 // 串口中断优先级配置
	 USART_NVIC_Config();

	 // 使能串口接收中断
	 USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);

	 // 使能串口
	 USART_Cmd(USARTx, ENABLE);
}
// 发送一个字节
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
	/* 发送一个字节数据到USART */
	USART_SendData(pUSARTx,ch);

	/* 等待发送数据寄存器为空*/
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}
// 发送两个字节
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t data)
{
	uint8_t data_h = (data & 0Xff00) >> 8 ,data_l = data & 0xff;
	
	Usart_SendByte(pUSARTx,data_h);
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
	
	Usart_SendByte(pUSARTx,data_l);
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

// 发送8位数据的数组
void Usart_SendArray( USART_TypeDef * pUSARTx, uint8_t* array,uint8_t num)
{
	for(uint8_t i = 0;i < num;i++){
		Usart_SendByte(pUSARTx,array[i]);
		while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
	}
}


 /***************** 发送字符串**********************/
void Usart_SendString( USART_TypeDef * pUSARTx, uint8_t *str)
{
	uint8_t k = 0;
	do{
		Usart_SendByte( pUSARTx, *(str + k) );
		k++;
	}while (*(str + k)!='\0');

	 /* 等待发送完成*/
	 while (USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}


//重定向fputc()函数
int fputc(int ch ,FILE *f)
{
	USART_SendData(USARTx,(uint8_t)ch);
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
	
	return ch;
}

//重定向fgetc()函数
int fgetc(FILE *f)
{
	while (USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);
	return (int)USART_ReceiveData(USARTx);
}


// 实现回显
void USART_IRQHandler(void)
{
	uint8_t ucTemp;
	if (USART_GetITStatus(USARTx,USART_IT_RXNE)!=RESET) {
		ucTemp = USART_ReceiveData(USARTx);
		USART_SendData(USARTx,ucTemp); //注释之后没有回显
	}
}

