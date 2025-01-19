#include <Arduino.h>
#include "Mykeypad.h"
#include "Player.h"

unsigned long loopCount;
unsigned long startTime;
MyKeypad * keypad;
Player * player ;

void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    keypad = new MyKeypad();
    player = new Player();

}


void loop() {

    // Affichage des touches du keypad
    //keypad->displayKeypadInfo();
    char c = keypad->getFirstPressedChar();
  
    if (c != '*') {
        player->gererTouche(c);
    }

    player->displayPlayerDetail();
}  // End loop
