/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Port.c>
 *       Module:  PORT
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Common/Platform_Types.h"

#include "../../Common/Bit_Math.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define GPIO_INPUT      0
#define GPIO_OUTPUT     1

#define GPIO_INTERRRUPT_EDGE_SENSITIVE          0
#define GPIO_INTERRRUPT_LEVEL_SENSITIVE         1

#define GPIO_INTERRRUPT_DISABLE_BOTH_EDGES      0
#define GPIO_INTERRRUPT_ON_BOTH_EDGES           1


#define GPIO_INTERRRUPT_EVENT_FALLING_and_LOW   0
#define GPIO_INTERRRUPT_EVENT_RISING_and_HIGH   1

#define GPIO_INTERRRUPT_MASK_DISABLE            0
#define GPIO_INTERRRUPT_MASK_ENABLE             1


#define GPIO_2mA_DRIVE_DISABLE                  0
#define GPIO_2mA_DRIVE_ENABLE                   1
#define GPIO_4mA_DRIVE_DISABLE                  0
#define GPIO_4mA_DRIVE_ENABLE                   1
#define GPIO_8mA_DRIVE_DISABLE                  0
#define GPIO_8mA_DRIVE_ENABLE                   1

#define GPIO_OPEN_DRAIN_DISABLE                 0
#define GPIO_OPEN_DRAIN_ENABLE                  1

#define GPIO_PULLUP_DISABLE                     0
#define GPIO_PULLUP_ENABLE                      1

#define GPIO_PULLDOWN_DISABLE                   0
#define GPIO_PULLDOWN_ENABLE                    1

#define GPIO_SLEW_RATE_DISABLE                  0
#define GPIO_SLEW_RATE_ENABLE                   1

#define GPIO_DIGITAL_FUNC_DISABLE               0
#define GPIO_DIGITAL_FUNC_ENABLE                1

#define GPIO_UNLOCKED                           0
#define GPIO_LOCKED                             1

#define GPIO_COMMIT_DISABLED                    0
#define GPIO_COMMIT_ENABLED                     1

#define GPIO_ANALOG_FUNC_DISABLED               0
#define GPIO_ANALOG_FUNC_ENABLED                1

#define GPIO_ADC_DISABLED                       0
#define GPIO_ADC_ENABLED                        1

#define GPIO_UDMA_DISABLED                      0
#define GPIO_UDMA_ENABLED                       1



/********************************Alternate Functions declarations******************************************************/
#define PinA0_U0Rx                              1
#define PinA0_CAN1Rx                            8

#define PinA1_U0Tx                              1
#define PinA1_CAN1Tx                            8

#define PinA2_SSI0Clk                           2

#define PinA3_SSI0Fss                           2

#define PinA4_SSI0Rx                            2

#define PinA5_SSI0Tx                            2

#define PinA6_I2C1SCL                           3
#define PinA6_M1PWM2                            5

#define PinA7_I2C1SDA                           3
#define PinA7_M1PWM3                            5


#define PinB0_U1Rx                              1
#define PinB0_T2CCP0                            7

#define PinB1_U1Tx                              1
#define PinB1_T2CCP1                            7

#define PinB2_I2C0SCL                           3
#define PinB2_T3CCP0                            7

#define PinB3_I2C0SDA                           3
#define PinB3_T3CCP1                            7

#define PinB4_SSI2Clk                           2
#define PinB4_M0PWM2                            4
#define PinB4_T1CCP0                            7
#define PinB4_CAN0Rx                            8

#define PinB5_SSI2Fss                           2
#define PinB5_M0PWM3                            4
#define PinB5_T1CCP1                            7
#define PinB5_CAN0Tx                            8

#define PinB6_SSI2Rx                            2
#define PinB6_M0PWM0                            4
#define PinB6_T0CCP0                            7

#define PinB7_SSI2Tx                            2
#define PinB7_M0PWM1                            4
#define PinB7_T0CCP1                            7


#define PinC0_TCK_SWCLK                         1
#define PinC0_T4CCP0                            7

#define PinC1_TMS_SWDIO                         1
#define PinC1_T4CCP1                            7

#define PinC2_TDI                               1
#define PinC2_T5CCP0                            7

#define PinC3_TDO_SWO                           1
#define PinC3_T5CCP1                            7

#define PinC4_U4Rx                              1
#define PinC4_U1Rx                              2
#define PinC4_M0PWM6                            4
#define PinC4_IDX1                              6
#define PinC4_WT0CCP0                           7
#define PinC4_U1RTS                             8

#define PinC5_U4Tx                              1
#define PinC5_U1Tx                              2
#define PinC5_M0PWM7                            4
#define PinC5_PhA1                              6
#define PinC5_WT0CCP1                           7
#define PinC5_U1CTS                             8

#define PinC6_U3Rx                              1
#define PinC6_PhB1                              6
#define PinC6_WT1CCP0                           7
#define PinC6_USB0EPEN                          8

#define PinC7_U3Tx                              1
#define PinC7_WT1CCP1                           7
#define PinC7_USB0PFLT                          8

