/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
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
#include "PORT.h"
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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr )       
* \Description     : Initialize GPIO Ports                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr){

	u8 locPinNum, locDir, locPort, locMode, locAttach, locCurrent, i;
for(i = 0; i < ACTIVE_PORTS_NUM; i++){
	// Loop on number of active ports
	
	locPinNum = (ConfigPtr->pin)%8;
	locDir = ConfigPtr->dir;
	locPort = locPinNum/8;
	locMode = ConfigPtr->mode;
	locAttach = ConfigPtr->attach;
	locCurrent = ConfigPtr->current;

	switch(locPort){
	
		case 0: {
			SET_BIT(GPIO_PORTA_GPIODEN, locPinNum);
			// Enable digital Pin
			if(locDir){
				SET_BIT(GPIO_PORTA_GPIODIR, locPinNum);
				// Set direction bit if output
			}
			else{
				CLEAR_BIT(GPIO_PORTA_GPIODIR, locPinNum);
				// Clear direction pin if input
			}

			if(locMode){
				SET_BIT(GPIO_PORTA_GPIOAFSEL, locPinNum);
				// Set Alternative function bit
				GPIO_PORTA_GPIOPCTL |= locMode << (locPinNum*4);
				// Select mode for choosen pin (4 bits each)
			}
			else{
				CLEAR_BIT(GPIO_PORTA_GPIOAFSEL, locPinNum);
				
			}
			if(locAttach == 0){
				SET_BIT(GPIO_PORTA_GPIOODR, locPinNum);
			}
			else if (locAttach == 1){
				SET_BIT(GPIO_PORTA_GPIOPUR, locPinNum);
			}
			else if (locAttach == 2){
				SET_BIT(GPIO_PORTA_GPIOPDR, locPinNum);
			}
			
			if(locCurrent == 0){
				SET_BIT(GPIO_PORTA_GPIODR2R, locPinNum);
			}
			else if(locCurrent == 1){
				SET_BIT(GPIO_PORTA_GPIODR4R, locPinNum);
			}
			else if(locCurrent == 2){
				SET_BIT(GPIO_PORTA_GPIODR8R, locPinNum);
			}
			
			break;	
		}
		case 1: {
			SET_BIT(GPIO_PORTB_GPIODEN, locPinNum);
			if(locDir){
				SET_BIT(GPIO_PORTB_GPIODIR, locPinNum);
			}
			else{
				CLEAR_BIT(GPIO_PORTB_GPIODIR, locPinNum);
			}

			if(locMode){
				SET_BIT(GPIO_PORTB_GPIOAFSEL, locPinNum);
				GPIO_PORTB_GPIOPCTL |= locMode << (locPinNum*4);
			}
			else{
				CLEAR_BIT(GPIO_PORTB_GPIOAFSEL, locPinNum);
				
			}
			if(locAttach == 0){
				SET_BIT(GPIO_PORTB_GPIOODR, locPinNum);
			}
			else if (locAttach == 1){
				SET_BIT(GPIO_PORTB_GPIOPUR, locPinNum);
			}
			else if (locAttach == 2){
				SET_BIT(GPIO_PORTB_GPIOPDR, locPinNum);
			}
			
			if(locCurrent == 0){
				SET_BIT(GPIO_PORTB_GPIODR2R, locPinNum);
			}
			else if(locCurrent == 1){
				SET_BIT(GPIO_PORTB_GPIODR4R, locPinNum);
			}
			else if(locCurrent == 2){
				SET_BIT(GPIO_PORTB_GPIODR8R, locPinNum);
			}
			
			break;	
		}
		case 2: {
			SET_BIT(GPIO_PORTC_GPIODEN, locPinNum);
			if(locDir){
				SET_BIT(GPIO_PORTC_GPIODIR, locPinNum);
			}
			else{
				CLEAR_BIT(GPIO_PORTC_GPIODIR, locPinNum);
			}

			if(locMode){
				SET_BIT(GPIO_PORTC_GPIOAFSEL, locPinNum);
				GPIO_PORTC_GPIOPCTL |= locMode << (locPinNum*4);
			}
			else{
				CLEAR_BIT(GPIO_PORTC_GPIOAFSEL, locPinNum);
				
			}
			if(locAttach == 0){
				SET_BIT(GPIO_PORTC_GPIOODR, locPinNum);
			}
			else if (locAttach == 1){
				SET_BIT(GPIO_PORTC_GPIOPUR, locPinNum);
			}
			else if (locAttach == 2){
				SET_BIT(GPIO_PORTC_GPIOPDR, locPinNum);
			}
			
			if(locCurrent == 0){
				SET_BIT(GPIO_PORTC_GPIODR2R, locPinNum);
			}
			else if(locCurrent == 1){
				SET_BIT(GPIO_PORTC_GPIODR4R, locPinNum);
			}
			else if(locCurrent == 2){
				SET_BIT(GPIO_PORTC_GPIODR8R, locPinNum);
			}
			
			break;	
		}
		case 3: {
			SET_BIT(GPIO_PORTD_GPIODEN, locPinNum);
			if(locDir){
				SET_BIT(GPIO_PORTD_GPIODIR, locPinNum);
			}
			else{
				CLEAR_BIT(GPIO_PORTD_GPIODIR, locPinNum);
			}

			if(locMode){
				SET_BIT(GPIO_PORTD_GPIOAFSEL, locPinNum);
				GPIO_PORTD_GPIOPCTL |= locMode << (locPinNum*4);
			}
			else{
				CLEAR_BIT(GPIO_PORTD_GPIOAFSEL, locPinNum);
				
			}
			if(locAttach == 0){
				SET_BIT(GPIO_PORTD_GPIOODR, locPinNum);
			}
			else if (locAttach == 1){
				SET_BIT(GPIO_PORTD_GPIOPUR, locPinNum);
			}
			else if (locAttach == 2){
				SET_BIT(GPIO_PORTD_GPIOPDR, locPinNum);
			}
			
			if(locCurrent == 0){
				SET_BIT(GPIO_PORTD_GPIODR2R, locPinNum);
			}
			else if(locCurrent == 1){
				SET_BIT(GPIO_PORTD_GPIODR4R, locPinNum);
			}
			else if(locCurrent == 2){
				SET_BIT(GPIO_PORTD_GPIODR8R, locPinNum);
			}
		
			break;		
		}
		case 4: {
			SET_BIT(GPIO_PORTE_GPIODEN, locPinNum);
			if(locDir){
				SET_BIT(GPIO_PORTE_GPIODIR, locPinNum);
			}
			else{
				CLEAR_BIT(GPIO_PORTE_GPIODIR, locPinNum);
			}

			if(locMode){
				SET_BIT(GPIO_PORTE_GPIOAFSEL, locPinNum);
				GPIO_PORTE_GPIOPCTL |= locMode << (locPinNum*4);
			}
			else{
				CLEAR_BIT(GPIO_PORTE_GPIOAFSEL, locPinNum);
				
			}
			if(locAttach == 0){
				SET_BIT(GPIO_PORTE_GPIOODR, locPinNum);
			}
			else if (locAttach == 1){
				SET_BIT(GPIO_PORTE_GPIOPUR, locPinNum);
			}
			else if (locAttach == 2){
				SET_BIT(GPIO_PORTE_GPIOPDR, locPinNum);
			}
			
			if(locCurrent == 0){
				SET_BIT(GPIO_PORTE_GPIODR2R, locPinNum);
			}
			else if(locCurrent == 1){
				SET_BIT(GPIO_PORTE_GPIODR4R, locPinNum);
			}
			else if(locCurrent == 2){
				SET_BIT(GPIO_PORTE_GPIODR8R, locPinNum);
			}
		
			break;		
		}
		case 5: {
			SET_BIT(GPIO_PORTF_GPIODEN, locPinNum);
			if(locDir){
				SET_BIT(GPIO_PORTF_GPIODIR, locPinNum);
			}
			else{
				CLEAR_BIT(GPIO_PORTF_GPIODIR, locPinNum);
			}

			if(locMode){
				SET_BIT(GPIO_PORTF_GPIOAFSEL, locPinNum);
				GPIO_PORTF_GPIOPCTL |= locMode << (locPinNum*4);
			}
			else{
				CLEAR_BIT(GPIO_PORTF_GPIOAFSEL, locPinNum);
				
			}
			if(locAttach == 0){
				SET_BIT(GPIO_PORTF_GPIOODR, locPinNum);
			}
			else if (locAttach == 1){
				SET_BIT(GPIO_PORTF_GPIOPUR, locPinNum);
			}
			else if (locAttach == 2){
				SET_BIT(GPIO_PORTF_GPIOPDR, locPinNum);
			}
			
			if(locCurrent == 0){
				SET_BIT(GPIO_PORTF_GPIODR2R, locPinNum);
			}
			else if(locCurrent == 1){
				SET_BIT(GPIO_PORTF_GPIODR4R, locPinNum);
			}
			else if(locCurrent == 2){
				SET_BIT(GPIO_PORTF_GPIODR8R, locPinNum);
			}
			
			break;	
		}

	}
}
}

/**********************************************************************************************************************
 *  END OF FILE: PORT.c
 *********************************************************************************************************************/
