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
#include "GPIO.h"
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
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)       
* \Description     : Read Pin level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	u8 locData, locPort, locPin;
	u32 locBit;

	locPort = ChannelId/8;
	locPin = ChannelId%8;
	locBit = 1 << locPin;
/*
	switch(locPort){
		
		case 0:{
			locData = *((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS+(locBit<<2)));
			locData = locData >> locPin;
			break;
		} 
		case 1:{
			locData = *((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS+(locBit<<2)));
			locData = locData >> locPin;
			break;
		}
		case 2:{
			locData = *((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS+(locBit<<2)));
			locData = locData >> locPin;
			break;
		}
		case 3:{
			locData = *((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS+(locBit<<2)));
			locData = locData >> locPin;
			break;
		}
		case 4:{
			locData = *((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS+(locBit<<2)));
			locData = locData >> locPin;
			break;
		}
		case 5:{
			locData = *((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS+(locBit<<2)));
			locData = locData >> locPin;
			break;
		}
	} */
	
		switch(locPort){
		
		case 0:{
			locData = *((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS));
			// Read from Data register
			locData = locData >> locPin;
			// Shift the bit to the least bit
			break;
		} 
		case 1:{
			locData = *((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS));
			locData = locData >> locPin;
			break;
		}
		case 2:{
			locData = *((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS));
			locData = locData >> locPin;
			break;
		}
		case 3:{
			locData = *((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS));
			locData = locData >> locPin;
			break;
		}
		case 4:{
			locData = *((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS));
			locData = locData >> locPin;
			break;
		}
		case 5:{
			locData = *((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS));
			locData = locData >> locPin;
			break;
		}
	}
		
	return (locData&0x01);
	// Return the least bit
}


/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)       
* \Description     : Write Pin level                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	u8 locPin, locPort;
	u32 locBit;
	
	locPort = ChannelId/8;
	locPin = ChannelId%8;
	locBit = 1 << locPin;

	switch(locPort){
		
		case 0:{
			*((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS)) = (Level<<locPin);
			// Write to the data register with the value shifted by the num of the pin
			break;
		} 
		case 1:{
			*((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS)) = (Level<<locPin);
			break;
		}
		case 2:{
			*((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS)) = (Level<<locPin);
			break;
		}
		case 3:{
			*((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS)) = (Level<<locPin);
			break;
		}
		case 4:{
			*((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS)) = (Level<<locPin);
			break;
		}
		case 5:{
			*((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS)) = (Level<<locPin);
			break;
		}
	}
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)       
* \Description     : Read Port                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	u32 locData, maskAddress;
/*	
	maskAddress = 0xFF << 2;

	switch(PortId){
		
		case 0:{
			locData = *((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS+(maskAddress)));
			break;
		} 
		case 1:{
			locData = *((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS+(maskAddress)));
			break;
		}
		case 2:{
			locData = *((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS+(maskAddress)));
			break;
		}
		case 3:{
			locData = *((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS+(maskAddress)));
			break;
		}
		case 4:{
			locData = *((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS+(maskAddress)));
			break;
		}
		case 5:{
			locData = *((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS+(maskAddress)));
			break;
		}
	}
*/

	switch(PortId){
		
		case 0:{
			locData = *((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS));
			// Read the data register 
			break;
		} 
		case 1:{
			locData = *((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS));
			break;
		}
		case 2:{
			locData = *((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS));
			break;
		}
		case 3:{
			locData = *((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS));
			break;
		}
		case 4:{
			locData = *((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS));
			break;
		}
		case 5:{
			locData = *((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS));
			break;
		}
	}	
	return locData;	
	// Return the data
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)       
* \Description     : Write to Port                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	u32 maskAddress;
/*	
	maskAddress = 0xFF << 2;

	switch(PortId){
		
		case 0:{
			*((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS+(maskAddress))) = Level;
			break;
		} 
		case 1:{
			*((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS+(maskAddress))) = Level;
			break;
		}
		case 2:{
			*((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS+(maskAddress))) = Level;
			break;
		}
		case 3:{
			*((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS+(maskAddress))) = Level;
			break;
		}
		case 4:{
			*((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS+(maskAddress))) = Level;
			break;
		}
		case 5:{
			*((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS+(maskAddress))) = Level;
			break;
		}
	}
*/

	switch(PortId){
		
		case 0:{
			*((volatile u32*)(GPIO_PORTA_GPIODATA_ADDRESS)) = Level;
			// Write to data register
			break;
		} 
		case 1:{
			*((volatile u32*)(GPIO_PORTB_GPIODATA_ADDRESS)) = Level;
			break;
		}
		case 2:{
			*((volatile u32*)(GPIO_PORTC_GPIODATA_ADDRESS)) = Level;
			break;
		}
		case 3:{
			*((volatile u32*)(GPIO_PORTD_GPIODATA_ADDRESS)) = Level;
			break;
		}
		case 4:{
			*((volatile u32*)(GPIO_PORTE_GPIODATA_ADDRESS)) = Level;
			break;
		}
		case 5:{
			*((volatile u32*)(GPIO_PORTF_GPIODATA_ADDRESS)) = Level;
			break;
		}
	}	
}
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
