/* Auto-generated config file hpl_sercom_config.h */
#ifndef HPL_SERCOM_CONFIG_H
#define HPL_SERCOM_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

#ifndef CONF_SERCOM_3_USART_ENABLE
#define CONF_SERCOM_3_USART_ENABLE 1
#endif

// <h> Basic Configuration

// <q> Receive buffer enable
// <i> Enable input buffer in SERCOM module
// <id> usart_rx_enable
#ifndef CONF_SERCOM_3_USART_RXEN
#define CONF_SERCOM_3_USART_RXEN 1
#endif

// <q> Transmitt buffer enable
// <i> Enable output buffer in SERCOM module
// <id> usart_tx_enable
#ifndef CONF_SERCOM_3_USART_TXEN
#define CONF_SERCOM_3_USART_TXEN 1
#endif

// <o> Frame parity
// <0x0=>No parity
// <0x1=>Even parity
// <0x2=>Odd parity
// <i> Parity bit mode for USART frame
// <id> usart_parity
#ifndef CONF_SERCOM_3_USART_PARITY
#define CONF_SERCOM_3_USART_PARITY 0x0
#endif

// <o> Character Size
// <0x0=>8 bits
// <0x1=>9 bits
// <0x5=>5 bits
// <0x6=>6 bits
// <0x7=>7 bits
// <i> Data character size in USART frame
// <id> usart_character_size
#ifndef CONF_SERCOM_3_USART_CHSIZE
#define CONF_SERCOM_3_USART_CHSIZE 0x0
#endif

// <o> Stop Bit
// <0=>One stop bit
// <1=>Two stop bits
// <i> Number of stop bits in USART frame
// <id> usart_stop_bit
#ifndef CONF_SERCOM_3_USART_SBMODE
#define CONF_SERCOM_3_USART_SBMODE 0
#endif

// <o> Baud rate <1-3000000>
// <i> USART baud rate setting
// <id> usart_baud_rate
#ifndef CONF_SERCOM_3_USART_BAUD
#define CONF_SERCOM_3_USART_BAUD 9600
#endif

// </h>

// <e> Advanced configuration
// <id> usart_advanced
#ifndef CONF_SERCOM_3_USART_ADVANCED_CONFIG
#define CONF_SERCOM_3_USART_ADVANCED_CONFIG 0
#endif

// <q> Run in stand-by
// <i> Keep the module running in standby sleep mode
// <id> usart_arch_runstdby
#ifndef CONF_SERCOM_3_USART_RUNSTDBY
#define CONF_SERCOM_3_USART_RUNSTDBY 0
#endif

// <q> Immediate Buffer Overflow Notification
// <i> Controls when the BUFOVF status bit is asserted
// <id> usart_arch_ibon
#ifndef CONF_SERCOM_3_USART_IBON
#define CONF_SERCOM_3_USART_IBON 0
#endif

// <q> Start of Frame Detection Enable
// <i> Will wake the device from any sleep mode if usart_init and usart_enable was run priort to going to sleep. (receive buffer must be enabled)
// <id> usart_arch_sfde
#ifndef CONF_SERCOM_3_USART_SFDE
#define CONF_SERCOM_3_USART_SFDE 0
#endif

// <o> Operating Mode
// <0x0=>USART with external clock
// <0x1=>USART with internal clock
// <i> Drive the shift register by an internal clock generated by the baud rate generator or an external clock supplied on the XCK pin.
// <id> usart_arch_clock_mode
#ifndef CONF_SERCOM_3_USART_MODE
#define CONF_SERCOM_3_USART_MODE 0x1
#endif

// <o> Data Order
// <0=>MSB is transmitted first
// <1=>LSB is transmitted first
// <i> Data order of the data bits in the frame
// <id> usart_arch_dord
#ifndef CONF_SERCOM_3_USART_DORD
#define CONF_SERCOM_3_USART_DORD 1
#endif

// Does not do anything in UART mode
#define CONF_SERCOM_3_USART_CPOL 0

// <o> Debug Stop Mode
// <i> Behavior of the baud-rate generator when CPU is halted by external debugger.
// <0=>Keep running
// <1=>Halt
// <id> usart_arch_dbgstop
#ifndef CONF_SERCOM_3_USART_DEBUG_STOP_MODE
#define CONF_SERCOM_3_USART_DEBUG_STOP_MODE 0
#endif

// </e>

#ifndef CONF_SERCOM_3_USART_CMODE
#define CONF_SERCOM_3_USART_CMODE 0
#endif

#ifndef CONF_SERCOM_3_USART_RXPO
#define CONF_SERCOM_3_USART_RXPO 1 /* RX is on PIN_PA23 */
#endif

#ifndef CONF_SERCOM_3_USART_TXPO
#define CONF_SERCOM_3_USART_TXPO 0 /* TX is on PIN_PA22 */
#endif

/* Set correct parity settings in register interface based on PARITY setting */
#if CONF_SERCOM_3_USART_PARITY == 0
#define CONF_SERCOM_3_USART_PMODE 0
#define CONF_SERCOM_3_USART_FORM 0
#else
#define CONF_SERCOM_3_USART_PMODE CONF_SERCOM_3_USART_PARITY - 1
#define CONF_SERCOM_3_USART_FORM 1
#endif

// Calculate BAUD register value in UART mode
#ifndef CONF_SERCOM_3_USART_BAUD_RATE
#define CONF_SERCOM_3_USART_BAUD_RATE                                                                                  \
	65536 - ((65536 * 16.0f * CONF_SERCOM_3_USART_BAUD) / CONF_GCLK_SERCOM3_CORE_FREQUENCY)
#endif

// <<< end of configuration section >>>

#endif // HPL_SERCOM_CONFIG_H
