#include "highscore.h"
#include "ui_highscore.h"
#include "qcustomplot.h"
#include "QStandardItemModel"
#include "xmlstreamreader.h"

Highscore::Highscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Highscore)
{
    srand(QDateTime::currentDateTime().toTime_t());
    ui->setupUi(this);


    persons  = new Persons();

    std::cout<<"32"<<std::endl;
    reader.setPerson(persons);

    std::cout<<"33"<<std::endl;
    reader.readFile("../highscore.xml");

    std::cout<<"34"<<std::endl;
    ui->plot0->setInteractions(QCP::iRangeDrag  |QCP::iRangeZoom);
    ui->plot1->setInteractions(QCP::iRangeDrag  |QCP::iRangeZoom);
    ui->plot2->setInteractions(QCP::iRangeDrag  |QCP::iRangeZoom);

}

void Highscore::initHighScore(Person *p){
    bool newName = true;

    std::cout<<"h:0"<<std::endl;

    for (int i= 0;i<persons->persons.size();i++){
        if(persons->persons.at(i).name.compare(p->name)){
            Run *rr = new Run();
            rr->runChallenge = p->runs.at(0).runChallenge;
            rr->runOn = p->runs.at(0).runOn;
            rr->runError = 0;
            rr->runScoreTime = 0;
            rr->typePoints = p->runs.at(0).typePoints;

            for(int j=0; j < rr->typePoints.size();j++){
                rr->runScoreTime = rr->typePoints.at(j).timeInMilliSeconds + rr->runScoreTime;
                rr->runError = rr->typePoints.at(j).error + rr->runError;
                rr->runOn = 0;
            }
            persons->persons[i].runs.append(*rr);
            persons->persons[i].bestScoreTime = std::max(persons->persons[i].bestScoreTime,  rr->runScoreTime);
            persons->persons[i].error = std::max(persons->persons[i].error, rr->runError);
            persons->persons[i].memberSince = 0;
            newName = false;
            break;
        }
    }

    std::cout<<p->runs.size()<<std::endl;

    if(newName){
        Run *rr = new Run();
        rr->runScoreTime = 0;
        rr->runError = 0;
        for(int j=0; j < p->runs.at(0).typePoints.size();j++){
            rr->runScoreTime = p->runs.at(0).typePoints.at(0).timeInMilliSeconds + rr->runScoreTime;
            rr->runError = p->runs.at(0).typePoints.at(j).error + rr->runError;
            rr->runOn = 0;
            rr->runChallenge = p->runs.at(0).runChallenge;
            rr->typePoints = p->runs.at(0).typePoints;
        }
        Person *pp = new Person();
        pp->memberSince = 0;
        pp->bestScoreTime = rr->runScoreTime;
        pp->error = rr->runError;
        pp->runs.append(*rr);
        persons->persons.append(*pp);
    }

    std::cout<<p->runs.at(0).typePoints.size()<<std::endl;

    reader.writeXml("../hhighscore.xml");
    std::cout<<"h:1"<<std::endl;
    for (int i= 0;i<persons->persons.size();i++){
        if (persons->persons.at(i).name == "marco"){

            std::cout<<"h:2"<<std::endl;
            addGraphForAllRunsOfOnePerson(ui->plot0, persons->persons.at(i));
            addGraphForLastRunOfOnePerson(ui->plot1, persons->persons.at(i).runs.at(persons->persons.at(i).runs.size()-1));

            std::cout<<"h:3"<<std::endl;
            std::map<int,int> map;
            for(int j=0; j<persons->persons.at(i).runs.size(); j++){
                map[persons->persons.at(i).runs.at(j).runScoreTime] = j;
            }

            std::cout<<"h:4"<<std::endl;
            std::map<int,int>::iterator g  = map.begin();
            std::pair<int,int> f;
            while(g!=map.end()){
                f = *g;
                g++;
            }
            addGraphOneBestToOneActual(ui->plot2, persons->persons.at(i).runs.at(persons->persons.at(i).runs.size()-1), persons->persons.at(i).runs.at(f.second));
        }
        std::map<int,int> map;
        for(int j=0; j<persons->persons.size(); j++){
            map[persons->persons.at(j).bestScoreTime] = j;
        }
        std::map<int,int>::iterator g  = map.begin();
        std::pair<int,int> f;
        while(g!=map.end()){
            f = *g;
            g++;
        }
        //addGraphOneBestToOneActual(ui->plot2, persons->persons.at(i).runs.at(persons->persons.at(i).runs.size()-1), persons->persons.at(i).runs.at(f.second));
    }
}

