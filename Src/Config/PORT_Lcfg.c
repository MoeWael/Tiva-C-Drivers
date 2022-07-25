#include "PORT.h"

/* 
   {PIN, Direction, Mode, Internal Attach, Current}
   
   Pin Number
   Direction       : INPUT - OUTPUT
   Mode            : DIGITAL - UART - SSI - I2C - PWM (PIN4) - PWM (PIN5) - CCP - CAN
   Internal Attach : OPEN_DRAIN - PULL_UPP - PULL_DOWN    
   Current         : 2 mA - 4 mA - 8 mA
   Example : {Pin_A1, OUTPUT, DIGITAL, OPEN_DRAIN, mA_2}

*/

Port_ConfigType Port_Cfg[ACTIVE_PORTS_NUM] = {Pin_A0, OUTPUT, DIGITAL, OPEN_DRAIN, mA_2};
	

