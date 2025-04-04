#pragma once
#include "main.h"

/* Magic numbers */

#define GPIO_MODE_OUTPUT 0b10UL
#define GPIO_OUTPUT_PP   0b00UL
#define GPIO_OUTPUT_OD   0b01UL
#define GPIO_INPUT_P     0b10UL

#define HSI_FREQ         8000000 // Hz
#define SYSCLK_FREQ      (RCC->CFGR >> RCC_CFGR_SWS_Pos) & 0b11

/* General configuration */

void ClockConfig(void);
void GPIO_Config(void);
