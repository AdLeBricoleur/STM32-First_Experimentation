#include "stm32l4xx_hal.h"

/* LED2 */
void LED2_ON(void);
void LED2_OFF(void);
void LED2_TOGGLE(void);

/* test code */
void code_0(void);
void code_1(uint32_t Delay_ms);
void code_2(void);
void code_3(int *mode,uint32_t Delay_ms);
void code_4(int *mode,uint32_t Delay_ms_button,uint32_t Delay_ms_toggle);
void code_5(int *mode,int *toggle_flag);

/* Code Timer 16 */
void Timer16_start(TIM_HandleTypeDef *htim16);
void Timer16_routine(TIM_HandleTypeDef *htim16);

/* Code ADC1 */
void Debug_ADC1_ON(void);
void Debug_ADC1_OFF(void);
void Debug_ADC1_TOGGLE(void);
