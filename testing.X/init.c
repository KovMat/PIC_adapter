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