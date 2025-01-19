#include "Mykeypad.h"


const byte ROWS = 6; //four rows
const byte COLS = 6; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3','4','5'},
  {'6','7','8','9','A','B'},
  {'C','D','E','F','G','H'},
  {'I','J','K','L','M','N'},
  {'O','P','Q','R','S','T'},
  {'U','V','W','X','Y','Z'},
};
byte rowPins[ROWS] = {14, 15, 16, 17, 5, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 11, 10, 9, 8, 7}; //connect to the column pinouts of the keypad

Keypad kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


MyKeypad::MyKeypad() {
    // initialisation du keypad
    Serial.println("Initialisation keypad terminée");
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



char MyKeypad::getFirstPressedChar(){
    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged && kpd.key[i].kstate == PRESSED )   // Only find keys that have changed state.
            {
                return kpd.key[i].kchar;
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(F(" PRESSED"));
            }
        }
    }

    // retour par défaut du caractère *
    return '*';
}
