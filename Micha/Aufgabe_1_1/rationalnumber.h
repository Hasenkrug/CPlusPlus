#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    unsigned zaehler,nenner;
};

RationalNumber normalize(RationalNumber a);

bool rnIsValid(RationalNumber n);

bool rnEqual(RationalNumber a, RationalNumber b);

bool rnLessThan(RationalNumber a, RationalNumber b);

RationalNumber rnAdd(RationalNumber a, RationalNumber b);

RationalNumber rnSubtract(RationalNumber a, RationalNumber b);

RationalNumber rnMultiply(RationalNumber a, RationalNumber b);

RationalNumber rnDivide(RationalNumber a, RationalNumber b);

#endif // RATIONALNUMBER_H
