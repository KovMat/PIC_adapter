#include "button.h"
#include "INCLUDES.h"

void initButton(void)
{

}

void gombTeszt()
{
    if(PORTB & 0x04) {
        RB4 = 1; 
    }
    else {
        RB4 = 0;
    }
}
