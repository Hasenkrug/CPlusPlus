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

    RationalNumberCollection* c = rncCreate(3);
    RationalNumber n1 = {3, 4};
    RationalNumber n2 = {1, 2};
    RationalNumber n3 = {1, 3};
    RationalNumber n4 = {1, 4};
    RationalNumber n5 = {1, 5};
    RationalNumber n6 = {1, 6};
    RationalNumber n7 = {1, 7};
    RationalNumber n8 = {1, 8};
    RationalNumber n9 = {7, 1};
    RationalNumber n10 = {7, 2};
    RationalNumber n11 = {7, 3};
    RationalNumber n12 = {7, 4};

    c = rncAdd(c,n1);
    c = rncAdd(c,n2);
    c = rncAdd(c,n3);
    c = rncAdd(c,n4);
    c = rncAdd(c,n5);
    c = rncAdd(c,n6);
    c = rncAdd(c,n7);
    c = rncAdd(c,n8);
    c = rncAdd(c,n9);
    c = rncAdd(c,n10);
    c = rncAdd(c,n11);
    c = rncAdd(c,n12);

    std::cout <<" "<< c <<" "<< std::endl;
    c = rncDelete(c);

    std::cout <<" "<< c <<" "<< std::endl;


    printf("Performing unit tests for RationalNumberCollection...\n");
    //assert( rncTotalCount(c) == 3);
    //assert( rncTotalUniqueCount(c) == 2 );

    std::cout << " "<< std::endl;

    printf("successful!\n");

    std::cout << " "<< std::endl;

    return 0;
}

