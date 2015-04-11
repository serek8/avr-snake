# avr-snake
<h2>Projekt rekrutacyjny do M.O.S</h2>

<h2>Gry na matrycy LED.</h2>

Nasz rekrutacyjny projekt polegał na wykorzystaniu wyświetlacza LED do stworzenia gry Snake oraz wyścigów sterowanymi najprostszymi przyciskami, a następnie stworzenia obudowy do całego układu, aby cały projekt, choć trochę przypominał stare konsole do gry. Oto jak powstawał nasz Snake.

Do całego projektu użyliśmy:<br />
•	Wyświetlacza LED 8x8  (1sztuka)<br />
•	Rejestr przesuwny z zatrzaskiem (2sztuki)<br />
•	Atmega 32<br />
•	Przyciski<br />
•	Rezystorów i kondensatory do sprawnego działania procka.<br />
<br />
![alt tag](https://github.com/serek8/avr-snake/blob/master/sample_3.jpg)
<br />
<h2>Jak to działa?<h2><br />
<h3>Podłączanie</h3><br />
Zaczęliśmy od sprawdzenia, które dwa piny wyświetlacza odpowiadał, której diodzie na wyświetlaczu a następnie pogrupowanie ich na wiersze i kolumny tak, aby następnie łatwo podłączyć to do rejestrów przesuwnych. Następnie podłączyliśmy szeregowo rejestry używając, aby używać jak najmniej nóżek naszej Amegi.
Programowanie w C
Do przesyłu bitów do rejestrów użyliśmy wbudowanej funkcji AVRow do komunikacji SPI . Wysyłaliśmy za każdym razem 2bajty, gdzie pierwszy bajt ustawiał, które wiersze na matrycy mają być zapalone, a drugi robił dokładnie to samo tylko z kolumnami. Od razu potem nadszedł czas na multipleksowanie, które wykonaliśmy używając 8-bitowego Timer0 do odświeżania całego obrazu. 

<h2>Programowanie Snake </h2>
Zaczęliśmy od wprowadzenie do naszego projektu przycisków i kolejnego timera – 16-bitowego Timer1, który miał za zadanie na bieżąco sprawdzać stan wciśnięcia przycisków a następnie na podstawie ich stanu i interwału w nim ustawionego zapalać lub gasić odpowiedni piksel na matrycy.

![alt tag](https://github.com/serek8/avr-snake/blob/master/sample_1.jpg)
![alt tag](https://github.com/serek8/avr-snake/blob/master/sample_2.jpg)
