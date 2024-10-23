#include "Mykeypad.h"


MyKeypad::MyKeypad() {
    // initialisation du keypad
    this->kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
    Serial.println("Initialisation keypad terminée");
}

Keypad * MyKeypad::getKeypad(){
    return &this->kpd;
}

void MyKeypad::displayKeypadInfo(){
    String msg = ""; 
    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
            }
        }
    }
}