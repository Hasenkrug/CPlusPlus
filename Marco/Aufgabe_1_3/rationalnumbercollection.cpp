#include "rationalnumbercollection.h"
#include "stdlib.h"

#include <stdio.h>
#include <assert.h>
#include <iostream>


struct RationalNumberCollection {
    CollectionElement* collection;
    int size;
    int nfi;
    RationalNumber rnSum;
    int totalCount;
    int totalUniqueCount;
};

bool rncInit(RationalNumberCollection* c, int size, int nfi, int totalCount, int totalUniqueCount, RationalNumber rnSum) {

    RationalNumber rn = { 0, 1 };

    c->size = size;
    c->nfi = nfi;
    c->rnSum = rnSum;
    c->totalCount = totalCount;
    c->totalUniqueCount = totalUniqueCount;

    for(int i = 0; i < size; i++) {
        c->collection[i].rn = rn;
        c->collection[i].count = 0;
    }

    return true;
}

RationalNumberCollection* rncCreate(int size) {
    RationalNumberCollection* rnc = (RationalNumberCollection*) malloc(sizeof(RationalNumberCollection));    
    rnc->collection = (CollectionElement*) malloc(size*sizeof(CollectionElement));
    RationalNumber n = {0,1};
    rncInit(rnc, size, 0, 0, 0, n);
    return rnc;
}

RationalNumberCollection *rncDelete(RationalNumberCollection* c) {
    free(c->collection);
    free(c);
    return c;
}

RationalNumberCollection* rncUpdateSize(RationalNumberCollection *rncOld, bool increase){
    int newSize;
    if(increase){
        newSize = rncOld->size*2;
        printf("\nthe capacity will be incresed to the double size.\n");
        RationalNumberCollection* rncNew = rncCreate(newSize);
        rncInit(rncNew, newSize, rncOld->nfi, rncOld->totalCount, rncOld->totalUniqueCount, rncOld->rnSum);
        for( int i = 0; i<rncOld->size; i++){
            rncNew->collection[i].rn.denominator = rncOld->collection[i].rn.denominator;
            rncNew->collection[i].rn.numerator = rncOld->collection[i].rn.numerator;
            rncNew->collection[i].count = rncOld->collection[i].count;
        }
        return rncNew;
    }else{
        newSize = rncOld->size/2;
        printf("\nthe capacity will be decresed to the half size.:%i\n", newSize);
        RationalNumberCollection* rncNew = rncCreate(newSize);
        rncInit(rncNew, newSize, rncOld->nfi, rncOld->totalCount, rncOld->totalUniqueCount, rncOld->rnSum);
        for( int i = 0; i<newSize; i++){
            rncNew->collection[i].rn.denominator = rncOld->collection[i].rn.denominator;
            rncNew->collection[i].rn.numerator = rncOld->collection[i].rn.numerator;
            rncNew->collection[i].count = rncOld->collection[i].count;
        }
        return rncNew;
    }


}

int rncFindPosition(RationalNumberCollection* c, RationalNumber n) {
    for(int i = 0; i < c->size; i++) {
        if(c->collection[i].count != 0) {
            if(rnEqual(c->collection[i].rn, n)) {
                return i;
            }
        }
    }
    return -1;
}

int rncFindIndex(RationalNumberCollection* c, RationalNumber n) {
    int von = 0;
    int bis = c->nfi-1;

    while(von <= bis) {
        int mitte = von + (bis-von) / 2;

        if(rnLessThan(c->collection[mitte].rn,n)) {
            von = mitte + 1;
        } else if(rnLessThan(n,c->collection[mitte].rn)) {
            bis = mitte - 1;
        } else {
            return mitte;
        }
    }
    return von;
}

