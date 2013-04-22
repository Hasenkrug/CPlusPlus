#include "rationalnumbercollection.h"
#include "rationalnumber.h"


bool rncInit(RationalNumberCollection* c) {

    RationalNumber rn = { 0, 1 };

    c->size = 1000;
    c->nfi = 0;
    c->rnSum = rn;

    for(int i = 0; i < 1000; i++) {
        c->collection[i].rn = rn;
        c->collection[i].count = 0;
    }

    return true;
}

int rncFindPosition(RationalNumberCollection* c, RationalNumber n) {
    for(int i = 0; i < c->size; i++) {
        if(c->collection[i].count != 0) {
            if(c->collection[i].rn.numerator == n.numerator) {
                if(c->collection[i].rn.denominator == n.denominator) {
                    return i;
                }
            }
        }
    }
    return -1;
}

bool rncAdd(RationalNumberCollection* c, RationalNumber n) {
    int pos = rncFindPosition(c,n);

    if(pos != -1) {
        c->collection[pos].count++;
        c->rnSum = rnAdd(c->rnSum,c->collection[pos].rn);
        return true;
    } else if(c->nfi < c->size) {
        c->collection[c->nfi].rn.numerator = n.numerator;
        c->collection[c->nfi].rn.denominator = n.denominator;
        c->collection[c->nfi].count++;
        c->nfi++;
        c->Sum = rnAdd(c->Sum,c->collection[c->collection[c->nfi].rn]);

        return true;
    }
    return false;
}

bool rncRemove(RationalNumberCollection *c, RationalNumber n) {
    int pos = rncFindPosition(c,n);

    if(pos != -1 && c->collection[pos].count > 1) {
        c->collection[pos].count--;
        c->rnSum = rnSubtract(c->rnSum,c->collection[pos].rn);
        return true;
    } else if(pos != -1 && c->collection[pos].count == 1) {
        c->collection[pos] = c->collection[c->nfi-1];
        c->collection[c->nfi-1].count = 0;
        c->nfi--;
        c->Sum = rnSubtract(c->Sum,c->collection[c->collection[c->nfi].rn]);

        return true;
    }
    return false;
}


RationalNumber rncSum(RationalNumberCollection* c){
    return c->rnSum;
}

RationalNumber rncAverage(RationalNumberCollection* c){
    return rnDivide(c->rncSum,rncTotalCount(c));
}


