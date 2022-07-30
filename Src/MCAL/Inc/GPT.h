

#include "../../Common/Std_Types.h"
#include "../../Common/Platform_Types.h"




#define TimerA_DISABLED                 0
#define TimerA_ENABLED                  1
/***********************************************/

#define config_32bit_in_16_32timer      0
#define config_16bit_in_16_32timer      4
/***********************************************/


#define ONE_SHOT_TIMERA                 1
#define PERIODIC_TIMERA                 2
#define CAPTURE_MODE_TIMERA             3

#define TIMERA_COUNTING_DOWN            0
#define TIMERA_COUNTING_UP              1

#define TIMERA_MATCH_INT_DISABLED       0
#define TIMERA_MATCH_INT_ENABLED        1

#define TIMERA_SNAPSHOT_MODE_DISABLED   0
#define TIMERA_SNAPSHOT_MODE_ENABLED    1

#define TIMERA_COUNT_AT_ENABLE          0
#define TIMERA_COUNT_AT_TRIGGER         1
/***********************************************/


#define TIMERA_TIMEOUT_INT_DISABLED      0
#define TIMERA_TIMEOUT_INT_ENABLED       1

#define GPTM_TIMERA_MATCH_INT_DISABLED   0
#define GPTM_TIMERA_MATCH_INT_ENABLED    1
/***********************************************/
typedef enum{
    Timer0Module,
    Timer1Module,
    Timer2Module,
    Timer3Module,
    Timer4Module,
    Timer5Module
}TimerModules;


/*
A function that initializes the timer, but doesn't start it. (Refer to Section 11.4 of the data sheet)
A function that starts the timer, it takes the timer we want to activate and the time to be loaded to the timer.
A function that stops the timer (Disables the timer)
At this point the timer module should be working and testable.
For the interrupt portion of the timer:
A function that enables the interrupt of the timer.
A function that disables the interrupt of the timer.
The function that will be called when the interrupt is triggered
*/


void GPT_Init(void);
void GPT_StartTimer(TimerModules TimerModule);
void GPT_StopTimer(void);
void GPT_SetPeriodicInterrupt(void);


