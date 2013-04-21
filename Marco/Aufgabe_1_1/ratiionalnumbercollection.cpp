#include "ratiionalnumbercollection.h"

void rncInit(RationalNumberCollection* rnc){
    rnc->counter = 0;
    rnc->rationalnumber.
}
void rncAdd(rationalNumberCollection* rnc, RationalNumber rn){
    rnc->rationalnumber = rn;
    rnc->counter = rnc->counter+1;
}

struct rationalNumberCollection{
    RationalNumber rationalnumber;
    int counter;
}
