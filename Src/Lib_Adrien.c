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

void code_0(void)
{
	// option 1
	LED2_TOGGLE();

	//option 2
	//LED2_OFF();
	//LED2_ON();
}

void code_1(void)
{
	LED2_TOGGLE();
	HAL_Delay(1000);
}

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

int code_3(int param_code_3)
{
	switch (param_code_3)
	{
		case 0:
			LED2_OFF();
			HAL_Delay(5000);
			break;
		case 1:
			LED2_ON();
			HAL_Delay(5000);
			break;
		case 2:
			for(int i=0;i<10;i++)
			{
				LED2_TOGGLE();
				HAL_Delay(500);
			}
			break;
		default:
			break;
	}

	if(param_code_3>=2)
	{
		param_code_3 = 0;
	}
	else
	{
		param_code_3++;
	}

	return param_code_3;
}

int code_4(int param_code_4)
{
	int stateOfPushButton = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

	if ( stateOfPushButton != 1 )
	{
		param_code_4++;

		if(param_code_4>2)
		{
			param_code_4 = 0;
		}

		HAL_Delay(1000);
	}

	switch (param_code_4)
	{
		case 0:
			LED2_OFF();
			break;
		case 1:
			LED2_ON();
			break;
		case 2:
			for(int i=0;i<10;i++)
			{
				LED2_TOGGLE();
				HAL_Delay(500);
			}
			break;
		default:
			break;
	}

	return param_code_4;
}
