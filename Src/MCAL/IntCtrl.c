/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/IntCtrl.h"

#include "../Common/Std_Types.h"
#include "../Common/Mcu_Hw.h"
#include "../Config/IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCtrl_Init(void)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : void
*******************************************************************************/
void IntCtrl_Init(void)
{
	//Configure groups and subgrous with APINT
    SCB_REG->APINT.R= 0xFA05|(Int_Group_and_Subgroup_config<<8);
    //Assign group\subgroup priority in NVIC_PRIx Nvic and SCB_SUSPRIx regs
    /***********************************PRIx***********************************/
    NVIC_REGISTER_PRI->N0.R|=(PRI_GPIO_PORTA<<5)|(PRI_GPIO_PORTB<<13)|(PRI_GPIO_PORTC<<21)|(PRI_GPIO_PORTD<<29);
    NVIC_REGISTER_PRI->N1.R|=(PRI_GPIO_PORTE<<5)|(PRI_UART0<<13)|(PRI_UART1<<21)|(PRI_SSI0<<29);
    NVIC_REGISTER_PRI->N2.R|=(PRI_I2C0<<5)|(PRI_PWM0_Fault<<13)|(PRI_PWM0_Generator0<<21)|(PRI_PWM0_Generator1<<29);
    NVIC_REGISTER_PRI->N3.R|=(PRI_PWM0_Generator2<<5)|(PRI_QEI0<<13)|(PRI_ADC0_Sequence0<<21)|(PRI_ADC0_Sequence1<<29);
    NVIC_REGISTER_PRI->N4.R|=(PRI_ADC0_Sequence2<<5)|(PRI_ADC0_Sequence3<<13)|(PRI_Watchdog_Timers0and1<<21)|(PRI_Timer0A_16or32Bit<<29);
    NVIC_REGISTER_PRI->N5.R|=(PRI_Timer0B_16or32Bit<<5)|(PRI_Timer1A_16or32Bit<<13)|(PRI_Timer1B_16or32Bit<<21)|(PRI_Timer2A_16or32Bit<<29);
    NVIC_REGISTER_PRI->N6.R|=(PRI_Timer2B_16or32Bit<<5)|(PRI_Analog_Comparator0<<13)|(PRI_Analog_Comparator1<<21);
    NVIC_REGISTER_PRI->N7.R|=(PRI_SystemControl<<5)|(PRI_FMCAndEEPROMC<<13)|(PRI_GPIO_PortF<<21);
    NVIC_REGISTER_PRI->N8.R|=(PRI_UART2<<13)|(PRI_SSI1<<21)|(PRI_Timer3A_16or32Bit<<29);
    NVIC_REGISTER_PRI->N9.R|=(PRI_Timer3B_16or32Bit<<5)|(PRI_I2C1<<13)|(QEI1<<21)|(CAN0<<29);
    NVIC_REGISTER_PRI->N10.R|=(PRI_CAN1<<5)|(PRI_HibernationModule<<13);
    NVIC_REGISTER_PRI->N11.R|=(PRI_USB<<5)|(PRI_PWM0_Generator3<<13)|(PRI_uDMA_Software<<21)|(PRI_uDMA_Error<<29);
    NVIC_REGISTER_PRI->N12.R|=(PRI_ADC1_Sequence0<<5)|(PRI_ADC1_Sequence1<<13)|(PRI_ADC1_Sequence2<<21)|(PRI_ADC1_Sequence3<<29);
    NVIC_REGISTER_PRI->N14.R|=(PRI_SSI2<<13)|(PRI_SSI3<<21)|(PRI_UART3<<29);
    NVIC_REGISTER_PRI->N15.R|=(PRI_UART4<<5)|(PRI_UART5<<13)|(PRI_UART6<<21)|(PRI_UART7<<29);
    NVIC_REGISTER_PRI->N17.R|=(PRI_I2C2<<5)|(PRI_I2C3<<13)|(PRI_Timer4A_16or32Bit<<21)|(PRI_Timer4B_16or32Bit<<29);
    NVIC_REGISTER_PRI->N23.R|=(PRI_Timer5A_16or32Bit<<5)|(PRI_Timer5B_16or32Bit<<13)|(PRI_Timer0A_32or64Bit<<21)|(PRI_Timer0B_32or64Bit<<29);
    NVIC_REGISTER_PRI->N24.R|=(PRI_Timer1A_32or64Bit<<5)|(PRI_Timer1B_32or64Bit<<13)|(PRI_Timer2A_32or64Bit<<21)|(PRI_Timer2B_32or64Bit<<29);
    NVIC_REGISTER_PRI->N25.R|=(PRI_Timer3A_32or64Bit<<5)|(PRI_Timer3B_32or64Bit<<13)|(PRI_Timer4A_32or64Bit<<21)|(PRI_Timer4B_32or64Bit<<29);
    NVIC_REGISTER_PRI->N26.R|=(PRI_Timer5A_32or64Bit<<5)|(PRI_Timer5B_32or64Bit<<13)|(PRI_SystemException<<21);

    NVIC_REGISTER_PRI->N33.R|=(PRI_PWM1_Generator0<<21)|(PRI_PWM1_Generator1<<29);
    NVIC_REGISTER_PRI->N34.R|=(PRI_PWM1_Generator2<<5)|(PRI_PWM1_Generator3<<13)|(PRI_PWM1_Fault<<21);

    /************************************************************************************************************/
    /*******************************************SYSPRIx**********************************************************/
    SCB_REG->SYSPRI1.R|=(SYSPRI_MEM<<5)|(SYSPRI_BUS<<13)|(SYSPRI_USAGE<<21);
    SCB_REG->SYSPRI2.R|=(SYSPRI_SVC<<29);
    SCB_REG->SYSPRI3.R|=(SYSPRI_DEBUG<<5)|(SYSPRI_PENDSV<<21)|(SYSPRI_TICK<<21);

    //Enable\disable using user configs in NVIC_ENx and SCB_Sys regs.
    if (GPIO_PORTA_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_0=ENABLE;
    if (GPIO_PORTB_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_1=ENABLE;
    if (GPIO_PORTC_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_2=ENABLE;
    if (GPIO_PORTD_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_3=ENABLE;
    if (GPIO_PORTE_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_4=ENABLE;
    if (GPIO_PORTF_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_30=ENABLE;


    if (UART0_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N0.bit_5=ENABLE;
    if (UART1_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N0.bit_6=ENABLE;
    if (UART2_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_1=ENABLE;
    if (UART3_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_27=ENABLE;
    if (UART4_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_28=ENABLE;
    if (UART5_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_29=ENABLE;
    if (UART6_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_30=ENABLE;
    if (UART7_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_31=ENABLE;

    if (SSI0_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N0.bit_7=ENABLE;
    if (SSI1_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_2=ENABLE;
    if (SSI2_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_25=ENABLE;
    if (SSI3_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_26=ENABLE;

    if (I2C0_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N0.bit_8=ENABLE;
    if (I2C1_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_5=ENABLE;
    if (I2C2_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N2.bit_4=ENABLE;
    if (I2C3_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N2.bit_5=ENABLE;

    if (PWM0_Fault_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_9=ENABLE;
    if (PWM0_Generator0_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_10=ENABLE;
    if (PWM0_Generator1_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_11=ENABLE;
    if (PWM0_Generator2_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_12=ENABLE;
    if (PWM0_Generator3_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_13=ENABLE;

    if (PWM1_Fault_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N4.bit_10=ENABLE;
    if (PWM1_Generator0_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N4.bit_6=ENABLE;
    if (PWM1_Generator1_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N4.bit_7=ENABLE;
    if (PWM1_Generator2_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N4.bit_8=ENABLE;
    if (PWM1_Generator3_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N4.bit_9=ENABLE;

    if (QEI0_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N0.bit_13=ENABLE;
    if (QEI1_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_6=ENABLE;

    if (ADC0_Sequence0_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_14=ENABLE;
    if (ADC0_Sequence1_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_15=ENABLE;
    if (ADC0_Sequence2_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_16=ENABLE;
    if (ADC0_Sequence3_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_17=ENABLE;
    if (ADC1_Sequence0_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_21=ENABLE;
    if (ADC1_Sequence1_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_22=ENABLE;
    if (ADC1_Sequence2_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_23=ENABLE;
    if (ADC1_Sequence3_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_24=ENABLE;


    if (Watchdog_Timers0and1_Int_State==ENABLE)   	NVIC_REGISTER_EN->N0.bit_18=ENABLE;

    if (Timer0A_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_19=ENABLE;
    if (Timer0B_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_20=ENABLE;
    if (Timer1A_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_21=ENABLE;
    if (Timer1B_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_22=ENABLE;
    if (Timer2A_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_23=ENABLE;
    if (Timer2B_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_24=ENABLE;
    if (Timer3A_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_3=ENABLE;
    if (Timer3B_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_4=ENABLE;
    if (Timer4A_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N2.bit_6=ENABLE;
    if (Timer4B_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N2.bit_7=ENABLE;
    if (Timer5A_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N2.bit_28=ENABLE;
    if (Timer5B_16or32Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N2.bit_29=ENABLE;
    if (Timer0A_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N2.bit_30=ENABLE;
    if (Timer0B_32or64Bit_Int_State==ENABLE)    	NVIC_REGISTER_EN->N2.bit_31=ENABLE;

    if (Timer1A_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_1=ENABLE;
    if (Timer1B_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_2=ENABLE;
    if (Timer2A_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_3=ENABLE;
    if (Timer2B_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_4=ENABLE;
    if (Timer3A_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_5=ENABLE;
    if (Timer3B_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_6=ENABLE;
    if (Timer4A_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_7=ENABLE;
    if (Timer4B_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_8=ENABLE;
    if (Timer5A_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_9=ENABLE;
    if (Timer5B_32or64Bit_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_10=ENABLE;

    if (Analog_Comparator0_Int_State==ENABLE)   	NVIC_REGISTER_EN->N0.bit_25=ENABLE;
    if (Analog_Comparator1_Int_State==ENABLE)   	NVIC_REGISTER_EN->N0.bit_26=ENABLE;

    if (SystemControl_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N0.bit_28=ENABLE;
    if (FMC_and_EEPROMC_Int_state==ENABLE)   	    NVIC_REGISTER_EN->N0.bit_29=ENABLE;
    if (CAN0_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_7=ENABLE;
    if (CAN1_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_8=ENABLE;
    if (HibernationModule_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N1.bit_11=ENABLE;
    if (USB_Int_State==ENABLE)   	                NVIC_REGISTER_EN->N1.bit_12=ENABLE;
    if (UDMA_Software_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N1.bit_14=ENABLE;
    if (UDMA_Error_Int_State==ENABLE)   	        NVIC_REGISTER_EN->N1.bit_15=ENABLE;
    if (SystemException_Int_State==ENABLE)   	    NVIC_REGISTER_EN->N3.bit_11=ENABLE;

    /***********************************SCB_SYS****************************************/
    SCB_REG->SYSHNDCTRL.R|=(MEMA_State<<MEMA)|(BUS_State<<BUSA)|(USGA_State<<USGA)|(SVCA_State<<SVCA)|(MON_State<<MON)|(PNDSV_State<<PNDSV)|(TICK_State<<TICK)|(USAGEP_State<<USAGEP)|(MEMP_State<<MEMP)|(BUSP_State<<BUSP)|(SVC_State<<SVC)|(MEM_State<<MEM)|(BUS_State<<BUS)|(USAGE_State<<USAGE);
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
