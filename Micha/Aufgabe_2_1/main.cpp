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

    cout << "" << endl;
    cout << "" << endl;
    cout << "Map-Test-Area" << endl;
    cout << "" << endl;

    Map map1;

    cout << "Create map1" << endl;
    cout << "RootNode of map1: " << map1.getRootNode() << endl;
    cout << "Size of map1: " << map1.size() << endl;
    cout << "" << endl;

    // cout << "insert insert(1, 'Hola')" << endl;
    // map1.getRootNode()->insert(1, "Hola");
    // cout << "" << endl;

    map1[1];
    cout << "Size of map1: " << map1.size() << endl;
    cout << "" << endl;

    cout << "let us find this '1': " << map1.getRootNode()->find(1)->m_pair.second << endl;
    cout << "" << endl;

    map1[2];
    cout << "Size of map1: " << map1.size() << endl;
    cout << "" << endl;

    cout << "let us find this '2': " << map1.getRootNode()->find(2)->m_pair.second << endl;
    cout << "" << endl;

#if 0
#endif

    cout << "" << endl;
    cout << "all tests completed." << endl;
    cout << "" << endl;

    return 0;
}

