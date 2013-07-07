#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>
#include "qcustomplot.h"
#include "person.h"
#include "xmlstreamreader.h"

namespace Ui {
class Highscore;
}

class Highscore : public QDialog
{
    Q_OBJECT
    
public:
    explicit Highscore(QWidget *parent = 0);
    ~Highscore();
    void initHighScore(Person *P);
    Persons *persons;
    XmlStreamReader reader;

    Ui::Highscore *ui;
    
private:
    void showHighscore(QCustomPlot *plot, Persons p);
    void addGraphForAllRunsOfOnePerson(QCustomPlot *plot, Person p);//Gesamtzeit/Runs
    void addGraphForLastRunOfOnePerson(QCustomPlot *plot, Run r);//zeit pro Anschlag/Anschlag
    void addGraphOneBestToOneActual(QCustomPlot *plot, Run rL, Run rB);
    void addGraphBestRunAllPersonsTopTen(QCustomPlot *plot, Run rL, Run rB);

};

#endif // HIGHSCORE_H
