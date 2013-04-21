#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H
#include "rationalnumber.h"

struct RationalNumberCollectionElement {
    RationalNumber rn;
    int count;
};

struct RationalNumberCollection {
    RationalNumberCollectionElement* collection;
    int size;
    int nfi;
};

bool rncInit(RationalNumberCollection* c);

bool rncAdd(RationalNumberCollection* c, RationalNumber n);

bool rncRemove(RationalNumberCollection* c, RationalNumber n);

int rncCount(RationalNumberCollection* c, RationalNumber n);

int rncTotalUniqueCount(RationalNumberCollection* c);

int rncTotalCount(RationalNumberCollection* c);

RationalNumber rncSum(RationalNumberCollection* c);

RationalNumber rncAverage(RationalNumberCollection* c);

#endif // RATIONALNUMBERCOLLECTION_H
