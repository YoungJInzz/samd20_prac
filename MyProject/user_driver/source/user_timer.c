/*
 * user_header.c
 *
 * Created: 2024-12-02 오후 4:27:14
 *  Author: sohaj
 */ 
#include <atmel_start.h>

static struct timer_task TIMER_0_task1;
int isReset = 0;

static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{	
	gpio_toggle_pin_level(s1_led);
	gpio_toggle_pin_level(s2_led);
	isReset=1;
	/*wdt_feed(&WDT_0);*/
}



void TIMER_0_enable(void)
{
	TIMER_0_task1.interval = 2000;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
	//TIMER_0_task2.interval = 200;
	//TIMER_0_task2.cb       = TIMER_0_task2_cb;
	//TIMER_0_task2.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_0_task1);
	//timer_add_task(&TIMER_0, &TIMER_0_task2);
	timer_start(&TIMER_0);
}
