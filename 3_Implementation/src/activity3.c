#include "activity2.h"
#include "activity3.h"

#include<avr/io.h>
#include<util/delay.h>

void InitADC()
{
ADMUX=(1<<REFS0);
ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch)
{
ADMUX&=0xf8;
ch=ch&0b00000111;
ADMUX|=ch;
ADCSRA|=(1<<ADSC);
while(!(ADCSRA & (1<<ADIF)));
ADCSRA!=(1<<ADIF);
return(ADC);
}


void timer_initialization(void){

    TIMER1_FAST_PWM; //setting timer1 for PWM
    TIMER_PRESCALER_AS_64; //8 prescalar
    PWM_OUTPUT_PIN; //Setting PB1 as output pin

}

void pwm_out(uint16_t ADC_READING){
    char Temp[20];
    char start[]="Temperature :)";

    if(ADC_READING>0 && ADC_READING<=200){

        OCR1A = 195; //20% duty cycle
        Temp[0] = '2';
        Temp[1] = '0';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=210) && (ADC_READING<=500)){

        OCR1A = 495; //40% duty cycle
        Temp[0] = '2';
        Temp[1] = '5';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=501) && (ADC_READING<=700)){

        OCR1A = 695;//70% duty cycle
        Temp[0] = '2';
        Temp[1] = '9';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=701) && (ADC_READING<=1024)){

        OCR1A = 1019; //95% duty cycle
        Temp[0] = '3';
        Temp[1] = '3';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else{
        OCR1A = 0; //0% output
        Temp[0] = 'O';
        Temp[1] = 'F';
        Temp[2] = 'F';
        Temp[3] = ' ';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }

}
