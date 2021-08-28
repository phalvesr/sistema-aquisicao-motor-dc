#ifndef _UTIL_CONSTANTS_H_
#define _UTIL_CONSTANTS_H_

// Software constants:
#define true  1
#define false 0

// Hardware map:
#define VOLTAGE_INPUT_PIN 0
#define CURRENT_INPUT_PIN 1
#define DEBUG_PIN PORTA.F2
#define SEND_MESSAGE flagsA.F0

// Macros:
#define CLEAR(bit)   bit = 0
#define SET(bit)     bit = 1
#define TOGGLE(bit)  bit = ~bit
#define PIC_UART_EOL    UART1_Write('\r'); UART1_Write('\n');

#endif