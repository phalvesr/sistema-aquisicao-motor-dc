/*
        === Projeto: Plataforma embarcada de aquisi��o de dados motor DC ===
        Instituto Federal de Educa��o, Ci�ncia e Tecnologia de S�o Paulo - IFSP
        Autor: Pedro Henrique Alves Rosendo
        Curso: Engenharia de Controle e Automa��o
        Hardware: PIC 16F876A
        Crystal: 16 MHZ
*/

#include "DataSender.h"
#include "ConfigRegisters.h"
#include "MovingAverage.h"
#include "UtilConstants.h"
#include "GlobalVariables.h"

// Fun��o de interrup��o
void interrupt() 
{
    if (INTF_bit)
    {
       CLEAR(INTF_bit);
       pulses++;
    }
    
    if (TMR0IF_bit)
    {
        SET(SEND_MESSAGE);
        tenMillisecondsCounter++;
        LOAD_REGISTER_WITH(TMR0, 99);
        CLEAR(TMR0IF_bit);
    }

    // Base de tempo de 1 minuto
    if (tenMillisecondsCounter == 6000)
    {
       TOGGLE(DEBUG_PIN);
       tenMillisecondsCounter = 0;
       SET(SEND_RPM);
    }
}
// Fun��o principal
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
            
            if (SEND_RPM)
            {
               CLEAR(SEND_RPM);
               sendSerialData(RPM, pulses);
               pulses = 0;
            }
            
            PIC_UART_EOL;
        }
    }
}