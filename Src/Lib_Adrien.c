#include "Lib_Adrien.h"

void LED2_ON(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

void LED2_OFF(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

void LED2_TOGGLE(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

// It's a simple toggle on LED2
void code_0(void)
{
	LED2_TOGGLE();
}

// It's a toggle every 1 second on LED2
void code_1(uint32_t Delay_ms)
{
	LED2_TOGGLE();
	HAL_Delay(Delay_ms);
}

// When button B1 is pressed, LED2 lights up
void code_2(void)
{
	int stateOfPushButton = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

	if ( stateOfPushButton == 1 )
	{
		LED2_OFF();
	}
	else
	{
		LED2_ON();
	}
}

// It is a machine with 3 states which is linked automatically every 5 seconds
// LED2 Off then LED2 On and LED2 Toggle
void code_3(int *mode,uint32_t Delay_ms)
{
	switch (*mode)
	{
		case 0:
			LED2_OFF();
			HAL_Delay(Delay_ms);
			break;
		case 1:
			LED2_ON();
			HAL_Delay(Delay_ms);
			break;
		case 2:
			for(int i=0;i<10;i++)
			{
				LED2_TOGGLE();
				HAL_Delay(Delay_ms/10);
			}
			break;
		default:
			break;
	}

	if(*mode>=2)
	{
		*mode = 0;
	}
	else
	{
		*mode++;
	}
}

// It's a 3-state machine that happens each time you press the B1 button (we don't use interrupts)
// LED2 Off then LED2 On and LED2 Toggle
void code_4(int *mode,uint32_t Delay_ms_button,uint32_t Delay_ms_toggle)
{
	int stateOfPushButton = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

	if ( stateOfPushButton != 1 )
	{
		*mode++;

		if(*mode>2)
		{
			*mode = 0;
		}

		HAL_Delay(Delay_ms_button);
	}

	switch (*mode)
	{
		case 0:
			LED2_OFF();
			break;
		case 1:
			LED2_ON();
			break;
		case 2:
			LED2_TOGGLE();
			HAL_Delay(Delay_ms_toggle);
			break;
		default:
			break;
	}
}

// It's a 3-state machine that happens each time you press the B1 button (we use interrupts)
// LED2 Off then LED2 On and LED2 Toggle
void code_5(int *mode,int *toggle_flag)
{
	switch (*mode)
	{
		case 0: // Mode : LED OFF
			LED2_OFF();
			break;
		case 1: // Mode : LED ON
			LED2_ON();
			break;
		case 2: // Mode : LED TOGGLE
			if (*toggle_flag == 1)
			{
				LED2_TOGGLE();
				*toggle_flag = 0;
			}
			break;
		default: // Default Mode
			break;
	}
}
