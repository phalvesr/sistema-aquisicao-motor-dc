#ifndef _UTIL_CONSTANTS_H_
#define _UTIL_CONSTANTS_H_

// Software constants:
#define true  1
#define false 0
#define VOLTAGE 'V'
#define CURRENT 'I'
#define RPM 'R'

// Hardware map:
#define VOLTAGE_INPUT_PIN 0
#define CURRENT_INPUT_PIN 1
#define DEBUG_PIN PORTA.F5
#define SEND_MESSAGE flagsA.F0
#define SEND_RPM flagsA.F1

// Macros:
#define CLEAR(bit)                           bit = 0
#define SET(bit)                             bit = 1
#define TOGGLE(bit)                          bit = ~bit
#define LOAD_REGISTER_WITH(register, value)  register = value
#define FROM_RPS_TO_RPM(rps)                 rps * 60
#define PIC_UART_EOL                         UART1_Write('\r'); \
                                             UART1_Write('\n')

#endif