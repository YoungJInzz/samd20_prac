#include <stdint.h>
#include <stdbool.h>
#include <atmel_start.h>
#include <hal_gpio.h>
#include <hal_delay.h>
#include <hal_usart_async.h>
#include "user_uart.h"

// Modbus 관련 상수 정의
#define MODBUS_BUFFER_SIZE 256
#define MODBUS_SLAVE_ID 1
#define MAX_HOLDING_REGISTERS 100  // Holding Register 크기

// 버퍼 및 상태 변수
static uint8_t rx_buffer[MODBUS_BUFFER_SIZE];
static uint8_t tx_buffer[MODBUS_BUFFER_SIZE];
volatile uint16_t rx_count = 0;
volatile bool rx_complete = false;

// Holding Register 배열
static uint16_t holding_registers[MAX_HOLDING_REGISTERS] = {0};

// Holding Register 읽기 함수
static uint16_t get_holding_register(uint16_t address) {
    if (address < MAX_HOLDING_REGISTERS) {
        return holding_registers[address];
    }
    return 0;  // 잘못된 주소
}

// Holding Register 쓰기 함수
static void set_holding_register(uint16_t address, uint16_t value) {
    if (address < MAX_HOLDING_REGISTERS) {
        holding_registers[address] = value;
    }
}

// Pin 정의
#define RS485_TX_PIN GPIO(GPIO_PORTA, 22)  // TX: PA22
#define RS485_RX_PIN GPIO(GPIO_PORTA, 23)  // RX: PA23
#define RS485_DIR_PIN GPIO(GPIO_PORTA, 24) // DIR: PA24

// Direction pin 상태
#define RS485_DIR_TX true   // 송신 모드
#define RS485_DIR_RX false  // 수신 모드

// CRC 계산 함수
static uint16_t modbus_crc16(uint8_t *buffer, uint16_t length) {
    uint16_t crc = 0xFFFF;
    
    for (uint16_t pos = 0; pos < length; pos++) {
        crc ^= (uint16_t)buffer[pos];
        
        for (uint8_t i = 8; i != 0; i--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

// UART 수신 콜백
static void rx_cb_USART_0(const struct usart_async_descriptor *const io_descr) {
    uint8_t received_byte;
    struct io_descriptor *io;
    static uint32_t last_rx_time = 0;
    uint32_t current_time;
    
    if (rx_count > 8) rx_count = 0;
    
    usart_async_get_io_descriptor(&USART_0, &io);
    io_read(io, &received_byte, 1);
    
    // 디버깅 출력
    //struct io_descriptor *debug_io;
    //usart_async_get_io_descriptor(&USART_0, &debug_io);
    //uint8_t debug_msg[4];
    //debug_msg[0] = 0xAA;  // 시작 마커
    //debug_msg[1] = rx_count;
    //debug_msg[2] = received_byte;
    //debug_msg[3] = 0xFF;  // 종료 마커
    //io_write(debug_io, debug_msg, 4);
    
    if (rx_count < MODBUS_BUFFER_SIZE) {
        rx_buffer[rx_count++] = received_byte;
        if (rx_count >= 8) {
            rx_complete = true;
        }
    }
}

// 송신 모드로 전환
static void rs485_set_tx_mode(void) {
    gpio_set_pin_level(RS485_DIR_PIN, RS485_DIR_TX);
    delay_us(10);  // 모드 전환 지연
}

// 수신 모드로 전환
static void rs485_set_rx_mode(void) {
    delay_us(10);  // 마지막 데이터 전송 대기
    gpio_set_pin_level(RS485_DIR_PIN, RS485_DIR_RX);
}

// UART 송신 완료 콜백
static void tx_cb_USART_0(const struct usart_async_descriptor *const io_descr) {
    rs485_set_rx_mode();  // 송신 완료 후 수신 모드로 전환
}

// Read Holding Registers 처리
static void handle_read_holding_registers(uint16_t start_address) {
    uint16_t reg_count = (rx_buffer[4] << 8) | rx_buffer[5];
    
    // 응답 패킷 구성
    tx_buffer[0] = rx_buffer[0];  // Slave ID
    tx_buffer[1] = rx_buffer[1];  // Function Code
    tx_buffer[2] = reg_count * 2; // Byte Count
    
    // 실제 레지스터 값 읽어오기
    for (uint16_t i = 0; i < reg_count; i++) {
        uint16_t reg_value = get_holding_register(start_address + i);
        tx_buffer[3 + i*2] = (reg_value >> 8) & 0xFF;  // 상위 바이트
        tx_buffer[4 + i*2] = reg_value & 0xFF;         // 하위 바이트
    }
    
    uint8_t length = 5 + reg_count * 2;
    
    // CRC 추가
    uint16_t crc = modbus_crc16(tx_buffer, 3 + reg_count * 2);
    tx_buffer[3 + reg_count * 2] = crc & 0xFF;
    tx_buffer[4 + reg_count * 2] = (crc >> 8) & 0xFF;
    
    // 응답 전송
    struct io_descriptor *io;
    rs485_set_tx_mode();
    usart_async_get_io_descriptor(&USART_0, &io);
    io_write(io, tx_buffer, length);
}

// Modbus 요청 처리 함수
void process_modbus_request(void) {
    if (rx_count < 8) return; // 최소 프레임 길이 체크
    
    // CRC 검증
    uint16_t received_crc = (rx_buffer[rx_count-1] << 8) | rx_buffer[rx_count-2];
    uint16_t calculated_crc = modbus_crc16(rx_buffer, rx_count-2);
    
    if (received_crc != calculated_crc) {
        rx_count = 0;  // CRC 오류시 버퍼 리셋
        rx_complete = false;
        return;
    }
    
    // Slave ID 확인
    if (rx_buffer[0] != MODBUS_SLAVE_ID) return;
    
    // Function Code 처리
    uint8_t function_code = rx_buffer[1];
    uint16_t start_address = (rx_buffer[2] << 8) | rx_buffer[3];
    
    switch (function_code) {
        case 0x03: // Read Holding Registers
            handle_read_holding_registers(start_address);
            break;
        // 다른 function code 처리 추가
    }
}

// GPIO 및 UART 초기화
static void rs485_init(void) {
    // TX 핀 설정
    gpio_set_pin_function(RS485_TX_PIN, PINMUX_PA22C_SERCOM3_PAD0);
    
    // RX 핀 설정
    gpio_set_pin_function(RS485_RX_PIN, PINMUX_PA23C_SERCOM3_PAD1);
    
    // Direction 핀 설정
    gpio_set_pin_direction(RS485_DIR_PIN, GPIO_DIRECTION_OUT);
    gpio_set_pin_level(RS485_DIR_PIN, RS485_DIR_RX);    // 초기 상태는 수신
}

void USART_0_init_PROCESS(void) {
    struct io_descriptor *io;
    
    // RS-485 핀 초기화
    rs485_init();
    
    // UART 초기화 및 콜백 등록
    usart_async_register_callback(&USART_0, USART_ASYNC_TXC_CB, tx_cb_USART_0);
    usart_async_register_callback(&USART_0, USART_ASYNC_RXC_CB, rx_cb_USART_0);
    
    usart_async_get_io_descriptor(&USART_0, &io);
    usart_async_enable(&USART_0);
}