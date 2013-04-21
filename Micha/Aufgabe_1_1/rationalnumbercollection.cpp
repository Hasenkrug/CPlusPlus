#include "rationalnumbercollection.h"


bool rncInit(RationalNumberCollection* c) {

    RationalNumber rn = { 0, 1 };

    c->size = 1000;
    c->nfi = 0;

    for(int i = 0; i < 1000; i++) {
        c->collection[i].rn = rn;
        c->collection[i].count = 0;
    }

    return true;
}

int rncFindPosition(RationalNumberCollection* c, RationalNumber n) {
    for(int i = 0; i < c->size; i++) {
        if(c->collection[i].rn.numerator == n.numerator) {
            if(c->collection[i].rn.denominator == n.denominator) {
                return i;
            }
        }
    }
    return -1;
}

bool rncAdd(RationalNumberCollection* c, RationalNumber n) {
    int pos = rncFindPosition(c,n);

    if(pos != -1) {
        c->collection[pos].count++;
        return true;
    } else if(c->nfi < c->size) {
        c->collection[c->nfi].rn.numerator = n.numerator;
        c->collection[c->nfi].rn.denominator = n.denominator;
        c->collection[c->nfi].count++;
        c->nfi++;
        return true;
    }
    return false;
}
