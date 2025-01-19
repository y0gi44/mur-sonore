#include "Player.h"

#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/2, /*tx =*/3);
#define FPSerial softSerial


// #if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))   // Using a soft serial port
// #include <SoftwareSerial.h>
// SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
// #define FPSerial softSerial
// #else
// #define FPSerial Serial1
// #endif

String listeTouches= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getElement(char c){
  return listeTouches.indexOf(c);
}


Player::Player(){
    current_folder = 1;


  FPSerial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(20);  //Set volume value. From 0 to 30

}

void Player::volumeUp() {
  myDFPlayer.volumeUp();
}

void Player::volumeDown() {
  myDFPlayer.volumeDown();
}

void Player::gererTouche(char key_pressed){
    int id_key_pressed =  getElement(key_pressed);
    
    if (id_key_pressed < 0){
      Serial.print(F("La touche pressee n'existe pas :"));
      Serial.println(key_pressed);
      return;
    }

    
    if (id_key_pressed <30)
    {
      Serial.print(F(" playing folder "));
      Serial.print(current_folder);
      Serial.print(F(" item "));
      current_file = 1+ id_key_pressed;

      Serial.println(current_file);

      myDFPlayer.playFolder(current_folder, current_file);
    } else {
      switch (id_key_pressed)
      {
         case 30: // vol down
          Serial.println(F("Vol down"));
          this->volumeDown();
          break;
         case 31: // vol up
         Serial.println(F("Vol up"));
          this->volumeUp();
          break;
         case 32: // prev folder
          this->previousFolder();
          Serial.print(F("prev folder, current is now "));
          Serial.println(current_folder);
          break;
         case 33: // next folder
          this->nextFolder();
          Serial.println(F("next folder, current is now "));
          Serial.println(current_folder);
          break;
         case 34: // stop
          myDFPlayer.stop();
          Serial.println(F("Stop"));
          break;
         case 35:
          
          break;
      
        default:
          break;
      }
    }
}

void Player::nextFolder(){
  this->current_folder ++;
  if (current_folder == 100){
    current_folder = 0 ;
  }
}

void Player::previousFolder(){
  this->current_folder --;
  if (current_folder == 0 ){
    current_folder = 99;
  }
}


void Player::playMusicInFolder(uint8_t directory, uint8_t element){
      myDFPlayer.playFolder(directory, element);  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
}

void Player::displayPlayerDetail(){
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void Player::printDetail(uint8_t type, int value)
{
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
