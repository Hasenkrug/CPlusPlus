#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber{
    int numerator;
    int denominator;
};

bool rnIsValid(RationalNumber n);


bool rnLessThan(RationalNumber rn1, RationalNumber rn2);
bool rnEqual(RationalNumber rn1, RationalNumber rn2);

RationalNumber rnAdd(RationalNumber rnSummand1, RationalNumber rnSummand2);
RationalNumber rnSubtract(RationalNumber rnMinuend, RationalNumber rnSubtrahend);
RationalNumber rnMultiply(RationalNumber rnFaktor1, RationalNumber rnFaktor2);
RationalNumber rnDivide(RationalNumber rnDividend, RationalNumber rnDivisor);

RationalNumber rnNormalize(RationalNumber rn);



#endif // RATIONALNUMBER_H