#define PinD0_SSI3Clk                           1
#define PinD0_SSI1Clk                           2
#define PinD0_I2C3SCL                           3
#define PinD0_M0PWM6                            4
#define PinD0_M1PWM0                            5
#define PinD0_WT2CCP0                           7


#define PinD1_SSI3Fss                           1
#define PinD1_SSI1Fss                           2
#define PinD1_I2C3SDA                           3
#define PinD1_M0PWM7                            4
#define PinD1_M1PWM1                            5
#define PinD1_WT2CCP1                           7

#define PinD2_SSI3Rx                            1
#define PinD2_SSI1Rx                            2
#define PinD2_M0FAULT0                          4
#define PinD2_WT3CCP0                           7
#define PinD2_USB0EPEN                          8

#define PinD3_SSI3Tx                            1
#define PinD3_SSI1Tx                            2
#define PinD3_IDX0                              6
#define PinD3_WT3CCP1                           7
#define PinD3_USB0PFLT                          8

#define PinD4_U6Rx                              1
#define PinD4_WT4CCP0                           7

#define PinD5_U6Tx                              1
#define PinD5_WT4CCP1                           7

#define PinD6_U2Rx                              1
#define PinD6_M0FAULT0                          4
#define PinD6_PhA0                              6
#define PinD6_WT5CCP0                           7

#define PinD7_U2Tx                              1
#define PinD7_PhB0                              6
#define PinD7_WT5CCP1                           7
#define PinD7_NMI                               8


#define PinE0_U7Rx                              1

#define PinE1_U7Tx                              1

#define PinE4_U5Rx                              1
#define PinE4_I2C2SCL                           3
#define PinE4_M0PWM4                            4
#define PinE4_M1PWM2                            5
#define PinE4_CAN0Rx                            8

#define PinE5_U5Tx                              1
#define PinE5_I2C2SDA                           3
#define PinE5_M0PWM5                            4
#define PinE5_M1PWM3                            5
#define PinE5_CAN0Tx                            8


#define PinF0_U1RTS                             1
#define PinF0_SSI1Rx                            2
#define PinF0_CAN0Rx                            3
#define PinF0_M1PWM4                            5
#define PinF0_PhA0                              6
#define PinF0_T0CCP0                            7
#define PinF0_NMI                               8
#define PinF0_C0o                               9

#define PinF1_U1CTS                             1
#define PinF1_SSI1Tx                            2
#define PinF1_M1PWM5                            5
#define PinF1_PhB0                              6
#define PinF1_T0CCP1                            7
#define PinF1_C1o                               14
#define PinF1_TRD1                              15

#define PinF2_SSI1Clk                           2
#define PinF2_M0FAULT0                          4
#define PinF2_M1PWM6                            5
#define PinF2_T1CCP0                            7
#define PinF2_TRD0                              14

#define PinF3_SSI1Fss                           2
#define PinF3_CAN0Tx                            3
#define PinF3_M1PWM7                            5
#define PinF3_T1CCP1                            7
#define PinF3_TRCLK                             14

#define PinF4_M1FAULT0                          5
#define PinF4_IDX0                              6
#define PinF4_T2CCP0                            7
#define PinF4_USB0EPEN                          8
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef enum{
    PinA0,
    PinA1,
    PinA2,
    PinA3,
    PinA4,
    PinA5,
    PinA6,
    PinA7,
    PinB0,
    PinB1,
    PinB2,
    PinB3,
    PinB4,
    PinB5,
    PinB6,
    PinB7,
    PinC0,
    PinC1,
    PinC2,
    PinC3,
    PinC4,
    PinC5,
    PinC6,
    PinC7,
    PinD0,
    PinD1,
    PinD2,
    PinD3,
    PinD4,
    PinD5,
    PinD6,
    PinD7,
    PinE0,
    PinE1,
    PinE2,
    PinE3,
    PinE4,
    PinE5,
    PinF0,
    PinF1,
    PinF2,
    PinF3,
    PinF4
}Port_PinType;

typedef enum {
    DIO,
    AlternateFunction,
    AnalogFunction,
    ExternalInterrupt
}Port_PinModeType;

typedef enum{
    PORT_MUX_CONTROL_0,
    PORT_MUX_CONTROL_1=4,
    PORT_MUX_CONTROL_2=8,
    PORT_MUX_CONTROL_3=12,
    PORT_MUX_CONTROL_4=16,
    PORT_MUX_CONTROL_5=20,
    PORT_MUX_CONTROL_6=24,
    PORT_MUX_CONTROL_7=28
}PORT_MUX_CONTROL;


typedef struct{
    Port_PinModeType PortPinMode;
    u8 PortPinLevelValue;
    u8 PortPinDirection;
    u8 PortPinInternalAttach;
    u8 PortPinOutputCurrent_2mA;
    u8 PortPinOutputCurrent_4mA;
    u8 PortPinOutputCurrent_8mA;
    u8 PortPinPullUp;
    u8 PortPinPulldown;
    u8 PortPinAnalogFunction;
    u8 PortPinAlternateFunction;
    u8 PortPinInterruptense;
    u8 PortPinInterruptBothEdgesEvent;
    u8 PortPinInterruptChooseEdge;
}PinConfig;

extern PinConfig ConfiguredPin[43];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void PORT_init(void);
 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
