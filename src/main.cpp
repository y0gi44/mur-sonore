#include <Arduino.h>
#include "Mykeypad.h"
#include "Player.h"
#include "Ecran.h"

/* relative path for GDB stub valid only if this file is in the examples subfolder */
//#include "avr8-stub.h"

unsigned long loopCount;
unsigned long startTime;
MyKeypad * keypad;
Player * player ;
Ecran * ecran;

void setup() {

    debug_init();
    //Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    keypad = new MyKeypad();
    player = new Player();

    //ecran = new Ecran();
    //ecran->init();
    Serial.println(F("Mur Sonore Initialisé ... "));
}


void loop() {

    // Affichage des touches du keypad
    //keypad->displayKeypadInfo();
    char c = keypad->getFirstPressedChar();
  
    if (c != '*') {
        player->gererTouche(c);
        ecran->display(player->getCurrentFolder(), player->getCurrentFile());
    }

    player->displayPlayerDetail();

}


