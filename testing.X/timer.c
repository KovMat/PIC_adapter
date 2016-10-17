#include "timer.h"
#include "INCLUDES.h"

void initTimer0(){
    TMR0 = 0;   // TMR0 init
    T0CS = 0;   // internal clock
    T0SE = 0;   // reacting on low2high edge
    PSA = 0;    // Choosing to work with prescaler
    PS0 = 1;
    PS1 = 1;    // prescaler value divides in 256
    PS2 = 1;
    
    T0IE = 1;   // enable timer0 interrupt
    GIE = 1;    // enable global interrupts
}



     //Main Interrupt Service Routine (ISR)
void interrupt ISR() {
    //Check if it is TMR0 Overflow ISR
    if (TMR0IE && TMR0IF) {
        //TMR0 Overflow ISR

        counter++; //Increment Over Flow Counter

        if (counter == 13) {
            //Toggle RB1 (LED)
          
            if (RB1 == 0)
                RB1 = 1;
            else
                RB1 = 0;
          
            counter = 0; //Reset Counter
        }
        //Clear Flag
        TMR0IF = 0;
    }
}
