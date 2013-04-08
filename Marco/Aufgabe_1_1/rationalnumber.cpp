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
bool rnLessThen(Rationalnumber n, Rationalnumber m){
    if(n.denominator == m.denominator && n.numerator == m.numerator){
        return true;
    }
    return false;
}
