#include "user_switch.h"
#include <string.h>

// Global variable to store hex value
uint8_t hex_val = 0;

// Switch configuration array (like a JavaScript object)
SwitchConfig switch_map[] = {
    {sw1, 1, "SW1"},  // Replace SW1_PIN with actual GPIO pin
    {sw2, 2, "SW2"},  // Replace SW2_PIN with actual GPIO pin
    {sw3, 3, "SW3"},  // Replace SW3_PIN with actual GPIO pin
    {sw4, 4, "SW4"}   // Replace SW4_PIN with actual GPIO pin
};

// Number of switches in the configuration
const uint8_t SWITCH_COUNT = sizeof(switch_map) / sizeof(switch_map[0]);

// Read switch by ID
uint8_t read_switch(uint8_t switch_id) {
    for (uint8_t i = 0; i < SWITCH_COUNT; i++) {
        if (switch_map[i].id == switch_id) {
            return !gpio_get_pin_level(switch_map[i].pin);
        }
    }
    return 0;  // Invalid switch ID
}

// Read switch by name
uint8_t read_switch_by_name(const char* switch_name) {
    for (uint8_t i = 0; i < SWITCH_COUNT; i++) {
        if (strcmp(switch_map[i].name, switch_name) == 0) {
            return gpio_get_pin_level(switch_map[i].pin);
        }
    }
    return 0;  // Switch not found
}

// Function to read all switch states as a single hexadecimal value
uint8_t read_switch_hex_value(void) {
    // Construct 4-bit value where sw1 is the 4th bit and sw4 is the 1st bit
    hex_val = 
        (read_switch(1) << 3) | 
        (read_switch(2) << 2) | 
        (read_switch(3) << 1) | 
        read_switch(4);
    
    return hex_val;
}