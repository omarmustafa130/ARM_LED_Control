#include "../MCAL/Inc/Port.h"


/**********************************EXTERNAL INTERRUPTS COFIGURATIONS******************************************/

#define     PinC7_PinMode               ExternalInterrupt
#define     PinC7_Interrupt_sense       GPIO_INTERRRUPT_EDGE_SENSITIVE
#define     PinC7_Both_Edges_Event      GPIO_INTERRRUPT_DISABLE_BOTH_EDGES
#define     PinC7_Choose_Edge           GPIO_INTERRRUPT_EVENT_RISING_and_HIGH



#define     PinC0_Interrupt_sense       0
#define     PinC0_Both_Edges_Event      0
#define     PinC0_Choose_Edge           0

#define     PinC1_Interrupt_sense       0
#define     PinC1_Both_Edges_Event      0
#define     PinC1_Choose_Edge           0

#define     PinC2_Interrupt_sense       0
#define     PinC2_Both_Edges_Event      0
#define     PinC2_Choose_Edge           0

#define     PinC3_Interrupt_sense       0
#define     PinC3_Both_Edges_Event      0
#define     PinC3_Choose_Edge           0

#define     PinC7_Direction             0
#define     PinC7_LevelValue            0
#define     PinC7_InternalAttach        0
#define     PinC7_OutputCurrent_2mA     0
#define     PinC7_OutputCurrent_4mA     0
#define     PinC7_OutputCurrent_4mA     0
#define     PinC7_PULLDOWN              0
#define     PinC7_PULLUP                0

/***********************************CONFIGURED Alternate functions***********************************************************/
#define     PinA0_AltFunctionChosen     PinA0_U0Rx
#define     PinA1_AltFunctionChosen     PinA1_U0Tx
#define     PinA2_AltFunctionChosen     PinA2_SSI0Clk
#define     PinA3_AltFunctionChosen     PinA3_SSI0Fss
#define     PinA4_AltFunctionChosen     PinA4_SSI0Rx
#define     PinA5_AltFunctionChosen     PinA5_SSI0Tx
#define     PinA6_AltFunctionChosen     PinA6_I2C1SCL
#define     PinA7_AltFunctionChosen     PinA7_I2C1SDA

#define     PinB0_AltFunctionChosen     PinB0_U1Rx
#define     PinB1_AltFunctionChosen     PinB1_U1Tx
#define     PinB2_AltFunctionChosen     PinB2_I2C0SCL
#define     PinB3_AltFunctionChosen     PinB3_I2C0SDA
#define     PinB4_AltFunctionChosen     PinB4_SSI2Clk
#define     PinB5_AltFunctionChosen     PinB5_SSI2Fss
#define     PinB6_AltFunctionChosen     PinB6_SSI2Rx
#define     PinB7_AltFunctionChosen     PinB7_SSI2Tx

#define     PinC0_AltFunctionChosen     PinC0_TCK_SWCLK
#define     PinC1_AltFunctionChosen     PinC1_TMS_SWDIO
#define     PinC2_AltFunctionChosen     PinC2_TDI
#define     PinC3_AltFunctionChosen     PinC3_TDO_SWO
#define     PinC4_AltFunctionChosen     PinC4_U4Rx
#define     PinC5_AltFunctionChosen     PinC5_U4Tx
#define     PinC6_AltFunctionChosen     PinC6_U3Rx
#define     PinC7_AltFunctionChosen     PinC7_U3Tx

#define     PinD0_AltFunctionChosen     PinD0_SSI3Clk
#define     PinD1_AltFunctionChosen     PinD1_SSI3Fss
#define     PinD2_AltFunctionChosen     PinD2_SSI3Rx
#define     PinD3_AltFunctionChosen     PinD3_SSI3Tx
#define     PinD4_AltFunctionChosen     PinD4_U6Rx
#define     PinD5_AltFunctionChosen     PinD5_U6Tx
#define     PinD6_AltFunctionChosen     PinD6_U2Rx
#define     PinD7_AltFunctionChosen     PinD7_U2Tx

#define     PinE0_AltFunctionChosen     PinE0_U7Rx
#define     PinE1_AltFunctionChosen     PinE1_U7Tx
#define     PinE4_AltFunctionChosen     PinE4_U5Rx
#define     PinE5_AltFunctionChosen     PinE5_U5Tx

#define     PinF0_AltFunctionChosen     PinF0_U1RTS
#define     PinF1_AltFunctionChosen     PinF1_M1PWM5
#define     PinF2_AltFunctionChosen     PinF2_M1PWM6
#define     PinF3_AltFunctionChosen     PinF3_M1PWM7
#define     PinF4_AltFunctionChosen     PinF4_T2CCP0
