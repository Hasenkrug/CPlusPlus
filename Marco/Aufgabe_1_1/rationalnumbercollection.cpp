#include "rationalnumbercollection.h"


bool rncInit(RationalNumberCollection* c) {

    RationalNumber rn = { 0, 1 };

    c->size = 1000;
    c->nfi = 0;
    c->rnSum = rn;
    c->totalCount = 0;

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

bool rncAdd(RationalNumberCollection* c, RationalNumber n) {
    int pos = rncFindPosition(c,n);

    if(pos != -1) {
        c->collection[pos].count++;
        RationalNumber summand = c->collection[pos].rn;
        c->rnSum = rnAdd(c->rnSum,summand);
        c->totalCount++;
        return true;
    } else if(c->nfi < c->size) {
        RationalNumber summand = n;
        c->rnSum = rnAdd(c->rnSum,summand);
        c->totalCount++;
        if(rncFindIndex(c,n) == c->nfi) {
            c->collection[c->nfi].rn.numerator = n.numerator;
            c->collection[c->nfi].rn.denominator = n.denominator;
            c->collection[c->nfi].count++;

            c->nfi++;
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
            return true;
        }
    }
    return false;
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
        c->collection[pos] = c->collection[c->nfi-1];
        c->collection[c->nfi-1].count = 0;
        RationalNumber subtrahend = c->collection[c->nfi-1].rn;
        c->rnSum = rnSubtract(c->rnSum,subtrahend);
        c->nfi--;
        c->totalCount--;
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
    RationalNumber divisor = {rncTotalCount(c),1};
    return rnDivide(c->rnSum, divisor);
}
