/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_usart_async.h>
#include <hal_timer.h>
#include <tc_lite.h>
#include <tc_lite.h>

#include <hal_wdt.h>

extern struct usart_async_descriptor USART_0;
extern struct timer_descriptor       TIMER_0;

extern struct wdt_descriptor WDT_0;

void USART_0_PORT_init(void);
void USART_0_CLOCK_init(void);
void USART_0_init(void);

void PWM_BLUE_CLOCK_init(void);

void PWM_BLUE_PORT_init(void);

int8_t PWM_BLUE_init(void);

void PWM_GREEN_RED_CLOCK_init(void);

void PWM_GREEN_RED_PORT_init(void);

int8_t PWM_GREEN_RED_init(void);

void WDT_0_CLOCK_init(void);
void WDT_0_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
