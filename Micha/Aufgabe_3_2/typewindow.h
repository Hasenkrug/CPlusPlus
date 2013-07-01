#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QDialog>

namespace Ui {

class Typewindow;
}

class Typewindow : public QDialog {
    Q_OBJECT
    
public:

    QString s;
    QStringList list;
    int errors;
    int hits;
    int position; //wird eig. nicht mehr gebraucht da es nicht mehr hochgezählt wird

    explicit Typewindow(QWidget *parent = 0, QString s = "");

    ~Typewindow();

    void keyPressEvent(QKeyEvent *e);
    // wichtig zum abfangen von space & enter
    bool eventFilter(QObject *object, QEvent *event);
    void lessonControl(QString k);
    void startLesson();
    bool checkInput(QString pressed);

    
public:
    Ui::Typewindow *ui;
};

#endif // TYPEWINDOW_H
