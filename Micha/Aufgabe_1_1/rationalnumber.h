#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


struct RationalNumber {
    int numerator, denominator;
};

int eukl(RationalNumber n);

RationalNumber normalize(RationalNumber n);

bool rnIsValid(RationalNumber n);

bool rnEqual(RationalNumber x, RationalNumber y);

bool rnLessThan(RationalNumber x, RationalNumber y);

RationalNumber rnAdd(RationalNumber x, RationalNumber y);

RationalNumber rnSubtract(RationalNumber x, RationalNumber y);

RationalNumber rnMultiply(RationalNumber x, RationalNumber y);

RationalNumber rnDivide(RationalNumber x, RationalNumber y);

#endif // RATIONALNUMBER_H
