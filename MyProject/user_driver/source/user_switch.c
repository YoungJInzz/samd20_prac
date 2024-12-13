#include "user_switch.h"
#include <string.h>

uint8_t hex_val = 0;

SwitchConfig switch_map[] = {
    {sw1, 1, "SW1"}, 
    {sw2, 2, "SW2"}, 
    {sw3, 3, "SW3"},  
    {sw4, 4, "SW4"}  
};

const uint8_t SWITCH_COUNT = sizeof(switch_map) / sizeof(switch_map[0]);

uint8_t read_switch(uint8_t switch_id) {
	return !gpio_get_pin_level(switch_map[switch_id-1].pin);
}

uint8_t read_switch_hex_value(void) {
    hex_val = 
        (read_switch(1) << 3) | 
        (read_switch(2) << 2) | 
        (read_switch(3) << 1) | 
        read_switch(4);
    
    return hex_val;
}