RationalNumberCollection *rncAdd(RationalNumberCollection* c, RationalNumber n) {
    printf("\n %i/%i will be added to storage.\n",n.numerator,n.denominator);
    int pos = rncFindPosition(c,n);

    // wenn es die RationalNumber schon im Array gibt
    if(pos != -1) {
        c->collection[pos].count++;
        RationalNumber summand = c->collection[pos].rn;
        c->rnSum = rnAdd(c->rnSum, summand);
        c->totalCount++;
    } else
        // schaffe Platz wenn der nfi belegt sein sollte.
        if(!(c->nfi < c->size)) {
            RationalNumberCollection *cNew = rncUpdateSize(c, true);
            c = rncDelete(c);
            c = cNew;
        }
        RationalNumber summand = n;
        c->rnSum = rnAdd(c->rnSum, summand);

        // und die perfekte Postition dem nfi entspricht
        if(rncFindIndex(c,n) == c->nfi) {
            c->collection[c->nfi].rn.numerator = n.numerator;
            c->collection[c->nfi].rn.denominator = n.denominator;
            c->collection[c->nfi].count++;
            c->nfi++;
            c->totalCount++;
            c->totalUniqueCount++;
        } else {
            int tempIndex = c->nfi;
            while(rncFindIndex(c,n) < tempIndex) {
                CollectionElement tempInhalt = c->collection[tempIndex - 1];
                c->collection[tempIndex] = tempInhalt;
                tempIndex--;
            }
            int stelle = rncFindIndex(c,n);
            c->collection[stelle].rn = n;
            c->collection[stelle].count = 1;
            c->nfi++;
            c->totalCount++;
            c->totalUniqueCount++;
        }
        print(c);
    return c;
}

RationalNumberCollection* rncRemove(RationalNumberCollection *c, RationalNumber n) {
    printf("\n %i/%i will be removed from the storage.\n",n.numerator,n.denominator);
    int pos = rncFindPosition(c,n);

    if(pos != -1 && c->collection[pos].count > 1) {
        c->collection[pos].count--;
        RationalNumber subtrahend = c->collection[pos].rn;
        c->rnSum = rnSubtract(c->rnSum,n);
        c->totalCount--;
    } else
        if((c->nfi <= c->size/2)) {
            RationalNumberCollection *cNew = rncUpdateSize(c, false);
            c = rncDelete(c);
            c = cNew;
        }
        if(pos != -1 && c->collection[pos].count == 1) {
            for(int i = pos; i < c->nfi-1; i++) {
                c->collection[i] = c->collection[i+1];
            }
            RationalNumber subtrahend = c->collection[c->nfi-1].rn;
            c->rnSum = rnSubtract(c->rnSum,n);
            c->nfi--;
            c->collection[c->nfi].count = 0;
            c->collection[c->nfi].rn.numerator = 0;
            c->collection[c->nfi].rn.denominator = 1;
            c->totalCount--;
            c->totalUniqueCount--;
        }
    print(c);
    return c;
}

int rncCount(RationalNumberCollection *c, RationalNumber n) {
    int pos = rncFindPosition(c,n);

    if(pos != -1) {
        return c->collection[pos].count;
    }
    return 0;
}

int rncTotalUniqueCount(RationalNumberCollection *c) {
    return c->nfi;
}

int rncTotalCount(RationalNumberCollection *c) {
    return c->totalCount;
}

RationalNumber rncSum(RationalNumberCollection* c){
    return c->rnSum;
}

RationalNumber rncAverage(RationalNumberCollection* c){
    if(c->totalCount != 0) {
        RationalNumber divisor = {c->totalCount,1};
        return rnDivide(c->rnSum, divisor);
    } else {
        RationalNumber rn = {0, 1};
        return rn;
    }
}
void print(RationalNumberCollection *c2){
    if(true){
    printf("Collection      : ");
    for(int i=0; i<c2->size; i++){
        printf("[%i]", c2->collection[i].rn.numerator);
    }
    printf("\n                  ");
    for(int i=0; i<c2->size; i++){
        printf("[%i]", c2->collection[i].rn.denominator);
    }
    printf("\nCounter         : ");
    for(int i=0; i<c2->size; i++){
        printf("|%i|",  c2->collection[i].count);
    }
    printf("\nTotalCount      : %i",  c2->totalCount);
    printf("\nTotalUniqueCount: %i",  c2->totalUniqueCount);
    printf("\nrncSum          : %i/%i",  c2->rnSum.numerator, c2->rnSum.denominator);
    printf("\nrncAverage      : %i/%i",  rncAverage(c2).numerator, rncAverage(c2).denominator);
    printf("\n\n");
    }
}
