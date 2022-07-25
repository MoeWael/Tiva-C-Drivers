/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  NVIC
 *
 *  Description:  Header file for NVIC Module    
 *  
 *********************************************************************************************************************/
#ifndef INT_CTRL_H
#define INT_CTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NVIC_GROUPING_OPTION_XXX    4
#define NVIC_GROUPING_OPTION_XXY    5
#define NVIC_GROUPING_OPTION_XYY    6
#define NVIC_GROUPING_OPTION_YYY    7

#define APINT_VECTKEY               0x05FA
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



typedef enum            /*Represent All Interrupt Numbers */
{
	NVIC_GPIO_PORTA  			,
	NVIC_GPIO_PORTB     			,
	NVIC_GPIO_PORTC     			,
	NVIC_GPIO_PORTD     			,
	NVIC_GPIO_PORTE     			,
				
	NVIC_UART0         			,
	NVIC_UART1         			,
				
	NVIC_SSI0          			,
				
	NVIC_I2C0          			,
				
	NVIC_PWM0_FAULT    			,
	NVIC_PWM0_GENERATOR0    		,
	NVIC_PWM0_GENERATOR1    		,
	NVIC_PWM0_GENERATOR2    		,
				
	NVIC_QEI0          			,
				
	NVIC_ADC0_SEQ0    			,
	NVIC_ADC0_SEQ1    			,
	NVIC_ADC0_SEQ2    			,
	NVIC_ADC0_SEQ3    			,
	
	NVIC_TIMER_WATCHDOG 	   		,
	NVIC_TIMER0A      			,
	NVIC_TIMER0B      			,
	NVIC_TIMER1A     			,
	NVIC_TIMER1B      			,
	NVIC_TIMER2A      			,
	NVIC_TIMER2B      			,
	
	NVIC_ANALOG_COMPARATOR0   		,
	NVIC_ANALOG_COMPARATOR1   		,
	
	NVIC_SYSTEM_CONTROL = 28   		,
	
	NVIC_FLASH_EEPROM_CONTROL,
	
	NVIC_GPIO_PORTF    			 	,
	
	NVIC_UART2 = 33   				,
	
	NVIC_SSI1         				,
	
	NVIC_TIMER3A     		,
	NVIC_TIMER3B     		,
	
	NVIC_I2C1         				,
	
	NVIC_QEI1         				,
	
	NVIC_CAN0         				,
	NVIC_CAN1         				,
	
	NVIC_HIBERNATION = 43 			,
	
	NVIC_USB           				,
					
	NVIC_PWM_GENERATOR3     				,
					
	NVIC_UDMA_SOFTWARE 				,
	NVIC_UDMA_ERROR    				,
					
	NVIC_ADC1_SEQ0   				,
	NVIC_ADC1_SEQ1   				,
	NVIC_ADC1_SEQ2   				,
	NVIC_ADC1_SEQ3   				,
	
	NVIC_SSI2 = 57    				,
	NVIC_SSI3         				,
					
	NVIC_UART3        				,
	NVIC_UART4        				,
	NVIC_UART5        				,
	NVIC_UART6        				,
	NVIC_UART7        				,
	
	NVIC_I2C2 = 68    				,
	NVIC_I2C3         				,
	
	NVIC_TIMER4A     		,
	NVIC_TIMER4B     		,
	
	NVIC_TIMER5A = 92		,
	NVIC_TIMER5B     		,
	NVIC_32_64_TIMER0A     		,
	NVIC_32_64_TIMER0B     		,
	NVIC_32_64_TIMER1A     		,
	NVIC_32_64_TIMER1B     		,
	NVIC_32_64_TIMER2A     		,
	NVIC_32_64_TIMER2B     		,
	NVIC_32_64_TIMER3A     		,
	NVIC_32_64_TIMER3B     		,
	NVIC_32_64_TIMER4A     		,
	NVIC_32_64_TIMER4B     		,
	NVIC_32_64_TIMER5A     		,
	NVIC_32_64_TIMER5B     		,
	
	NVIC_SYSTEM_EXCEPTION    		,
	
	NVIC_PWM1_GENERATOR0 = 134   		,
	NVIC_PWM1_GENERATOR1         		,
	NVIC_PWM1_GENERATOR2         		,
	NVIC_PWM1_GENERATOR3         		,
	NVIC_PWM1_FAULT
	
}Nvic_IntType;

typedef struct
{
	Nvic_IntType interruptNumber;
	u8        groupPriority;
	u8        subgroupPriority;
	
}Nvic_CfgType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Nvic_CfgType Nvic_Cfg[];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
void IntCtrl_init(void);
 
#endif  /* INT_CTRL_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
