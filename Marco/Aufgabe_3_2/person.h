#ifndef PERSON_H
#define PERSON_H

#include "iostream"
#include <QList>
//#include "mydate.h"

class TypePoint
{

public:
    TypePoint(){};
    int timeInMilliSeconds;
    int error;
};

class Run
{
public:
    Run(){};
    int runOn;
    int runChallenge;
    QList<TypePoint> typePoints;

};

class Person
{
public:
    Person(){};
    std::string name;
    int scoreTime;
    int error;
    int memberSince;
    QList<Run> runs;

};


class Persons
{
public:
    Persons(){};
    QList<Person> persons;

};


#endif // PERSON_H
