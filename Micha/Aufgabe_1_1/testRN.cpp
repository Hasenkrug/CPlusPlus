/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "rationalnumbercollection.h"


int main() {    

    std::cout << " "<< std::endl;
    std::cout << " "<< std::endl;

    RationalNumberCollection c2;

    //RationalNumber numb01 = {1,1};
    RationalNumber numb02 = {1,2};
    RationalNumber numb03 = {1,3};
    RationalNumber numb04 = {1,4};
    RationalNumber numb05 = {1,5};
    //RationalNumber numb06 = {1,6};

    std::cout << "RationalNumberCollection c2;"<< std::endl;

    std::cout << " "<< std::endl;

    std::cout << "rncInit( &c2 ) returns: " << rncInit( &c2 ) << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Collection      : " << "[" << c2.collection[0].rn.numerator << "]" << "[" << c2.collection[1].rn.numerator << "]" << "[" << c2.collection[2].rn.numerator << "]" << "[" << c2.collection[3].rn.numerator << "]" << "[" << c2.collection[4].rn.numerator << "]" << std::endl;
    std::cout << "                  " << "[" << c2.collection[0].rn.denominator << "]" << "[" << c2.collection[1].rn.denominator << "]" << "[" << c2.collection[2].rn.denominator << "]" << "[" << c2.collection[3].rn.denominator << "]" << "[" << c2.collection[4].rn.denominator << "]" << std::endl;
    std::cout << "Counter         : " << "|" << c2.collection[0].count << "|" << "|" << c2.collection[1].count << "|" << "|" << c2.collection[2].count << "|" << "|" << c2.collection[3].count << "|" << "|" << c2.collection[4].count << "|" << std::endl;
    std::cout << "TotalCount      : " << c2.totalCount << std::endl;
    std::cout << "TotalUniqueCount: " << c2.totalUniqueCount << std::endl;

    std::cout << " " << std::endl;

    std::cout << "rncAdd( 1/4 ) returns: " << rncAdd( &c2, numb04 ) << std::endl;
    std::cout << "rncAdd( 1/3 ) returns: " << rncAdd( &c2, numb03 ) << std::endl;
    std::cout << "rncAdd( 1/2 ) returns: " << rncAdd( &c2, numb02 ) << std::endl;

    std::cout << " " << std::endl;

    std::cout << "Collection      : " << "[" << c2.collection[0].rn.numerator << "]" << "[" << c2.collection[1].rn.numerator << "]" << "[" << c2.collection[2].rn.numerator << "]" << "[" << c2.collection[3].rn.numerator << "]" << "[" << c2.collection[4].rn.numerator << "]" << std::endl;
    std::cout << "                  " << "[" << c2.collection[0].rn.denominator << "]" << "[" << c2.collection[1].rn.denominator << "]" << "[" << c2.collection[2].rn.denominator << "]" << "[" << c2.collection[3].rn.denominator << "]" << "[" << c2.collection[4].rn.denominator << "]" << std::endl;
    std::cout << "Counter         : " << "|" << c2.collection[0].count << "|" << "|" << c2.collection[1].count << "|" << "|" << c2.collection[2].count << "|" << "|" << c2.collection[3].count << "|" << "|" << c2.collection[4].count << "|" << std::endl;
    std::cout << "TotalCount      : " << c2.totalCount << std::endl;
    std::cout << "TotalUniqueCount: " << c2.totalUniqueCount << std::endl;

    std::cout << " " << std::endl;

    std::cout << "rncAdd( 1/5 ) returns: " << rncAdd( &c2, numb05 ) << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Collection      : " << "[" << c2.collection[0].rn.numerator << "]" << "[" << c2.collection[1].rn.numerator << "]" << "[" << c2.collection[2].rn.numerator << "]" << "[" << c2.collection[3].rn.numerator << "]" << "[" << c2.collection[4].rn.numerator << "]" << std::endl;
    std::cout << "                  " << "[" << c2.collection[0].rn.denominator << "]" << "[" << c2.collection[1].rn.denominator << "]" << "[" << c2.collection[2].rn.denominator << "]" << "[" << c2.collection[3].rn.denominator << "]" << "[" << c2.collection[4].rn.denominator << "]" << std::endl;
    std::cout << "Counter         : " << "|" << c2.collection[0].count << "|" << "|" << c2.collection[1].count << "|" << "|" << c2.collection[2].count << "|" << "|" << c2.collection[3].count << "|" << "|" << c2.collection[4].count << "|" << std::endl;
    std::cout << "TotalCount      : " << c2.totalCount << std::endl;
    std::cout << "TotalUniqueCount: " << c2.totalUniqueCount << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "rncRemove( 1/4 ) returns: " << rncRemove( &c2, numb04 ) << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "Collection      : " << "[" << c2.collection[0].rn.numerator << "]" << "[" << c2.collection[1].rn.numerator << "]" << "[" << c2.collection[2].rn.numerator << "]" << "[" << c2.collection[3].rn.numerator << "]" << "[" << c2.collection[4].rn.numerator << "]" << std::endl;
    std::cout << "                  " << "[" << c2.collection[0].rn.denominator << "]" << "[" << c2.collection[1].rn.denominator << "]" << "[" << c2.collection[2].rn.denominator << "]" << "[" << c2.collection[3].rn.denominator << "]" << "[" << c2.collection[4].rn.denominator << "]" << std::endl;
    std::cout << "Counter         : " << "|" << c2.collection[0].count << "|" << "|" << c2.collection[1].count << "|" << "|" << c2.collection[2].count << "|" << "|" << c2.collection[3].count << "|" << "|" << c2.collection[4].count << "|" << std::endl;
    std::cout << "TotalCount      : " << c2.totalCount << std::endl;
    std::cout << "TotalUniqueCount: " << c2.totalUniqueCount << std::endl;

    std::cout << " "<< std::endl;

    std::cout << "rncAdd( 1/3 ) returns: " << rncAdd( &c2, numb03 ) << std::endl;

    std::cout << " " << std::endl;

    std::cout << "Collection      : " << "[" << c2.collection[0].rn.numerator << "]" << "[" << c2.collection[1].rn.numerator << "]" << "[" << c2.collection[2].rn.numerator << "]" << "[" << c2.collection[3].rn.numerator << "]" << "[" << c2.collection[4].rn.numerator << "]" << std::endl;
    std::cout << "                  " << "[" << c2.collection[0].rn.denominator << "]" << "[" << c2.collection[1].rn.denominator << "]" << "[" << c2.collection[2].rn.denominator << "]" << "[" << c2.collection[3].rn.denominator << "]" << "[" << c2.collection[4].rn.denominator << "]" << std::endl;
    std::cout << "Counter         : " << "|" << c2.collection[0].count << "|" << "|" << c2.collection[1].count << "|" << "|" << c2.collection[2].count << "|" << "|" << c2.collection[3].count << "|" << "|" << c2.collection[4].count << "|" << std::endl;
    std::cout << "TotalCount      : " << c2.totalCount << std::endl;
    std::cout << "TotalUniqueCount: " << c2.totalUniqueCount << std::endl;

    std::cout << " " << std::endl;

    printf("successful!\n");

    //    assert( rncInit( &c ) );
    //    assert( rncAdd(&c, n1) );
    //    assert( rncAdd(&c, n2) );


// ====================================================================

    //    printf("Performing unit tests for RationalNumberCollection...\n");
    //    std::cout << " "<< std::endl;
    //    RationalNumberCollection c;
    //    RationalNumber n1 = { 1, 2 };
    //    RationalNumber n2 = { 1, 2 };
    //    RationalNumber n3 = { 1, 4 };

    //    std::cout << "Inizierung der Collection erfolgreich: " << rncInit( &c ) << std::endl;
    //    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "Eintrag zufuegen - Ergebnis: " << rncAdd(&c, n1) << std::endl;
    //    std::cout << "RationalNumber: " << n1.numerator << "/" << n1.denominator << std::endl;
    //    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    //    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    //    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    //    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "Eintrag zufuegen - Ergebnis: " << rncAdd(&c, n2) << std::endl;
    //    std::cout << "RationalNumber: " << n2.numerator << "/" << n2.denominator << std::endl;
    //    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    //    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    //    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    //    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "Eintrag zufuegen - Ergebnis: " << rncAdd(&c, n3) << std::endl;
    //    std::cout << "RationalNumber: " << n3.numerator << "/" << n3.denominator << std::endl;
    //    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    //    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    //    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    //    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "rncCount von 1/2: "<< rncCount(&c,n2) << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "rncTotalCount: "<< rncTotalCount(&c) << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "Eintrag loeschen - Ergebnis: " << rncRemove(&c, n2) << std::endl;
    //    std::cout << "RationalNumber: " << n2.numerator << "/" << n2.denominator << std::endl;
    //    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    //    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    //    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    //    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "Eintrag loeschen - Ergebnis: " << rncRemove(&c, n2) << std::endl;
    //    std::cout << "RationalNumber: " << n2.numerator << "/" << n2.denominator << std::endl;
    //    std::cout << "Zaehler Stelle 0: " << c.collection[0].count << std::endl;
    //    std::cout << "Zaehler Stelle 1: " << c.collection[1].count << std::endl;
    //    std::cout << "Zaehler Stelle 2: " << c.collection[2].count << std::endl;
    //    std::cout << "naechster freier Index: " << c.nfi << std::endl;

    //    std::cout << " "<< std::endl;

    //    std::cout << "RationalNumber an Stelle 0: " << c.collection[0].rn.numerator << "/" << c.collection[0].rn.denominator << std::endl;

    //    std::cout << " "<< std::endl;
    //    std::cout << " "<< std::endl;

// ====================================================================



//    printf("Performing unit tests for RationalNumber...\n");

//    /* Part 1 - RationalNumber data type */
//    RationalNumber  n1 = { 3, 4 },
//                    n2 = { 6, 4 },
//                    n3 = { 3, 2 },
//                    n4 = { -9, -6 },
//                    n5 = { 9, -6 },
//                    n6 = { 9, 4 },
//                    n0 = { 0, 4 },
//                    nn = { 4, 0 };

//    assert( rnIsValid(n0) );
//    assert( !rnIsValid(nn) );

//    assert( rnEqual( n2, n3) );
//    assert( rnEqual( rnAdd(n1,n1), n2) );
//    assert( rnEqual( n2,n4) );
//    assert( !rnEqual( n4,n5) );
//    assert( rnLessThan( n5,n3) );

//    RationalNumber t1 = rnAdd(n1,n2);
//    RationalNumber t2 = rnDivide(n3,n3);
//    RationalNumber t3 = rnDivide(n2,n2);
//    RationalNumber t4 = rnDivide(n6,n0);

//    assert( rnEqual(t1, n6) );
//    assert( rnEqual(t2, t3) );
//    assert( !rnIsValid(t4) );

//    printf(" successful!\n");

    return 0;
}

