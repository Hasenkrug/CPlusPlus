#include "dialog.h"
#include "ui_dialog.h"
#include "iostream"

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->searchText, SIGNAL(textChanged(QString)),
            this, SLOT(getSearchText(QString)));

    connect(ui->closeButton, SIGNAL(clicked()),
            this, SLOT(clickedCloseButton()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::getSearchText(QString s) {
    cout << "Ausgabe: " << s.toStdString() << endl;
}

void Dialog::clickedCloseButton()
{
    ui(new Ui::Dialog)
}
