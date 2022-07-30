/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <IntCtrl_Cfg.h>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_PORTA_Int_State                                ENABLE
#define GPIO_PORTB_Int_State                                ENABLE
#define GPIO_PORTC_Int_State                                ENABLE
#define GPIO_PORTD_Int_State                                ENABLE
#define GPIO_PORTE_Int_State                                ENABLE
#define GPIO_PORTF_Int_State                                ENABLE

#define UART0_Int_State                                     ENABLE
#define UART1_Int_State                                     ENABLE
#define UART2_Int_State                                     ENABLE
#define UART3_Int_State                                     ENABLE
#define UART4_Int_State                                     ENABLE
#define UART5_Int_State                                     ENABLE
#define UART6_Int_State                                     ENABLE
#define UART7_Int_State                                     ENABLE

#define SSI0_Int_State                                      ENABLE
#define SSI1_Int_State                                      ENABLE
#define SSI2_Int_State                                      ENABLE
#define SSI3_Int_State                                      ENABLE

#define I2C0_Int_State                                      DISABLE
#define I2C1_Int_State                                      DISABLE
#define I2C2_Int_State                                      DISABLE
#define I2C3_Int_State                                      DISABLE

#define PWM0_Fault_Int_State                                DISABLE

#define PWM0_Generator0_Int_State                           DISABLE
#define PWM0_Generator1_Int_State                           DISABLE
#define PWM0_Generator2_Int_State                           DISABLE
#define PWM0_Generator3_Int_State                           DISABLE

#define PWM1_Fault_Int_State                                DISABLE

#define PWM1_Generator0_Int_State                           DISABLE
#define PWM1_Generator1_Int_State                           DISABLE
#define PWM1_Generator2_Int_State                           DISABLE
#define PWM1_Generator3_Int_State                           DISABLE

#define QEI0_Int_State                                      DISABLE
#define QEI1_Int_State                                      DISABLE

#define ADC0_Sequence0_Int_State                            DISABLE
#define ADC0_Sequence1_Int_State                            DISABLE
#define ADC0_Sequence2_Int_State                            DISABLE
#define ADC0_Sequence3_Int_State                            DISABLE

#define ADC1_Sequence0_Int_State                            DISABLE
#define ADC1_Sequence1_Int_State                            DISABLE
#define ADC1_Sequence2_Int_State                            DISABLE
#define ADC1_Sequence3_Int_State                            DISABLE

#define Watchdog_Timers0and1_Int_State                      DISABLE

#define Timer0A_16or32Bit_Int_State                         ENABLE
#define Timer0B_16or32Bit_Int_State                         ENABLE

#define Timer1A_16or32Bit_Int_State                         DISABLE
#define Timer1B_16or32Bit_Int_State                         DISABLE

#define Timer2A_16or32Bit_Int_State                         DISABLE
#define Timer2B_16or32Bit_Int_State                         DISABLE

#define Timer3A_16or32Bit_Int_State                         DISABLE
#define Timer3B_16or32Bit_Int_State                         DISABLE

#define Timer4A_16or32Bit_Int_State                         DISABLE
#define Timer4B_16or32Bit_Int_State                         DISABLE

#define Timer5A_16or32Bit_Int_State                         DISABLE
#define Timer5B_16or32Bit_Int_State                         DISABLE

#define Timer0A_32or64Bit_Int_State                         DISABLE
#define Timer0B_32or64Bit_Int_State                         DISABLE

#define Timer1A_32or64Bit_Int_State                         DISABLE
#define Timer1B_32or64Bit_Int_State                         DISABLE

#define Timer2A_32or64Bit_Int_State                         DISABLE
#define Timer2B_32or64Bit_Int_State                         DISABLE

#define Timer3A_32or64Bit_Int_State                         DISABLE
#define Timer3B_32or64Bit_Int_State                         DISABLE

#define Timer4A_32or64Bit_Int_State                         DISABLE
#define Timer4B_32or64Bit_Int_State                         DISABLE

#define Timer5A_32or64Bit_Int_State                         DISABLE
#define Timer5B_32or64Bit_Int_State                         DISABLE

#define Analog_Comparator0_Int_State                        DISABLE
#define Analog_Comparator1_Int_State                        DISABLE

#define SystemControl_Int_State                             DISABLE

#define FMC_and_EEPROMC_Int_state                           DISABLE

#define CAN0_Int_State                                      DISABLE
#define CAN1_Int_State                                      DISABLE

#define HibernationModule_Int_State                         DISABLE

#define USB_Int_State                                       DISABLE

#define UDMA_Software_Int_State                             DISABLE
#define UDMA_Error_Int_State                                DISABLE

#define SystemException_Int_State                           DISABLE

#define Int_Group_and_Subgroup_config                       _8Groups_1Subgroup

