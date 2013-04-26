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

RationalNumberCollection* rncUpdateSize(RationalNumberCollection *rncOld){

    int newSize = rncOld->size*2;
    RationalNumber rn = { 0, 1 };
    RationalNumberCollection* rncNew = rncCreate(newSize);
    rncInit(rncNew, newSize, rncOld->nfi, rncOld->totalCount, rncOld->totalUniqueCount, rncOld->rnSum);
    for( int i = 0; i<rncOld->size; i++){
        rncNew->collection[i].rn.denominator = rncOld->collection[i].rn.denominator;
        rncNew->collection[i].rn.numerator = rncOld->collection[i].rn.numerator;
        rncNew->collection[i].count = rncOld->collection[i].count;
    }
    return rncNew;
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
    int pos = rncFindPosition(c,n);

    // wenn es die RationalNumber schon im Array gibt
    if(pos != -1) {
        c->collection[pos].count++;
        RationalNumber summand = c->collection[pos].rn;
        c->rnSum = rnAdd(c->rnSum, summand);
        c->totalCount++;
        //return true;
    // sonst, wenn noch Platz im Array ist
    } else
        if(!(c->nfi < c->size)) {

            printf("b: %i\n",c->size);
            printf("c: %i\n",c);
            RationalNumberCollection *cNew = rncUpdateSize(c);
            c = rncDelete(c);
            printf("c: %i\n",c);
            c = cNew;
            printf("f: %i\n",c->size);
            printf("c: %i\n",c);
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

            //return true;
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
            c->nfi += 1;
            c->totalCount++;
            c->totalUniqueCount++;
            //return true;
        }
    return c;
}

bool rncRemove(RationalNumberCollection *c, RationalNumber n) {
    int pos = rncFindPosition(c,n);

    if(pos != -1 && c->collection[pos].count > 1) {
        c->collection[pos].count--;
        RationalNumber subtrahend = c->collection[pos].rn;
        c->rnSum = rnSubtract(c->rnSum,subtrahend);
        c->totalCount--;
        return true;
    } else if(pos != -1 && c->collection[pos].count == 1) {
        for(int i = pos; i < c->nfi-1; i++) {
            c->collection[i] = c->collection[i+1];
        }
        RationalNumber subtrahend = c->collection[c->nfi-1].rn;
        c->rnSum = rnSubtract(c->rnSum,subtrahend);
        c->nfi--;
        c->collection[c->nfi].count = 0;
        c->collection[c->nfi].rn.numerator = 0;
        c->collection[c->nfi].rn.denominator = 1;
        c->totalCount--;
        c->totalUniqueCount--;
        return true;
    }
    return false;
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



//printf("\n\n");
//printf("size: %i; \n",c->size);
//printf("nfi: %i; \n",c->nfi);
//printf("rnSum: %i; \n",c->rnSum);
//printf("totalCount: %i; \n",c->totalCount);
//printf("totalUniqueCount: %i; \n",c->totalUniqueCount);
//printf("\n");
//for(int i=0; i<c->size;i++){
//    printf("collectionElement: \n");
//    printf("Zaehler: %i; an Stelle: %i;  \n",c->collection[i].rn.numerator, i);
//    printf("Nenner: %i; an Stelle: %i;  \n",c->collection[i].rn.denominator, i);
//    printf("collectionCounter: %i; an Stelle: %i;  \n",c->collection[i].count, i);
//}
//printf("\n\n");
//c = rncUpdateSize(c);
//printf("\n\n");
//printf("size: %i; \n",c->size);
//printf("nfi: %i; \n",c->nfi);
//printf("rnSum: %i; \n",c->rnSum);
//printf("totalCount: %i; \n",c->totalCount);
//printf("totalUniqueCount: %i; \n",c->totalUniqueCount);
//printf("\n");
//for(int i=0; i<c->size;i++){
//    printf("collectionElement:\n");
//    printf("Zaehler: %i; an Stelle: %i;  \n",c->collection[i].rn.numerator, i);
//    printf("Nenner: %i; an Stelle: %i;  \n",c->collection[i].rn.denominator, i);
//    printf("collectionCounter: %i; an Stelle: %i;  \n",c->collection[i].count, i);
//}
//printf("\n\n");
