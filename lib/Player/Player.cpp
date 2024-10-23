#include "Player.h"

Player::Player(){
    // Adding key-value pairs to the hashtable
    tableMappingTouche.put('0', 0);
    tableMappingTouche.put('1', 1);
    tableMappingTouche.put('2', 2);
    tableMappingTouche.put('3', 3);
    tableMappingTouche.put('4', 4);
    tableMappingTouche.put('5', 5);
    tableMappingTouche.put('6', 6);
    tableMappingTouche.put('7', 7);
    tableMappingTouche.put('8', 8);
    tableMappingTouche.put('9', 9);
    tableMappingTouche.put('A', 10);
    tableMappingTouche.put('B', 11);
    tableMappingTouche.put('C', 12);
    tableMappingTouche.put('D', 13);
    tableMappingTouche.put('E', 14);
    tableMappingTouche.put('F', 15);
    tableMappingTouche.put('G', 16);
    tableMappingTouche.put('H', 17);
    tableMappingTouche.put('I', 18);
    tableMappingTouche.put('J', 19);
    tableMappingTouche.put('K', 20);
    tableMappingTouche.put('L', 21);
    tableMappingTouche.put('M', 22);
    tableMappingTouche.put('N', 23);
    tableMappingTouche.put('O', 24);
    tableMappingTouche.put('P', 25);
    tableMappingTouche.put('Q', 26);
    tableMappingTouche.put('R', 27);
    tableMappingTouche.put('S', 28);
    tableMappingTouche.put('T', 29);
    tableMappingTouche.put('U', 30);
    tableMappingTouche.put('V', 31);
    tableMappingTouche.put('W', 32);
    tableMappingTouche.put('X', 33);
    tableMappingTouche.put('Y', 34);
    tableMappingTouche.put('Z', 35);
 
 #if (defined ESP32)
  FPSerial.begin(9600, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
    #else
  FPSerial.begin(9600);
  #endif

  Serial.begin(115200);

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
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3

}

uint8_t Player::getIdMusic(char c) {
    if (tableMappingTouche.containsKey(c)){
        return tableMappingTouche.getElement(c);
    }
    Serial.print(F("Erreur de touche, caractère inconnu"));
    Serial.println(c);
    return 0;
}

void Player::playMusicInFolder(uint8_t directory, uint8_t element){
      myDFPlayer.playFolder(directory, element);  //play specific mp3 in SD:/15/004.mp3; Folder Name(1~99); File Name(1~255)
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
