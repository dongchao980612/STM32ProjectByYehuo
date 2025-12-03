#ifndef __STM32F10x_H
#define __STM32F10x_H

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

//  Periph
#define PERIPH_BASE           ((uint32_t)0x40000000)

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

// RCC
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)


// GPIO
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)



typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

/** 
  * @brief General Purpose I/O
  */
typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} GPIO_TypeDef;


/** 
  * @brief Reset and Clock Control
  */
typedef struct
{
    uint32_t CR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;

} RCC_TypeDef;



#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)

#define RCC ((RCC_TypeDef *)RCC_BASE)


#endif /* __STM32F10x_H */
