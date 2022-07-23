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
#define CORTEXM4_PRIV_PERIPH_BASE_ADDR                  0xE000E000
#define NVIC_REG                                       *(volatile IntCtrl_Reg*)(CORTEXM4_PRIV_PERIPH_BASE_ADDR + 0x100)
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


typedef struct 
{
    IntCtrl_BF EN0;
    IntCtrl_BF EN1;
    IntCtrl_BF EN2;
    IntCtrl_BF EN3;
    IntCtrl_BF EN4;
    IntCtrl_BF DIS0;
    IntCtrl_BF DIS1;
    IntCtrl_BF DIS2;
    IntCtrl_BF DIS3;
    IntCtrl_BF DIS4;
    IntCtrl_BF PIND0;
    IntCtrl_BF PIND1;
    IntCtrl_BF PIND2;
    IntCtrl_BF PIND3;
    IntCtrl_BF PIND4;
    IntCtrl_BF UNPIND0;
    IntCtrl_BF UNPIND1;
    IntCtrl_BF UNPIND2;
    IntCtrl_BF UNPIND3;
    IntCtrl_BF UNPIND4;
    IntCtrl_BF ACTIVE0;
    IntCtrl_BF ACTIVE1;
    IntCtrl_BF ACTIVE2;
    IntCtrl_BF ACTIVE3;
    IntCtrl_BF ACTIVE4;
    IntCtrl_BF PRI0;
    IntCtrl_BF PRI1;
    IntCtrl_BF PRI2;
    IntCtrl_BF PRI3;
    IntCtrl_BF PRI4;
    IntCtrl_BF PRI5;
    IntCtrl_BF PRI6;
    IntCtrl_BF PRI7;
    IntCtrl_BF PRI8;
    IntCtrl_BF PRI9;
    IntCtrl_BF PRI10;
    IntCtrl_BF PRI11;
    IntCtrl_BF PRI12;
    IntCtrl_BF PRI13;
    IntCtrl_BF PRI14;
    IntCtrl_BF PRI15;
    IntCtrl_BF PRI16;
    IntCtrl_BF PRI17;
    IntCtrl_BF PRI18;
}IntCtrl_Reg;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 #endif  /* Mcu_Hw_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
