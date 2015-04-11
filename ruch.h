/*
 * ruch.h
 *
 *  Created on: 26 lis 2014
 *      Author: Janek
 */

#ifndef RUCH_H_
#define RUCH_H_

#include "matryca.h"
#include <avr/interrupt.h>

/*
 *  initTimer1 inicjalizuje Timer1 16bit
 *  Czestotliwosc Procka = 8,000,000Hz
 *  Prescaler 1024
 *  Wiec na sekunde otrzymujemy 8,000,000 / 1024 = 7812 przerwan
 *
 *	Timer uzywa trybu CTC, ktory zlicza impulsy 'czestotliwosc_zliczania_imp'
 *	dziêki czemu mozemy uzyskac jeszcze mniej przerwan na sekunde.
 *	Liczba przerwan na sekunde wynosi: 7812 / czestotliwosc_zliczania_imp
 *
 *
 *	0 <= czestotliwosc_zliczania_imp <= 61535   !!!!!!!!!!!
 *
 */
void initTimer1(uint16_t czestotliwosc_zliczania_imp);





#endif /* RUCH_H_ */
