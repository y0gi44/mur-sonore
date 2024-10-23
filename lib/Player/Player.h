#ifndef PLAYER
#define PLAYER

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include <Hashtable.h>

#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))   // Using a soft serial port
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif

DFRobotDFPlayerMini myDFPlayer;

class Player {

private:
    Hashtable<char, uint8_t> tableMappingTouche ;


public:
    Player() = default;

    String getIdMusic(char c);

    void playMusicInFolder(uint8_t dir, uint8_t element);

    void printDetail(uint8_t type, int value);

}


#endif