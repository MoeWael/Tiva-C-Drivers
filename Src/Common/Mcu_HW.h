/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_HW.h
 *       Module:  -
 *
 *  Description:       
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* SysTick Registers */

#define SYSTICK_BASE_ADDRESS 		 0xE000E000

#define STCTRL_OFFSET			 0X010
#define STRELOAD_OFFSET			 0X014
#define STCURRENT_OFFSET		 0X018

#define SYSTICK_STCTRL			 *((volatile u32*)(SYSTICK_BASE_ADDRESS  + STCTRL_OFFSET))
#define SYSTICK_STRELOAD		 *((volatile u32*)(SYSTICK_BASE_ADDRESS  + STRELOAD_OFFSET))
#define SYSTICK_STCURRENT		 *((volatile u32*)(SYSTICK_BASE_ADDRESS  + STCURRENT_OFFSET))

/* NVIC Registers */

#define NVIC_BASE_ADDRESS                0xE000E000

#define APINT                            *((volatile u32*)0xE000ED0C)

#define NVIC_EN0                         *((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_EN1                         *((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))
#define NVIC_EN2                         *((volatile u32*)(NVIC_BASE_ADDRESS + 0x108))
#define NVIC_EN3                         *((volatile u32*)(NVIC_BASE_ADDRESS + 0x10C))
#define NVIC_EN4                         *((volatile u32*)(NVIC_BASE_ADDRESS + 0x110))

#define NVIC_PRI0                        *((volatile u32*)(NVIC_BASE_ADDRESS + 0x400))

#define NVIC_PRIGROUP 			 8
#define NVIC_VECTKEY			 16

/* RCC Registers */

#define RCC_BASE_ADDRESS		 0x400FE000

#define RCC_RCGCTIMER			 *((volatile u32*)(RCC_BASE_ADDRESS + 0x604))
#define RCC_RCGCGPIO			 *((volatile u32*)(RCC_BASE_ADDRESS + 0x608))

#define RCC_GPIOA_EN			 0
#define RCC_GPIOB_EN			 1
#define RCC_GPIOC_EN			 2
#define RCC_GPIOD_EN			 3
#define RCC_GPIOE_EN			 4
#define RCC_GPIOF_EN			 5

#define RCC_TIMER0_EN			 0
#define RCC_TIMER1_EN			 1
#define RCC_TIMER2_EN			 2
#define RCC_TIMER3_EN			 3
#define RCC_TIMER4_EN			 4
#define RCC_TIMER5_EN			 5

/* GPIO Registers */

#define GPIO_PORTA_APB_BASE_ADDRESS	 0x40004000
#define GPIO_PORTB_APB_BASE_ADDRESS	 0x40005000
#define GPIO_PORTC_APB_BASE_ADDRESS	 0x40006000
#define GPIO_PORTD_APB_BASE_ADDRESS	 0x40007000
#define GPIO_PORTE_APB_BASE_ADDRESS	 0x40024000
#define GPIO_PORTF_APB_BASE_ADDRESS	 0x40025000

#define GPIODATA_OFFSET 			 0x000

#define GPIO_PORTA_GPIODATA_ADDRESS	 GPIO_PORTA_APB_BASE_ADDRESS + GPIODATA_OFFSET
#define GPIO_PORTB_GPIODATA_ADDRESS	 GPIO_PORTB_APB_BASE_ADDRESS + GPIODATA_OFFSET
#define GPIO_PORTC_GPIODATA_ADDRESS	 GPIO_PORTC_APB_BASE_ADDRESS + GPIODATA_OFFSET
#define GPIO_PORTD_GPIODATA_ADDRESS	 GPIO_PORTD_APB_BASE_ADDRESS + GPIODATA_OFFSET
#define GPIO_PORTE_GPIODATA_ADDRESS	 GPIO_PORTE_APB_BASE_ADDRESS + GPIODATA_OFFSET
#define GPIO_PORTF_GPIODATA_ADDRESS	 GPIO_PORTF_APB_BASE_ADDRESS + GPIODATA_OFFSET

