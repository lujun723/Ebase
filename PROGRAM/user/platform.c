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
/*	Global variables -----------------------------------------------*/
extern int nano_board_heartbeat_init(void);
extern int core_test_init(void);
/*	Private typedef ------------------------------------------------*/
/*	Private define -------------------------------------------------*/
/*	Private macro --------------------------------------------------*/
/*	Private variables ----------------------------------------------*/

/*	Private function prototypes ------------------------------------*/
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
	nano_board_heartbeat_init();//25
	//core_test_init();
}




/*******************(C)	COPYRIGHT TELLYES *****END OF FILE***********/
