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

    map1[3];
    cout << "Size of map1: " << map1.size() << endl;
    cout << "" << endl;

    map1[3] = "Root Node - Wert: 3";
    cout << map1.getRootNode()->find(3)->m_pair.second << endl;
    cout << "" << endl;

    map1[2] = "ich bin eine zwei";
    cout << map1.getRootNode()->find(2)->m_pair.second << endl;
    cout << "Elternknoten der 2: " << map1.getRootNode()->find(2)->m_up->m_pair.second << endl;
    cout << "" << endl;

    map1[5] = "ich bin eine fuenf";
    cout << map1.getRootNode()->find(5)->m_pair.second << endl;
    cout << "Elternknoten der 5: " << map1.getRootNode()->find(5)->m_up->m_pair.second << endl;
    cout << "" << endl;

    map1[6] = "ich bin eine sechs";
    cout << map1.getRootNode()->find(6)->m_pair.second << endl;
    cout << "Elternknoten der 6: " << map1.getRootNode()->find(6)->m_up->m_pair.second << endl;
    cout << "" << endl;

    cout << "Rechter Unterknoten von ROOT: " << map1.m_root->m_right->m_pair.second << endl;
    cout << "Linker Unterknoten von ROOT: " << map1.m_root->m_left->m_pair.second << endl;
    cout << "Linker Unterknoten von 5: " << map1.m_root->find(5)->m_left << endl;
    cout << "Rechter Unterknoten von 5: " << map1.m_root->find(5)->m_right->m_pair.second << endl;
    cout << "" << endl;

#if 0
#endif

    cout << "" << endl;
    cout << "all tests completed." << endl;
    cout << "" << endl;

    return 0;
}

