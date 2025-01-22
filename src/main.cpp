#include <Arduino.h>
#include <MemoryFree.h>

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

void displayFreeRam(){
    Serial.print(F("Memory Free : "));
    Serial.println(freeMemory());
}


void setup() {

    //debug_init();
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();

    Serial.println(F("avant init"));
    displayFreeRam();

    player = new Player();

    Serial.println(F("après init player"));
    displayFreeRam();

    
    keypad = new MyKeypad();
    
    Serial.println(F("après init clavier"));
    displayFreeRam();
    
    ecran = new Ecran();
    ecran->init();
    Serial.println(F("après init ecran"));
    displayFreeRam();
    
    Serial.println(F("Mur Sonore Initialisé ... "));
    
}


void loop() {

    // Affichage des touches du keypad
    //keypad->displayKeypadInfo();
    char c = keypad->getFirstPressedChar();
    //char  c = 'z';
  
    if (c != '*') {
        Serial.print(F("Envoi de la touche au player : "));
        Serial.println(c);
        player->gererTouche(c);
        ecran->display(player->getCurrentFolder(), player->getCurrentFile());
    }

    //player->displayPlayerDetail();

    //ecran->display(1, 12);

}