#define GPIODIR_OFFSET 			 0x400

#define GPIO_PORTA_GPIODIR		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIODIR_OFFSET))
#define GPIO_PORTB_GPIODIR		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIODIR_OFFSET))
#define GPIO_PORTC_GPIODIR		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIODIR_OFFSET))
#define GPIO_PORTD_GPIODIR		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIODIR_OFFSET))
#define GPIO_PORTE_GPIODIR		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIODIR_OFFSET))
#define GPIO_PORTF_GPIODIR		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIODIR_OFFSET))
	 
#define GPIOAFSEL_OFFSET		 0x420

#define GPIO_PORTA_GPIOAFSEL		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIOAFSEL_OFFSET))
#define GPIO_PORTB_GPIOAFSEL		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIOAFSEL_OFFSET))
#define GPIO_PORTC_GPIOAFSEL		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIOAFSEL_OFFSET))
#define GPIO_PORTD_GPIOAFSEL		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIOAFSEL_OFFSET))
#define GPIO_PORTE_GPIOAFSEL		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIOAFSEL_OFFSET))
#define GPIO_PORTF_GPIOAFSEL		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIOAFSEL_OFFSET))

#define GPIOPCTL_OFFSET		 	 0x52C

#define GPIO_PORTA_GPIOPCTL		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIOPCTL_OFFSET))
#define GPIO_PORTB_GPIOPCTL		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIOPCTL_OFFSET))
#define GPIO_PORTC_GPIOPCTL		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIOPCTL_OFFSET))
#define GPIO_PORTD_GPIOPCTL		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIOPCTL_OFFSET))
#define GPIO_PORTE_GPIOPCTL		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIOPCTL_OFFSET))
#define GPIO_PORTF_GPIOPCTL		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIOPCTL_OFFSET))

#define GPIOODR_OFFSET			 0x50C

#define GPIO_PORTA_GPIOODR		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIOODR_OFFSET))
#define GPIO_PORTB_GPIOODR		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIOODR_OFFSET))
#define GPIO_PORTC_GPIOODR		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIOODR_OFFSET))
#define GPIO_PORTD_GPIOODR		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIOODR_OFFSET))
#define GPIO_PORTE_GPIOODR		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIOODR_OFFSET))
#define GPIO_PORTF_GPIOODR		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIOODR_OFFSET))

#define GPIOPUR_OFFSET			 0x510

#define GPIO_PORTA_GPIOPUR		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIOPUR_OFFSET))
#define GPIO_PORTB_GPIOPUR		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIOPUR_OFFSET))
#define GPIO_PORTC_GPIOPUR		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIOPUR_OFFSET))
#define GPIO_PORTD_GPIOPUR		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIOPUR_OFFSET))
#define GPIO_PORTE_GPIOPUR		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIOPUR_OFFSET))
#define GPIO_PORTF_GPIOPUR		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIOPUR_OFFSET))

#define GPIOPDR_OFFSET			 0x514

#define GPIO_PORTA_GPIOPDR		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIOPDR_OFFSET))
#define GPIO_PORTB_GPIOPDR		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIOPDR_OFFSET))
#define GPIO_PORTC_GPIOPDR		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIOPDR_OFFSET))
#define GPIO_PORTD_GPIOPDR		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIOPDR_OFFSET))
#define GPIO_PORTE_GPIOPDR		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIOPDR_OFFSET))
#define GPIO_PORTF_GPIOPDR		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIOPDR_OFFSET))

#define GPIODR2R_OFFSET			 0x500

#define GPIO_PORTA_GPIODR2R		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIODR2R_OFFSET))
#define GPIO_PORTB_GPIODR2R		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIODR2R_OFFSET))
#define GPIO_PORTC_GPIODR2R		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIODR2R_OFFSET))
#define GPIO_PORTD_GPIODR2R		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIODR2R_OFFSET))
#define GPIO_PORTE_GPIODR2R		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIODR2R_OFFSET))
#define GPIO_PORTF_GPIODR2R		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIODR2R_OFFSET))

