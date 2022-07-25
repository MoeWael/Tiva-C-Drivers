/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  Header file for DIO Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
	Channel_A0,
	Channel_A1,
	Channel_A2,
	Channel_A3,
	Channel_A4,
	Channel_A5,
	Channel_A6,
	Channel_A7,
	Channel_B0,
	Channel_B1,
	Channel_B2,
	Channel_B3,
	Channel_B4,
	Channel_B5,
	Channel_B6,
	Channel_B7,
	Channel_C0,
	Channel_C1,
	Channel_C2,
	Channel_C3,
	Channel_C4,
	Channel_C5,
	Channel_C6,
	Channel_C7,
	Channel_D0,
	Channel_D1,
	Channel_D2,
	Channel_D3,
	Channel_D4,
	Channel_D5,
	Channel_D6,
	Channel_D7,
	Channel_E0,
	Channel_E1,
	Channel_E2,
	Channel_E3,
	Channel_E4,
	Channel_E5,
	Channel_E6,
	Channel_E7,
	Channel_F0,
	Channel_F1,
	Channel_F2,
	Channel_F3,
	Channel_F4,
	Channel_F5,
	Channel_F6,
	Channel_F7

}Dio_ChannelType;

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF

}Dio_PortType;

typedef enum{
	Dio_LOW,
	Dio_HIGH

}Dio_LevelType;

typedef u8 Dio_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

//Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
