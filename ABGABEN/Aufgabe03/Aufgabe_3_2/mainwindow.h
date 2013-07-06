#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:    

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void startLessonClicked();

private:
    int c;
    std::string u;
    Ui::MainWindow *ui;
    QStringList getEasyString();
    QStringList getMediumString();
    QString getHardString();
};

#endif // MAINWINDOW_H
