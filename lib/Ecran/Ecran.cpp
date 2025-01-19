#include "Ecran.h"

#include <Adafruit_SSD1306.h>


#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);



Ecran::Ecran(){

}


void Ecran::init(){

    if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    {
        Serial.println(F("Echec d'initialisation de l'écran"));
        for(;;);
    } else {
        Serial.println(F("Init Ecran ok"));

    }
    
    ecranOLED.clearDisplay();

    ecranOLED.setTextSize(1);                   // Taille des caractères (1:1, puis 2:1, puis 3:1)
    ecranOLED.setCursor(0, 0);                                  // Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche
    ecranOLED.setTextColor(SSD1306_WHITE);

    ecranOLED.println(F("=  Mur Sonore v0.1  ="));
    ecranOLED.display();
    delay(2000);

}

void Ecran::display(uint8_t repertoire, uint8_t piste) {
    ecranOLED.clearDisplay();

    ecranOLED.setTextSize(1);                   // Taille des caractères (1:1, puis 2:1, puis 3:1)
    ecranOLED.setCursor(0, 0);                                  // Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche

    ecranOLED.println(F("=  Mur Sonore v0.1  ="));

    ecranOLED.setTextSize(2);                   // Taille des caractères (1:1, puis 2:1, puis 3:1)
    ecranOLED.setCursor(0, 15);

    ecranOLED.print(F("Rep : "));
    ecranOLED.println(repertoire);

    ecranOLED.setCursor(0, 40);
    ecranOLED.print(F("Piste : "));
    ecranOLED.println(piste);
    
    ecranOLED.display();
}


