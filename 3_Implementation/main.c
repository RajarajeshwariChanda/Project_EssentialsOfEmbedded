#include <avr/io.h>
#include<util/delay.h>
#include "activity1.h"
#include "activity2.h"
#include"activity3.h"
int main(void)
{
    SEAT_CHECKING(); 
    ADC_INITIALIZATION(); 
    TIMER_INITIALIZATION(); 
    LCD_INITIALIZATION(); 

    uint16_t read;

	while(1)
    {
        if(SEAT_CHECK)
        {
            PORTD|=(1<<PD2);
            if(HEATER_ON){
                LED_ON;
                _delay_ms(200);
                CLEAR_LCD();
                read=SENSE_ADC(0);
                PWM_OUPUT(read);

            }
            else
                {
                    LED_OFF;
                     _delay_ms(200);
                    HEATER_OFF;
                    _delay_ms(200);
                    CLEAR_LCD();
                }
        }
        else{
            LED_OFF;
            _delay_ms(200);
            HEATER_OFF;
            _delay_ms(200);
            CLEAR_LCD();
        }
    }
    return 0;
}
