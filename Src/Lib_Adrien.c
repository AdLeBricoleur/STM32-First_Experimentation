#include "Lib_Adrien.h"

// Turn on the Nucleo LED2
void LED2_ON(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

// Turn off the Nucleo LED2
void LED2_OFF(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

// Toggle the Nucleo LED2
void LED2_TOGGLE(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

// It's a simple toggle on Nucleo's LED2
void code_0(void)
{
	LED2_TOGGLE();
}

// It's a toggle on Nucleo's LED2
// You can choose the Delay in ms (implement Delay_ms)
void code_1(uint32_t Delay_ms)
{
	LED2_TOGGLE();
	HAL_Delay(Delay_ms);
}

// When Nucleo's button B1 is pressed (low state), Nucleo's LED2 lights up (high state)
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

// It's a 3-state machine linked together according to the choice of tempo
// You have two input parameters:
// - the pointer to the mode being the state number (*mode)
// - the choice of delay in ms (Delay_ms)
// state 0: LED2 is off during Delay_ms
// state 1: LED2 is on during Delay_ms
// state 2: LED2 toggle 10 times every Delay_ms/10
// default: nothing
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

	if((*mode)>=2)
	{
		*mode = 0;
	}
	else
	{
		(*mode)++;
	}
}

// It's a 3-state machine switching from one state to another each time button B1 is pressed without using interrupts
// You have three input parameters:
// - the pointer to the mode being the state number (*mode)
// - the choice of the button blocking delay in ms (Delay_ms_button)
// - the choice of toggle delay in ms (Delay_ms_toggle)
// state 0: LED2 is off
// state 1: LED2 is on
// state 2: LED2 toggle every Delay_ms_toggle
// default: nothing
void code_4(int *mode,uint32_t Delay_ms_button,uint32_t Delay_ms_toggle)
{
	int stateOfPushButton = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

	if ( stateOfPushButton != 1 )
	{
		(*mode)++;

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

// It's a 3-state machine switching from one state to another each time button B1 is pressed with using interrupts
// You have two input parameters:
// - the pointer to the mode being the state number (*mode)
// - the pointer to the toggle flag indicates timer 16 overflows (*toggle_flag)
// state 0: LED2 is off
// state 1: LED2 is on
// state 2: LED2 toggle each time timer 16 overflows (using interrupts)
// default: nothing
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

// This function starts Timer 16.
// You have one input parameter:
// - the pointer to timer 16 structure (*htim16)
void Timer16_start(TIM_HandleTypeDef *htim16)
{
	// Start timer
	HAL_TIM_Base_Start(htim16);
}

// this function toggles LED2 each time timer 16 exceeds 10000
// You have one input parameter:
// - the pointer to timer 16 structure (*htim16)
void Timer16_routine(TIM_HandleTypeDef *htim16)
{
	// If enough time has passed (1 second), toggle LED and get new timestamp
	if (__HAL_TIM_GET_COUNTER(htim16) >= 10000)
	{
		LED2_TOGGLE();
	  __HAL_TIM_SET_COUNTER(htim16,0);
	}
}
