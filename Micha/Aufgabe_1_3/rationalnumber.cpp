#include "rationalnumber.h"
#include "stdio.h"


int eukl(RationalNumber n){
    if(n.denominator == 0) return n.numerator;

     else {
        RationalNumber rn = {n.denominator, n.numerator % n.denominator};
        return eukl(rn);
    }
}

RationalNumber normalize(RationalNumber n){
    int valueNum = n.numerator/eukl(n);
    int valueDem = n.denominator/eukl(n);
    RationalNumber rn = {valueNum, valueDem};
    return rn;
}

bool rnIsValid(RationalNumber n){
    return n.denominator!=0;
}

bool rnEqual(RationalNumber x, RationalNumber y){
    RationalNumber a = normalize(x);
    RationalNumber b = normalize(y);
    return (a.numerator*a.denominator)==(b.numerator*b.denominator);
}

bool rnLessThan(RationalNumber x, RationalNumber y){
    if (x.denominator<0){
        x.numerator = x.numerator * -1;
        x.denominator = x.denominator * -1;
    }
    if (y.denominator<0){
        y.numerator = y.numerator * -1;
        y.denominator = y.denominator * -1;
    }
    return (x.numerator*y.denominator)<(x.denominator*y.numerator);
}

RationalNumber rnAdd(RationalNumber x, RationalNumber y){
    int valueDem = x.denominator*y.denominator;
    int value1 = x.numerator*y.denominator;
    int value2 = y.numerator*x.denominator;
    int valueNum = value1+value2;
    RationalNumber r = {valueNum, valueDem};
    RationalNumber rn = normalize(r);
    return rn;
}

RationalNumber rnSubtract(RationalNumber x, RationalNumber y){
    int valueDem = x.denominator*y.denominator;
    int value1 = x.numerator*y.denominator;
    int value2 = y.numerator*x.denominator;
    int valueNum = value1-value2;
    RationalNumber r = {valueNum, valueDem};
    RationalNumber rn = normalize(r);
    return rn;
}

RationalNumber rnMultiply(RationalNumber x, RationalNumber y){
    int valueNum = x.numerator*y.numerator;
    int valueDem = x.denominator*y.denominator;
    RationalNumber r = {valueNum, valueDem};
    RationalNumber rn = normalize(r);
    return rn;
}

RationalNumber rnDivide(RationalNumber x, RationalNumber y){
    int valueNum = x.numerator*y.denominator;
    int valueDem = x.denominator*y.numerator;
    RationalNumber r = {valueNum, valueDem};
    RationalNumber rn = normalize(r);
    return rn;
}
