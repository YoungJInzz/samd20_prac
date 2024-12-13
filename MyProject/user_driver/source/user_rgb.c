#include <atmel_start.h>
#include "user_timer.h"

 
// static struct timer_task RGB_TIMER_task;
// static uint16_t current_brightness = 0;
// static bool dimming_up = true;
// static bool wait_state = false;
// static uint32_t wait_counter = 0;

// static void rgb_timer_cb(const struct timer_task *const timer_task)
// {
//     if (wait_state) {
//         wait_counter++;
//         if (wait_counter >= 4000) { // 2초 대기 (500Hz timer 기준)
//             wait_state = false;
//             wait_counter = 0;
//             dimming_up = !dimming_up; // 방향 전환
//         }
//         return;
//     }

//     if (dimming_up) {
//         if (current_brightness < 65535) {
//             current_brightness++;
//             hri_tccount16_write_CC_reg(TC0, 1, current_brightness);
//             //hri_tccount16_write_CC_reg(TC1, 0, 65535-current_brightness);
//         } else {
//             wait_state = true;
//         }
//     } else {
//         if (current_brightness > 0) {
//             current_brightness--;
//             hri_tccount16_write_CC_reg(TC0, 1, current_brightness);
//             //hri_tccount16_write_CC_reg(TC1, 0, 65535-current_brightness);
//         } else {
//             wait_state = true;
//         }
//     }
// }

// void dimming(void)
// {
//     // Initialize timer for RGB dimming
//     RGB_TIMER_task.interval = 2;     // 500Hz (2ms interval)
//     RGB_TIMER_task.cb = rgb_timer_cb;
//     RGB_TIMER_task.mode = TIMER_TASK_REPEAT;

//     // Add and start the timer task
//     timer_add_task(&TIMER_0, &RGB_TIMER_task);
// }

uint16_t brightness = 0;
uint8_t	dim_mod = 1;

#define Brigter 1
#define Darker 2

void dimming()
{
	if(timer_ms_count) return;
	
	switch (dim_mod)
	{
	case Brigter: //밝기 조절
		hri_tccount16_write_CC_reg(TC1, 0, brightness);
		timer_ms_count = 10;
		
		brightness +=1;
		if(brightness == 255) 
		{
			dim_mod = Darker;
		}
		break;
		
	case Darker : //대기시간
		brightness -= 1;
		hri_tccount16_write_CC_reg(TC1, 0, brightness);
		timer_ms_count = 10;
		
		if(brightness == 0) 
		{
			dim_mod = Brigter;
			//timer_ms_count = 2000;

		}
		
		//dim_mod = DIM_RUN;
		//brightness = 0;
		break;
		
	}
	
	/*
	for(int brightness = 0; brightness <= 65535; brightness+=10) {
	hri_tccount16_write_CC_reg(TC0, 1, brightness);
	//hri_tccount16_write_CC_reg(TC1, 0, 65535-brightness);
		timer_delay_ms(1);  // loop 3초 3/65535
	}
  
	timer_delay_ms(2000);  
	
	
	for(int brightness = 0; brightness <= 65535; brightness+=10) {
	hri_tccount16_write_CC_reg(TC0, 1, 65535-brightness);
	//hri_tccount16_write_CC_reg(TC1, 0, brightness);
		timer_delay_ms(1); 
	}
  
	timer_delay_ms(2000);  
	*/
}