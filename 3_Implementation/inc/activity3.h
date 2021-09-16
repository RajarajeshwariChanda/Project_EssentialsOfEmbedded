#ifndef ACTIVITY3_H_INCLUDED
#define ACTIVITY3_H_INCLUDED
#include<avr/io.h>
#include "util/delay.h"

#define TIMER1_FAST_PWM TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11)
#define TIMER_PRESCALER_AS_64 TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10)
#define PWM_OUTPUT_PIN DDRB|=(1<<PB1)

uint16_t ReadADC(uint8_t ch);
void InitADC();
void timer_initialization(void);
void pwm_out(uint16_t ADC_READING);

#endif // ACTIVITY3_H_INCLUDED
