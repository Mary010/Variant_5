#pragma once
#include "AEROFLOT.h"

class Keeper {
public:
    struct container {
        AEROFLOT obj;
        container* next;
    };
    int counter = 0;
    container* first;
    container* last;

    Keeper();
    ~Keeper();

};


