/*
 * IncFile1.h
 *
 * Created: 2024-12-04 오전 11:00:00
 *  Author: sohaj
 */ 
#include <stdint.h>
#include <stdbool.h>
#define TCP485_DIR GPIO(GPIO_PORTB, 10)
extern volatile uint16_t rx_count;
extern volatile bool rx_complete;

void USART_0_init_PROCESS(void);
void process_modbus_request(void);
