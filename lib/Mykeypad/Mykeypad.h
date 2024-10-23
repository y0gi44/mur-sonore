#ifndef MY_KEYPAD
#define MY_KEYPAD

#include "Arduino.h"
#include "Keypad.h"



class MyKeypad {

  //Keypad kpd = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);;
  Keypad * kpd;
  public:
    MyKeypad();      
    Keypad * getKeypad();

    void displayKeypadInfo();

    char getFirstPressedChar();
  
};


#endif