Highscore::~Highscore()
{
    delete ui;
}

void Highscore::showHighscore(QCustomPlot *plot, Persons p){
    /*QAbstractItemModel *m = ui->tableWidget->model();
    m->setHeaderData(0,Qt::Horizontal, QObject::tr("User"), Qt::DisplayRole);
    m->setHeaderData(1,Qt::Horizontal, QObject::tr("Score"),Qt::DisplayRole);
    ui->tableWidget->*/
}
void Highscore::addGraphForAllRunsOfOnePerson(QCustomPlot *plot, Person p){
    plot->plotLayout()->insertRow(0);
    plot->plotLayout()->addElement(0, 0, new QCPPlotTitle(plot, "Alle absolvierten Durchgänge"));

    int runsCount = p.runs.size();
    int xMin = -1;
    int xMax = runsCount+1;
    int yMin = 0;
    double yMax = 0;
    int yMaxErr = 0;

    QVector<double> x(runsCount), y(runsCount), y2(runsCount*11), x2(runsCount*11);
    for(int i = 0;i<runsCount;i++){
        y[i] = p.runs.at(i).typePoints.size()/ (p.runs.at(i).runScoreTime/60000.0);
        x[i] = i;
        yMax = std::max(y[i],yMax);
        for(double j = 0; j<11;j++){
            y2[11*i+j] =  p.runs.at(i).runError;
            x2[11*i+j] =  (i-0.02)+(0.004*j);
        }
        yMaxErr = std::max(p.runs.at(i).runError,yMaxErr);

    }
    plot->addGraph(plot->xAxis, plot->yAxis);
    plot->graph(0)->setName("Anschläge / Minute");
    plot->graph(0)->setData(x,y);
    plot->graph(0)->setLineStyle((QCPGraph::LineStyle)(1));
    plot->graph(0)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(1)));

    QPen graphPen;
    graphPen.setColor(QColor(200, 50, 0, 85));
    graphPen.setWidthF(2);
    plot->graph(0)->setPen(graphPen);

    plot->addGraph(plot->xAxis, plot->yAxis2);
    plot->graph(1)->setName("Fehler");
    plot->graph(1)->setData(x2,y2);
    plot->graph(1)->setLineStyle((QCPGraph::LineStyle)(5));

    QPen graphPen2;
    graphPen2.setColor(QColor(0, 50, 0, 100));
    graphPen2.setWidthF(3);
    plot->graph(1)->setPen(graphPen2);

    plot->yAxis2->setVisible(true);
    plot->xAxis2->setVisible(true);
    plot->xAxis->setVisible(true);

    plot->xAxis->setLabel("Durchlauf");
    plot->yAxis->setLabel("Anschläge pro Minute");
    plot->yAxis2->setLabel("Fehler");

    plot->xAxis->setRange(xMin, xMax);
    plot->yAxis->setRange(yMin, yMax+1);
    plot->yAxis2->setRange(yMin,yMaxErr*1.5 );
    plot->xAxis2->setRange(xMin, xMax);

    plot->xAxis->setAutoTickStep(false);
    plot->xAxis->setTickStep(1);
    plot->xAxis->setSubTickCount(1);


    plot->xAxis2->setTickLength(0, 0);
    plot->xAxis2->setSubTickLength(0, 0);
    plot->xAxis2->setTickStep(false);
    plot->xAxis2->setAutoTickLabels(false);
    plot->xAxis2->setTickLabels(false);

    plot->yAxis2->setAutoTickStep(false);
    plot->yAxis2->setTickStep(1);
    plot->yAxis2->setSubTickCount(0);
    plot->yAxis2->setTickLength(3, 3);
    plot->yAxis2->setSubTickLength(0, 0);

    plot->graph(0)->setBrush(QBrush(QColor(255,200,20,70)));
}
void Highscore::addGraphForLastRunOfOnePerson(QCustomPlot *plot, Run r){
    int typePointsCount = r.typePoints.size();
    int xMin = -1;
    int xMax = typePointsCount+1;
    int yMin = 0;
    double yMax = 0;
    int yMaxErr = 0;

    QVector<double> x(typePointsCount), y(typePointsCount), y2(typePointsCount*11), x2(typePointsCount*11);
    for(int i = 0;i<typePointsCount;i++){
        y[i] = 1/ (r.typePoints.at(i).timeInMilliSeconds/60000.0);
        x[i] = i;
        yMax = std::max(y[i],yMax);
        for(double j = 0; j<11;j++){
            y2[11*i+j] =  r.typePoints.at(i).error;
            x2[11*i+j] =  (i-0.02)+(0.004*j);
        }
        yMaxErr = std::max(r.typePoints.at(i).error,yMaxErr);

    }
    plot->addGraph(plot->xAxis, plot->yAxis);
    plot->graph(0)->setName("Anschläge / Minute");
    plot->graph(0)->setData(x,y);
    plot->graph(0)->setLineStyle((QCPGraph::LineStyle)(1));
    plot->graph(0)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(1)));

    QPen graphPen;
    graphPen.setColor(QColor(200, 50, 0, 85));
    graphPen.setWidthF(2);
    plot->graph(0)->setPen(graphPen);

    plot->addGraph(plot->xAxis, plot->yAxis2);
    plot->graph(1)->setName("Fehler");
    plot->graph(1)->setData(x2,y2);
    plot->graph(1)->setLineStyle((QCPGraph::LineStyle)(5));

    QPen graphPen2;
    graphPen2.setColor(QColor(0, 50, 0, 100));
    graphPen2.setWidthF(3);
    plot->graph(1)->setPen(graphPen2);

    plot->yAxis2->setVisible(true);
    plot->xAxis2->setVisible(true);
    plot->xAxis->setVisible(true);

    plot->xAxis->setLabel("Durchlauf");
    plot->yAxis->setLabel("Anschläge pro Minute");
    plot->yAxis2->setLabel("Fehler");

    plot->xAxis->setRange(xMin, xMax);
    plot->yAxis->setRange(yMin, yMax+1);
    plot->yAxis2->setRange(yMin,yMaxErr*1.5 );
    plot->xAxis2->setRange(xMin, xMax);

    plot->xAxis->setAutoTickStep(false);
    plot->xAxis->setTickStep(1);
    plot->xAxis->setSubTickCount(1);


    plot->xAxis2->setTickLength(0, 0);
    plot->xAxis2->setSubTickLength(0, 0);
    plot->xAxis2->setTickStep(false);
    plot->xAxis2->setAutoTickLabels(false);
    plot->xAxis2->setTickLabels(false);

    plot->yAxis2->setAutoTickStep(false);
    plot->yAxis2->setTickStep(1);
    plot->yAxis2->setSubTickCount(0);
    plot->yAxis2->setTickLength(3, 3);
    plot->yAxis2->setSubTickLength(0, 0);

    plot->graph(0)->setBrush(QBrush(QColor(255,200,20,70)));
}
void Highscore::addGraphOneBestToOneActual(QCustomPlot *plot, Run rL, Run rB){

    plot->legend->setVisible(true);
    plot->legend->setFont(QFont("Helvetica",9));
    plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    int typePointsCount = rB.typePoints.size();
    int xMin = -1;
    int xMax = 101;
    int yMin = 0;
    double yMax = 0;
    int yMaxErr = 0;

    int s = 0;
    QVector<double> x(typePointsCount), y(typePointsCount), y2(typePointsCount*11), x2(typePointsCount*11);
    for(int i = 0;i<typePointsCount;i++){
        y[i] = 1/ (rB.typePoints.at(i).timeInMilliSeconds/60000.0);
        s = s+rB.typePoints.at(i).timeInMilliSeconds;
        x[i] = (s*100)/rB.runScoreTime;
        yMax = std::max(y[i],yMax);
        for(double j = 0; j<11;j++){
            y2[11*i+j] =  rB.typePoints.at(i).error;
            x2[11*i+j] =  (x[i]-0.02)+(0.004*j)+0.04;
        }
        yMaxErr = std::max(rB.typePoints.at(i).error,yMaxErr);

    }
    plot->addGraph(plot->xAxis, plot->yAxis);
    double d = rB.typePoints.size()/(rB.runScoreTime/60000.0);
    plot->graph(0)->setName("APM ");
    plot->graph(0)->setData(x,y);
    plot->graph(0)->setLineStyle((QCPGraph::LineStyle)(1));
    plot->graph(0)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(1)));

    QPen graphPen;
    graphPen.setColor(QColor(200, 50, 0, 85));
    graphPen.setWidthF(2);
    plot->graph(0)->setPen(graphPen);

    plot->addGraph(plot->xAxis, plot->yAxis2);
    plot->graph(1)->setName("Fehler");
    plot->graph(1)->setData(x2,y2);
    plot->graph(1)->setLineStyle((QCPGraph::LineStyle)(5));

    QPen graphPen1;
    graphPen1.setColor(QColor(200, 50, 0, 100));
    graphPen1.setWidthF(3);
    plot->graph(1)->setPen(graphPen1);

    //plot->graph(0)->setBrush(QBrush(QColor(255,200,20,70)));

    typePointsCount = rL.typePoints.size();

    s = 0;
    QVector<double> x3(typePointsCount), y3(typePointsCount), y4(typePointsCount*11), x4(typePointsCount*11);
    for(int i = 0;i<typePointsCount;i++){
        y3[i] = 1/ (rL.typePoints.at(i).timeInMilliSeconds/60000.0);
        s = s+rL.typePoints.at(i).timeInMilliSeconds;
        x3[i] = (s*100)/rL.runScoreTime;

        yMax = std::max(y3[i],yMax);
        for(double j = 0; j<11;j++){
            y4[11*i+j] =  rL.typePoints.at(i).error;
            x4[11*i+j] =  (x3[i]-0.02)+(0.004*j)-0.04;
        }
        yMaxErr = std::max(rL.typePoints.at(i).error,yMaxErr);

    }
    plot->addGraph(plot->xAxis, plot->yAxis);
    plot->graph(2)->setName("Anschläge / Minute");
    plot->graph(2)->setData(x3,y3);
    plot->graph(2)->setLineStyle((QCPGraph::LineStyle)(1));
    plot->graph(2)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(1)));

    QPen graphPen2;
    graphPen2.setColor(QColor(130, 30, 0, 85));
    graphPen2.setWidthF(2);
    plot->graph(2)->setPen(graphPen2);

    plot->addGraph(plot->xAxis, plot->yAxis2);
    plot->graph(3)->setName("Fehler");
    plot->graph(3)->setData(x4,y4);
    plot->graph(3)->setLineStyle((QCPGraph::LineStyle)(5));

    QPen graphPen3;
    graphPen3.setColor(QColor(130, 30, 0, 100));
    graphPen3.setWidthF(3);
    plot->graph(3)->setPen(graphPen3);

    plot->yAxis2->setVisible(true);
    plot->xAxis2->setVisible(true);
    plot->xAxis->setVisible(true);

    plot->xAxis->setLabel("Zeit in %");
    plot->yAxis->setLabel("Anschläge pro Minute");
    plot->yAxis2->setLabel("Fehler");

    plot->xAxis->setRange(xMin, xMax);
    plot->yAxis->setRange(yMin, yMax+1);
    plot->yAxis2->setRange(yMin,yMaxErr*1.5 );
    plot->xAxis2->setRange(xMin, xMax*1.2);

    plot->xAxis->setAutoTickStep(false);
    plot->xAxis->setTickStep(10);
    plot->xAxis->setSubTickCount(10);


    plot->xAxis2->setTickLength(0, 0);
    plot->xAxis2->setSubTickLength(0, 0);
    plot->xAxis2->setTickStep(false);
    plot->xAxis2->setAutoTickLabels(false);
    plot->xAxis2->setTickLabels(false);

    plot->yAxis2->setAutoTickStep(false);
    plot->yAxis2->setTickStep(1);
    plot->yAxis2->setSubTickCount(0);
    plot->yAxis2->setTickLength(3, 3);
    plot->yAxis2->setSubTickLength(0, 0);


    //plot->graph(0)->setBrush(QBrush(QColor(255,200,20,70)));
}
void Highscore::addGraphBestRunAllPersonsTopTen(QCustomPlot *plot, Persons p){

}




