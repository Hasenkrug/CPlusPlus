#ifndef RATIIONALNUMBERCOLLECTION_H
#define RATIIONALNUMBERCOLLECTION_H
#include "rationalnumber.h;

struct RationalNumberCollection{
    RationalNumber rationalnumber[1000];
    int counter;
};



void rncInit(RationalNumberCollection* rnc);

void rncAdd(RationalNumberCollection* rnc, RationalNumber n );

#endif // RATIIONALNUMBERCOLLECTION_H
