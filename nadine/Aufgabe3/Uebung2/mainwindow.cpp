#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     connect(ui->startLessonButton, SIGNAL(clicked()), this, SLOT(startLessonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startLessonClicked()
{
    //TODO Fensterwechsel zu lesson.ui
}
