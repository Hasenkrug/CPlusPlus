#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow) {
        ui->setupUi(this);

        connect(ui->inputField, SIGNAL(textChanged(QString)), this, SLOT(getSearchText(QString)));
    }

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::getSearchText(QString value) {

    m_searchText = value;

    cout << m_searchText.toStdString() << endl;
}

void MainWindow::on_btnQuit_clicked() {

    QWidget *dialog = new QWidget();
    dialog->setWindowTitle("Quit and Save");

    QPushButton *cancel = new QPushButton("Abbruch");
    QPushButton *save = new QPushButton("Speichern");
    QPushButton *quit = new QPushButton("Applikation beenden");

    QObject::connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));

    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(quit, SIGNAL(clicked()), dialog, SLOT(close()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(cancel);
    layout->addWidget(save);
    layout->addWidget(quit);

    dialog->setLayout(layout);
    dialog->show();
}
