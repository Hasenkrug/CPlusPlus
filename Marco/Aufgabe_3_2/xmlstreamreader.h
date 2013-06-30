#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
#include <QTreeWidget>
#include <QXmlStreamReader>
#include "person.h"

class XmlStreamReader
{
public:
    XmlStreamReader(QTreeWidget *tree);

    bool readFile(const QString &fileName);

private:
    void readBookindexElement();
    void readPersonElement();
    void readTypePointElements(Person *person);
    void skipUnknownElement();

    QTreeWidget *treeWidget;
    QXmlStreamReader reader;
};

#endif // XMLSTREAMREADER_H
