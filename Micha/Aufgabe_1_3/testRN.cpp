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

    RationalNumberCollection* c = rncCreate(8);

    RationalNumber n1 = {1, 1};
    RationalNumber n2 = {1, 2};
    RationalNumber n3 = {1, 3};
    RationalNumber n4 = {1, 4};
    RationalNumber n5 = {1, 5};
    RationalNumber n6 = {1, 6};
    RationalNumber n7 = {1, 7};
    RationalNumber n8 = {1, 8};

    rncAdd(c,n1);
    rncAdd(c,n1);
    rncAdd(c,n2);

    printf("Performing unit tests for RationalNumberCollection...\n");

    assert( rncTotalCount(c) == 3);
    assert( rncTotalUniqueCount(c) == 2 );

    std::cout << " "<< std::endl;

    printf("successful!\n");

    std::cout << " "<< std::endl;

    return 0;
}

