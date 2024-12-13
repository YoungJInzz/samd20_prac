#ifndef USER_SWITCH_H_
#define USER_SWITCH_H_
#include <atmel_start.h>

// Function to read individual switch states
uint8_t read_switch1(void);
uint8_t read_switch2(void);
uint8_t read_switch3(void);
uint8_t read_switch4(void);

// Function to read all switch states as a single value
uint8_t hex_val; 

typedef struct {
    uint8_t pin;
    uint8_t id;
    char* name;
} SwitchConfig;

uint8_t read_switch_hex_value(void);


#endif /* USER_SWITCH_H_ */