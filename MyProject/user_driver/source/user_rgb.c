//#include "user_rgb.h"
//#include <hal_gpio.h>
//
//// PWM instances for each LED
//struct pwm_descriptor PWM_BLUE;
//struct pwm_descriptor PWM_GREEN;
//struct pwm_descriptor PWM_RED;
//
//// Pin 정의
//#define BLUE GPIO(GPIO_PORTA, 5)  // TX: PA22
//#define GREEN GPIO(GPIO_PORTA, 6)  // RX: PA23
//#define RED GPIO(GPIO_PORTA, 7) // DIR: PA24
//
//void rgb_led_init(void)
//{
	//// Configure pins as outputs
	//gpio_set_pin_direction(BLUE, GPIO_DIRECTION_OUT);    // Blue
	//gpio_set_pin_direction(GREEN, GPIO_DIRECTION_OUT);    // Green
	//gpio_set_pin_direction(RED, GPIO_DIRECTION_OUT);    // Red
	//
	//// Initialize PWM for Blue LED (PA05)
	//pwm_init(&PWM_BLUE, TC0, _tc_get_pwm());
	//pwm_set_parameters(&PWM_BLUE, 255, 0);    // period = 255, duty = 0
	//pwm_enable(&PWM_BLUE);
	//
	//// Initialize PWM for Green LED (PA06)
	//pwm_init(&PWM_GREEN, TC1, _tc_get_pwm());
	//pwm_set_parameters(&PWM_GREEN, 255, 0);
	//pwm_enable(&PWM_GREEN);
	//
	//// Initialize PWM for Red LED (PA07)
	//pwm_init(&PWM_RED, TC2, _tc_get_pwm());
	//pwm_set_parameters(&PWM_RED, 255, 0);
	//pwm_enable(&PWM_RED);
//}
//
//void set_blue_pwm(uint8_t duty)
//{
	//pwm_set_parameters(&PWM_BLUE, 255, duty);
//}
//
//void set_green_pwm(uint8_t duty)
//{
	//pwm_set_parameters(&PWM_GREEN, 255, duty);
//}
//
//void set_red_pwm(uint8_t duty)
//{
	//pwm_set_parameters(&PWM_RED, 255, duty);
//}
