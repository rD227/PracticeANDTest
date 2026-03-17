#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

// 按键引脚定义 (根据你的实际接线修改)
#define KEY1_PIN        GPIO_Pin_0
#define KEY1_PORT       GPIOB
#define KEY1_CLK        RCC_APB2Periph_GPIOB

#define KEY2_PIN        GPIO_Pin_1
#define KEY2_PORT       GPIOB
#define KEY2_CLK        RCC_APB2Periph_GPIOB

// 按键返回值
#define KEY_NONE        0
#define KEY1_PRESSED    1
#define KEY2_PRESSED    2

void Key_Init(void);
uint8_t Key_Scan(void);

#endif
