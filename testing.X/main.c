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
#pragma config WDTE = OFF//N // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

unsigned char counter = 0;

void gombTeszt()
{
    if(PORTB & 0x01) {
        RB1 = 1; 
    }
    else {
        RB1 = 0;
    }
}

int lepes=0;
void porget_7seg()
{
    if(lepes >= 16) lepes = 0; 
    PORTD = szamok[lepes]; // RB0 = 1;  // LED ON
    //__delay_ms(500);        // 1 Second Delay
    
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


     //Main Interrupt Service Routine (ISR)
void interrupt ISR() {
    //Check if it is TMR0 Overflow ISR
    if (TMR0IE && TMR0IF) {
        //TMR0 Overflow ISR

        counter++; //Increment Over Flow Counter

        if (counter == 13) {
            //Toggle RB1 (LED)
            lepes++;
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

void InitADC(void)
{
	ADCON1  = 0x80;	     // Make PORTA and PORTE analog pins
						 // Also, Vref+ = 5v and Vref- = GND
	TRISA   = 0x2f;      // Make RA5, RA3, RA2, RA1, RA0 input
	TRISE   = 0x07;		 // Make RE0, RE1 and RE2 input
	ADCON0  = 0x81;		 // Turn on the A/D Converter
}


unsigned int GetADCValue(unsigned char Channel)
{
	ADCON0 &= 0xc7;         // Clear Channel selection bits
	ADCON0 |= (Channel<<3); // Select channel pin as ADC input
    
    __delay_ms(10);         // Time for Acqusition capacitor 
							// to charge up and show correct value
	GO_nDONE  = 1;		    // Enable Go/Done

	while(GO_nDONE);        // Wait for conversion completion

	return ((ADRESH<<8)+ADRESL);   // Return 10 bit ADC value
}




int main()
{
  init_device();
  char Count = 0;
  char led = 0;
  RB1 = 1;
  __delay_ms(100);
  RB1=0;
  
  initTimer0();
  InitADC();
  
  unsigned int adcValue = 0;
  

    while(1)
    {
        porget_7seg();
        adcValue = GetADCValue(7);
    }
  return 0;
}