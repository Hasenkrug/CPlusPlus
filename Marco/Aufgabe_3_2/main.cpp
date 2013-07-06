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
#include <mainwindow.h>
#include <testwidget.h>
#include <highscore.h>

int main(int argc, char *argv[])
{



    //QApplication app(argc, argv);
    //QStringList args = QApplication::arguments();

    std::cout << argv[0] << std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    TestWidget myWindow;
    w.show();
    Highscore* s = new Highscore();
    s->installEventFilter(s);
    //s->setText();
    s->show();
    Persons *persons = new Persons();
    XmlStreamReader reader(persons);
    reader.readFile("../highscore.xml");
    reader.writeXml("../newHighscore.xml");

    a.exec();

    return 0;


}
