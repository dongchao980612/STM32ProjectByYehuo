#include "iic.h"

void I2C_EE_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* 使能与I2C 有关的时钟*/
	EEPROM_I2C_APBxClock_FUN(EEPROM_I2C_CLK, ENABLE);// 使能I2C外设时钟
	EEPROM_I2C_GPIO_APBxClock_FUN(EEPROM_I2C_GPIO_CLK, ENABLE);

	/* I2C_SCL、I2C_SDA*/
	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SCL_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD; // 开漏输出
	GPIO_Init(EEPROM_I2C_SCL_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD; // 开漏输出
	GPIO_Init(EEPROM_I2C_SDA_PORT, &GPIO_InitStructure);
	
	
	I2C_InitTypeDef I2C_InitStructure;
	
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable ;
	
	/* I2C 配置*/
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;

	/* 高电平数据稳定，低电平数据变化SCL 时钟线的占空比*/
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;

	I2C_InitStructure.I2C_OwnAddress1 =I2Cx_OWN_ADDRESS7;


	/* I2C 的寻址模式*/
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

	/* 通信速率*/
	I2C_InitStructure.I2C_ClockSpeed = I2C_Speed;

	/* I2C 初始化*/
	I2C_Init(EEPROM_I2Cx, &I2C_InitStructure);

	/* 使能I2C */
	I2C_Cmd(EEPROM_I2Cx, ENABLE);
	
	
 }


/*
 * @brief 写一个字节到I2C EEPROM 中
 * @param pBuffer: 缓冲区指针
 * @param WriteAddr: 写地址
 * @retval 正常返回1，异常返回0
 */

void I2C_EE_ByteWrite(uint8_t addr, uint8_t data)
{
	/* 产生I2C 起始信号*/
	I2C_GenerateSTART(EEPROM_I2Cx, ENABLE);
	
	/* 检测EV5 事件并清除标志*/
	while (I2C_CheckEvent(EEPROM_I2Cx, I2C_EVENT_MASTER_MODE_SELECT)==ERROR)
	{

	}
	
	/* 发送EEPROM 设备地址*/
	I2C_Send7bitAddress(EEPROM_I2Cx, EEPROM_ADDRESS,I2C_Direction_Transmitter);
	
	/* 检测EV6 事件并清除标志*/
	 while (!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	 {

	 }
	 
	 //  第二次起始信号
	 /* 发送要写入的EEPROM 内部地址(即EEPROM 内部存储器的地址) */
	I2C_SendData(EEPROM_I2Cx, addr);

	 /* 检测EV8 事件并清除标志*/
	 while (!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	 {

	 }

	 /* 发送一字节要写入的数据*/
	I2C_SendData(EEPROM_I2Cx, data);
	 
	 /* 检测EV8 事件并清除标志*/
	 while (!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	 {

	 }
	 
	 /* 发送停止信号*/
	 I2C_GenerateSTOP(EEPROM_I2Cx, ENABLE);


}

/*
 * @brief 从EEPROM 里面读取一块数据
 * @param pBuffer: 存放从EEPROM 读取的数据的缓冲区指针
 * @param ReadAddr: 接收数据的EEPROM 的地址
 * @param NumByteToRead: 要从EEPROM 读取的字节数
 * @retval 正常返回1，异常返回0
 */

void I2C_EE_BufferRead(uint8_t addr, uint8_t* data,uint8_t NumByteToRead)

{
	/* 产生I2C 起始信号*/
	I2C_GenerateSTART(EEPROM_I2Cx, ENABLE);
	
	/* 检测EV5 事件并清除标志*/
	while (I2C_CheckEvent(EEPROM_I2Cx, I2C_EVENT_MASTER_MODE_SELECT)==ERROR)
	{

	}
	
	/* 发送EEPROM 设备地址*/
	I2C_Send7bitAddress(EEPROM_I2Cx, EEPROM_ADDRESS,I2C_Direction_Transmitter);
	
	/* 检测EV6 事件并清除标志*/
	 while (!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	 {

	 }
	 
	//  第二次起始信号
	 
	/* 产生I2C 起始信号*/
	I2C_GenerateSTART(EEPROM_I2Cx, ENABLE);
	
	/* 检测EV5 事件并清除标志*/
	while (I2C_CheckEvent(EEPROM_I2Cx, I2C_EVENT_MASTER_MODE_SELECT)==ERROR)
	{

	}
	
	/* 第二次 发送EEPROM 设备地址*/
	I2C_Send7bitAddress(EEPROM_I2Cx, EEPROM_ADDRESS,I2C_Direction_Receiver);
	
	/* 检测EV6 事件并清除标志*/
	 while (!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	 {

	 }
		 
	 
	 /* 发送要写入的EEPROM 内部地址(即EEPROM 内部存储器的地址) */

	 /* 检测EV7 事件并清除标志*/

	 
	while (NumByteToRead)
	{
		// 若NumByteToRead=1，表示已经接收到最后一个数据了
		if (NumByteToRead == 1)
		{
			/* 发送非应答信号*/
			 I2C_AcknowledgeConfig(EEPROM_I2Cx, DISABLE);

			/* 发送停止信号*/
			// I2C_GenerateSTOP(EEPROM_I2Cx, ENABLE);
		}
		
		while (!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_RECEIVED))
		{
			
		} 
		
		/* 通过I2C，从设备中读取一个字节的数据*/
		*data = I2C_ReceiveData(EEPROM_I2Cx);
		
		/* 存储数据的指针指向下一个地址*/
		data++;
		
		/* 接收数据自减*/
		NumByteToRead--;
	
	 }



	 /* 发送停止信号*/
	 I2C_GenerateSTOP(EEPROM_I2Cx, ENABLE);
	 
	 I2C_AcknowledgeConfig(EEPROM_I2Cx, ENABLE);
	
}





void I2C_EE_ByetsWrite(uint8_t* pBuffer,uint8_t WriteAddr, uint16_t NumByteToWrite)
{
	
}

void I2C_EE_WaitEepromStandbyState(void)
{
	
}

void I2C_EE_PageWrite(uint8_t* pBuffer, uint8_t WriteAddr,uint8_t NumByteToWrite)
{
	
}

