#include "../Common/Std_Types.h"
#include "../Common/Platform_Types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Mcu_Hw.h"
#include "../MCAL/Inc/IntCtrl_types.h"
#include "../MCAL/Inc/IntCtrl.h"
#include "../MCAL/Inc/Sys_Ctrl.h"
#include "../MCAL/Inc/ExternalInterrupts.h"
#include "../MCAL/Inc/Port.h"
#include "../MCAL/Inc/Dio.h".h"

#include "../MCAL/Inc/GPT.h"

#include "../Config/IntCtrl_Cfg.h"
#include "../Config/Sys_Ctrl_Cfg.h"
#include "../Config/Port_Cfg.h"
#include "../Config/GPT_Cfg.h"

#define offTime		100
#define onTime		100
static u8 Flag=0;
static u32 Preload_for_ON=0;
static u32 Preload_for_OFF=0;
void GPIOF_Handler(void);
void GPIOF_Handler(void)
{	
  u32 correspondingInterruptPin = GPIO_PORTF_REG_SET1->GPIOMIS.R;

  switch (correspondingInterruptPin)
  {
  case 1:
    /* PF0 caused interrupt */
    /*your ISR*/

    /*Clear interrupt flag*/
    GPIO_PORTF_REG_SET1->GPIOICR.B.bit_0|=1;
    break;
  case 2:
    /* PF1 caused interrupt */
    /*your ISR*/

    /*Clear interrupt flag*/
    GPIO_PORTF_REG_SET1->GPIOICR.B.bit_1=1;
    break;
  case 4:
    /* PF2 caused interrupt */
    /*your ISR*/

    /*Clear interrupt flag*/
    GPIO_PORTF_REG_SET1->GPIOICR.B.bit_2=1;
    break;
  case 8:
    /* PF3 caused interrupt */
    /*your ISR*/

    /*Clear interrupt flag*/
    GPIO_PORTF_REG_SET1->GPIOICR.B.bit_3=1;
    break;
  case 16:
    /* PF4 caused interrupt */
    /*your ISR*/

    /*Clear interrupt flag*/
    GPIO_PORTF_REG_SET1->GPIOICR.B.bit_4=1;
    break;
  } 

}
void TIMER0A_Handler(void);
void TIMER0A_Handler(void)
{
	  if(TIMER0_16_32_REG_SET2->GPTMMIS.B.bit_0==1)
		{
			u32 NeededTicks_for_on, NeededTicks_off;
			u32 overflow_time = 0xFFFFFFFF / 16000000;
			NeededTicks_for_on = (onTime/overflow_time)*0xFFFFFFFF;
			Preload_for_ON = NeededTicks_for_on;
			NeededTicks_off = (offTime/overflow_time)*0xFFFFFFFF;
			Preload_for_OFF = NeededTicks_off;
		/* toggle Blue LED*/
      if(Flag == 0)
      {
          TIMER0_16_32_REG_SET2->GPTMTAILR.R&=Preload_for_ON;
      }
      else if(Flag == 1)
      {
          TIMER0_16_32_REG_SET2->GPTMTAILR.R&=Preload_for_OFF;
      }
			/*ISR here*/
			Flag=~Flag;

			TIMER0_16_32_REG_SET2->GPTMICR.B.bit_0 = 1;

		}
}

int main()
{	
	IntCtrl_Init();
	SYS_CTRL_INIT();
	PORT_init();
	GPT_Init();
	Dio_WritePort(PORTD, 255);
	GPT_SetPeriodicInterrupt();
	GPT_StartTimer(TimerModule);
	while(1)
	{GPT_SetPeriodicInterrupt();
	GPT_StartTimer(TimerModule);}
	return 0;
}
