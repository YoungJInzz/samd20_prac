#include <atmel_start.h>

#include "user_rgb.h"
#include "user_switch.h"
#include "user_timer.h"
#include "user_uart.h"

/**
* Example of using TIMER_0.
*/
// uint16_t test_type = 300;

int main(void)
{
	atmel_start_init();

	TIMER_0_enable();

	wdt_enable(&WDT_0);
	USART_0_init_PROCESS();
	//hri_tccount16_write_CC_reg(TC1, 0, 200);
	while (1)
	{
		//dimming();
		read_switch_hex_value();
		changeColor();

		if (isReset == 1)
		{
			wdt_feed(&WDT_0);
			isReset = 0;
		}
		if (rx_complete)
		{
			process_modbus_request();
			rx_count = 0;
			rx_complete = false;
		}
		asm("NOP");
	}
}
