#ifndef _MOVING_AVERAGE_H_
#define _MOVING_AVERAGE_H_

#define MAX_VOLTAGE_READS 8
#define MAX_CURRENT_READS 8

double voltageMovingAverage(int voltagePin)
{
       static int voltageReads[MAX_VOLTAGE_READS] = { 0, 0, 0, 0, 0, 0, 0, 0 };
       unsigned static int index = 0;
       int i;
       double sum = 0;

       if (index > MAX_VOLTAGE_READS - 1)
       {
          index = 0;
       }

       // voltageReads[index] = analogRead(voltagePin);

       for (i = 0; i < MAX_VOLTAGE_READS; i++)
       {
          sum += voltageReads[i];
       }

       index++;

       return sum / ((double)MAX_VOLTAGE_READS);
}

double currentMovingAverage(int currentPin)
{
       static int voltageReads[MAX_CURRENT_READS] = { 0, 0, 0, 0, 0, 0, 0, 0 };
       unsigned static int index = 0;
       int i;
       double sum = 0;

       if (index > MAX_CURRENT_READS - 1)
       {
          index = 0;
       }

       // voltageReads[index] = analogRead(voltagePin);

       for (i = 0; i < MAX_CURRENT_READS; i++)
       {
          sum += voltageReads[i];
       }
       
       index++;

       return sum / ((double)MAX_CURRENT_READS);
}

#endif