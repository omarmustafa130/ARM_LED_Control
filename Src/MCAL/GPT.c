#include "../Common/Std_Types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Platform_Types.h"
#include "../Common/Mcu_Hw.h"

#include "Inc/GPT.h"
#include "../Config/GPT_Cfg.h"




void GPT_Init(void)
{
    TIMER0_16_32_REG_SET1->GPTMCTL.B.bit_0=0;
    TIMER0_16_32_REG_SET1->GPTMCFG.R=TimerConfig;
    TIMER0_16_32_REG_SET1->GPTMTAMR.R|=(TimerMode);
    TIMER0_16_32_REG_SET1->GPTMTAMR.B.bit_4=(TimerCountDirection);
    TIMER0_16_32_REG_SET1->GPTMTAMR.B.bit_6=(TimerEnableMode);
    TIMER0_16_32_REG_SET1->GPTMTAMR.B.bit_7=(SnapshotMode);
    TIMER0_16_32_REG_SET2->GPTMIMR.B.bit_0=(TimeOutInterrupt);

}
void GPT_StartTimer(TimerModules TimerModule)
{	
		if (TimerModule == 0)
    TIMER0_16_32_REG_SET1->GPTMCTL.B.bit_0=1;
}
void GPT_StopTimer(void)
{
    TIMER0_16_32_REG_SET1->GPTMCTL.B.bit_0=1; 
}
void GPT_SetPeriodicInterrupt(void)
{
		
    TIMER0_16_32_REG_SET2->GPTMTAILR.R|=0x1;
}


/*
 One-Shot/Periodic Timer Mode
The GPTM is configured for One-Shot and Periodic modes by the following sequence:
1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
any changes.
2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.
3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
a. Write a value of 0x1 for One-Shot mode.
b. Write a value of 0x2 for Periodic mode.
4. Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
to select whether to capture the value of the free-running timer at time-out, use an external
trigger to start counting, configure an additional trigger or interrupt, and count up or down.
5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register
(GPTMIMR).
7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
Register (GPTMICR).
If the TnMIE bit in the GPTMTnMR register is set, the RTCRIS bit in the GPTMRIS register is set,
and the timer continues counting. In One-Shot mode, the timer stops counting after the time-out
event. To re-enable the timer, repeat the sequence. A timer configured in Periodic mode reloads
the timer and continues counting after the time-out event.
*/

