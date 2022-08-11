#include "IntCtrl.h"
#include "PORT.h"
#include "GPIO.h"
#include "GPT.h"
#include "stk_interface.h"
#include "Mcu_HW.h"
#include "common_macros.h"

#define ACTIVE_FREQ_MHZ 16

#define REQUIRED_TIME_MS 200 
#define REQUIRED_TICKS  REQUIRED_TIME_MS*ACTIVE_FREQ_MHZ*1000


	void callbackfun(void){
		
			if(Dio_ReadChannel(Channel_A0)==0){
			Dio_WriteChannel(Channel_A0, 1);
		}
		else {
			Dio_WriteChannel(Channel_A0, 0);
		}	
	}
	
int main(){
	
	SET_BIT(RCC_RCGCGPIO, RCC_GPIOA_EN);
  SET_BIT(RCC_RCGCTIMER, RCC_TIMER0_EN);
	
	Port_Init(&Port_Cfg);
	//Gpt_Init(&Gpt_Cfg);
	//Gpt_StartTimer(TIMER0_16_32, REQUIRED_TICKS);
	
	MSTK_voidInit(STK_CLK_SRC_AHB);
	
	MSTK_voidSetIntervalPeriodic(1000, SYSTICK_TICKS_MS , &callbackfun);
	
	
	while(1){

	}
	
	return 0;
	
}