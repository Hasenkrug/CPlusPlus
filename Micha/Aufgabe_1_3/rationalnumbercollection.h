#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H
#include "rationalnumber.h"


struct CollectionElement {
    RationalNumber rn;
    int count;
};

struct RationalNumberCollection;

RationalNumberCollection* rncCreate(int size);

RationalNumberCollection* rncDelete(RationalNumberCollection* c);

RationalNumberCollection* rncAdd(RationalNumberCollection* c, RationalNumber n);

RationalNumberCollection* rncRemove(RationalNumberCollection* c, RationalNumber n);

int rncCount(RationalNumberCollection* c, RationalNumber n);

int rncTotalUniqueCount(RationalNumberCollection* c);

int rncTotalCount(RationalNumberCollection* c);

RationalNumber rncSum(RationalNumberCollection* c);

RationalNumber rncAverage(RationalNumberCollection* c);

void print(RationalNumberCollection* c);

#endif // RATIONALNUMBERCOLLECTION_H
