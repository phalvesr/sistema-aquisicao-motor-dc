#ifndef _DATA_SENDER_H_
#define _DATA_SENDER_H_

void sendSerialData(char prefix, int serialValue)
{
    char unitsRead, tensRead, hundredsRead, thousandsRead, tensOfThousandsRead;
    
    tensOfThousandsRead = (((serialValue / 10000) % 10) + '0');
    thousandsRead = (((serialValue / 1000) % 10) + '0');
    hundredsRead = (((serialValue / 100) % 10) + '0');
    tensRead = (((serialValue / 10) % 10) + '0');
    unitsRead = ((serialValue % 10) + '0');
    UART1_Write(prefix);
    UART1_Write(':');
    UART1_WRITE(tensOfThousandsRead);
    UART1_Write(thousandsRead);
    UART1_Write(hundredsRead);
    UART1_Write(tensRead);
    UART1_Write(unitsRead);
    UART1_Write(';');
}

#endif