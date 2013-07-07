#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QDialog>
#include <QTime>
#include "person.h"

namespace Ui {
class Typewindow;
}

class Typewindow : public QDialog {
    Q_OBJECT
    
public:
    Person *p;
    Run *r;
    QString s;
    QString row;
    QStringList list;
    int errors;
    int hits;
    int rowCount;
    bool timelimit;
    int limit;
    int doubleEvasion; // wird im eventFilter "benötigt"
    QTime timer;
    int timeStamp;

    explicit Typewindow(QWidget *parent = 0, QString s = "");

    ~Typewindow();

    void keyPressEvent(QKeyEvent *e);
    // wichtig zum abfangen von space & enter
    bool eventFilter(QObject *object, QEvent *event);
    void lessonControl(QString k);
    void startLesson(QStringList liste, bool tl, int l);
    void nextRow();
    bool checkInput(QString pressed);
    void mixList();
    void setKeyStyle();
    void setUser(std::string u,int c);

    
public:
    Ui::Typewindow *ui;
};

#endif // TYPEWINDOW_H
