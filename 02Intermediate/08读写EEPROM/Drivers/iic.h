#ifndef __IIC_H
#define __IIC_H

#include "stm32f10x.h" 









#define  EEPROM_ADDRESS  0xA0

// IIC
#define EEPROM_I2Cx											I2C1

#define EEPROM_I2C_APBxClock_FUN 				RCC_APB1PeriphClockCmd
#define EEPROM_I2C_CLK 									RCC_APB1Periph_I2C1

#define EEPROM_I2C_GPIO_APBxClock_FUN 	RCC_APB2PeriphClockCmd
#define EEPROM_I2C_GPIO_CLK 						RCC_APB2Periph_GPIOB

#define EEPROM_I2C_SCL_PORT 						GPIOB
#define EEPROM_I2C_SCL_PIN 							GPIO_Pin_6
#define EEPROM_I2C_SDA_PORT 						GPIOB
#define EEPROM_I2C_SDA_PIN 							GPIO_Pin_7


#define I2C_Speed 											400000 
#define I2Cx_OWN_ADDRESS7 							0X0A

void I2C_EE_Config(void);
void I2C_EE_ByteWrite(uint8_t addr, uint8_t data);
void I2C_EE_BufferRead(uint8_t addr, uint8_t* data,uint8_t NumByteToRead);

#endif /* __IIC_H */
