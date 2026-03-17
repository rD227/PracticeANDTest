#include "LED.h"

void LED_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    
    // 使能LED端口时钟
    RCC_APB2PeriphClockCmd(LED_CLK, ENABLE);
    
    // 配置LED引脚为推挽输出
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
    
    // 默认关闭LED
    LED_Off();
}

void LED_On(void) {
    GPIO_ResetBits(LED_PORT, LED_PIN);  // 低电平点亮
}

void LED_Off(void) {
    GPIO_SetBits(LED_PORT, LED_PIN);    // 高电平熄灭
}

void LED_Toggle(void) {
    if (GPIO_ReadOutputDataBit(LED_PORT, LED_PIN) == Bit_SET) {
        LED_On();
    } else {
        LED_Off();
    }
}
