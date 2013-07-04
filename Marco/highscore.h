#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>

namespace Ui {
class highscore;
}

class highscore : public QDialog
{
    Q_OBJECT
    
public:
    explicit highscore(QWidget *parent = 0);
    ~highscore();
    
private:
    Ui::highscore *ui;
};

#endif // HIGHSCORE_H
