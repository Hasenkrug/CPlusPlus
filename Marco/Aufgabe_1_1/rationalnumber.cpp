#include "rationalnumber.h"
#include <stdio.h>

bool rnIsValid(RationalNumber n){
    if(n.denominator ==0){
        return false;
    }
    return true;
}
bool rnEqual(RationalNumber rn1, RationalNumber rn2){

    rn1 = rnNormalize(rn1);
    rn2 = rnNormalize(rn2);
    return (rn1.numerator*rn1.denominator)==(rn2.numerator*rn2.denominator);
}
bool rnLessThan(RationalNumber rn1, RationalNumber rn2){
    rn2 = rnNormalize(rn2);
    rn1 = rnNormalize(rn1);
    return (rn1.numerator*rn1.denominator)<(rn2.numerator*rn2.denominator);
}

RationalNumber rnAdd(RationalNumber rnSummand1, RationalNumber rnSummand2){
    int summand1 = rnSummand2.denominator*rnSummand1.numerator;
    int summand2 = rnSummand1.denominator*rnSummand2.numerator;
    int dem = rnSummand1.denominator*rnSummand2.denominator;
    RationalNumber rnSumme;
    rnSumme.denominator = dem;
    rnSumme.numerator = summand1 + summand2;
    rnSumme = rnNormalize(rnSumme);
    return rnSumme;
}

RationalNumber rnSubtract(RationalNumber rnMinuend, RationalNumber rnSubtrahend){
    int minuend = rnSubtrahend.denominator*rnMinuend.numerator;
    int subtrahend = rnMinuend.denominator*rnSubtrahend.numerator;
    RationalNumber rnDifferenz;
    rnDifferenz.denominator = rnMinuend.denominator *rnSubtrahend.denominator;
    rnDifferenz.numerator = minuend - subtrahend;
    return rnDifferenz;
}

RationalNumber rnMultiply(RationalNumber rnFaktor1, RationalNumber rnFaktor2){
    RationalNumber rnProdukt;
    rnProdukt.denominator = rnFaktor1.denominator * rnFaktor2.denominator;
    rnProdukt.numerator = rnFaktor1.numerator * rnFaktor2.numerator;
    return rnProdukt;
}

RationalNumber rnDivide(RationalNumber rnDividend, RationalNumber rnDivisor){
    RationalNumber rnQuitient;
    rnQuitient.denominator = rnDividend.denominator * rnDivisor.numerator;
    rnQuitient.numerator = rnDividend.numerator * rnDivisor.denominator;
    return rnQuitient;
}

RationalNumber rnNormalize(RationalNumber rn){
    bool negNum, negDem;
    int divisor = 2;
    if(rn.denominator <0){
        negDem = true;
        rn.denominator = rn.denominator *-1;
    }else{
        negDem = false;
    }
    if(rn.numerator <0){
        negNum = true;
        rn.numerator = rn.numerator *-1;
    }else{
        negNum = false;
    }
    while(rn.denominator >= divisor && rn.numerator >= divisor){
       if(rn.denominator%divisor == 0 && rn.numerator%divisor == 0){
            rn.denominator = rn.denominator/divisor;
            rn.numerator = rn.numerator/divisor;
            rnNormalize(rn);
        }
        divisor++;
    }
    if(negNum){
        rn.numerator = rn.numerator *-1;
    }
    if(negDem){
        rn.denominator = rn.denominator *-1;
    }
    return rn;
}
