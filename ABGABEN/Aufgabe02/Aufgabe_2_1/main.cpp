/**
 *
 *  C++ für Java-Programmierer
 *  Testtreiber zur Aufgabe 2, "MyDate"
 *  Autor: Hartmut Schirmacher, http://hschirmacher.beuth-hochschule.de
 *
*/

#include <iostream>
#include <assert.h>
#include "map.h"
#include "mydate.h"
#include "mydate_map.h"

using namespace MyTemplate;
using namespace std;
using namespace MyDate;

int main() {

    // Day, Month, Year are just type-safe wrappers for unsigned int
    Days myday;
    assert(myday.value() == 0);

    Months mymonth(12);
    assert(mymonth.value() == 12);

    // have you declared your getters const??? :-)
    const Years CONST_YEAR(2012);
    assert(CONST_YEAR.value() == 2012);

    // test implicit conversion to unsigned int (operator unsigned int())
    assert(0 == myday);
    assert(12 == mymonth);
    assert(2012 == CONST_YEAR);

    // static member function Date::daysInMonth()
    /*int days_feb = Date::daysInMonth(2);
    cout << "February normally has " << days_feb << " days." << endl;
    assert(days_feb == 28);*/

    int days_feb_2400 = Date::daysInMonth(Months(2),Years(2400));
    cout << "In year 2400, February will have " << days_feb_2400 << " days." << endl;
    assert(days_feb_2400 == 29);

    // Date constructor, getters, and stream output
    Date d1;
    cout << "Date1: " << d1 << endl;
    assert(d1.day() == 0);
    assert(d1.month() == 0);
    assert(d1.year() == 0);

    // comparison of two dates
    Date d2(1, 1, 2013);
    cout << "Date2: " << d2 << endl;
    Date d3(28, 2, 2013);
    cout << "Date3: " << d3 << endl;
    cout << "Date2 == Date3: " << (d2==d3) << endl;
    assert(! (d2 == d3));
    cout << "Date2 != Date3: " << (d2!=d3) << endl;
    assert(d2 != d3);
    cout << "Date2 < Date3: " << (d2<d3) << endl;
    assert(d2<d3);
    cout << "Date3 < Date3: " << (d3<d2) << endl;
    assert(!(d3<d2));

    // static member function Date::isLeapYear()
    cout << "Is 1999 a leap year: " << Date::isLeapYear(1999) << endl;
    assert(!Date::isLeapYear(1999));
    cout << "Is 2000 a leap year: " << Date::isLeapYear(2000) << endl;
    assert(Date::isLeapYear(2000));
    cout << "Is 2100 a leap year: " << Date::isLeapYear(2100) << endl;
    assert(!Date::isLeapYear(2100));

    Date d4(28, 2, 2013);

    // add one day
    d4 += Days(1);
    cout << "Date3 +1d: " << d4 << endl;
    assert(d4 == Date(1,3,2013));

    // add many days (multiple months)
    int manydays = 31+30+31+30+31+31; // March ... August
    d4 += Days(manydays);
    cout << "Date3 +" << manydays << "d: " << d4 << endl;
    assert(d4 == Date(1,9,2013));

    // does += return the correct return type and value?
    Date x(1,1,2012);
    Date y = x+=Days(4); // should work!!!// Fehler!!!
    cout << x << " + 4d = " << y <<endl;
    assert(x == Date(5,1,2012));

    Date d5(1,1,2015);

    // add months
    Months m3 = d5.month();
    d5 += Months(2);
    cout << "Date3 +2m:" << d5 << endl;
    assert(d5.month() == m3+2);

    // add years
    Years y3 = d5.year();
    d5 += Years(20);
    cout << "Date3 +20y:" << d5 << endl;
    assert(d5.year() == y3+20);

    // verifizieren Sie, dass die folgende Zeile NICHT compiliert,
    // und kommentieren Sie sie dann aus
    // d5 += 1;

    // non-mutating addition operators
    const Date dd(31,12,2012);
    Date dd2 = dd + Days(1);
    cout << dd << " + 1 day = " << dd2 << endl;
    assert(dd2 == Date(1,1,2013));

    Date dd3 = dd + Months(4);
    cout << dd << " + 4 months = " << dd3 << endl;
    assert(dd3 == Date(30,4,2013));

    Date dd4 = dd + Years(1000);

    cout << dd << " + 1000 years = " << dd4 << endl;
    assert(dd4 == Date(31,12,3012));

    // mixed units
    Date dd5 = dd + Days(2) + Months(3) + Years(5);
    cout << dd << " + 2d + 3m + 5y = " << dd5 << endl;

    assert(dd5 == Date(2,4,2018));


    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
    cout << "                         Map-Test-Area                   " << endl;
    cout << "                                                         " << endl;


    Date date1(1,5,2013);
    Date date2(6,12,2013);

    Date date3(2,4,2013);
    Date date4(6,4,2013);
    Date date5(5,5,2013);
    Date date6(5,4,2013);
    Date date7(7,4,2013);
    Date date8(8,4,2013);


    //MyDate::Map map1;
    MyTemplate::Map<Date,string> map1;
    map1[date1] = "Wenig Arbeit, viele Demos";
    map1[date2] = "Nikolaus kommt";
    assert(map1.size() == 2);
    map1[date2] = "Nikolaus kommt doch nicht";
    assert(map1.size() == 2);

    assert(map1.getRootNode()->m_right->m_pair.first == date2);

    map1[date3] = "der 02.04.2013";
    map1[date4] = "der 06.04.2013";
    map1[date5] = "der 05.05.2013";
    map1[date6] = "der 05.04.2013";
    map1[date7] = "der 07.04.2013";

    assert(map1.size() == 7);

    // tier 1 rechts
    assert(map1.m_root->contains(date2));
    // tier 1 links
    assert(map1.m_root->contains(date3));
    // tier 3 links
    assert(map1.m_root->contains(date7));
    // nicht in der map
    assert(!map1.m_root->contains(date8));

    // Abfrage der Position der Daten in der map1
    assert(map1.m_root->m_pair.first == date1);
    assert(map1.m_root->m_left->m_pair.first == date3);
    assert(map1.m_root->m_right->m_pair.first == date2);
    assert(map1.m_root->m_left->m_right->m_pair.first == date4);
    assert(map1.m_root->m_right->m_left->m_pair.first == date5);
    assert(map1.m_root->m_left->m_right->m_left->m_pair.first == date6);
    assert(map1.m_root->m_left->m_right->m_right->m_pair.first == date7);

    cout << "                 Unsere Map an dieser Stelle             " << endl;
    cout << "                                                         " << endl;
    cout << "                          [1,5,2013]                     " << endl;
    cout << "                               |                         " << endl;
    cout << "        _______________________|__________________       " << endl;
    cout << "       |                                          |      " << endl;
    cout << "       |                                          |      " << endl;
    cout << "   [2,4,2013]                                [6,12,2013] " << endl;
    cout << "       |                                          |      " << endl;
    cout << "       |___________                    ___________|      " << endl;
    cout << "                   |                  |                  " << endl;
    cout << "                   |                  |                  " << endl;
    cout << "               [6,4,2013]         [5,5,2013]             " << endl;
    cout << "                   |                                     " << endl;
    cout << "             ______|______                               " << endl;
    cout << "            |             |                              " << endl;
    cout << "            |             |                              " << endl;
    cout << "        [5,4,2013]    [7,4,2013]                         " << endl;
    cout << "                                                         " << endl;

    MyTemplate::Map<Date,string> map2;

    // Zuweisungsoperator Test
    map2=map1;

    assert(map2.size() == 7);

    // Abfrage der Position der Daten in der map2
    assert(map2.m_root->m_pair.first == date1);
    assert(map2.m_root->m_left->m_pair.first == date3);
    assert(map2.m_root->m_right->m_pair.first == date2);
    assert(map2.m_root->m_left->m_right->m_pair.first == date4);
    assert(map2.m_root->m_right->m_left->m_pair.first == date5);
    assert(map2.m_root->m_left->m_right->m_left->m_pair.first == date6);
    assert(map2.m_root->m_left->m_right->m_right->m_pair.first == date7);

    map2.m_root->m_right->m_pair.second = "Darf nicht in map1 stehen!";
    assert(&map1.m_root->m_right->m_pair != &map2.m_root->m_right->m_pair);
    assert(map2.m_root->m_right->m_pair.second == "Darf nicht in map1 stehen!");
    assert(map1.m_root->m_right->m_pair.second != "Darf nicht in map1 stehen!");

    // Copy-Konstruktor-Test
    MyTemplate::Map<Date,string> map3(map1);

    assert(map3.m_root->m_pair.first == date1);
    assert(map3.m_root->m_left->m_pair.first == date3);
    assert(map3.m_root->m_right->m_pair.first == date2);
    assert(map3.m_root->m_left->m_right->m_pair.first == date4);
    assert(map3.m_root->m_right->m_left->m_pair.first == date5);
    assert(map3.m_root->m_left->m_right->m_left->m_pair.first == date6);
    assert(map3.m_root->m_left->m_right->m_right->m_pair.first == date7);

    map3.m_root->m_right->m_pair.second = "Darf nicht in map1 stehen!";
    assert(&map1.m_root->m_right->m_pair != &map3.m_root->m_right->m_pair);
    assert(map3.m_root->m_right->m_pair.second == "Darf nicht in map1 stehen!");
    assert(map1.m_root->m_right->m_pair.second != "Darf nicht in map1 stehen!");

    // Templateparameter int/string Test
    MyTemplate::Map<int, string> map4;
    map4[23]= "was";
    assert(map4.m_root->m_pair.second=="was");

    // Templateparameter string/string Test
    MyTemplate::Map<string, string> map5;
    map5["key"]= "wieso";
    assert(map5.m_root->m_pair.second=="wieso");

    // Iterator Copyconstructor Test
    MyTemplate::Map<Date,string>::Iterator it(map1.m_root);
    MyTemplate::Map<Date,string>::Iterator it1;

    // Iterator Zuweisungsoperator Test
    it1 = it;

    // Test auf Gleichheit
    assert(it1 == it);

    // Test auf Ungleichheit
    assert(!(it1 != it));

    // Dereferenzierung mittels * Test
    pair<Date,string> a = *it;
    assert(a.second == "Wenig Arbeit, viele Demos");

    // Dereferenzierung mittels -> Test
    assert(it1->second == "Wenig Arbeit, viele Demos");

    // Inkrement Test
    it = it++;
    assert(it->second == "der 05.05.2013");

    // Map::begin() Test
    it = map1.begin();
    assert(it->second == "der 02.04.2013");

    // Aufgabenblatt Test Beispiel
    MyTemplate::Map<int,string> m;
    m[4] = "vier";
    m[7] = "sieben";
    m[2] = "zwei";
    MyTemplate::Map<int,string>::Iterator i = m.begin();
    cout << "kleinstes Element: " << i->first << "/" << i->second << endl;
    cout << "weitere Elemente, sortiert: " << endl;
    while(i!=m.end()) {
        pair<int,string> p = *i;
        cout << " " << p.first << "/" << p.second << endl;
        i++; // nach hinten verlagert, wahrscheinlich hier korrekt.
    }
    m.begin()->second = "neuer Wert";

    // hier darf kein wert nachgetragen werden.
    //m.begin()->first = 2;
    cout <<  ""<< endl;
    cout << "Mapped_t ist nun anderer Paramenter als string: " << ii->first << "/" << ii->second << endl;

    MyTemplate::Map<int,bool> mm;
    mm[4] = false;
    mm[5] = true;
    MyTemplate::Map<int,bool>::Iterator ii = mm.begin();
    cout << "kleinstes Element: " << ii->first << "/" << ii->second << endl;



#if 0
#endif

    cout << "" << endl;
    cout << "all tests completed." << endl;
    cout << "" << endl;

    return 0;
}


