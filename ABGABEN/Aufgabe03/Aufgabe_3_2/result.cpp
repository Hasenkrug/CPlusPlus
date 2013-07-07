#include "result.h"
#include "ui_result.h"
#include "highscore.h"
#include "person.h"

Result::Result(QWidget *parent, Person *p) :
    QDialog(parent),
    person(p),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    connect(ui->statistik, SIGNAL(clicked()), this, SLOT(resultButtonClicked()));


}

Result::~Result()
{
    delete ui;
}

void Result::fillLabels(QString hits, QString hitsPerMinute, QString totalErrors, QString errorQuote, QString points){
   ui->hits->setText(hits);
   ui->apm->setText(hitsPerMinute);
   ui->totalErrors->setText(totalErrors);
   ui->errorQuote->setText(QString(errorQuote) + QString("%"));
   ui->points->setText(points);


}

void Result::resultButtonClicked()
{
    Highscore* s = new Highscore(this);
    s->initHighScore(person);
    s->installEventFilter(s);
    s->show();
}
