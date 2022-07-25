#include "GPT.h"

/* 
   {Channel, Tick Frequency, Max Ticks, Mode, Notification}
   
   Example : {TIMER0_16_32, 16, 128, CONTINUOUS, &Gpt_Notification}

*/

Gpt_ConfigType Gpt_Cfg[ACTIVE_TIMERS_NUM] = {TIMER0_16_32, 16, 128, CONTINUOUS, &Gpt_Notification};
	

