#include "rationalnumber.h"


bool rnIsValid(RationalNumber n){
    if(n.d ==0){
        return true;
    }
    return false;
}
bool rnEqual(Rationalnumber n, Rationalnumber m){
    bool equalNum = n.numerator == m.numerator;
    bool equalDen = n.denominator == m.denominator;

    if(equalDen && equalNum){
        return true;
    }
    return false;
}
bool rnLessThen(Rationalnumber rn1, Rationalnumber rn2){
    int numeratorNormalizedRn1 = rn2.denominator*rn1.numerator;
    int numeratorNormalizedRn2 = rn1.denominator*rn2.numerator;
    if(numeratorNormalizedRn1 < numeratorNormalizedRn2){
        return true;
    }
    return false;
}

