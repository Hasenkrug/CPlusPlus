#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H
#include "rationalnumber.h"

// this data type represents an element of a collection
// it contains a rationalnumber and a counter
struct CollectionElement {
    RationalNumber rn;
    int count;
};

// this data type represents a rationalnumber collection
// it contains a collection of collectionelements, a value size,
// a value representing the next free index (nfi), a value rnsum,
// a value totalCount and a value uniqueCount
struct RationalNumberCollection {
    CollectionElement collection[1000];
    int size;
    int nfi;
    RationalNumber rnSum;
    int totalCount;
    int totalUniqueCount;
};

//gets a rationalnumbercollection by reference and initializes it
bool rncInit(RationalNumberCollection* c);

//gets a rationalnumbercollection by reference and adds a rationalnumber
bool rncAdd(RationalNumberCollection* c, RationalNumber n);

//gets a rationalnumbercollection by reference and removes a rationalnumber
bool rncRemove(RationalNumberCollection* c, RationalNumber n);

//gets a rationalnumber and returns the count of it, containing in the collection
int rncCount(RationalNumberCollection* c, RationalNumber n);

//returns the count of occupied elements in the collection
int rncTotalUniqueCount(RationalNumberCollection* c);

//returns the count of rationalnumbers in the collection
int rncTotalCount(RationalNumberCollection* c);

//returns the sum of all rationalnumbers in the collection
RationalNumber rncSum(RationalNumberCollection* c);

//returns the average of rationalnumbers in the collection
RationalNumber rncAverage(RationalNumberCollection* c);

#endif // RATIONALNUMBERCOLLECTION_H
