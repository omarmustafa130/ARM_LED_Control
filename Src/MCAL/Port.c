#include "../Common/Std_Types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Platform_Types.h"
#include "../Common/Mcu_Hw.h"

#include "Inc/Port.h"
#include "../Config/Port_Cfg.h"

void PORT_init(void)
{
    u8 conf_pin_count;
    for(conf_pin_count=0; conf_pin_count<43; conf_pin_count++)
    {   
        if (conf_pin_count<=7)
        {   
            /*check on mode*/
            if (ConfiguredPin[conf_pin_count].PortPinMode == DIO)
            {   
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTA_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTA_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE GPIO Function, Enable Digital function, Disable Analog Finction
                CLR_BIT(GPIO_PORTA_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTA_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTA_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);

                //Direction and Level
                GPIO_PORTA_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                if (ConfiguredPin[conf_pin_count].PortPinLevelValue == HIGH)
                    SET_BIT(GPIO_PORTA_GPIODATA->R, conf_pin_count%7);
                //InternalAttach
                GPIO_PORTA_REG_SET2->GPIOODR.R|=(ConfiguredPin[conf_pin_count].PortPinInternalAttach)<<(conf_pin_count%7);
                //PULLUP & PULLDOWN
                GPIO_PORTA_REG_SET2->GPIOPUR.R|=(ConfiguredPin[conf_pin_count].PortPinPullUp)<<(conf_pin_count%7);
                GPIO_PORTA_REG_SET2->GPIOPDR.R|=(ConfiguredPin[conf_pin_count].PortPinPulldown)<<(conf_pin_count%7);

                //Output current
                GPIO_PORTA_REG_SET2->GPIODR2R.R|=(0x000000FF)|(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_2mA)<<(conf_pin_count%7);
                GPIO_PORTA_REG_SET2->GPIODR4R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_4mA)<<(conf_pin_count%7);
                GPIO_PORTA_REG_SET2->GPIODR8R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_8mA)<<(conf_pin_count%7);

            }

            else if (ConfiguredPin[conf_pin_count].PortPinMode == AlternateFunction)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTA_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTA_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE Alternate Function, Disable Digital function, Disable Analog Finction
                SET_BIT(GPIO_PORTA_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTA_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTA_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);
                if (conf_pin_count%7==0)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA0_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==1)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA1_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==2)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA2_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==3)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA3_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==4)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA4_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==5)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA5_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==6)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA6_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==7)             GPIO_PORTA_REG_SET2->GPIOPCTL.R|=PinA7_AltFunctionChosen<<((conf_pin_count%7)*4);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AnalogFunction)
            {   
                //CHOOSE GPIO Function, Disable Digital function, Enable Analog Finction
                CLR_BIT(GPIO_PORTA_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTA_REG_SET2->GPIODEN.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTA_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTA_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == ExternalInterrupt)
            { 
                GPIO_PORTA_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                //Enable interrupt mask, choose interrupt sense, choose both edges, choose edge or level
                SET_BIT(GPIO_PORTA_REG_SET1->GPIOIM.R, conf_pin_count%7);
                GPIO_PORTA_REG_SET1->GPIOIS.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptense)<<(conf_pin_count%7);
                GPIO_PORTA_REG_SET1->GPIOIBE.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptBothEdgesEvent)<<(conf_pin_count%7);
                GPIO_PORTA_REG_SET1->GPIOIEV.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptChooseEdge)<<(conf_pin_count%7);
                SET_BIT(GPIO_PORTA_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 
                
            }
        }
        else if (conf_pin_count>=8&&conf_pin_count<=15)
        {   
            if (ConfiguredPin[conf_pin_count].PortPinMode == DIO)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTB_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTB_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE GPIO Function, Enable Digital function, Disable Analog Finction
                CLR_BIT(GPIO_PORTB_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTB_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTB_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);

                //Direction and Level
                GPIO_PORTB_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                if (ConfiguredPin[conf_pin_count].PortPinLevelValue == HIGH)
                    SET_BIT(GPIO_PORTB_GPIODATA->R, conf_pin_count%7);
                //InternalAttach
                GPIO_PORTB_REG_SET2->GPIOODR.R|=(ConfiguredPin[conf_pin_count].PortPinInternalAttach)<<(conf_pin_count%7);
                //PULLUP & PULLDOWN
                GPIO_PORTB_REG_SET2->GPIOPUR.R|=(ConfiguredPin[conf_pin_count].PortPinPullUp)<<(conf_pin_count%7);
                GPIO_PORTB_REG_SET2->GPIOPDR.R|=(ConfiguredPin[conf_pin_count].PortPinPulldown)<<(conf_pin_count%7);
                //Output current
                GPIO_PORTB_REG_SET2->GPIODR2R.R|=(0x000000FF)|(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_2mA)<<(conf_pin_count%7);
                GPIO_PORTB_REG_SET2->GPIODR4R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_4mA)<<(conf_pin_count%7);
                GPIO_PORTB_REG_SET2->GPIODR8R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_8mA)<<(conf_pin_count%7);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AlternateFunction)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTB_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTB_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE Alternate Function, Disable Digital function, Disable Analog Finction
                SET_BIT(GPIO_PORTB_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTB_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTB_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);
                if (conf_pin_count%7==0)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB0_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==1)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB1_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==2)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB2_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==3)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB3_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==4)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB4_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==5)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB5_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==6)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB6_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==7)             GPIO_PORTB_REG_SET2->GPIOPCTL.R|=PinB7_AltFunctionChosen<<((conf_pin_count%7)*4);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AnalogFunction)
            {   
                //CHOOSE GPIO Function, Disable Digital function, Enable Analog Finction
                CLR_BIT(GPIO_PORTB_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTB_REG_SET2->GPIODEN.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTB_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTB_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 

            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == ExternalInterrupt)
            {   
                GPIO_PORTB_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                //Enable interrupt mask, choose interrupt sense, choose both edges, choose edge or level
                SET_BIT(GPIO_PORTB_REG_SET1->GPIOIM.R, conf_pin_count%7);
                GPIO_PORTB_REG_SET1->GPIOIS.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptense)<<(conf_pin_count%7);
                GPIO_PORTB_REG_SET1->GPIOIBE.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptBothEdgesEvent)<<(conf_pin_count%7);
                GPIO_PORTB_REG_SET1->GPIOIEV.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptChooseEdge)<<(conf_pin_count%7);
                SET_BIT(GPIO_PORTB_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 
                
            }
        }

        else if (conf_pin_count>=16&&conf_pin_count<=23)
        {   
            if (ConfiguredPin[conf_pin_count].PortPinMode == DIO)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTC_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTC_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE GPIO Function, Enable Digital function, Disable Analog Finction
                CLR_BIT(GPIO_PORTC_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTC_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTC_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);

                //Direction and Level
                GPIO_PORTC_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                if (ConfiguredPin[conf_pin_count].PortPinLevelValue == HIGH)
                    SET_BIT(GPIO_PORTC_GPIODATA->R, conf_pin_count%7);
                //InternalAttach
                GPIO_PORTC_REG_SET2->GPIOODR.R|=(ConfiguredPin[conf_pin_count].PortPinInternalAttach)<<(conf_pin_count%7);
                //PULLUP & PULLDOWN
                GPIO_PORTC_REG_SET2->GPIOPUR.R|=(ConfiguredPin[conf_pin_count].PortPinPullUp)<<(conf_pin_count%7);
                GPIO_PORTC_REG_SET2->GPIOPDR.R|=(ConfiguredPin[conf_pin_count].PortPinPulldown)<<(conf_pin_count%7);
                //Output current
                GPIO_PORTC_REG_SET2->GPIODR2R.R|=(0x000000FF)|(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_2mA)<<(conf_pin_count%7);
                GPIO_PORTC_REG_SET2->GPIODR4R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_4mA)<<(conf_pin_count%7);
                GPIO_PORTC_REG_SET2->GPIODR8R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_8mA)<<(conf_pin_count%7);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AlternateFunction)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTC_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTC_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE Alternate Function, Disable Digital function, Disable Analog Finction
                SET_BIT(GPIO_PORTC_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTC_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTC_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);
                if (conf_pin_count%7==0)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC0_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==1)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC1_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==2)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC2_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==3)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC3_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==4)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC4_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==5)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC5_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==6)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC6_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==7)             GPIO_PORTC_REG_SET2->GPIOPCTL.R|=PinC7_AltFunctionChosen<<((conf_pin_count%7)*4);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AnalogFunction)
            {   
                //CHOOSE GPIO Function, Disable Digital function, Enable Analog Finction
                CLR_BIT(GPIO_PORTC_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTC_REG_SET2->GPIODEN.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTC_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTC_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 

            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == ExternalInterrupt)
            {   
                GPIO_PORTC_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);

                //Enable interrupt mask, choose interrupt sense, choose both edges, choose edge or level
                SET_BIT(GPIO_PORTC_REG_SET1->GPIOIM.R, conf_pin_count%7);
                GPIO_PORTC_REG_SET1->GPIOIS.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptense)<<(conf_pin_count%7);
                GPIO_PORTC_REG_SET1->GPIOIBE.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptBothEdgesEvent)<<(conf_pin_count%7);
                GPIO_PORTC_REG_SET1->GPIOIEV.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptChooseEdge)<<(conf_pin_count%7);
                SET_BIT(GPIO_PORTC_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 
                
            }
        }  
        else if (conf_pin_count>=24&&conf_pin_count<=31)
        {   
            if (ConfiguredPin[conf_pin_count].PortPinMode == DIO)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTD_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTD_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE GPIO Function, Enable Digital function, Disable Analog Finction
                CLR_BIT(GPIO_PORTD_REG_SET1->GPIOAFSEL.R, conf_pin_count%7);
                SET_BIT(GPIO_PORTD_REG_SET2->GPIODEN.R, conf_pin_count%7);
                CLR_BIT(GPIO_PORTD_REG_SET2->GPIOAMSEL.R, conf_pin_count%7);

                //Direction and Level
                GPIO_PORTD_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                if (ConfiguredPin[conf_pin_count].PortPinLevelValue == HIGH)
                    SET_BIT(GPIO_PORTD_GPIODATA->R, conf_pin_count);
                //InternalAttach
                GPIO_PORTD_REG_SET2->GPIOODR.R|=(ConfiguredPin[conf_pin_count].PortPinInternalAttach)<<conf_pin_count;
                //PULLUP & PULLDOWN
                GPIO_PORTD_REG_SET2->GPIOPUR.R|=(ConfiguredPin[conf_pin_count].PortPinPullUp)<<conf_pin_count;
                GPIO_PORTD_REG_SET2->GPIOPDR.R|=(ConfiguredPin[conf_pin_count].PortPinPulldown)<<conf_pin_count;
                //Output current
                GPIO_PORTD_REG_SET2->GPIODR2R.R|=(0x000000FF)|(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_2mA)<<conf_pin_count;
                GPIO_PORTD_REG_SET2->GPIODR4R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_4mA)<<conf_pin_count;
                GPIO_PORTD_REG_SET2->GPIODR8R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_8mA)<<conf_pin_count;
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AlternateFunction)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTD_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTD_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE Alternate Function, Disable Digital function, Disable Analog Finction
                SET_BIT(GPIO_PORTD_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTD_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTD_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));
                if (conf_pin_count%7==0)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD0_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==1)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD1_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==2)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD2_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==3)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD3_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==4)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD4_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==5)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD5_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==6)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD6_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==7)             GPIO_PORTD_REG_SET2->GPIOPCTL.R|=PinD7_AltFunctionChosen<<((conf_pin_count%7)*4);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AnalogFunction)
            {   
                //CHOOSE GPIO Function, Disable Digital function, Enable Analog Finction
                CLR_BIT(GPIO_PORTD_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTD_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTD_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTD_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 

            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == ExternalInterrupt)
            {   
                GPIO_PORTD_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);

                //Enable interrupt mask, choose interrupt sense, choose both edges, choose edge or level
                SET_BIT(GPIO_PORTD_REG_SET1->GPIOIM.R, conf_pin_count%7);
                GPIO_PORTD_REG_SET1->GPIOIS.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptense)<<(conf_pin_count%7);
                GPIO_PORTD_REG_SET1->GPIOIBE.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptBothEdgesEvent)<<(conf_pin_count%7);
                GPIO_PORTD_REG_SET1->GPIOIEV.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptChooseEdge)<<(conf_pin_count%7);
                SET_BIT(GPIO_PORTD_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 
                
            }
        } 
        else if (conf_pin_count>=32&&conf_pin_count<=37)
        {   
            if (ConfiguredPin[conf_pin_count].PortPinMode == DIO)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTE_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTE_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE GPIO Function, Enable Digital function, Disable Analog Finction
                CLR_BIT(GPIO_PORTE_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTE_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTE_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));

                //Direction and Level
                GPIO_PORTE_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                if (ConfiguredPin[conf_pin_count].PortPinLevelValue == HIGH)
                    SET_BIT(GPIO_PORTE_GPIODATA->R, (conf_pin_count%7));
                //InternalAttach
                GPIO_PORTE_REG_SET2->GPIOODR.R|=(ConfiguredPin[conf_pin_count].PortPinInternalAttach)<<(conf_pin_count%7);
                //PULLUP & PULLDOWN
                GPIO_PORTE_REG_SET2->GPIOPUR.R|=(ConfiguredPin[conf_pin_count].PortPinPullUp)<<(conf_pin_count%7);
                GPIO_PORTE_REG_SET2->GPIOPDR.R|=(ConfiguredPin[conf_pin_count].PortPinPulldown)<<(conf_pin_count%7);
                //Output current
                GPIO_PORTE_REG_SET2->GPIODR2R.R|=(0x000000FF)|(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_2mA)<<(conf_pin_count%7);
                GPIO_PORTE_REG_SET2->GPIODR4R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_4mA)<<(conf_pin_count%7);
                GPIO_PORTE_REG_SET2->GPIODR8R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_8mA)<<(conf_pin_count%7);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AlternateFunction)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTE_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTE_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE Alternate Function, Disable Digital function, Disable Analog Finction
                SET_BIT(GPIO_PORTE_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTE_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTE_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));
                if (conf_pin_count%7==0)             GPIO_PORTE_REG_SET2->GPIOPCTL.R|=PinE0_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==1)             GPIO_PORTE_REG_SET2->GPIOPCTL.R|=PinE1_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==4)             GPIO_PORTE_REG_SET2->GPIOPCTL.R|=PinE4_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==5)             GPIO_PORTE_REG_SET2->GPIOPCTL.R|=PinE5_AltFunctionChosen<<((conf_pin_count%7)*4);
    
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AnalogFunction)
            {   
                //CHOOSE GPIO Function, Disable Digital function, Enable Analog Finction
                CLR_BIT(GPIO_PORTE_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTE_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTE_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTE_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 

            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == ExternalInterrupt)
            {   
                GPIO_PORTE_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);

                //Enable interrupt mask, choose interrupt sense, choose both edges, choose edge or level
                SET_BIT(GPIO_PORTE_REG_SET1->GPIOIM.R, conf_pin_count%7);
                GPIO_PORTE_REG_SET1->GPIOIS.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptense)<<(conf_pin_count%7);
                GPIO_PORTE_REG_SET1->GPIOIBE.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptBothEdgesEvent)<<(conf_pin_count%7);
                GPIO_PORTE_REG_SET1->GPIOIEV.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptChooseEdge)<<(conf_pin_count%7);
                SET_BIT(GPIO_PORTE_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 
                
            }
        }
        else if (conf_pin_count>=38&&conf_pin_count<=42)
        {   
            if (ConfiguredPin[conf_pin_count].PortPinMode == DIO)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTF_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTF_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE GPIO Function, Enable Digital function, Disable Analog Finction
                CLR_BIT(GPIO_PORTF_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTF_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTF_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));

                //Direction and Level
                GPIO_PORTF_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);
                if (ConfiguredPin[conf_pin_count].PortPinLevelValue == HIGH)
                    SET_BIT(GPIO_PORTF_GPIODATA->R, (conf_pin_count%7));
                //InternalAttach
                GPIO_PORTF_REG_SET2->GPIOODR.R|=(ConfiguredPin[conf_pin_count].PortPinInternalAttach)<<(conf_pin_count%7);
                //PULLUP & PULLDOWN
                GPIO_PORTF_REG_SET2->GPIOPUR.R|=(ConfiguredPin[conf_pin_count].PortPinPullUp)<<(conf_pin_count%7);
                GPIO_PORTF_REG_SET2->GPIOPDR.R|=(ConfiguredPin[conf_pin_count].PortPinPulldown)<<(conf_pin_count%7);
                //Output current
                GPIO_PORTF_REG_SET2->GPIODR2R.R|=(0x000000FF)|(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_2mA)<<(conf_pin_count%7);
                GPIO_PORTF_REG_SET2->GPIODR4R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_4mA)<<(conf_pin_count%7);
                GPIO_PORTF_REG_SET2->GPIODR8R.R|=(ConfiguredPin[conf_pin_count].PortPinOutputCurrent_8mA)<<(conf_pin_count%7);
            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AlternateFunction)
            {   
                //check if the pin is not gpio by default
                if (conf_pin_count==0 || conf_pin_count==1 || conf_pin_count==2 || conf_pin_count==3 || conf_pin_count==4 || conf_pin_count==5 || conf_pin_count==10 || conf_pin_count==11 || conf_pin_count==16 || conf_pin_count==31 || conf_pin_count==38)
                {
                    //unlock and commit
                    GPIO_PORTF_REG_SET2->GPIOLOCK.R=0x4C4F434B;
                    GPIO_PORTF_REG_SET2->GPIOCR.R=(1<<conf_pin_count%7);
                }
                //CHOOSE Alternate Function, Disable Digital function, Disable Analog Finction
                SET_BIT(GPIO_PORTF_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTF_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTF_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));
                if (conf_pin_count%7==0)             GPIO_PORTF_REG_SET2->GPIOPCTL.R|=PinF0_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==1)             GPIO_PORTF_REG_SET2->GPIOPCTL.R|=PinF1_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==2)             GPIO_PORTF_REG_SET2->GPIOPCTL.R|=PinF2_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==3)             GPIO_PORTF_REG_SET2->GPIOPCTL.R|=PinF3_AltFunctionChosen<<((conf_pin_count%7)*4);
                if (conf_pin_count%7==4)             GPIO_PORTF_REG_SET2->GPIOPCTL.R|=PinF4_AltFunctionChosen<<((conf_pin_count%7)*4);

            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == AnalogFunction)
            {   
                //CHOOSE GPIO Function, Disable Digital function, Enable Analog Finction
                CLR_BIT(GPIO_PORTF_REG_SET1->GPIOAFSEL.R, (conf_pin_count%7));
                CLR_BIT(GPIO_PORTF_REG_SET2->GPIODEN.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTF_REG_SET2->GPIOAMSEL.R, (conf_pin_count%7));
                SET_BIT(GPIO_PORTF_REG_SET2->GPIOADCCTL.R, conf_pin_count%7); 

            }
            else if (ConfiguredPin[conf_pin_count].PortPinMode == ExternalInterrupt)
            { 
                GPIO_PORTF_REG_SET1->GPIODIR.R|=(ConfiguredPin[conf_pin_count].PortPinDirection)<<(conf_pin_count%7);

                //Enable interrupt mask, choose interrupt sense, choose both edges, choose edge or level
                SET_BIT(GPIO_PORTF_REG_SET1->GPIOIM.R, conf_pin_count%7);
                GPIO_PORTF_REG_SET1->GPIOIS.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptense)<<(conf_pin_count%7);
                GPIO_PORTF_REG_SET1->GPIOIBE.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptBothEdgesEvent)<<(conf_pin_count%7);
                GPIO_PORTF_REG_SET1->GPIOIEV.R|=(ConfiguredPin[conf_pin_count].PortPinInterruptChooseEdge)<<(conf_pin_count%7);
                SET_BIT(GPIO_PORTF_REG_SET2->GPIOADCCTL.R, conf_pin_count%7);                
            }
        }
    }
    
}
