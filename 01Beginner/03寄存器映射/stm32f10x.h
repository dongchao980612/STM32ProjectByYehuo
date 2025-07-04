#ifndef __STM32F10x_H
#define __STM32F10x_H
 
	
typedef unsigned int uint32_t;


// 外设
#define PERIPH_BASE           ((uint32_t*)0x40000000)


// 总线
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

// RCC
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)


// GPIOB
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)


// RCC_APB2ENR
#define RCC_APB2ENR           (*(uint32_t*)(RCC_BASE + 0x18))


// GPIOB_CRL
#define GPIOB_CRL             (*(uint32_t*)(GPIOB_BASE + 0x00))

// GPIOB_CRH
#define GPIOB_CRH             (*(uint32_t*)(GPIOB_BASE + 0x04))

// GPIOB_IDR
#define GPIOB_IDR             (*(uint32_t*)(GPIOB_BASE + 0x08))

// GPIOB_ODR
#define GPIOB_ODR             (*(uint32_t*)(GPIOB_BASE + 0x0C))

// GPIOB_BSRR
#define GPIOB_BSRR            (*(uint32_t*)(GPIOB_BASE + 0x10))

// GPIOB_BRR
#define GPIOB_BRR             (*(uint32_t*)(GPIOB_BASE + 0x14))

// GPIOB_LCKR
#define GPIOB_LCKR            (*(uint32_t*)(GPIOB_BASE + 0x18))

#endif /* __STM32F10x_H */
