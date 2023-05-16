#include "stm32l4xx_hal.h"

typedef struct
{
  int mode = 0;
  int toggle_flag = 0;
} LibA_param_TypeDef;

void LED2_ON(void);
void LED2_OFF(void);
void LED2_TOGGLE(void);
void code_0(void);
void code_1(void);
void code_2(void);
int code_3(int param_code_3);
int code_4(int param_code_4);
