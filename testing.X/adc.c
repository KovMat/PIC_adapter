#include "adc.h"
#include "INCLUDES.h"


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
