# BuiltInSystemLABB1
Built In systems Architecture and Design
//Program to Impliment UART in avr programing 
//using Atmega328p MCU (Arduino uno)
//IDE visual code

1.4.1 DELUPPGIFT 1: BLINKA LED

1. Läs databladen för tillhandahållen LED och resistorer och räkna ut en lämplig resistorstorlek
2. Koppla in LED och lämplig resistor till pinne 8 på Arduinons expansionsport med hjälp av 
kopplingsdäck och kablar
3. Använd elschemat för Arduinon för att lista ut vilken port och pinne på ATMegan detmotsvarar
4. Konfigurera upp pinnen som utgång
5. Skapa en oändlig loop i main(), och omväxlande tänd/släck LEDen med 500 ms av- respektive
på-tid.
6. Städa upp din kod och skapa en git-commit med ovanstående och redogör för resistorberäkningen i
commit- meddelandet

1.4.2 DELUPPGIFT 2: KONFIGURERA UPP UART FÖR SÄNDNING (TX)

Samtliga nämnda funktioner deklareras i serial.h och implementeras i serial.c.
1. Implementera funktionen uart_init så att den konfigurerar upp USART0 för sändning 
(TX) enligt 8N1 i 38400 baud.
2. Implementera funktionen uart_putchar så att den skickar ett enskilt tecken över 
USART0, och lägger till tecknet ’\r’ (radretur) om tecknet vi vill skicka är ’\n’ 
(radbrytning).
3. Testa funktionen med hjälp av en serieterminal på din dator — anropa periodiskt 
uart_putchar från din loop i main.
4. Implementera funktionen uart_putstr så att den med hjälp av uart_putchar skriver ut
en hel sträng på serieterminalen.
5. Visa att funktionen fungerar genom att anropa uart_putstr från main med ditt namn + 
radbrytning som argument.
6. Städa upp din kod och skapa en git-commit med ovanstående förändringar.

1.4.3 DELUPPGIFT 3: KONFIGURERA UPP UART FÖR MOTTAGNING (RX)

1. Ändra implementationen av uart_init så att den även medger mottagning (RX).
2. Implementera funktionen uart_getchar så att den tar emot ett enskilt tecken.
3. Visa att funktionen fungerar genom att implementera uart_echo så att den väntar på ett 
inkommande tecken med hjälp av uart_getchar, och direkt skickar tillbaka samma tecken 
med uart_putchar. Anropa funktionen från main.
4. Städa upp din kod och skapa en git-commit med ovanstående förändringar.
1.4.4 DELUPPGIFT 4 (VG-KRAV): STYR LED VIA UART
1. Deklarera, implementera, och kommentera en funktion som via UART tar emot strängarna 
’ON\r\n’ och ’OFF\r\n’ och tänder respektive släcker en LED (samma som ovan, en ny på 
godtycklig pinne, eller den inbyggda på pinne 13).
2. Städa upp och skapa en git-commit med ovanstående förändring. Dokumentera beteendet och 
vilken pinne LEDen förväntas sitta på
