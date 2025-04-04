#include "main.h"

int main(void)
{
    ClockConfig();
    GPIO_Config();

    while (1) {
        GPIOC->BSRR |= GPIO_BSRR_BS13_Msk;
        delay(1000000);
        GPIOC->BSRR |= GPIO_BSRR_BR13_Msk;
        delay(1000000);
    }
}

void delay(uint32_t delay_time)
{
    for (int i = 0; i < delay_time; i++)
        __NOP();
}