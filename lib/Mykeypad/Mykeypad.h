#ifndef MY_KEYPAD
#define MY_KEYPAD

#include "Arduino.h"
#include "Keypad.h"

const byte ROWS = 6; //four rows
const byte COLS = 6; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3','4','5'},
  {'6','7','8','9','A','B'},
  {'C','D','E','F','G','H'},
  {'I','J','K','L','M','N'},
  {'O','P','Q','R','S','T'},
  {'U','V','w','X','Y','Z'},
};
byte rowPins[ROWS] = {3, 2, 1, 0, 3, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4, 6, 11}; //connect to the column pinouts of the keypad


class MyKeypad {

  Keypad kpd ;

  public:
    MyKeypad() ;

      
    Keypad * getKeypad();

    void displayKeypadInfo();
  
};


#endif