/*
 ================================================================================================
 Name        : Distance_ Display.c
 Author      : Hesham Medhat
 Description : Calculate the distance using ultrasonic module
 Date        : 13/10/2021
 ================================================================================================
 */
#define F_CPU 8000000
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h> /* For the delay functions */

int main (void)
{
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	LCD_init();
	LCD_displayStringRowColumn(0,0,"Distance=    cm");
	while (1)
	{
		uint16 distance;
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		_delay_ms(80);
	}
}

