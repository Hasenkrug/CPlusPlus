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
        std::cout << "A" << std::endl;
    } else if (e->key() == Qt::Key_B) {
        std::cout << "B" << std::endl;
    } else if (e->key() == Qt::Key_C) {
        std::cout << "C" << std::endl;
    } else if (e->key() == Qt::Key_D) {
        std::cout << "D" << std::endl;
    } else if (e->key() == Qt::Key_E) {
        std::cout << "E" << std::endl;
    } else if (e->key() == Qt::Key_F) {
        std::cout << "F" << std::endl;
    } else if (e->key() == Qt::Key_G) {
        std::cout << "G" << std::endl;
    } else if (e->key() == Qt::Key_H) {
        std::cout << "H" << std::endl;
    } else if (e->key() == Qt::Key_I) {
        std::cout << "I" << std::endl;
    } else if (e->key() == Qt::Key_J) {
        std::cout << "J" << std::endl;
    } else if (e->key() == Qt::Key_K) {
        std::cout << "K" << std::endl;
    } else if (e->key() == Qt::Key_L) {
        std::cout << "L" << std::endl;
    } else if (e->key() == Qt::Key_M) {
        std::cout << "M" << std::endl;
    } else if (e->key() == Qt::Key_N) {
        std::cout << "N" << std::endl;
    } else if (e->key() == Qt::Key_O) {
        std::cout << "O" << std::endl;
    } else if (e->key() == Qt::Key_P) {
        std::cout << "P" << std::endl;
    } else if (e->key() == Qt::Key_Q) {
        std::cout << "Q" << std::endl;
    } else if (e->key() == Qt::Key_R) {
        std::cout << "R" << std::endl;
    } else if (e->key() == Qt::Key_S) {
        std::cout << "S" << std::endl;
    } else if (e->key() == Qt::Key_T) {
        std::cout << "T" << std::endl;
    } else if (e->key() == Qt::Key_U) {
        std::cout << "U" << std::endl;
    } else if (e->key() == Qt::Key_V) {
        std::cout << "V" << std::endl;
    } else if (e->key() == Qt::Key_W) {
        std::cout << "W" << std::endl;
    } else if (e->key() == Qt::Key_X) {
        std::cout << "X" << std::endl;
    } else if (e->key() == Qt::Key_Y) {
        std::cout << "Y" << std::endl;
    } else if (e->key() == Qt::Key_Z) {
        std::cout << "Z" << std::endl;
    } else if (e->key() == 196) {
        std::cout << "Ä" << std::endl;
    } else if (e->key() == 214) {
        std::cout << "Ö" << std::endl;
    } else if (e->key() == 220) {
        std::cout << "Ü" << std::endl;
    }
}
