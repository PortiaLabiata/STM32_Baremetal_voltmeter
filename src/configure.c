#include "configure.h"

void ClockConfig(void)
{
    RCC->CR |= RCC_CR_HSION_Msk; // Starting HSI
    while (!(RCC->CR & RCC_CR_HSIRDY_Msk)) 
        __NOP();

    // Setting PLL source is unnecessary, since reset value is 0 and
    // it corresponds to HSI/2. f=49MHz
    RCC->CFGR |= RCC_CFGR_ADCPRE_DIV4; // Set ADC divider, f=12MHz
    RCC->CFGR |= RCC_CFGR_SW_PLL; // Set PLL as SysTick clock source
    RCC->CFGR |= RCC_CFGR_PLLMULL12_Msk << RCC_CFGR_PLLMULL_Pos; // Setting PLL multiplier
    RCC->CR |= RCC_CR_PLLON_Msk; // Starting PLL
    while (!(RCC->CR & RCC_CR_PLLRDY_Msk)) 
        __NOP();
}

void SysTick_Config(void)
{
    SysTick->CTRL |= (1 << SysTick_CTRL_CLKSOURCE_Pos); // Set AHB clock as SysTick clock source
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    /*
        Calculating reload value: interrupt fires every ms,
                f=48MHz=48 000 000Hz -> 48 000 cycles per ms -> 47 999.
    */
   SysTick->LOAD = 47999;
}

void GPIO_Config(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN_Msk; // Enable GPIOC clocking
    GPIOC->CRH |= (GPIO_MODE_OUTPUT << GPIO_CRH_MODE13_Pos); // Set mode to output
    GPIOC->CRH &= ~(GPIO_OUTPUT_PP << GPIO_CRH_CNF13_Pos); // Set mode to output PP
}