#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QDialog>

namespace Ui {
class Typewindow;
}

class Typewindow : public QDialog {
    Q_OBJECT
    
public:
    explicit Typewindow(QWidget *parent = 0);
    ~Typewindow();

    void keyPressEvent(QKeyEvent *e);
    // wichtig zum abfangen von space & enter
    bool Typewindow::eventFilter(QObject *object, QEvent *event);
    
public:
    Ui::Typewindow *ui;
};

#endif // TYPEWINDOW_H
