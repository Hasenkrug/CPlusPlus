#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void setSearchText(QString value);
    QString getSearchText();
    void on_btnQuit_clicked();
    void saveInput();

private:
    Ui::MainWindow *ui;

    QString m_searchText;
};

#endif // MAINWINDOW_H
