/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  Source file for GPIO Module
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "GPT.h"
#include "Mcu_HW.h"
#include "common_macros.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 PrescalerValue[12];
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)       
* \Description     : Read Pin level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr){
	
	Gpt_ConfigType *locConfigPtr = ConfigPtr;
	Gpt_ChannelType locChannel;
	Gpt_ModeType locMode;
	Gpt_ValueType locMaxTicks;
	u8 locFreq, locCopyPrescaler, locShiftCount = 0;
	
	for(u8 i=0; i<ACTIVE_TIMERS_NUM; i++){
		locChannel = locConfigPtr[i].GptChannelId;
		locMode = locConfigPtr[i].ChannelMode;
		locMaxTicks = locConfigPtr[i].GptChannelTickValueMax;
		locFreq = locConfigPtr[i].GptChannelTickFrequency;
		
		locCopyPrescaler = 16/locFreq;
		while(locCopyPrescaler != 1){
			
			locShiftCount++;
			locCopyPrescaler>>1;
			
			if(locCopyPrescaler == 0) break;
		}
		
		PrescalerValue[locChannel] = locShiftCount;
		
		CLEAR_BIT(GPTMCTL(locChannel), 0);
		GPTMCFG(locChannel) |= 0x0;
		GPTMTAMR(locChannel) |= locMode;
		SET_BIT(GPTMIMR(locChannel), 0);
		SET_BIT(GPTMTAMR(locChannel), 4);
	}
}



/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);       
* \Description     : Start timer count                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
		
	SET_BIT(GPTMICR(Channel), 0);
	
	GPTMTAILR(Channel) = Value;
	
	SET_BIT(GPTMCTL(Channel), 0);
	
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)       
* \Description     : Stop timer                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	CLEAR_BIT(GPTMCTL(Channel), 0);
}

/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)       
* \Description     : Disable notifications                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	CLEAR_BIT(GPTMIMR(Channel), 0);
}

/******************************************************************************
* \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType Channel)       
* \Description     : Enable notifications                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
	SET_BIT(GPTMIMR(Channel), 0);
	
	SET_BIT(GPTMICR(Channel), 0);
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)       
* \Description     : Get the counted ticks count                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{

	return ((GPTMTAV(Channel) >> PrescalerValue[Channel]) & (0x0000FFFF));

}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)       
* \Description     : Get the counted ticks count                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
	return (GPTMTAILR(Channel) - Gpt_GetTimeElapsed(Channel));
}

/******************************************************************************
* \Syntax          : void Gpt_Notification(void)       
* \Description     : Funtion to be executed as ISR                                    
*                                                                             
* \Sync\Async      :                                                
* \Reentrancy      :                                              
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Gpt_Notification(void)
{
	
}

TIMER0A_Handler(void)
{
	Gpt_Notification();
	
}
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
