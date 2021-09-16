#include "Activity1.h"

void SEAT_CHECKING(){
    DDRD|=(1<<PD0); 
    DDRD&=~(1<<PD1); 
    PORTD|=(1<<PD1); 
    DDRD&=~(1<<PD2); 
    PORTD|=(1<<PD2); 
}