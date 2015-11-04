/**
	********************************************************************
	*	@file			chest_board_V1.0.c
	*	@author		Jun.Lu
	*	@version	V1.0.0
	*	@date			25-Feb-2013
	*	@brief		
	********************************************************************
	*	@attention
	*	This file is the master control program of Chest Main Board(CMB).
	*-----------------------------
	*
	*	Change Logs:
	*	Date							Author						Notes
	*	2013-2-25					Jun.Lu						Version V1.0.0
	*
	********************************************************************
	*/

/*	Includes -------------------------------------------------------*/
#include <rtthread.h>
#include "stm32f4xx.h"

/*	Global variables -----------------------------------------------*/
extern int nano_board_heartbeat_init(uint8_t prio);
extern int core_test_init(void);
/*	Private typedef ------------------------------------------------*/
/*	Private define -------------------------------------------------*/
/*	Private macro --------------------------------------------------*/
/*	Private variables ----------------------------------------------*/
enum
{
	BLUETOOTH_PRIO=5,
	RS232_PRIO,
	DATABACK_PRIO,
	PROTOCOL_PRIO,
	ADC_PRIO,
	BATTERY_PRIO,
	SLEEVEPRESSURE_PRIO,
	SLEEVEPOSITION_PRIO,
	EPULSE_PRIO,
	HEARTBEAT_PRIO,
	TOUCH_PRIO,
	DETECT_PRIO,
	SENSORSTATE_PRIO,
	LED_PRIO,
	DEBUG_PRIO
}PRIORITY;
/*	Private function prototypes ------------------------------------*/
extern int nano_board_heartbeat_init(uint8_t prio);
/*	Private fuctions -----------------------------------------------*/

/**
	*	@brief	using for what
	*	@note		description
	*	@param	
	*	@retval	
	*/


/**
	*	@name	2 cmb_platform_init
	*	@brief	Chest Main Board Threads Init Functions Init
	*	@param	None
	*	@retval	None
	*/
void platform_init(void)
{
	nano_board_heartbeat_init(LED_PRIO);//25

}




/*******************(C)	COPYRIGHT TELLYES *****END OF FILE***********/
