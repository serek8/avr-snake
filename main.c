/*
 * main.c
 *
 *  Created on: 5 lis 2014
 *      Author: Janek
 */



#include <avr/io.h>
#include <util/delay.h>

#include "matryca.h"
#include "ruch.h"

int main()
{
	InitSpi();		// inicjalizuje SPI
	initTimer1(5500);
	InitTimer();	// inicjalizuje multiplexowanie
	sei();		// wlaczenie globalnego zezwolenia na przerwania
	wyczyscTablicePikseli();


	while(1)
	{


	}

}



