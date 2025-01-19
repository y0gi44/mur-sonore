#ifndef MY_KEYPAD
#define MY_KEYPAD

#include "Arduino.h"
#include "Keypad.h"



class MyKeypad {

  public:
    MyKeypad();      

    void displayKeypadInfo();

    char getFirstPressedChar();
  
};


#endif