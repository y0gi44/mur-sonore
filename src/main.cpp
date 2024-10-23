#include <Arduino.h>
#include "Mykeypad.h"


//initialize an instance of class NewKeypad
//Keypad kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


unsigned long loopCount;
unsigned long startTime;
MyKeypad * keypad;

void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    keypad = new MyKeypad();
}


void loop() {
    loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print(F("Average loops per second = "));
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    keypad->displayKeypadInfo();

}  // End loop
