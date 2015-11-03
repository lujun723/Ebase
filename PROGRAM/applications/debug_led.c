/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 */

/**
 * @addtogroup STM32
 */
/*@{*/

#include <stdio.h>
#include "stm32f4xx.h"
#include <rtthread.h>

static void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//init gpio configuration 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void TIM_Config(void)
{
 TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
 
	/* --------------------------- System Clocks Configuration -----------------*/
  /* TIM7 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Prescaler = 8400 - 1; // 10KHz
  TIM_TimeBaseStructure.TIM_Period = 10000 - 1; // 2 KHz to 2 Hz
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);
 
  /* TIM7 enable counter */
  TIM_Cmd(TIM7, ENABLE);
 
  /* TIM7 enable update interrupt */
  TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);

}

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
 
  /* Enable TIM7 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


ALIGN(RT_ALIGN_SIZE)
static char thread_heartbeat_stack[512];
struct rt_thread thread_heartbeat;
static void rt_thread_entry_heartbeat(void* parameter)
{
    GPIO_Configuration();
	TIM_Config();
	NVIC_Configuration();
	while (1)
    {
		/*
		GPIO_SetBits(GPIOE,GPIO_Pin_15);
		//GPIO_SetBits(GPIOA,GPIO_Pin_12);
		heartbeat_for_lowpower=1;
        rt_thread_delay(RT_TICK_PER_SECOND*2/50);
		
		GPIO_ResetBits(GPIOE,GPIO_Pin_15);
		//GPIO_ResetBits(GPIOA,GPIO_Pin_12);
		heartbeat_for_lowpower=0;
        rt_thread_delay(RT_TICK_PER_SECOND*7/50);
		
		GPIO_SetBits(GPIOE,GPIO_Pin_15);
		//GPIO_SetBits(GPIOA,GPIO_Pin_12);
		heartbeat_for_lowpower=1;
        rt_thread_delay(RT_TICK_PER_SECOND*1/50);
		
		GPIO_ResetBits(GPIOE,GPIO_Pin_15);
		//GPIO_ResetBits(GPIOA,GPIO_Pin_12);
		heartbeat_for_lowpower=0;
		*/
        rt_thread_delay(RT_TICK_PER_SECOND*40/50);
    }
}

int nano_board_heartbeat_init(void)
{
    rt_thread_init(&thread_heartbeat,
                   "heartbeat",
                   rt_thread_entry_heartbeat,
                   RT_NULL,
                   &thread_heartbeat_stack[0],
                   sizeof(thread_heartbeat_stack),25,5);
    rt_thread_startup(&thread_heartbeat);

    return 0;
}

/*@}*/
