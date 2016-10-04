/*
 * File:   main.c
 * Author: KovMat
 *
 * Created on September 25, 2016, 11:19 AM
 */

#define _XTAL_FREQ 3579500

#include <xc.h>
#include "init.h"

// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF //N // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG



void gombTeszt()
{
    if(PORTB & 0x01) {
        RB1 = 1; 
    }
    else {
        RB1 = 0;
    }
}


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

unsigned char counter = 0;
     //Main Interrupt Service Routine (ISR)
void interrupt ISR() {
    //Check if it is TMR0 Overflow ISR
    if (TMR0IE && TMR0IF) {
        //TMR0 Overflow ISR

        counter++; //Increment Over Flow Counter

        if (counter == 76) {
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



int main()
{
  init_device();
  char Count = 0;
  char led = 0;
  RB1=0;
  
  initTimer0();
  
    while(1)
    {
        porget_7seg();
    }
  return 0;
}