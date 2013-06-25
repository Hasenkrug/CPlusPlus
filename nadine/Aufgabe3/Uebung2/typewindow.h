#ifndef TYPEWINDOW_H
#define TYPEWINDOW_H

#include <QDialog>

namespace Ui {
class Typewindow;
}

class Typewindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit Typewindow(QWidget *parent = 0);
    ~Typewindow();
    
public:
    Ui::Typewindow *ui;
};

#endif // TYPEWINDOW_H
