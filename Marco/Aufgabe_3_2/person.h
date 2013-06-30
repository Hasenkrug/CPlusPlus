#ifndef PERSON_H
#define PERSON_H

#include "iostream"
#include <QString>
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
    QString name;
    float scoreTime;
    int error;
    int date;
    QList<TypePoint> typePoints;

};

#endif // PERSON_H
