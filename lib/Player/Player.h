#ifndef PLAYER
#define PLAYER

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

class Player {

private:

    DFRobotDFPlayerMini myDFPlayer;
    uint8_t current_folder;
    uint8_t current_file;

public:
    Player();

    String getIdMusic(char c);

    void playMusicInFolder(uint8_t dir, uint8_t element);

    void printDetail(uint8_t type, int value);


    void volumeUp();
    void volumeDown();  

    void setCurrentFolder(uint8_t current_folder) { this->current_folder = current_folder;};
    uint8_t getCurrentFolder() { return current_folder;};
    uint8_t getCurrentFile(){ return current_file;};

    void nextFolder();
    void previousFolder();
    void gererTouche(char key_pressed);
    void displayPlayerDetail();

};

#endif