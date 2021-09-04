#ifndef _REGISTERS_CONFIGURATION_H
#define _REGISTERS_CONFIGURATION_H
#include "UtilConstants.h"


void ConfigureRegisters()
{
  // Registers referents to timers:
  LOAD_REGISTER_WITH(INTCON, 0b11110000);
  LOAD_REGISTER_WITH(TMR0, 99);
  LOAD_REGISTER_WITH(OPTION_REG, 0b11000111);  // Last three bits sets the prescaler:
  /*
                                    000      1 : 2
                                    001      1 : 4
                                    010      1 : 8
                                    011      1 : 16
                                    100      1 : 32
                                    101      1 : 64
                                    110      1 : 128
                                    111      1 : 256

                      Overflow time equation:
               --------------------------------------------
              | Tovf = (256 - TMR0) * prescaler * 4/fosc   |
               --------------------------------------------
  */

  // Registers referents to IOs
  LOAD_REGISTER_WITH(CMCON, 0b00000111);
  LOAD_REGISTER_WITH(ADCON0, 0b10000001);
  LOAD_REGISTER_WITH(ADCON1, 0b10001101);
  
  LOAD_REGISTER_WITH(TRISA, 0b11011011);
  LOAD_REGISTER_WITH(PORTA, 0b11111111);
  LOAD_REGISTER_WITH(PORTB, 0b11111111);
  
  // UART configuration
  UART1_Init(9600);
}
#endif