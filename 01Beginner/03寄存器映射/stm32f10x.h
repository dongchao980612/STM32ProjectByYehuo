#ifndef __STM32F10x_H
#define __STM32F10x_H

typedef unsigned int uint32_t;


//  Periph
#define PERIPH_BASE           ((uint32_t)0x40000000)

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

// RCC
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)


// GPIOB
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOB_CRL             (*(uint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_ODR             (*(uint32_t*)(GPIOB_BASE + 0x0C))


// GPIOE
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOE_CRL             (*(uint32_t*)(GPIOE_BASE + 0x00))
#define GPIOE_ODR             (*(uint32_t*)(GPIOE_BASE + 0x0C))


// RCC_APB2ENR
#define RCC_APB2ENR           (*(uint32_t*)(RCC_BASE + 0x18))






#endif /* __STM32F10x_H */
