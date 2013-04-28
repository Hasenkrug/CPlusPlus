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
struct RationalNumberCollection;

// creates a new rationalnumbercollection and returns it by reference
RationalNumberCollection* rncCreate(int size);

// deletes the rationalnumbercollection and deallocates the memory
RationalNumberCollection* rncDelete(RationalNumberCollection* c);

// adds a rationalnumber and returns the rationalnumbercollection by reference
RationalNumberCollection* rncAdd(RationalNumberCollection* c, RationalNumber n);

// removes a rationalnumber and returns the rationalnumbercollection by reference
RationalNumberCollection* rncRemove(RationalNumberCollection* c, RationalNumber n);

// gets a rationalnumber and returns the count of it, containing in the collection
int rncCount(RationalNumberCollection* c, RationalNumber n);

// returns the count of occupied elements in the collection
int rncTotalUniqueCount(RationalNumberCollection* c);

// returns the count of rationalnumbers in the collection
int rncTotalCount(RationalNumberCollection* c);

// returns the sum of all rationalnumbers in the collection
RationalNumber rncSum(RationalNumberCollection* c);

// returns the average of rationalnumbers in the collection
RationalNumber rncAverage(RationalNumberCollection* c);

void print(RationalNumberCollection* c);

#endif // RATIONALNUMBERCOLLECTION_H
