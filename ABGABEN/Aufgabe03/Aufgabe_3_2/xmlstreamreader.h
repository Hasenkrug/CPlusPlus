#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
#include <QTreeWidget>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "person.h"
#include <QList>

class XmlStreamReader
{
public:
    XmlStreamReader();
    XmlStreamReader(Persons *p);

    bool readFile(const QString &fileName);
    bool writeXml(const QString &fileName);
    void setPerson(Persons *p)
    {
        persons = p;}

private:
    void readHighscoreElement();
    void readPersonElement();
    void readRunElements(Person*person);
    void readTypePointElements(Run *run);
    void skipUnknownElement();


    void writePersonEntry(QXmlStreamWriter *xmlWriter,Person *person);
    void writeRunEntry(QXmlStreamWriter *xmlWriter, Run *run);
    void writeTypePointEntry(QXmlStreamWriter *xmlWriter, TypePoint *typePoint);


    Persons *persons;
    QXmlStreamReader reader;
};

#endif // XMLSTREAMREADER_H
