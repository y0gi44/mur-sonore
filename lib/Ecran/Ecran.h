#ifndef ECRAN
#define ECRAN

#include <Arduino.h>


class Ecran {

public:
    Ecran();

    void init();
    void display(uint8_t repertoire, uint8_t piste);

};

#endif