#define GPIODR4R_OFFSET			 0x504

#define GPIO_PORTA_GPIODR4R		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIODR4R_OFFSET))
#define GPIO_PORTB_GPIODR4R		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIODR4R_OFFSET))
#define GPIO_PORTC_GPIODR4R		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIODR4R_OFFSET))
#define GPIO_PORTD_GPIODR4R		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIODR4R_OFFSET))
#define GPIO_PORTE_GPIODR4R		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIODR4R_OFFSET))
#define GPIO_PORTF_GPIODR4R		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIODR4R_OFFSET))

#define GPIODR8R_OFFSET			 0x508

#define GPIO_PORTA_GPIODR8R		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIODR8R_OFFSET))
#define GPIO_PORTB_GPIODR8R		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIODR8R_OFFSET))
#define GPIO_PORTC_GPIODR8R		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIODR8R_OFFSET))
#define GPIO_PORTD_GPIODR8R		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIODR8R_OFFSET))
#define GPIO_PORTE_GPIODR8R		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIODR8R_OFFSET))
#define GPIO_PORTF_GPIODR8R		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIODR8R_OFFSET))

#define GPIODEN_OFFSET			 0x51C

#define GPIO_PORTA_GPIODEN		 *((volatile u32*)(GPIO_PORTA_APB_BASE_ADDRESS + GPIODEN_OFFSET))
#define GPIO_PORTB_GPIODEN		 *((volatile u32*)(GPIO_PORTB_APB_BASE_ADDRESS + GPIODEN_OFFSET))
#define GPIO_PORTC_GPIODEN		 *((volatile u32*)(GPIO_PORTC_APB_BASE_ADDRESS + GPIODEN_OFFSET))
#define GPIO_PORTD_GPIODEN		 *((volatile u32*)(GPIO_PORTD_APB_BASE_ADDRESS + GPIODEN_OFFSET))
#define GPIO_PORTE_GPIODEN		 *((volatile u32*)(GPIO_PORTE_APB_BASE_ADDRESS + GPIODEN_OFFSET))
#define GPIO_PORTF_GPIODEN		 *((volatile u32*)(GPIO_PORTF_APB_BASE_ADDRESS + GPIODEN_OFFSET))

/*************************************** GPT Registers ******************************************/

#define GPT_TIMERS_BASE_ADDRESS		 0x40030000

#define GPTMTAMR_OFFSET				 0x004
#define GPTMTBMR_OFFSET				 0x008
#define GPTMCTL_OFFSET				 0x00C
#define GPTMIMR_OFFSET				 0x018	 
#define GPTMCFG_OFFSET				 0x000
#define GPTMTAV_OFFSET			 	 0x050
#define GPTMTBV_OFFSET			 	 0x054
#define GPTMTAILR_OFFSET			 0x028
#define GPTMTBILR_OFFSET			 0x02C
#define GPTMICR_OFFSET				 0x024
#define GPTMRIS_OFFSET				 0x01C

#define GPT_TIMERS_BASE_ADDRESS(n)							(0x40030000+(0x1000*(n))+(0x14000*(n/8)))

#define GPTMCFG(n)											*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMCFG_OFFSET)))
#define GPTMTAMR(n)                              			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMTAMR_OFFSET)))
#define	GPTMTBMR(n)                              			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMTBMR_OFFSET)))
#define	GPTMCTL(n)                                			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMCTL_OFFSET)))
#define	GPTMIMR(n)                                			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMIMR_OFFSET)))
#define	GPTMICR(n)                                			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMICR_OFFSET)))
#define GPTMTAILR(n)                             			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMTAILR_OFFSET)))
#define GPTMTBILR(n)                               			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMTBILR_OFFSET)))
#define GPTMTAV(n)                                			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMTAV_OFFSET)))
#define GPTMTBV(n)                                			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMTBV_OFFSET)))
#define GPTMRIS(n)																			*((volatile u32*)(GPT_TIMERS_BASE_ADDRESS(n)+(GPTMRIS_OFFSET)))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_HW.h
 *********************************************************************************************************************/
