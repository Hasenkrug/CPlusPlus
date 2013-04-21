#include "rationalnumbercollection.h"
#include "rationalnumber.h"
#include <stdio.h>

void rncInit(RationalNumberCollection* rnc){
    rnc[1000];
    //rnc->rationalnumber;
    printf("djsknfksjn: %i", rnc->counter);
}
void rncAdd(RationalNumberCollection* rnc, RationalNumber rn){
    rnc[rnc->counter]->rationalnumber = rn;
    rnc[rnc->counter]->counter = rnc[rnc->counter]->counter+1;
    printf("djsknfksjn: %i", rnc[rnc->counter]->rationalnumber.denominator);
}

