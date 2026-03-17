#include "stm32f10x.h"
#include "Key.h"
#include "LED.h"

void delay_ms(int ms){
    int i;
    while(ms--){
        for(i=0; i<8000; i++) {
            __NOP(); 
        }
    }
}

int main(void){
    uint8_t keyValue;
    uint8_t ledState = 0;  // LED状态: 0=关闭, 1=打开
    
    // 初始化
    Key_Init();
    LED_Init();
    
    // 配置GPIOA用于流水灯
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    uint16_t i = 0x0001;
    
    while(1){
        // 扫描按键
        keyValue = Key_Scan();
        
        if(keyValue == KEY1_PRESSED){
            // KEY1按下: 切换LED状态
            ledState = !ledState;
            if(ledState){
                LED_On();
            } else {
                LED_Off();
            }
        }
        
        if(keyValue == KEY2_PRESSED){
            // KEY2按下: 手动切换流水灯
            i <<= 1;
            if(i == (0x0040 << 1)){
                i = 0x0001;
            }
            GPIO_Write(GPIOA, ~i);
        }
        
        delay_ms(10);  // 短延时，提高按键响应速度
    }
}
