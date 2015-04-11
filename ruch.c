/*
 * ruch.c
 *
 *  Created on: 26 lis 2014
 *      Author: Janek
 */

#include "ruch.h"

void initTimer1(uint16_t czestotliwosc_zliczania_imp)
{

	TCCR1B |= (1<<WGM12) | (1<<CS12) | (1<<CS10);  // preskaler 1024

	OCR1A = czestotliwosc_zliczania_imp;

	TIMSK |= (1<<OCIE1B);	// wlaczamy comparematch dla Timer1B


}


ISR(TIMER1_COMPB_vect)
{
	static uint8_t pikselX = 0;
	static uint8_t pikselY = 0;
	if(pikselX > 7)
		{
		pikselX = 0;
		++pikselY;
		}
	if(pikselY>7)
	{
		pikselY =0;
		wyczyscTablicePikseli();
	}

	ustawPiksel(pikselX,pikselY,1);
	++pikselX;


}
