#ifndef _INTERRUPT_INLINER_FUNCTIONS_
#define _INTERRUPT_INLINER_FUNCTIONS_

/*
        ============= "I'm limited by the technology of my time" =============
        By the time I'm writting this code seems like inline functionallity
        is not ~trully~ implemented in MikroC Pro For PIC. So as result, when
        taking a look on the generated asm file we can see that CALL is still
        been, well, called which points to the fact that inline does not make
        any effect. As result, I'll be macroing what could be pottencially be
        inline function  just for the sake of keeping interrupt function as 
        clean as possible.
                             
                                               -- P.H.A.Rosendo - 04/09/21
*/

#define CHECK_AND_HANDLE_EXTERNAL_INTERRUPT \
        if (INTF_bit) { CLEAR(INTF_bit); pulses++; }
#define CHECK_AND_HANDLE_TIMER_ZERO_OVERFLOW_EVERY_TEN_MILLISECONDS \
        if (TMR0IF_bit) { SET(SEND_MESSAGE); tenMillisecondsCounter++; LOAD_REGISTER_WITH(TMR0, 99); CLEAR(TMR0IF_bit); }
#define CHECK_AND_HANDLE_RPM_SEND_FLAG_EVERY_ONE_SECOND \
        if (tenMillisecondsCounter == 100){ tenMillisecondsCounter = 0; SET(SEND_RPM); }

#endif