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
#include "map_template.h"

using namespace std;
using namespace map_template;
// using namespace MyDate;

int main() {

    Map<MyDate::Date,std::string> map1;

    Date date1(1,5,2013);

    map1[date1] = "Wenig Arbeit, viele Demos";


/* Testfälle für mydate_map

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

    Map map1;

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

    Map map2;
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
    Map map3(map1);

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
*/

#if 0
#endif

    cout << "" << endl;
    cout << "all tests completed." << endl;
    cout << "" << endl;

    return 0;
}

