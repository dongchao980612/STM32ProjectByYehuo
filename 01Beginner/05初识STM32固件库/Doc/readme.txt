1、汇编编写的启动文件
startup_stm32f10x_hd.s：设置堆栈指针、设置PC指针、初始化中断向量表、配置系统时钟、调用C库函数main函数，最终去到C的世界

2、时钟配置文件
system_stm32f10x.c：把外部时钟HSE=8M，经过PLL倍频到72M

3、外设相关的文件
stm32f10x.h：实现内核外面的寄存器映射

xxx：GPIO、USART、I2C、SPI、FSMC
stm32f103x_xx.c：外设的驱动库函数文件
stm32f103x_xx.h：存放外设的初始化结构体，外设初始化结构体成员的参数列表，外设固件库函数的声名

4、内核相关的文件
core_cm3.h：实现内核里面的外设寄存器映射
core_cm3.c

NVIC(嵌套向量中断控制器、系统滴答定时器)
misc.h：
misc.c：

5、头文件的配置文件
stm32f10x_conf.h：头文件的头文件

6、中断服务函数文件
stm32f10x_it.h
stm32f10x_it.c