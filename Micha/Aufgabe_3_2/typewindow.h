#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QDialog>
#include <QTime>

namespace Ui {

class Typewindow;
}

class Typewindow : public QDialog {
    Q_OBJECT
    
public:

    QString s;
    QString row;
    QStringList list;
    int errors;
    int hits;
    int rowCount;
    int doubleEvasion; // wird im eventFilter "benötigt"
    int limit;
    QTime timer;

    explicit Typewindow(QWidget *parent = 0, QString s = "");

    ~Typewindow();

    void keyPressEvent(QKeyEvent *e);
    // wichtig zum abfangen von space & enter
    bool eventFilter(QObject *object, QEvent *event);
    void lessonControl(QString k);
    void startLesson(QStringList liste, int l);
    void nextRow();
    bool checkInput(QString pressed);
    void mixList();
    void setKeyStyle();

    
public:
    Ui::Typewindow *ui;
};

#endif // TYPEWINDOW_H
