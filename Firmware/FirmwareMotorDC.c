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
        
        LOAD_REGISTER_WITH(TMR0, 99);
        CLEAR(TMR0IF_bit);
    }
}
// Função principal
void main() 
{
     unsigned int currentMeasure = 0, voltageMeasure = 0;
     configureRegisters();
     
    while(true)
    {
        if (SEND_MESSAGE) {
            CLEAR(SEND_MESSAGE);
            voltageMeasure = voltageMovingAverage(VOLTAGE_INPUT_PIN);
            currentMeasure = currentMovingAverage(CURRENT_INPUT_PIN);
            sendSerialData(VOLTAGE, voltageMeasure);
            sendSerialData(CURRENT, currentMeasure);
            PIC_UART_EOL;
        }
    }
}