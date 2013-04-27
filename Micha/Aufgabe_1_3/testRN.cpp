/*
   Simple Tests for type RationalNumberCollection
*/

#include "rationalnumbercollection.h"
#include "stdio.h"
#include "assert.h"
#include "iostream"



int main() {
    printf("Performing tests for RationalNumberCollection...\n");

    RationalNumberCollection* c = rncCreate(3);
    RationalNumber n1 = {-3, 4};
    RationalNumber n2 = {1, 2};
    RationalNumber n3 = {-1, 3};
    RationalNumber n4 = {1, -3};
    RationalNumber n5 = {1, 5};
    RationalNumber n6 = {1, 6};
    RationalNumber n7 = {1, 7};
    RationalNumber n8 = {1, 8};
    RationalNumber n9 = {-7, 1};
    RationalNumber n10 = {7, 2};
    RationalNumber n11 = {7, -3};
    RationalNumber n12 = {7, 4};

    c = rncAdd(c,n3);
    c = rncAdd(c,n3);
    c = rncAdd(c,n1);
    c = rncAdd(c,n4);
    c = rncAdd(c,n5);
    c = rncAdd(c,n6);
    c = rncAdd(c,n7);
    c = rncAdd(c,n8);
    c = rncAdd(c,n9);
    c = rncAdd(c,n10);
    c = rncAdd(c,n11);
    c = rncAdd(c,n12);

    c = rncRemove(c,n1);
    c = rncRemove(c,n2);
    c = rncRemove(c,n3);
    c = rncRemove(c,n4);
    c = rncRemove(c,n5);
    c = rncRemove(c,n6);
    c = rncRemove(c,n7);
    c = rncRemove(c,n8);
    c = rncRemove(c,n9);
    c = rncRemove(c,n10);
    c = rncRemove(c,n11);
    c = rncRemove(c,n12);

    rncDelete(c);

    std::cout <<""<< std::endl;
    printf("successful!\n");
    std::cout <<""<< std::endl;
    std::cout <<"(._.) (|:) (.-.) (:|) (._.)"<< std::endl;
    std::cout <<""<< std::endl;

    return 0;
}

