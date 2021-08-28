/*
        Hardware: PIC 16F876A
        Crystal: 16 MHZ
*/

#include "DataSender.h"
#include "ConfigRegisters.h"
#include "MovingAverage.h"
#include "UtilConstants.h"
#include "GlobalVariables.h"

// Função de interrupção
void interrupt() 
{
     // Base de tempo de 10ms
    if (TMR0IF_bit)
    {
        counter++;
        // Base de tempo de 50ms
        if (counter == 5)
        {
            TOGGLE(DEBUG_PIN);
            counter = 0;
            SET(SEND_MESSAGE);
        }
        
        TMR0 = 99;
        TMR0IF_bit = 0;
    }
}
// Função principal
void main() 
{
     configureRegisters();

    while(true)
    {
        if (SEND_MESSAGE) {
            CLEAR(SEND_MESSAGE);
            voltageMovingAverage(VOLTAGE_INPUT_PIN);
            currentMovingAverage(CURRENT_INPUT_PIN);
            sendSerialData('V', 1023);
            sendSerialData('I', 255);
            PIC_UART_EOL;
        }
    }
}