#include <atmel_start.h>
#include "user_timer.h"
#include "user_uart.h"
#include "user_rgb.h"
#include "user_rgb.h"

/**
 * Example of using TIMER_0.
 */
//uint16_t test_type = 300;


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	TIMER_0_enable();
	//rgb_led_init();    // Initialize RGB LED PWM
	
	wdt_enable(&WDT_0);
	USART_0_init_PROCESS();
	
	
	hri_tccount16_write_CC_reg(TC0, 1, 0);
	hri_tccount16_write_CC_reg(TC1, 0, 0);
	hri_tccount16_write_CC_reg(TC1, 1, 0);

	//// Set initial LED colors
	//set_blue_pwm(128);    // 50% brightness
	//set_green_pwm(64);    // 25% brightness
	//set_red_pwm(192);     // 75% brightness
	
	while (1) {
	/*	wdt_feed(&WDT_0);*/
		dimming();
		
		
		if(isReset==1){
			wdt_feed(&WDT_0);
			isReset=0;
		}

		// process_modbus_request();
	
		//pwm_set_parameters(&PWM_GREEN_RED, 1000, 1);
		//pwm_enable(&PWM_GREEN_RED);
	
		//hri_tccount16_write_CC_reg(TC0, 1, 5);
		//hri_tccount8_write_CC_reg(TC1, 0, 5);
		//hri_tccount8_write_CC_reg(TC1, 1, 10);

	


		if (rx_complete) {
			process_modbus_request();
			rx_count = 0;
			rx_complete = false;
		}
		asm("NOP");
	}
}
