/*
 * File:   init.c
 * Author: KovMat
 *
 * Created on October 4, 2016, 2:36 PM
 */


#include "init.h"

void init_device(){
  TRISD = 0x00;
  TRISB = 0x01; //RB0 bemenet
    
  PORTD = 0xFF;
  
  RB1 = 0; 
}


void porget_7seg()
{
    int i=0;
    for(i=0 ; i<16 ; i++)
    {
        PORTD = szamok[i];      // RB0 = 1;  // LED ON
        //__delay_ms(500);        // 1 Second Delay
    }
}