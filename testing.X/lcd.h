/* 
 * File:   lcd.h
 * Author: KovMat
 *
 * Created on October 13, 2016, 7:03 PM
 */

#ifndef LCD_H
#define	LCD_H

// Define Pins
#define LCD_E    			RC6     // Enable pin for LCD
#define LCD_RS	 			RC4     // RS pin for LCD
#define LCD_RW              RC5     // RW pin for LCD

#define LCD_Data_Bus_D0     RD0     // Data bus bit 0
#define LCD_Data_Bus_D1     RD1     // Data bus bit 1
#define LCD_Data_Bus_D2     RD2     // Data bus bit 2
#define LCD_Data_Bus_D3     RD3     // Data bus bit 3

#define LCD_Data_Bus_D4		RD4		// Data bus bit 4
#define LCD_Data_Bus_D5		RD5		// Data bus bit 5
#define LCD_Data_Bus_D6		RD6		// Data bus bit 6
#define LCD_Data_Bus_D7		RD7		// Data bus bit 7

#define LCD_Data            PORTD 


// Define Pins direction registrers
#define LCD_E_Dir     			TRISC0
#define LCD_RS_Dir   	 		TRISC1
#define LCD_Data_Bus_Dir_D4   	TRISD4
#define LCD_Data_Bus_Dir_D5     TRISD5
#define LCD_Data_Bus_Dir_D6  	TRISD6
#define LCD_Data_Bus_Dir_D7 	TRISD7

// Constants
#define E_Delay       500  


// Function Declarations
void WriteCommandToLCD(unsigned char);
void WriteDataToLCD(char);
void InitLCD(void);
void WriteStringToLCD(const char*);
void ClearLCDScreen(void);



#endif	/* LCD_H */

