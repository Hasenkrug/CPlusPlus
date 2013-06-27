#include "typewindow.h"
#include "ui_typewindow.h"
#include "QKeyEvent"
#include "iostream"

Typewindow::Typewindow(QWidget *parent) : QDialog(parent), ui(new Ui::Typewindow) {
    ui->setupUi(this);    
}

Typewindow::~Typewindow() {
    delete ui;
}

void Typewindow::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_A) {
        ui->btnA->animateClick(100);
    } else if (e->key() == Qt::Key_B) {
        ui->btnB->animateClick(100);
    } else if (e->key() == Qt::Key_C) {
        ui->btnC->animateClick(100);
    } else if (e->key() == Qt::Key_D) {
        ui->btnD->animateClick(100);
    } else if (e->key() == Qt::Key_E) {
        ui->btnE->animateClick(100);
    } else if (e->key() == Qt::Key_F) {
        ui->btnF->animateClick(100);
    } else if (e->key() == Qt::Key_G) {
        ui->btnG->animateClick(100);
    } else if (e->key() == Qt::Key_H) {
        ui->btnH->animateClick(100);
    } else if (e->key() == Qt::Key_I) {
        ui->btnI->animateClick(100);
    } else if (e->key() == Qt::Key_J) {
        ui->btnJ->animateClick(100);
    } else if (e->key() == Qt::Key_K) {
        ui->btnK->animateClick(100);
    } else if (e->key() == Qt::Key_L) {
        ui->btnL->animateClick(100);
    } else if (e->key() == Qt::Key_M) {
        ui->btnM->animateClick(100);
    } else if (e->key() == Qt::Key_N) {
        ui->btnN->animateClick(100);
    } else if (e->key() == Qt::Key_O) {
        ui->btnO->animateClick(100);
    } else if (e->key() == Qt::Key_P) {
        ui->btnP->animateClick(100);
    } else if (e->key() == Qt::Key_Q) {
        ui->btnQ->animateClick(100);
    } else if (e->key() == Qt::Key_R) {
        ui->btnR->animateClick(100);
    } else if (e->key() == Qt::Key_S) {
        ui->btnS->animateClick(100);
    } else if (e->key() == Qt::Key_T) {
        ui->btnT->animateClick(100);
    } else if (e->key() == Qt::Key_U) {
        ui->btnU->animateClick(100);
    } else if (e->key() == Qt::Key_V) {
        ui->btnV->animateClick(100);
    } else if (e->key() == Qt::Key_W) {
        ui->btnW->animateClick(100);
    } else if (e->key() == Qt::Key_X) {
        ui->btnX->animateClick(100);
    } else if (e->key() == Qt::Key_Y) {
        ui->btnY->animateClick(100);
    } else if (e->key() == Qt::Key_Z) {
        ui->btnZ->animateClick(100);
    } else if (e->key() == 196) {
        ui->btnAe->animateClick(100);
    } else if (e->key() == 214) {
        ui->btnOe->animateClick(100);
    } else if (e->key() == 220) {
        ui->btnUe->animateClick(100);
    }
}

void Typewindow::showInput() {

}