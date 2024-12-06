#include <atmel_start.h>
#include "user_timer.h"
#include "user_uart.h"
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
	
	//// Set initial LED colors
	//set_blue_pwm(128);    // 50% brightness
	//set_green_pwm(64);    // 25% brightness
	//set_red_pwm(192);     // 75% brightness
	
	while (1) {
	/*	wdt_feed(&WDT_0);*/
	int8_t test = 1;
	if(isReset==1){
		wdt_feed(&WDT_0);
		isReset=0;
	}

	// process_modbus_request();


	if (rx_complete) {
		process_modbus_request();
		rx_count = 0;
		rx_complete = false;
	}
	asm("NOP");
	}
}