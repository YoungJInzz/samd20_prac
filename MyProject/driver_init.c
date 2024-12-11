/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_rtc_base.h>

/*! The buffer size for USART */
#define USART_0_BUFFER_SIZE 16

struct usart_async_descriptor USART_0;
struct timer_descriptor       TIMER_0;

static uint8_t USART_0_buffer[USART_0_BUFFER_SIZE];

struct wdt_descriptor WDT_0;

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_0_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_0_PORT_init()
{

	gpio_set_pin_function(PA22, PINMUX_PA22C_SERCOM3_PAD0);

	gpio_set_pin_function(PA23, PINMUX_PA23C_SERCOM3_PAD1);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_async_init(&USART_0, SERCOM3, USART_0_buffer, USART_0_BUFFER_SIZE, (void *)NULL);
	USART_0_PORT_init();
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, RTC);
	_gclk_enable_channel(RTC_GCLK_ID, CONF_GCLK_RTC_SRC);
	timer_init(&TIMER_0, RTC, _rtc_get_timer());
}

void PWM_BLUE_PORT_init(void)
{

	gpio_set_pin_function(blue, PINMUX_PA05F_TC0_WO1);
}

void PWM_BLUE_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC0);

	_gclk_enable_channel(TC0_GCLK_ID, CONF_GCLK_TC0_SRC);
}

void PWM_GREEN_RED_PORT_init(void)
{

	gpio_set_pin_function(PA06, PINMUX_PA06F_TC1_WO0);

	gpio_set_pin_function(PA07, PINMUX_PA07F_TC1_WO1);
}

void PWM_GREEN_RED_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC1);

	_gclk_enable_channel(TC1_GCLK_ID, CONF_GCLK_TC1_SRC);
}

void WDT_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, WDT);
	_gclk_enable_channel(WDT_GCLK_ID, CONF_GCLK_WDT_SRC);
}

void WDT_0_init(void)
{
	WDT_0_CLOCK_init();
	wdt_init(&WDT_0, WDT);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA08

	// Set pin direction to input
	gpio_set_pin_direction(sw1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(sw1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(sw1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA27

	gpio_set_pin_level(s1_led,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(s1_led, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(s1_led, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA28

	gpio_set_pin_level(s2_led,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(s2_led, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(s2_led, GPIO_PIN_FUNCTION_OFF);

	USART_0_init();

	TIMER_0_init();

	PWM_BLUE_CLOCK_init();

	PWM_BLUE_PORT_init();

	PWM_BLUE_init();

	PWM_GREEN_RED_CLOCK_init();

	PWM_GREEN_RED_PORT_init();

	PWM_GREEN_RED_init();

	WDT_0_init();
}
