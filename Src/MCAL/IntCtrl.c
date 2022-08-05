/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Source file for NVIC Module
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
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
* \Syntax          : void Nvic_Init(void)        
* \Description     : Initialize NVIC Module                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                      
* \Parameters (out):                                                       
* \Return value:   : 
*                                                                     
*******************************************************************************/
void IntCtrl_init(void)
{
	u8 locGroup,locSubGroup,intField,i;
	
	// Set the VECTKEY
	// Choose Priority grouping option
	APINT = (APINT_VECTKEY<<NVIC_VECTKEY) | (NVIC_GROUPING_OPTION<<NVIC_PRIGROUP);
	
	for(i = 0; i<NVIC_ACTIVE_INT_NUM; i++){
		// Loop on all active interrupts
		// Set the choosen bit according to its number
		if(Nvic_Cfg[i].interruptNumber < 32) {
			SET_BIT(NVIC_EN0, (Nvic_Cfg[i].interruptNumber)%32 );
		}
		else if (Nvic_Cfg[i].interruptNumber < 64){
			SET_BIT(NVIC_EN1, (Nvic_Cfg[i].interruptNumber)%32 );
		}
		else if (Nvic_Cfg[i].interruptNumber < 96){
			SET_BIT(NVIC_EN2, (Nvic_Cfg[i].interruptNumber)%32 );
		}
		else if (Nvic_Cfg[i].interruptNumber < 128) {
			SET_BIT(NVIC_EN3, (Nvic_Cfg[i].interruptNumber)%32 );
		}
		else {
			SET_BIT(NVIC_EN4, (Nvic_Cfg[i].interruptNumber)%32 );
		}
	
	locGroup = Nvic_Cfg[i].groupPriority;
	locSubGroup = Nvic_Cfg[i].subgroupPriority;
	
	// Construct the 3 bits group-subgroup combination
#if (NVIC_GROUPING_OPTION == NVIC_GROUPING_OPTION_XXX)
	    intField = locGroup;
#elif (NVIC_GROUPING_OPTION == NVIC_GROUPING_OPTION_XXY) 
        intField = ((locGroup<<1)&0x6) | (locSubGroup&0x1);
#elif (NVIC_GROUPING_OPTION == NVIC_GROUPING_OPTION_XYY) 
        intField = ((locGroup<<2)&0x4) | (locSubGroup&0x3);
#elif (NVIC_GROUPING_OPTION == NVIC_GROUPING_OPTION_YYY) 
        intField = locSubGroup;
#endif

		// Get the address of the register according to the choosen int number
		u32 regAddress = NVIC_BASE_ADDRESS + 0x400 + ((Nvic_Cfg[i].interruptNumber) / 4)*0x004;
		
		// Get the bit offset inside the register
		u32 bitOffset = ((Nvic_Cfg[i].interruptNumber)%4) * 3 + 5 * (((Nvic_Cfg[i].interruptNumber)%4) + 1);
		
		// Write the combination value in the calculated position
		*((volatile u32 *)(regAddress)) = intField<<bitOffset;
	
	
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
