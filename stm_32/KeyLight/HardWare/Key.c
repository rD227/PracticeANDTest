#include "Key.h"

// 简单延时函数用于消抖
static void Key_Delay(uint16_t time) {
    uint16_t i;
    while(time--) {
        for(i = 0; i < 100; i++);
    }
}

// 按键初始化
void Key_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    
    // 使能按键端口时钟
    RCC_APB2PeriphClockCmd(KEY1_CLK | KEY2_CLK, ENABLE);
    
    // 配置按键引脚为上拉输入
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  // 上拉输入
    GPIO_InitStructure.GPIO_Pin = KEY1_PIN;
    GPIO_Init(KEY1_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = KEY2_PIN;
    GPIO_Init(KEY2_PORT, &GPIO_InitStructure);
}

// 按键扫描 (带消抖)
uint8_t Key_Scan(void) {
    // 检测 KEY1
    if (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == Bit_RESET) {
        Key_Delay(100);  // 消抖延时
        if (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == Bit_RESET) {
            while(GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == Bit_RESET);  // 等待松开
            return KEY1_PRESSED;
        }
    }
    
    // 检测 KEY2
    if (GPIO_ReadInputDataBit(KEY2_PORT, KEY2_PIN) == Bit_RESET) {
        Key_Delay(100);  // 消抖延时
        if (GPIO_ReadInputDataBit(KEY2_PORT, KEY2_PIN) == Bit_RESET) {
            while(GPIO_ReadInputDataBit(KEY2_PORT, KEY2_PIN) == Bit_RESET);  // 等待松开
            return KEY2_PRESSED;
        }
    }
    
    return KEY_NONE;
}
