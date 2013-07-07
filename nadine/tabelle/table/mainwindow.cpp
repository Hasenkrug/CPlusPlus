#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setItem(2,5,new QTableWidgetItem("Item1"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
