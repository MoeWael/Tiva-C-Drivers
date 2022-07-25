/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  Header file for GPT Module    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "GPT_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_PREDEF_TIMER_100US_32BIT 		0
#define GPT_PREDEF_TIMER_1US_16BIT 		1
#define GPT_PREDEF_TIMER_1US_24BIT 		2
#define GPT_PREDEF_TIMER_1US_32BIT 		3
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
	TIMER0_16_32,
	TIMER1_16_32,
	TIMER2_16_32,
	TIMER3_16_32,
	TIMER4_16_32,
	TIMER5_16_32,
	TIMER0_32_64,
	TIMER1_32_64,
	TIMER2_32_64,
	TIMER3_32_64,
	TIMER4_32_64,
	TIMER5_32_64

}Gpt_ChannelType;

typedef u32 Gpt_ValueType;

typedef enum{
	ONE_SHOT = 1,
	CONTINUOUS

}Gpt_ModeType;

typedef struct{
	
	Gpt_ChannelType GptChannelId;
	u8 GptChannelTickFrequency;
	Gpt_ValueType GptChannelTickValueMax;
	Gpt_ModeType ChannelMode;
	void (*Gpt_Notification)(void);
	
}Gpt_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Gpt_ConfigType Gpt_Cfg[]; 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);

void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

void Gpt_StopTimer(Gpt_ChannelType Channel);

void Gpt_Notification(void);

void Gpt_DisableNotification(Gpt_ChannelType Channel);

void Gpt_EnableNotification(Gpt_ChannelType Channel);

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
 
#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
