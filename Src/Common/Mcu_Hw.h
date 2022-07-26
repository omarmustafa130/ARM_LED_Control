/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Mcu_Hw.h>
 *       Module:  Mcu
 *
 *  Description:  <This file contains the declarations of registers>     
 *  
 *********************************************************************************************************************/
#ifndef Mcu_Hw_H
#define Mcu_Hw_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Compiler.h"
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


// *************************************NVIC REGISTERS*************************************************
#define CORTEXM4_PRIV_PERIPH_BASE_ADDR                  0xE000E000
#define NVIC_REGISTER_EN                                ((volatile NVIC_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x100))
#define NVIC_REGISTER_DIS                               *(volatile NVIC_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x180)
#define NVIC_REGISTER_PEND                              *(volatile NVIC_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x200)
#define NVIC_REGISTER_UNPEND                            *(volatile NVIC_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x280)
#define NVIC_REGISTER_ACTIVE                            *(volatile NVIC_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x180)
#define NVIC_REGISTER_PRI                               ((volatile NVIC_PRI_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x400))
#define NVIC_REGISTER_SWTRIG                            *(volatile NVIC_REG_NO*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0xF00)

//*************************************SCB REGISTERS*************************************************
#define SCB_REG_ACTLR                                   (volatile INT_CTRL_TAG*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x008)
#define SCB_REG                                         ((volatile SCB_REG_TYPE*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0xD00))
//**********************************************************************************************************************
//*************************************SYSCTRL REGISTERS*************************************************
#define SYSCTRL_REG_SET1                                ((volatile SYSCTR_SET1*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x600))
#define SYSCTR_RCGCUSB_REG                              ((volatile INT_CTRL_TAG*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x628))
#define SYSCTRL_REG_SET2                                ((volatile SYSCTR_SET2*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x634))
#define SYSCTRL_REG_SET3                                ((volatile SYSCTR_SET3*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x658))

//*************************************GPIO REGISTERS*************************************************
#define GPIO_PORTA_REG                                  ((volatile GPIO_REG*)(0x40058000))
#define GPIO_PORTB_REG                                  ((volatile GPIO_REG*)(0x40059000))
#define GPIO_PORTC_REG                                  ((volatile GPIO_REG*)(0x4005A000))
#define GPIO_PORTD_REG                                  ((volatile GPIO_REG*)(0x4005B000))
#define GPIO_PORTE_REG                                  ((volatile GPIO_REG*)(0x4005C000))
#define GPIO_PORTF_REG                                  ((volatile GPIO_REG*)(0x4005D000))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    u32 bit_0       :1;
    u32 bit_1       :1;
    u32 bit_2       :1;
    u32 bit_3       :1;
    u32 bit_4       :1;
    u32 bit_5       :1;
    u32 bit_6       :1;
    u32 bit_7       :1;
    u32 bit_8       :1;
    u32 bit_9       :1;
    u32 bit_10      :1;
    u32 bit_11      :1;
    u32 bit_12      :1;
    u32 bit_13      :1;
    u32 bit_14      :1;
    u32 bit_15      :1;
    u32 bit_16      :1;
    u32 bit_17      :1;
    u32 bit_18      :1;
    u32 bit_19      :1;
    u32 bit_20      :1;
    u32 bit_21      :1;
    u32 bit_22      :1;
    u32 bit_23      :1;
    u32 bit_24      :1;
    u32 bit_25      :1;
    u32 bit_26      :1;
    u32 bit_27      :1;
    u32 bit_28      :1;
    u32 bit_29      :1;
    u32 bit_30      :1;
    u32 bit_31      :1;
}IntCtrl_BF;

typedef union 
{
    /* data */
    u32 R;
    IntCtrl_BF B;
}INT_CTRL_TAG;


typedef struct 
{
    IntCtrl_BF N0;
    IntCtrl_BF N1;
    IntCtrl_BF N2;
    IntCtrl_BF N3;
    IntCtrl_BF N4;
}NVIC_REG_NO;

