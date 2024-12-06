#ifndef RGB_LED_H_
#define RGB_LED_H_

#include <atmel_start.h>

// Function declarations
void rgb_led_init(void);
void set_blue_pwm(uint8_t duty);    // PA05
void set_green_pwm(uint8_t duty);   // PA06
void set_red_pwm(uint8_t duty);     // PA07

#endif /* RGB_LED_H_ */
