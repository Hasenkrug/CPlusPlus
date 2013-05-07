#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

// this data type represents a rationalnumber with an int value for each component
struct RationalNumber {
    int numerator, denominator;
};

// gets a rationalnumber and returns its greatest common divisor
int eukl(RationalNumber n);

// gets a rationalnumber and returns the reduced rationalnumber
RationalNumber normalize(RationalNumber n);

// returns true, if the rationalnumber is a valid number
bool rnIsValid(RationalNumber n);

// returns true, if a rationalnumber x is equals a rationalnumber y
bool rnEqual(RationalNumber x, RationalNumber y);

// returns true, if a rationalnumber x is less than a rationalnumber y
bool rnLessThan(RationalNumber x, RationalNumber y);

// adds two rationalnumbers and returns the result
RationalNumber rnAdd(RationalNumber x, RationalNumber y);

// subtracts two rationalnumbers and returns the result
RationalNumber rnSubtract(RationalNumber x, RationalNumber y);

// multiplies two rationalnumbers and returns the result
RationalNumber rnMultiply(RationalNumber x, RationalNumber y);

// divides two rationalnumbers and returns the result
RationalNumber rnDivide(RationalNumber x, RationalNumber y);

#endif // RATIONALNUMBER_H
