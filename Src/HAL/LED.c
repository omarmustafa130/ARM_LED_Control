#include "Inc/LED.h"
#include "../Common/Mcu_Hw.h"

#include "../Config/LED_Cfg.h"
#include "../MCAL/Inc/Dio.h"
#include "../MCAL/Inc/Port.h"

void led_state(Port_PinType ChannelID, Dio_LevelType Level)
{
    		GPIO_PORTF_GPIODATA->B.bit_4=Level;
}
