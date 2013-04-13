#include "rationalnumber.h"
#include <iostream.h>


unsigned gcd(unsigned a, unsigned b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

RationalNumber normalize(RationalNumber a) {
    unsigned z = a.zaehler/gcd(a.zaehler, a.nenner);
    unsigned n = a.nenner/gcd(a.zaehler, a.nenner);

    RationalNumber temp = {z, n};

    return temp;
}

bool rnIsValid(RationalNumber n) {    
    return n.nenner!=0;
}

bool rnEqual(RationalNumber a, RationalNumber b) {
    return true;
}

bool rnLessThan(RationalNumber a, RationalNumber b) {
    return (b.nenner * a.zaehler) < (a.nenner * b.zaehler);
}

RationalNumber rnAdd(RationalNumber a, RationalNumber b) {
    return a;
}

RationalNumber rnSubtract(RationalNumber a, RationalNumber b) {
    return a;
}

RationalNumber rnMultiply(RationalNumber a, RationalNumber b) {
    return a;
}

RationalNumber rnDivide(RationalNumber a, RationalNumber b) {
    return a;
}
