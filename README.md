# avr-snake
Projekt rekrutacyjny do M.O.S

Gry na matrycy LED.

Nasz rekrutacyjny projekt polegał na wykorzystaniu wyświetlacza LED do stworzenia gry Snake oraz wyścigów sterowanymi najprostszymi przyciskami, a następnie stworzenia obudowy do całego układu, aby cały projekt, choć trochę przypominał stare konsole do gry. Oto jak powstawał nasz Snake.

Do całego projektu użyliśmy:
•	Wyświetlacza LED 8x8  (1sztuka)
•	Rejestr przesuwny z zatrzaskiem (2sztuki)
•	Atmega 32
•	Przyciski
•	Rezystorów i kondensatory do sprawnego działania procka.

![alt tag](https://github.com/serek8/avr-snake/blob/master/sample_3.jpg)

Jak to działa?
Podłączanie
Zaczęliśmy od sprawdzenia, które dwa piny wyświetlacza odpowiadał, której diodzie na wyświetlaczu a następnie pogrupowanie ich na wiersze i kolumny tak, aby następnie łatwo podłączyć to do rejestrów przesuwnych. Następnie podłączyliśmy szeregowo rejestry używając, aby używać jak najmniej nóżek naszej Amegi.
Programowanie w C
Do przesyłu bitów do rejestrów użyliśmy wbudowanej funkcji AVRow do komunikacji SPI . Wysyłaliśmy za każdym razem 2bajty, gdzie pierwszy bajt ustawiał, które wiersze na matrycy mają być zapalone, a drugi robił dokładnie to samo tylko z kolumnami. Od razu potem nadszedł czas na multipleksowanie, które wykonaliśmy używając 8-bitowego Timer0 do odświeżania całego obrazu. 

Programowanie Snake 
Zaczęliśmy od wprowadzenie do naszego projektu przycisków i kolejnego timera – 16-bitowego Timer1, który miał za zadanie na bieżąco sprawdzać stan wciśnięcia przycisków a następnie na podstawie ich stanu i interwału w nim ustawionego zapalać lub gasić odpowiedni piksel na matrycy.
