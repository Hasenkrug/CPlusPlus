#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H
#include "rationalnumber.h"

struct CollectionElement {
    RationalNumber rn;
    int count;
};

struct RationalNumberCollection {
    CollectionElement collection[1000];
    int size;
    int nfi;
    RationalNumber rnSum;
    int totalCount;
    int totalUniqueCount;
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
