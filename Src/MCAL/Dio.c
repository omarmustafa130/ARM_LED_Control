/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Mcu_Hw.h"
#include "Inc/Dio.h"

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

 Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)
 {
    if (ChannelID>=0 && ChannelID<=7)
    {
        return(GET_BIT(GPIO_PORTA_REG->GPIODATA.R,ChannelID));
    }
    else if (ChannelID>=8 && ChannelID<=15)
    {
        return(GET_BIT(GPIO_PORTB_REG->GPIODATA.R,ChannelID));
    }
    else if (ChannelID>=16 && ChannelID<=23)
    {
        return(GET_BIT(GPIO_PORTC_REG->GPIODATA.R,ChannelID));
    }

    else if (ChannelID>=24 && ChannelID<=31)
    {
        return(GET_BIT(GPIO_PORTD_REG->GPIODATA.R,ChannelID));
    }  

    else if (ChannelID>=32 && ChannelID<=37)
    {
       return(GET_BIT(GPIO_PORTE_REG->GPIODATA.R,ChannelID));
    }

    else if (ChannelID>=38 && ChannelID<=42)
    {
        return(GET_BIT(GPIO_PORTF_REG->GPIODATA.R,ChannelID));
    }  
 }
 void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)
 {
    if (ChannelID>=0 && ChannelID<=7)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTA_REG->GPIODATA.R, ChannelID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTA_REG->GPIODATA.R, ChannelID);
    }
    else if (ChannelID>=8 && ChannelID<=15)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTB_REG->GPIODATA.R, ChannelID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTB_REG->GPIODATA.R, ChannelID);
    }
    else if (ChannelID>=16 && ChannelID<=23)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTC_REG->GPIODATA.R, ChannelID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTC_REG->GPIODATA.R, ChannelID);
    }

    else if (ChannelID>=24 && ChannelID<=31)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTD_REG->GPIODATA.R, ChannelID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTD_REG->GPIODATA.R, ChannelID);
    }  

    else if (ChannelID>=32 && ChannelID<=37)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTE_REG->GPIODATA.R, ChannelID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTE_REG->GPIODATA.R, ChannelID);
    }

    else if (ChannelID>=38 && ChannelID<=42)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTF_REG->GPIODATA.R, ChannelID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTF_REG->GPIODATA.R, ChannelID);
    }  
 }

 Dio_PortLevelType Dio_ReadPort(Dio_PortType Port)
 {
    switch (Port)
    {
    case PORTA:
        return (GPIO_PORTA_REG->GPIODATA.R);
        break;
    case PORTB:
        return (GPIO_PORTB_REG->GPIODATA.R);
        break;
    case PORTC:
        return (GPIO_PORTC_REG->GPIODATA.R);
        break;
    case PORTD:
        return (GPIO_PORTD_REG->GPIODATA.R);
        break;
    case PORTE:
        return (GPIO_PORTE_REG->GPIODATA.R);
        break;
    case PORTF:
        return (GPIO_PORTF_REG->GPIODATA.R);
        break;
    }
 }
 void Dio_WritePort(Dio_PortType Port, Dio_PortLevelType Level)
 {
    switch (Port)
    {
    case PORTA:
        GPIO_PORTA_REG->GPIODATA.R=Level;
        break;
    case PORTB:
        GPIO_PORTB_REG->GPIODATA.R=Level;
        break;
    case PORTC:
        GPIO_PORTC_REG->GPIODATA.R=Level;
        break;
    case PORTD:
        GPIO_PORTD_REG->GPIODATA.R=Level;
        break;
    case PORTE:
        GPIO_PORTE_REG->GPIODATA.R=Level;
        break;
    case PORTF:
        GPIO_PORTF_REG->GPIODATA.R=Level;
        break;
    }   
 }

 Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelID)
 {
    if (ChannelID>=0 && ChannelID<=7)
    {
        return(TOG_BIT(GPIO_PORTA_REG->GPIODATA.R,ChannelID));
    }
    else if (ChannelID>=8 && ChannelID<=15)
    {
        return(TOG_BIT(GPIO_PORTB_REG->GPIODATA.R,ChannelID));
    }
    else if (ChannelID>=16 && ChannelID<=23)
    {
        return(TOG_BIT(GPIO_PORTC_REG->GPIODATA.R,ChannelID));
    }

    else if (ChannelID>=24 && ChannelID<=31)
    {
        return(TOG_BIT(GPIO_PORTD_REG->GPIODATA.R,ChannelID));
    }  

    else if (ChannelID>=32 && ChannelID<=37)
    {
       return(TOG_BIT(GPIO_PORTE_REG->GPIODATA.R,ChannelID));
    }

    else if (ChannelID>=38 && ChannelID<=42)
    {
        return(TOG_BIT(GPIO_PORTF_REG->GPIODATA.R,ChannelID));
    }     
 }

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
