#include "xmlstreamreader.h"
#include <QTreeWidget>
#include <QFile>
#include "iostream"
#include "person.h"
#include <QList>
#include <QXmlStreamWriter>


XmlStreamReader::XmlStreamReader(Persons *p)
{
    this->persons = p;
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
    person->name = reader.attributes().value("name").toString().toLocal8Bit().constData();

    person->bestScoreTime = reader.attributes().value("bestScoreTime").toLocal8Bit().toInt(0);
    person->error = reader.attributes().value("error").toLocal8Bit().toInt(0,10);
    person->memberSince = reader.attributes().value("memberSince").toLocal8Bit().toInt(0,10);


    //std::cout<< "run: "<< reader.attributes().value("name").toString().toLocal8Bit().constData() << std::endl;

    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "run") {
                readRunElements(person);
            } else {
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }

    persons->persons.append(*person);


}


void XmlStreamReader::readRunElements(Person *person)
{
    Run *run = new Run();
    run->runChallenge = this->reader.attributes().value("runChallenge").toLocal8Bit().toInt(0,10);
    run->runOn = this->reader.attributes().value("runOn").toLocal8Bit().toInt(0,10);
    run->runError = this->reader.attributes().value("runError").toLocal8Bit().toInt(0,10);
    run->runScoreTime = this->reader.attributes().value("runScoreTime").toLocal8Bit().toInt(0,10);

    //std::cout<< "run: "<< this->reader.attributes().value("runChallenge").toLocal8Bit().toInt(0,10) << std::endl;

    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "typePoint") {
                readTypePointElements(run);
            } else {
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }

    person->runs.append(*run);
}

void XmlStreamReader::readTypePointElements(Run *run)
{
    TypePoint *typePoint = new TypePoint();
    typePoint->error = reader.attributes().value("error").toLocal8Bit().toInt(0,10);
    typePoint->timeInMilliSeconds = reader.attributes().value("timeInMilliSeconds").toLocal8Bit().toInt(0,10);
    run->typePoints.append(*typePoint);

    reader.readElementText();
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



void XmlStreamReader::writeTypePointEntry(QXmlStreamWriter *xmlWriter, TypePoint *typePoint)
{
    xmlWriter->writeStartElement("typePoint");
    xmlWriter->writeAttribute("timeInMilliSeconds", QString::number(typePoint->timeInMilliSeconds, 10));
    xmlWriter->writeAttribute("error", QString::number(typePoint->error,10));
    xmlWriter->writeEndElement();
}

void XmlStreamReader::writeRunEntry(QXmlStreamWriter *xmlWriter, Run *run)
{
    xmlWriter->writeStartElement("run");
    xmlWriter->writeAttribute("runOn", QString::number(run->runOn));
    xmlWriter->writeAttribute("runChallenge", QString::number(run->runChallenge));
    xmlWriter->writeAttribute("runError", QString::number(run->runError));
    xmlWriter->writeAttribute("runScoreTime", QString::number(run->runScoreTime));
    for (int i = 0; i < run->typePoints.length(); ++i){
        TypePoint *typePoint = new TypePoint();
        typePoint->error = run->typePoints.at(i).error;
        typePoint->timeInMilliSeconds = run->typePoints.at(i).timeInMilliSeconds;
        writeTypePointEntry(xmlWriter, typePoint);
    }
    xmlWriter->writeEndElement();
}

void XmlStreamReader::writePersonEntry(QXmlStreamWriter *xmlWriter, Person *person)
{
    xmlWriter->writeStartElement("person");

    xmlWriter->writeAttribute("name", QString::fromStdString(person->name));
    xmlWriter->writeAttribute("error", QString::number(person->error,10));
    xmlWriter->writeAttribute("bestScoreTime", QString::number(person->bestScoreTime,10));
    xmlWriter->writeAttribute("memeberSince", QString::number(person->memberSince,10));
    for (int i = 0; i < person->runs.length(); ++i){
        Run *run = new Run();
        run->runChallenge = person->runs.at(i).runChallenge;
        run->runOn = person->runs.at(i).runOn;
        run->runError = person->runs.at(i).runError;
        run->runScoreTime = person->runs.at(i).runScoreTime;
        run->typePoints = person->runs.at(i).typePoints;
        writeRunEntry(xmlWriter, run);
    }
    xmlWriter->writeEndElement();
}

bool XmlStreamReader::writeXml(const QString &fileName)
{

    std::cout << "1"<< std::endl;
    QFile file(fileName);
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
    for (int i = 0; i < this->persons->persons.length(); ++i){
        Person *pers = new Person();
        pers->error = this->persons->persons.at(i).error;
        pers->memberSince = this->persons->persons.at(i).memberSince;
        pers->name = this->persons->persons.at(i).name;
        pers->bestScoreTime = this->persons->persons.at(i).bestScoreTime;
        pers->runs = this->persons->persons.at(i).runs;
            writePersonEntry(&xmlWriter,pers);
    }
    xmlWriter.writeEndDocument();
    file.close();
    if (file.error()) {
        std::cerr << "Error: Cannot write file "
                  << qPrintable(fileName) << ": "
                  << qPrintable(file.errorString()) << std::endl;
        return false;
    }
    return true;
}
