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

unsigned char szamok[] = {
  //0bEGFDHCBA
    0b01001000, //0
    0b11111001, //1
    0b00101100, //2
    0b10101000, //3
  //0bEGFDHCBA
    0b10011001, //4
    0b10001010, //5
    0b00001010, //6
    0b11111000, //7
  //0bEGFDHCBA  
    0b00001000, //8
    0b10001000, //9
    0b00011000, //A
    0b00001011, //b
  //0bEGFDHCBA
    0b01001110, //C
    0b00101001, //d
    0b00001110, //E
    0b00011110  //F
  //0bEGFDHCBA
};

int main()
{
  init_device();
  int i = 0;
    RB1=1;
    __delay_ms(300);
    RB1=0;  
    __delay_ms(1000);
  while(1)
  {
    RB1=1;
    for(i=0 ; i<16 ; i++)
    {
        PORTD = szamok[i];      // RB0 = 1;  // LED ON
        __delay_ms(500);        // 1 Second Delay
    }
  }
  return 0;
}