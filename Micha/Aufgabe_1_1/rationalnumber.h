#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    unsigned zaehler,nenner;
};

bool rnIsValid(RationalNumber n);

bool rnEqual(RationalNumber a, RationalNumber b);

bool rnLessThan(RationalNumber a, RationalNumber b);

#endif // RATIONALNUMBER_H
