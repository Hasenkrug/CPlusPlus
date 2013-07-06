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
    int runError;
    int runScoreTime;
    QList<TypePoint> typePoints;

};

class Person
{
public:
    Person(){};
    std::string name;
    int bestScoreTime;
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
