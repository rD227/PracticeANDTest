#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

// LED引脚定义
#define LED_PIN         GPIO_Pin_12
#define LED_PORT        GPIOB
#define LED_CLK         RCC_APB2Periph_GPIOB

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif
