#ifndef _INTERRUPT_INLINER_FUNCTIONS_
#define _INTERRUPT_INLINER_FUNCTIONS_

static inline void checkAndHandleExternalInterrupt()
{
    if (INTF_bit)
    {
       CLEAR(INTF_bit);
       pulses++;
    }
}

static inline void checkAndHandleTimerZeroOverflowEveryTenMilliseconds()
{
    if (TMR0IF_bit)
    {
        SET(SEND_MESSAGE);
        tenMillisecondsCounter++;
        LOAD_REGISTER_WITH(TMR0, 99);
        CLEAR(TMR0IF_bit);
    }
}

static inline void checkAndHandleRPMSendFlagEveryOneSecond()
{
    if (tenMillisecondsCounter == 100)
    {
       tenMillisecondsCounter = 0;
       SET(SEND_RPM);
       PORTA.F5 = ~PORTA.F5;
    }
}

#endif