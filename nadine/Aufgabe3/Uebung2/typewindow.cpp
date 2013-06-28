#include "typewindow.h"
#include "ui_typewindow.h"

Typewindow::Typewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Typewindow)
{
    ui->setupUi(this);
}

Typewindow::~Typewindow()
{
    delete ui;
}
