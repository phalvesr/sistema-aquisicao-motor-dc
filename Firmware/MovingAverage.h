#ifndef _MOVING_AVERAGE_H_
#define _MOVING_AVERAGE_H_

#define MAX_VOLTAGE_READS 16
#define MAX_CURRENT_READS 16

int voltageMovingAverage(int voltagePin)
{
       static int voltageReads[MAX_VOLTAGE_READS];
       unsigned static int index = 0;
       int i;
       double sum = 0;

       if (index > MAX_VOLTAGE_READS - 1)
       {
          index = 0;
       }

       voltageReads[index] = ADC_Get_Sample(voltagePin);

       for (i = 0; i < MAX_VOLTAGE_READS; i++)
       {
          sum += voltageReads[i];
       }

       index++;

       return sum / MAX_VOLTAGE_READS;
}

int currentMovingAverage(int currentPin)
{
       static int voltageReads[MAX_CURRENT_READS];
       unsigned static int index = 0;
       int i;
       double sum = 0;

       if (index > MAX_CURRENT_READS - 1)
       {
          index = 0;
       }

       voltageReads[index] = ADC_Get_Sample(currentPin);

       for (i = 0; i < MAX_CURRENT_READS; i++)
       {
          sum += voltageReads[i];
       }
       
       index++;

       return sum / MAX_CURRENT_READS;
}

#endif