/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "rationalnumber.h"
#include "rationalnumbercollection.h"

int main() {

    printf("Performing unit tests for RationalNumberCollection...\n");
    std::cout << " "<< std::endl;
    RationalNumberCollection c;
    RationalNumber n1 = { 1, 2 };
    RationalNumber n2 = { 1, 2 };
    RationalNumber n3 = { 1, 4 };

    std::cout << "Inizierung der Collection erfolgreich: " << rncInit( &c ) << std::endl;
    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Eintrag zufuegen - Ergebnis: " << rncAdd(&c, n1) << std::endl;
    std::cout << "RationalNumber: " << n1.numerator << "/" << n1.denominator << std::endl;
    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    std::cout << "Gesamtwert aller Brüche: " << rncSum(&c).numerator << "/" << rncSum(&c).denominator << std::endl;
    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;
    std::cout << "Durchschnitt berechnen: " << rncAverage(&c).numerator << "/" << rncAverage(&c).denominator << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Eintrag zufuegen - Ergebnis: " << rncAdd(&c, n2) << std::endl;
    std::cout << "RationalNumber: " << n2.numerator << "/" << n2.denominator << std::endl;
    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    std::cout << "Gesamtwert aller Brüche: " << rncSum(&c).numerator << "/" << rncSum(&c).denominator << std::endl;
    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;
    std::cout << "Durchschnitt berechnen: " << rncAverage(&c).numerator << "/" << rncAverage(&c).denominator << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Eintrag zufuegen - Ergebnis: " << rncAdd(&c, n3) << std::endl;
    std::cout << "RationalNumber: " << n3.numerator << "/" << n3.denominator << std::endl;
    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    std::cout << "Gesamtwert aller Brüche: " << rncSum(&c).numerator << "/" << rncSum(&c).denominator << std::endl;
    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;
    std::cout << "Durchschnitt berechnen: " << rncAverage(&c).numerator << "/" << rncAverage(&c).denominator << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "rncCount von 1/2: "<< rncCount(&c,n2) << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Eintrag loeschen - Ergebnis: " << rncRemove(&c, n2) << std::endl;
    std::cout << "RationalNumber: " << n2.numerator << "/" << n2.denominator << std::endl;
    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    std::cout << "Gesamtwert aller Brüche: " << rncSum(&c).numerator << "/" << rncSum(&c).denominator << std::endl;
    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;
    std::cout << "Durchschnitt berechnen: " << rncAverage(&c).numerator << "/" << rncAverage(&c).denominator << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Eintrag loeschen - Ergebnis: " << rncRemove(&c, n2) << std::endl;
    std::cout << "RationalNumber: " << n2.numerator << "/" << n2.denominator << std::endl;
    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    std::cout << "Gesamtwert aller Brüche: " << rncSum(&c).numerator << "/" << rncSum(&c).denominator << std::endl;
    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;
    std::cout << "Durchschnitt berechnen: " << rncAverage(&c).numerator << "/" << rncAverage(&c).denominator << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "RationalNumber an Stelle 0: " << c.collection[0].rn.numerator << "/" << c.collection[0].rn.denominator << std::endl;

    std::cout << " "<< std::endl;


    std::cout << " "<< std::endl;

    printf("successful!\n");
}

    /* Part 1 - RationalNumber data type */
/*    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n7 = { -3, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    RationalNumberCollection c;
    rncInit(&c);
    RationalNumber n = {1,2};
    rncAdd(&c, n);

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    assert( !rnLessThan( n1,n7) );
    assert( rnLessThan( n7,n1) );
    assert( rnLessThan( n5,n1) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );

    printf(" successful!\n");

    return 0;
}

*/
