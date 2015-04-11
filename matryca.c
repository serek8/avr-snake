#include <avr/io.h>
#include <util/delay.h>

#include "matryca.h"


#define MOSI (1<<PB5)	// SERIAL INPUT
#define SCK (1<<PB7)	// SHIFT CLOCK	SC
#define LT (1<<PB4)		// LATCH CLOCK	LT


// Impuls LATCH
#define LT_ON PORTB |= LT		// impuls LATCH (rosnie)
#define LT_OFF PORTB &= ~LT		// impuls LATCH (maleje)


void InitSpi()
{
	DDRB |= MOSI | SCK | LT ;	// ustawiamy piny SPI jako wyjscia (potrzebne do wlaczenia sprzetowego SPI)

	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<DORD);	// wlaczamy tryb SPI i w³¹czamy tryb master

	SPSR |= (1<<SPI2X);			// czestotliwosc SCK = fo/2


}


void SendSpi(uint8_t bajt)
{

	SPDR = bajt;	// rejest to wsadzenia calego bajtu

	while(! (SPSR & (1<<SPIF) ) );	// oczekuje na flage zakonczenia przesylania


}


void EndSession()
{
	LT_ON;
	// tutaj moze wartoby bylo zrobic _delay_us(1); aby sygnal zdazyl dotrzec
	LT_OFF;
	for(uint8_t i=0 ; i<= LICZBA_REJESTROW_DLA_SPI ; ++i )
		{
			SPDR = 0;	//ustawiam stan niski na MOSI pod koniec ale nie laczuje zeby nie wyszlo mi na piny
			while(! (SPSR & (1<<SPIF) ) );
		}


}


void InitTimer()
{
	// ustawiam tryb CTC oraz prescaler 8,000,000 / 64
	TCCR0 |= (1<<WGM01) | (1<<CS01) | (1<<CS00);

	OCR0 = 39;	// licznik impulsow

	TIMSK |= (1<<OCIE0);	// Timer/Counter0 Compare Match interrupt is enabled
}

ISR(TIMER0_COMP_vect)
{

	static uint8_t licz_x =0;
	static uint8_t licz_y =0;

	// jesli przejde rozmiar wyswietlacza to zaczynam od nowa liczyc wsp x i y
	if( (licz_y  > (LICZBA_PIKSELI_NA_OSI_X-1)))
	{
		licz_x=0;
		licz_y=0;
	}

	if(tablicaPikseliMatrycy[licz_x][licz_y] == 1)
	{
		SendSpi(~wsp2hex[licz_y]);	// wiersze katody
		SendSpi(wsp2hex[licz_x]);	 // kolumny anody
		EndSession();
	}
	else if(tablicaPikseliMatrycy[licz_x][licz_y] == 0)
	{
		SendSpi(0);		// wiersze katody
		SendSpi(0); 	// kolumny anody
		EndSession();
	}


	++licz_x;

	// jak przejde caly wiersz to przechodze do nastepnej linijki
	if(  licz_x > (LICZBA_PIKSELI_NA_OSI_X-1)  )
		{
		licz_x = 0;	// przechodze do kolumny nr 0
		++licz_y;	// przechodze do nowego wiersza
		}

}


void wyczyscTablicePikseli()
{
	for(uint8_t i=0 ; i < LICZBA_PIKSELI_NA_OSI_X ; i++)
	{
		for(uint8_t j=0 ; j < LICZBA_PIKSELI_NA_OSI_X ; j++)
		tablicaPikseliMatrycy[i][j] = 0;

	}
}



void ustawPiksel(uint8_t x, uint8_t y, uint8_t nowy_stan)
{
	tablicaPikseliMatrycy[x][y] = nowy_stan;
}


uint8_t wsp2hex[8]={1,2,4,8,16,32,64,128};

