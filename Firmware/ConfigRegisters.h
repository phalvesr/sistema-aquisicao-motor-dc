#ifndef _REGISTERS_CONFIGURATION_H
#define _REGISTERS_CONFIGURATION_H

void ConfigureRegisters()
{
  // Registers referents to timers:
  
  INTCON = 0b11100000;
  TMR0 = 99;
  OPTION_REG = 0b10000111; // Last three bits sets the prescaler:
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
  
  CMCON = 0x07;
  ADCON0 = 0b00000001;
  ADCON1 = 0b10001101;
  
  TRISA = 0b11111011;
  PORTA = 0xFF;
  
  // UART configuration
  UART1_Init(9600);
}
#endif