#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QSet>
#include <QMap>
#include "iostream"


#include <QApplication>
#include <QTreewidget>
#include <xmllite.h>
#include <QXmlStreamReader>
#include <XmlStreamReader.h>
#include <person.h>
#include <QList>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QStringList args = QApplication::arguments();



    XmlStreamReader reader(persons);


    reader.readFile("../Aufgabe_3_2/highscore.xml");


    std::cout << "122"<< std::endl;
    for ( int i=0; i < persons->persons.length(); i++){

        std::cout << "1: " << i<< std::endl;
        std::cout << "Person: " << persons->persons.at(i).name << std::endl;
        //persons->persons.at(i).runs.at(i).
        std::cout << "Fehler: " << persons->persons.at(i).error << std::endl;
        std::cout << "ScoreTime: " << persons->persons.at(i).scoreTime << std::endl;
        std::cout << "runCount" << persons->persons.at(i).runs.length()<< std::endl;
        for( int j = 0; j< persons->persons.at(i).runs.length(); j++){
            std::cout << "runChallenge: " << persons->persons.at(i).runs.at(j).runChallenge << std::endl;
        }
    }

    std::cout << "11"<< std::endl;
    reader.writeXml("../Aufgabe_3_2/newHighscore.xml");
    return 0;


}

/*    //QCoreApplication app(argc, argv);  //(we don't use these)
    QString testbuf = "12345 Marco  123 2 234 3 456 0 244 0 123 0\n 1345 Nadine 23 1 34 0 56 0 44 0 123 0\n";
    QFile file("../Aufgabe_3_2/highscore.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << testbuf << endl;         // optional, as QFile destructor will already do it:
        file.close();
    }


    QFile file2("../Aufgabe_3_2/highscore.txt");
    file2.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in(&file2);
    QStringList li;
    while(!in.atEnd()) {
        QString line(in.readLine());
        li = line.split(" ");
        QSet<QString> set = li.toSet();
        QList<QString> list = set.toList();
        li.
        //QMap<int,QString> mMap;
        //int i[] = {3,3,4};
        mMap[3] = i;
        std::cout << "bool: " << mMap[3] << std::endl;
    }

    //QStringList



    //this would normally start the event loop, but is not needed for this
    //minimal example:
    //return app.exec();

    return 0;
}*/








/*
#include "mainwindow.h"
#include <QApplication>
#include "iostream"
#include <QtSql/QSqlDatabase>
#include <QtXml>

int main(int argc, char *argv[])


//LIBS+=C:/Progra~1/MySQL/MySQLS~1.0/lib/opt/liblibmysql.a
{
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("https://127.0.0.1:3306");
        db.setDatabaseName("sportplaces");
        db.setUserName("sportplaces");
        db.setPassword("sportplaces4224");
        bool ok = db.open();


        //std::cout << "bool: " << ok << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/
