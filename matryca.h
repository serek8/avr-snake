/*
 * matryca.h
 *
 *  Created on: 8 lis 2014
 *      Author: Janek
 */

#ifndef MATRYCA_H_
#define MATRYCA_H_


#include <avr/interrupt.h>



// JE¯ELI COS NIE DZIALA, NA POCZ¥TKU ZOBACZ CZY DOBRZE USTAWILES STALE DLA HARDWARE !!

/* * * *  S T A L E   H A R D W A R E  * * *
 *
 * Gdy dodajemy nowy rejestr do ukladu to po ustawieniu jego bitow przez SPI
 * i wylaczowaniu ich na piny nale¿y ustawic stan wszystkich SERIAL INPUT
 * na stan niski aby nie zaklócaly pracy rejestru. Dlatego jest stworzona
 * funkcja EndSession() która wystawia ten stan. Aby ona mogla dobrze dzialac
 * musi miec dobr¹ wartoœc LICZBA_REJESTROW_DLA_SPI, ktora opisuje ilosc rejestrow
 * ktore sa podpiete pod hardwarowe SPI
 *
 */


		#define LICZBA_REJESTROW_DLA_SPI 2

		#define LICZBA_PIKSELI_NA_OSI_X 8


 /*
 *
 *
 * * * *   K O N I E C    S T A L Y C H    H A R D W A R E    * * * * * * */



/* * Tutorial wysylania danych
 *
 * 	SendSpi(0b00100000);	 // to jest wysylane jako pierwsze i zostanie popchniete nastepnym SendSpi
 *							 // czyli bajt zapisany w tym argumencie odpowiada drugiemu rejestrowi
 *							 //
 *							 // Drugi rejestr to sa katody odpowiadajace kolejnym wierszom
 *
 *
 *	SendSpi(0b10100000);	// to wywolanie SendSpi przesuwa starszy bajt na nastepny rejsestr
 *							// a nowy bajt jest teraz przypisany pierwszemu rejestrowi
 *							//
 *							// Pierwszys rejestr(blizej wyjscia MOSI ATMEGA) odpowiada
 *							//    kolejnym anodom - kolumny
 *
 *
 *	Najmlodszy bit reprezentuje zawsze odpowiednio najbardziej lewy / gorny rog matrycy
 *
 */


/*
 *  tablicaPikseliMatrycy to tablica dwuwymiarowa przechowujaca stan wszystkich pikseli na matrycy
 *
 *  		mozliwe stany to 0 i 1
 *
 */
uint8_t tablicaPikseliMatrycy[LICZBA_PIKSELI_NA_OSI_X][LICZBA_PIKSELI_NA_OSI_X];



/*
 *  wyczyscTablicePikseli zeruje wszystkie elementy tablicy
 *
 */
void wyczyscTablicePikseli();



/*
 *  ustawPiksel ustawia piksel o wierszu X i kolumnie Y na stan nowy_stan
 *
 */
void ustawPiksel(uint8_t x, uint8_t y, uint8_t nowy_stan);


// Przerwanie dla Timer0
ISR(TIMER0_COMP_vect);



/*
 * 	InitSpi() - uruchamia biblioteke. Konieczne do uzywania pozostalych funkcji.
 *
 * 			  Ustawia rejestry ATMEGA32 aby mozna
 * 			  bylo korzystac ze sprzetowego SPI.
 */
void InitSpi();



/*
 *  SendSpi(...) - wysyla pojedynczy bajt przez SPI
 *
 *
 */
void SendSpi(uint8_t bajt);


/*
 *  EndSession() - zatrzaskuje rejestr (LATCH) oraz...
 *				   oraz wysyla na wszystkie piny 'SERIAL IN' rejestrow
 *				   stan niski aby rejest dzialal poprawnie.
 *
 *				   UWAGA !!!
 *				   ¯eby funkcja dziala poprawnie musi byc dobrze zdefiniowana
 *				   wartosc preprocesora LICZBA_REJESTROW_DLA_SPI, któr¹ nale¿y zmieniac
 *				   przy kazdej zmianie liczby rejestrow dla SPI
 */
void EndSession();


/*
 * InitTimer() - funkcja inicjalizuj¹ca Timer do multiplexowania
 *
 *				Niezbedne do dzialania ekranu
 *
 */
void InitTimer();



uint8_t wsp2hex[8];





#endif /* MATRYCA_H_ */
