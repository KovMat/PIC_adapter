#include "hetszegmens.h"
#include "INCLUDES.h"


void porget_7seg()
{
    if(lepes >= 16) lepes = 0; 
    PORTD = szamok[lepes]; // RB0 = 1;  // LED ON
    //__delay_ms(500);        // 1 Second Delay
    
}

