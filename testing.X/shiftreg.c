#include "shiftreg.h"
#include "INCLUDES.h"

        // RB2 -> Data
        // RB4 -> clock input 
        // RB5 -> Strobe
   

void shift_pulse(int ertek)
{

    RB2 = ertek;
    int i = 0;

    for (i = 0; i < 8; i++) {
        RB5 = 0;
        RB4 = 0;
        
        RB5 = 1;
        RB4 = 1;

        RB5 = 0;
        RB4 = 0;
        __delay_ms(1000);
    }
    
}