#include "shiftreg.h"
#include "INCLUDES.h"

        // RB2 -> Data
        // RB4 -> clock input 
        // RB5 -> Strobe
   
void clockpulse()
{
        RB4 = 0;
        RB3 = 0;
        
        RB4 = 1;
        RB3 = 1;

        RB4 = 0;
        RB3 = 0;
}

void shift_pulse(int ertek)
{
    int i = 0;
    RB2=0;

    clockpulse();
    __delay_ms(1000);
    clockpulse();
        
    
}