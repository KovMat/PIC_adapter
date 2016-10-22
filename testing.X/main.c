/*
 * File:   main.c
 * Author: KovMat
 *
 * Created on September 25, 2016, 11:19 AM
 */
#include "INCLUDES.h"

#include "lcd.h"

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

void init_device(){
  //TRISD = 0x00;     // port D kimenet
  TRISB = 0x00;     // port b kimenet
  //TRISC = 0x00;     // port c kimenet
  
  // Timer0, 
  initTimer0();
  
  // port érték init
  //PORTD = 0x00;
}

int main()
{
  
  init_device();
  RB1 = 1;
  __delay_ms(2000);
  RB1 = 0;
  
  while(1)
  {         
      shift_pulse(1);
  }
  
  return 0;
}