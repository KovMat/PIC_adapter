/* 
 * File:   hetszegmens.h
 * Author: KovMat
 *
 * Created on October 13, 2016, 7:07 PM
 */

#ifndef HETSZEGMENS_H
#define	HETSZEGMENS_H

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
int lepes=0;
void porget_7seg();


#endif	/* HETSZEGMENS_H */

