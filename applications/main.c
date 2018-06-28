/*
 * File      : main.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2015-07-29     Arda.Fu      first implementation
 */
#include <rtthread.h>
#include <board.h>
#include "bsp_led.h"
#include "drv_nrf24.h"

rt_uint8_t tmp_buf[20] = "5624222222";

int main(void)
{
	rt_hw_nrf_init();
	
	while(1)
	{
		rt_thread_delay(1000);
		
		if(nrf24lxx_data_packet(SET_TX_MODE, tmp_buf) == TX_OK)
		{
			rt_kprintf("Data sent successfully\n");
		}
		else
		{
			rt_kprintf("Data sent fail\n");
		}
	}
	
    return 0;
}





