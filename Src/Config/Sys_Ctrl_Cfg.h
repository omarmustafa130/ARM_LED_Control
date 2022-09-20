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

#define SYSCLK_DIVISION                SYS_CLOCK_DEVIDED
#define PWMCLK_DIVISION                USE_PWM_CLOCK_DIV
#define SYS_DIV_OPTION                 SYSCTL_SYSDIV_4
#define PWM_DIV_OPTION                 SYSCTL_PWMDIV_2
#define PLL_DIV_OPTION                 SYSCLK_PLLOUT_DIVIDED
#define PLL_BYPASS_OPTION              PLL_Normal
#define PORTA_BUS_CFG                  AHB_A
#define PORTB_BUS_CFG                  AHB_B
#define PORTC_BUS_CFG                  AHB_C
#define PORTD_BUS_CFG                  AHB_D
#define PORTE_BUS_CFG                  AHB_E
#define PORTF_BUS_CFG                  AHB_F


#define WD0_CLK_GATE                   Enable
#define WD1_CLK_GATE                   Enable
#define TMR0_16_32_CLK_GATE            Enable
#define TMR1_16_32_CLK_GATE            Enable
#define TMR2_16_32_CLK_GATE            Enable
#define TMR3_16_32_CLK_GATE            Enable
#define TMR4_16_32_CLK_GATE            Enable
#define TMR5_16_32_CLK_GATE            Enable
#define GPIOA_CLK_GATE                 Enable
#define GPIOB_CLK_GATE                 Enable
#define GPIOC_CLK_GATE                 Enable
#define GPIOD_CLK_GATE                 Enable
#define GPIOE_CLK_GATE                 Enable
#define GPIOF_CLK_GATE                 Enable
#define UDMA_CLK_GATE                  Enable
#define HIB_CLK_GATE                   Enable
#define UART0_CLK_GATE                 Enable
#define UART1_CLK_GATE                 Enable
#define UART2_CLK_GATE                 Enable
#define UART3_CLK_GATE                 Enable
#define UART4_CLK_GATE                 Enable
#define UART5_CLK_GATE                 Enable
#define UART6_CLK_GATE                 Enable
#define UART7_CLK_GATE                 Enable
#define SSI0_CLK_GATE                  Enable
#define SSI1_CLK_GATE                  Enable
#define SSI2_CLK_GATE                  Enable
#define SSI3_CLK_GATE                  Enable
#define I2C0_CLK_GATE                  Enable
#define I2C1_CLK_GATE                  Enable
#define I2C2_CLK_GATE                  Enable
#define I2C3_CLK_GATE                  Enable
#define USB_CLK_GATE                   Enable
#define CAN0_CLK_GATE                  Enable
#define CAN1_CLK_GATE                  Enable
#define ADC0_CLK_GATE                  Enable
#define ADC1_CLK_GATE                  Enable
#define AnalogComp_CLK_GATE            Enable
#define PWM0_CLK_GATE                  Enable
#define PWM1_CLK_GATE                  Enable
#define QEI0_CLK_GATE                  Enable
#define QEI1_CLK_GATE                  Enable
#define EEPROM_CLK_GATE                Enable
#define TMR0_32_64_CLK_GATE            Enable
#define TMR1_32_64_CLK_GATE            Enable
#define TMR2_32_64_CLK_GATE            Enable
#define TMR3_32_64_CLK_GATE            Enable
#define TMR4_32_64_CLK_GATE            Enable
#define TMR5_32_64_CLK_GATE            Enable


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


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