/**********************************PRI0****************************************/
#define PRI_GPIO_PORTA                                      G0
#define PRI_GPIO_PORTB                                      G0
#define PRI_GPIO_PORTC                                      G0
#define PRI_GPIO_PORTD                                      G0
/**********************************PRI1****************************************/
#define PRI_GPIO_PORTE                                      G0
#define PRI_UART0                                           G3
#define PRI_UART1                                           G3
#define PRI_SSI0                                            G4
/**********************************PRI2****************************************/
#define PRI_I2C0                                            G4
#define PRI_PWM0_Fault                                      G7
#define PRI_PWM0_Generator0                                 G0
#define PRI_PWM0_Generator1                                 G0
/**********************************PRI3****************************************/
#define PRI_PWM0_Generator2                                 G0
#define PRI_QEI0                                            G5
#define PRI_ADC0_Sequence0                                  G5
#define PRI_ADC0_Sequence1                                  G5
/**********************************PRI4****************************************/
#define PRI_ADC0_Sequence2                                  G5
#define PRI_ADC0_Sequence3                                  G5
#define PRI_Watchdog_Timers0and1                            G5
#define PRI_Timer0A_16or32Bit                               G1
/**********************************PRI5****************************************/
#define PRI_Timer0B_16or32Bit                               G1
#define PRI_Timer1A_16or32Bit                               G1
#define PRI_Timer1B_16or32Bit                               G1
#define PRI_Timer2A_16or32Bit                               G1
/**********************************PRI6****************************************/
#define PRI_Timer2B_16or32Bit                               G1
#define PRI_Analog_Comparator0                              G6
#define PRI_Analog_Comparator1                              G6
/**********************************PRI7****************************************/
#define PRI_SystemControl                                   G3
#define PRI_FMCAndEEPROMC                                   G7
#define PRI_GPIO_PortF                                      G0
/**********************************PRI8****************************************/
#define PRI_UART2                                           G4
#define PRI_SSI1                                            G4
#define PRI_Timer3A_16or32Bit                               G2
/**********************************PRI9****************************************/
#define PRI_Timer3B_16or32Bit                               G2
#define PRI_I2C1                                            G4
#define QEI1                                                G7
#define CAN0                                                G4
/**********************************PRI10****************************************/
#define PRI_CAN1                                            G4
#define PRI_HibernationModule                               G6
/**********************************PRI11****************************************/
#define PRI_USB                                             G4
#define PRI_PWM0_Generator3                                 G1
#define PRI_uDMA_Software                                   G6
#define PRI_uDMA_Error                                      G6
/**********************************PRI12****************************************/
#define PRI_ADC1_Sequence0                                  G6
#define PRI_ADC1_Sequence1                                  G6
#define PRI_ADC1_Sequence2                                  G6
#define PRI_ADC1_Sequence3                                  G6
/**********************************PRI13****************************************/
/**********************************PRI14****************************************/
#define PRI_SSI2                                            G4
#define PRI_SSI3                                            G4
#define PRI_UART3                                           G4
/**********************************PRI15****************************************/
#define PRI_UART4                                           G5
#define PRI_UART5                                           G5
#define PRI_UART6                                           G5
#define PRI_UART7                                           G5
/**********************************PRI16****************************************/
/**********************************PRI17****************************************/
#define PRI_I2C2                                            G5
#define PRI_I2C3                                            G5
#define PRI_Timer4A_16or32Bit                               G2
#define PRI_Timer4B_16or32Bit                               G2
/**********************************PRI18****************************************/
/**********************************PRI19****************************************/
/**********************************PRI20****************************************/
/**********************************PRI21****************************************/
/**********************************PRI22****************************************/
/**********************************PRI23****************************************/
#define PRI_Timer5A_16or32Bit                               G2
#define PRI_Timer5B_16or32Bit                               G2
#define PRI_Timer0A_32or64Bit                               G2
#define PRI_Timer0B_32or64Bit                               G2
/**********************************PRI24****************************************/
#define PRI_Timer1A_32or64Bit                               G2
#define PRI_Timer1B_32or64Bit                               G2
#define PRI_Timer2A_32or64Bit                               G2
#define PRI_Timer2B_32or64Bit                               G2
/**********************************PRI25****************************************/
#define PRI_Timer3A_32or64Bit                               G3
#define PRI_Timer3B_32or64Bit                               G3
#define PRI_Timer4A_32or64Bit                               G3
#define PRI_Timer4B_32or64Bit                               G3
/**********************************PRI26****************************************/
#define PRI_Timer5A_32or64Bit                               G3
#define PRI_Timer5B_32or64Bit                               G3
#define PRI_SystemException                                 G6

/**********************************PRI27****************************************/
/**********************************PRI28****************************************/
/**********************************PRI29****************************************/
/**********************************PRI30****************************************/
/**********************************PRI31****************************************/
/**********************************PRI32****************************************/

/**********************************PRI33****************************************/
#define PRI_PWM1_Generator0                                 G0
#define PRI_PWM1_Generator1                                 G1
/**********************************PRI34****************************************/
#define PRI_PWM1_Generator2                                 G1
#define PRI_PWM1_Generator3                                 G1
#define PRI_PWM1_Fault                                      G7
/*******************************************************************************/

/**********************************SYSPRI1****************************************/
#define SYSPRI_MEM                                          PRI0
#define SYSPRI_BUS                                          PRI1
#define SYSPRI_USAGE                                        PRI2
/**********************************SYSPRI2****************************************/
#define SYSPRI_SVC                                          PRI3
/**********************************SYSPRI3****************************************/
#define SYSPRI_DEBUG                                        PRI4
#define SYSPRI_PENDSV                                       PRI5
#define SYSPRI_TICK                                         PRI6
/*********************************************************************************/


/***********************************SYSHNDCTRL************************************/

#define MEMA_State                                         ENABLE
#define BUSA_State                                         ENABLE
#define USGA_State                                         ENABLE
#define SVCA_State                                         ENABLE
#define MON_State                                          ENABLE
#define PNDSV_State                                        ENABLE
#define TICK_State                                         ENABLE
#define USAGEP_State                                       ENABLE
#define MEMP_State                                         ENABLE
#define BUSP_State                                         ENABLE
#define SVC_State                                          ENABLE
#define MEM_State                                          ENABLE
#define BUS_State                                          ENABLE
#define USAGE_State                                        ENABLE

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/*




    SystemException,

    
*/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