typedef struct 
{
    INT_CTRL_TAG N0;
    INT_CTRL_TAG N1;
    INT_CTRL_TAG N2;
    INT_CTRL_TAG N3;
    INT_CTRL_TAG N4;
    INT_CTRL_TAG N5;
    INT_CTRL_TAG N6;
    INT_CTRL_TAG N7;
    INT_CTRL_TAG N8;
    INT_CTRL_TAG N9;
    INT_CTRL_TAG N10;
    INT_CTRL_TAG N11;
    INT_CTRL_TAG N12;
    INT_CTRL_TAG N13;
    INT_CTRL_TAG N14;
    INT_CTRL_TAG N15;
    INT_CTRL_TAG N16;
    INT_CTRL_TAG N17;
    INT_CTRL_TAG N18;
    INT_CTRL_TAG N19;
    INT_CTRL_TAG N20;
    INT_CTRL_TAG N21;
    INT_CTRL_TAG N22;
    INT_CTRL_TAG N23;
    INT_CTRL_TAG N24;
    INT_CTRL_TAG N25;
    INT_CTRL_TAG N26;
    INT_CTRL_TAG N27;
    INT_CTRL_TAG N28;
    INT_CTRL_TAG N29;
    INT_CTRL_TAG N30;
    INT_CTRL_TAG N31;
    INT_CTRL_TAG N32;
    INT_CTRL_TAG N33;
    INT_CTRL_TAG N34;
}NVIC_PRI_REG_NO;


typedef struct 
{
    INT_CTRL_TAG CPUID;
    INT_CTRL_TAG INTCTRL;
    INT_CTRL_TAG VTABLE;
    INT_CTRL_TAG APINT;
    INT_CTRL_TAG SYSCTRL;
    INT_CTRL_TAG CFGCTRL;
    INT_CTRL_TAG SYSPRI1;
    INT_CTRL_TAG SYSPRI2;
    INT_CTRL_TAG SYSPRI3;
    INT_CTRL_TAG SYSHNDCTRL;
    INT_CTRL_TAG FAULTSTAT;
    INT_CTRL_TAG HFAULTSTAT;
    INT_CTRL_TAG MMADDR;
    INT_CTRL_TAG FAULTADDR;
}SCB_REG_TYPE;


typedef struct 
{
    INT_CTRL_TAG RCGCWD;
    INT_CTRL_TAG RCGCTIMER;
    INT_CTRL_TAG RCGCGPIO;
    INT_CTRL_TAG RCGCDMA;
    INT_CTRL_TAG RCGCHIB;
    INT_CTRL_TAG RCGCUART;
    INT_CTRL_TAG RCGCSSI;
    INT_CTRL_TAG RCGCI2C;
}SYSCTR_SET1;

typedef struct 
{
    INT_CTRL_TAG RCGCCAN;
    INT_CTRL_TAG RCGCADC;
    INT_CTRL_TAG RCGCACMP;
    INT_CTRL_TAG RCGCPWM;
    INT_CTRL_TAG RCGCQEI;
}SYSCTR_SET2;

typedef struct 
{
    INT_CTRL_TAG RCGCEEPROM;
    INT_CTRL_TAG RCGCWTIMER;
}SYSCTR_SET3;


typedef struct 
{
    INT_CTRL_TAG GPIODATA;
    INT_CTRL_TAG GPIODIR;
    INT_CTRL_TAG GPIOIS;
    INT_CTRL_TAG GPIOIBE;    
    INT_CTRL_TAG GPIOIEV;
    INT_CTRL_TAG GPIOIM;    
    INT_CTRL_TAG GPIORIS;
    INT_CTRL_TAG GPIOMIS;    
    INT_CTRL_TAG GPIOICR;
    INT_CTRL_TAG GPIOAFSEL;    
    INT_CTRL_TAG GPIODR2R;
    INT_CTRL_TAG GPIODR4R;
    INT_CTRL_TAG GPIODR8R;
    INT_CTRL_TAG GPIOODR;
    INT_CTRL_TAG GPIOPUR;
    INT_CTRL_TAG GPIOPDR;    
    INT_CTRL_TAG GPIOSLR;
    INT_CTRL_TAG GPIODEN;    
    INT_CTRL_TAG GPIOLOCK;
    INT_CTRL_TAG GPIOCR;    
    INT_CTRL_TAG GPIOAMSEL;
    INT_CTRL_TAG GPIOPCTL;    
    INT_CTRL_TAG GPIOADCCTL;
    INT_CTRL_TAG GPIODMACTL;

    INT_CTRL_TAG GPIOPeriphID4;
    INT_CTRL_TAG GPIOPeriphID5;    
    INT_CTRL_TAG GPIOPeriphID6;
    INT_CTRL_TAG GPIOPeriphID7;    
    INT_CTRL_TAG GPIOPeriphID0;
    INT_CTRL_TAG GPIOPeriphID1;    
    INT_CTRL_TAG GPIOPeriphID2;
    INT_CTRL_TAG GPIOPeriphID3;  

    INT_CTRL_TAG GPIOPCellID0;
    INT_CTRL_TAG GPIOPCellID1;    
    INT_CTRL_TAG GPIOPCellID2;
    INT_CTRL_TAG GPIOPCellID3;  
}GPIO_REG;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 #endif  /* Mcu_Hw_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
