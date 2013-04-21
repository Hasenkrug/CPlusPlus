#ifndef RATIIONALNUMBERCOLLECTION_H
#define RATIIONALNUMBERCOLLECTION_H
#include "rationalnumber.h"

struct RationalNumberCollection{
    RationalNumber rationalnumber;
    int counter;
};

void rncInit(RationalNumberCollection* rnc);

void rncAdd(RationalNumberCollection* rnc, RationalNumber n );

#endif // RATIIONALNUMBERCOLLECTION_H
