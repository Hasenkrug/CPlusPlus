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

class Person
{
public:
    Person(){};
    std::string name;
    float scoreTime;
    int error;
    int date;
    QList<TypePoint> typePoints;

};


class Persons
{
public:
    Persons(){};
    QList<Person> persons;

};


#endif // PERSON_H
