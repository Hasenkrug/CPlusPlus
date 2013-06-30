#include "xmlstreamreader.h"
#include <QTreeWidget>
#include <QFile>
#include "iostream"
#include "person.h"



XmlStreamReader::XmlStreamReader(QTreeWidget *tree)
{
    treeWidget = tree;
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
                readBookindexElement();
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

void XmlStreamReader::readBookindexElement()
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

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
    person->name = reader.attributes().value("name").toString();

    //std::cout<< person->name << std::endl;
    person->scoreTime = reader.attributes().value("scoreTime").toLocal8Bit().toFloat(0);
    person->error = reader.attributes().value("error").toLocal8Bit().toInt(0,10);
    person->date = reader.attributes().value("date").toLocal8Bit().toInt(0,10);

    QString ste = person->name;
    std::string st = ste.toLocal8Bit().constData();
    std::cout << person->error << std::endl;

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
    std::cout <<"w"<< typePoint->timeInMilliSeconds << std::endl;
    if (reader.isEndElement())
        reader.readNext();
    /*
    QString page = reader.readElementText();


    QString allPages = parent->text(1);
    if (!allPages.isEmpty())
        allPages += ", ";
    allPages += page;
    parent->setText(1, allPages);*/
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
