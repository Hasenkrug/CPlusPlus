#include "xmlstreamreader.h"
#include <QTreeWidget>
#include <QFile>
#include "iostream"
#include "person.h"
#include <QList>



XmlStreamReader::XmlStreamReader(Persons *p)
{
    persons = p;
}

bool XmlStreamReader::readFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }

    reader.setDevice(&file);
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isStartElement()) {
            if (reader.name() == "highscore") {

                std::cout << "1" << std::endl;
                readHighscoreElement();
            } else {
                reader.raiseError(QObject::tr("Not a highscore file"));
            }
        } else {
            reader.readNext();
        }
    }
    file.close();

    if (reader.hasError()) {
        std::cerr << "Error: Failed to parse file "
                  << qPrintable(fileName) << ": "
                  << qPrintable(reader.errorString()) << std::endl;
        return false;
    } else if (file.error() != QFile::NoError) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;

    }
    return true;
}

void XmlStreamReader::readHighscoreElement()
{

    std::cout << "b" << std::endl;
    reader.readNext();
    while (!reader.atEnd()) {
        std::cout << "c" << std::endl;
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        std::cout << "2" << std::endl;
        if (reader.isStartElement()) {
            if (reader.name() == "person") {
                readPersonElement();
            }else{
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readPersonElement()
{
    Person *person = new Person();
    person->name = reader.attributes().value("name").toString().toLocal8Bit().constData();

    //std::cout<< person->name << std::endl;
    person->scoreTime = reader.attributes().value("scoreTime").toLocal8Bit().toFloat(0);
    person->error = reader.attributes().value("error").toLocal8Bit().toInt(0,10);
    person->date = reader.attributes().value("date").toLocal8Bit().toInt(0,10);
    std::cout << "w" << std::endl;
    persons->persons.append(*person);

    std::cout << "raus" << std::endl;
    /*QString ste = person->name;
    std::string st = ste.toLocal8Bit().constData();
    std::cout << person->error << std::endl;
*/
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {

            std::cout <<"end" << std::endl;
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "typePoint") {
                readTypePointElements(person);
            } else {
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readTypePointElements(Person *person)
{
    TypePoint *typePoint = new TypePoint();
    typePoint->error = reader.attributes().value("error").toLocal8Bit().toInt(0,10);
    typePoint->timeInMilliSeconds = reader.attributes().value("timeInMilliSeconds").toLocal8Bit().toInt(0,10);
    person->typePoints.append(*typePoint);

    reader.readElementText();
    //std::cout <<"w"<< typePoint->timeInMilliSeconds << std::endl;
    if (reader.isEndElement())
        reader.readNext();

}

void XmlStreamReader::skipUnknownElement()
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            skipUnknownElement();
        } else {
            reader.readNext();
        }
    }
}

bool writeXml(const QString &fileName, Person *person)
{
    /*QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        std::cerr << "Error: Cannot write file "
                  << qPrintable(fileName) << ": "
                  << qPrintable(file.errorString()) << std::endl;
        return false;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("highscore");
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i)
        writeIndexEntry(&xmlWriter, treeWidget->topLevelItem(i));
    xmlWriter.writeEndDocument();
    file.close();
    if (file.error()) {
        std::cerr << "Error: Cannot write file "
                  << qPrintable(fileName) << ": "
                  << qPrintable(file.errorString()) << std::endl;
        return false;
    }
    return true;*/
}

void writeIndexEntry(QXmlStreamWriter *xmlWriter, Person person)
{
    /*
    xmlWriter->writeStartElement("entry");
    xmlWriter->writeAttribute("term", item->text(0));
    QString pageString = item->text(1);
    if (!pageString.isEmpty()) {
        QStringList pages = pageString.split(", ");
        foreach (QString page, pages)
            xmlWriter->writeTextElement("page", page);
    }
    for (int i = 0; i < item->childCount(); ++i)
        writeIndexEntry(xmlWriter, item->child(i));
    xmlWriter->writeEndElement();
    */
}

