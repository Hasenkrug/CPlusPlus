#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
#include <QTreeWidget>
#include <QXmlStreamReader>
#include "person.h"
#include <QList>

class XmlStreamReader
{
public:
    XmlStreamReader(Persons *p);

    bool readFile(const QString &fileName);
    bool writeXml(const QString &fileName, Person *person);

private:
    void readHighscoreElement();
    void readPersonElement();
    void readTypePointElements(Person *person);
    void skipUnknownElement();

    void writeIndexEntry(QXmlStreamWriter *xmlWriter, Person person);

    Persons *persons;
    QXmlStreamReader reader;
};

#endif // XMLSTREAMREADER_H
