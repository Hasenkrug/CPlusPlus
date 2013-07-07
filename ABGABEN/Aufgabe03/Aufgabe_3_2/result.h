#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include "person.h"

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT
    
public:
    explicit Result(QWidget *parent = 0, Person *p = 0);
    ~Result();

    Person *person;
    void fillLabels(QString hits, QString hitsPerMinute, QString totalErrors, QString errorQuote, QString points);
    
public:
    Ui::Result *ui;

private slots:
    void resultButtonClicked();
};

#endif // RESULT_H
