/**
 *
 *  C++ für Java-Programmierer
 *  Testtreiber zur Aufgabe 2, "MyDate"
 *  Autor: Hartmut Schirmacher, http://hschirmacher.beuth-hochschule.de
 *
*/

#include <iostream>
#include <assert.h>
#include "mydate.h"
#include "mydate_map.h"

using namespace std;
using namespace MyDate;

int main()
{
    cout << "Starting Unit Tests for Day, Month, Year, Date..." << endl;
    {


        MyDate::Date date1(4,5,2013);
        MyDate::Date date2(3,5,2013);
        MyDate::Date date3(2,5,2013);
        MyDate::Date date4(6,5,2013);
        MyDate::Date date5(5,5,2013);
        MyDate::Date date6(7,5,2013);
        MyDate::Date christmas(6,12,2013);
        MyDate::Map map1;
        printf("map Konstruktor\n");



        map1[date1] = "4.5";
        printf("4.5 Element in Liste eingefügt:\n");
        map1[date2] = "3.5";
        printf("3.5 Element in Liste eingefügt:\n");
        map1[date3] = "2.5";
        printf("2.5 Element in Liste eingefügt:\n");
        map1[date4] = "6.5";
        printf("6.5 Element in Liste eingefügt:\n");
        map1[date5] = "5.5";
        printf("5.5 Element in Liste eingefügt:\n");
        map1[date6] = "7.5";
        printf("7.5 Element in Liste eingefügt:\n");



        map1[christmas] = "Nikolaus kommt!";
        cout << "Date2: " << map1[date2] << endl;
        assert(map1.size()==7);
        map1[christmas] = "Niko kommt doch nicht";

        cout << "Date2: " << map1[date2] << endl;
        assert(map1.size()==7);
    }

#if 0


    {


        int int1 = 5;
        int int2 = 9;
        MyDate::Map map1;
        printf("map Konstruktor/n");

        map1[int1] = "Wenig Arbeit, viele Demos";
        printf("erstes Date dazu gefügt/n");
        map1[int2] = "Nikolaus kommt!";
        printf("zweites Date dazu gefügt");

        assert(map1.size()==2);
        //map1[date2] = "Niko kommt doch nicht"
        //assert(map1.size()==2);
    }
#endif

    cout << "all tests completed." << endl;

    return 0;
}

