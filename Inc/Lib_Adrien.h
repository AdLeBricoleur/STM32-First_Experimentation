#include "stm32l4xx_hal.h"

void LED2_ON(void);
void LED2_OFF(void);
void LED2_TOGGLE(void);
void code_0(void);
void code_1(uint32_t Delay_ms);
void code_2(void);
void code_3(int *mode,uint32_t Delay_ms);
void code_4(int *mode,uint32_t Delay_ms_button,uint32_t Delay_ms_toggle);
void code_5(int *mode,int *toggle_flag);
void Timer_init(uint16_t *timer_val,TIM_HandleTypeDef *htim16);
void Timer_Test(uint16_t *timer_val,TIM_HandleTypeDef *htim16);
