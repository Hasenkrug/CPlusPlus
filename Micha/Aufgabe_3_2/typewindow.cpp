#include "typewindow.h"
#include "ui_typewindow.h"
#include "QKeyEvent"
#include "QChar"
#include "iostream"



Typewindow::Typewindow(QWidget *parent, QString string) :
    QDialog(parent), s(string), position(0), ui(new Ui::Typewindow) {

    ui->setupUi(this);    
    //setFocusPolicy(Qt::StrongFocus);
}

Typewindow::~Typewindow() {
    delete ui;
}

// wichtig zum abfangen von space & enter
bool Typewindow::eventFilter(QObject *object, QEvent *event) {
    // 51 = QEvent::ShortcutOverride - Key press in child, for overriding shortcut key handling (QKeyEvent)
    if(event->type() == 51 && object == this) {
        const QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        if(ke->key() == Qt::Key_Space) {
            std::cout << "typewindow.cpp, line 20: das hier wird 'noch' 2x ausgeführt >.<" << std::endl;
            ui->btnSpace->animateClick(100);
            return true;
        } else if(ke->key() == Qt::Key_Return) {
            std::cout << "typewindow.cpp, line 24: das hier wird 'noch' 2x ausgeführt >.<" << std::endl;
            ui->btnEnter->animateClick(100);
            return true;
        }
    }
    event->ignore();
    return false;
}

void Typewindow::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_A) {        
        ui->btnA->animateClick(100);
        checkInput("A");
    } else if (e->key() == Qt::Key_B) {
        ui->btnB->animateClick(100);
        checkInput("B");
    } else if (e->key() == Qt::Key_C) {
        ui->btnC->animateClick(100);
        checkInput("C");
    } else if (e->key() == Qt::Key_D) {
        ui->btnD->animateClick(100);        
        checkInput("D");
    } else if (e->key() == Qt::Key_E) {
        ui->btnE->animateClick(100);
        checkInput("E");
    } else if (e->key() == Qt::Key_F) {
        ui->btnF->animateClick(100);        
        checkInput("F");
    } else if (e->key() == Qt::Key_G) {
        ui->btnG->animateClick(100);
        checkInput("G");
    } else if (e->key() == Qt::Key_H) {
        ui->btnH->animateClick(100);
        checkInput("H");
    } else if (e->key() == Qt::Key_I) {
        ui->btnI->animateClick(100);
        checkInput("I");
    } else if (e->key() == Qt::Key_J) {
        ui->btnJ->animateClick(100);
        checkInput("J");
    } else if (e->key() == Qt::Key_K) {
        ui->btnK->animateClick(100);
        checkInput("K");
    } else if (e->key() == Qt::Key_L) {
        ui->btnL->animateClick(100);
        checkInput("L");
    } else if (e->key() == Qt::Key_M) {
        ui->btnM->animateClick(100);
        checkInput("M");
    } else if (e->key() == Qt::Key_N) {
        ui->btnN->animateClick(100);
        checkInput("N");
    } else if (e->key() == Qt::Key_O) {
        ui->btnO->animateClick(100);
        checkInput("O");
    } else if (e->key() == Qt::Key_P) {
        ui->btnP->animateClick(100);
        checkInput("P");
    } else if (e->key() == Qt::Key_Q) {
        ui->btnQ->animateClick(100);
        checkInput("Q");
    } else if (e->key() == Qt::Key_R) {
        ui->btnR->animateClick(100);
        checkInput("R");
    } else if (e->key() == Qt::Key_S) {
        ui->btnS->animateClick(100);
        checkInput("S");
    } else if (e->key() == Qt::Key_T) {
        ui->btnT->animateClick(100);
        checkInput("T");
    } else if (e->key() == Qt::Key_U) {
        ui->btnU->animateClick(100);
        checkInput("U");
    } else if (e->key() == Qt::Key_V) {
        ui->btnV->animateClick(100);
        checkInput("V");
    } else if (e->key() == Qt::Key_W) {
        ui->btnW->animateClick(100);
        checkInput("W");
    } else if (e->key() == Qt::Key_X) {
        ui->btnX->animateClick(100);
        checkInput("X");
    } else if (e->key() == Qt::Key_Y) {
        ui->btnY->animateClick(100);
        checkInput("Y");
    } else if (e->key() == Qt::Key_Z) {
        ui->btnZ->animateClick(100);
        checkInput("Z");
    } else if (e->key() == 196) { // Ä
        ui->btnAe->animateClick(100);
        checkInput("Ä");
    } else if (e->key() == 214) { // Ö
        ui->btnOe->animateClick(100);        
        checkInput("Ö");
    } else if (e->key() == 220) { // Ü
        ui->btnUe->animateClick(100);
        checkInput("Ü");
    } else if(e->key() == Qt::Key_Space) {
        ui->btnSpace->animateClick(100);
        checkInput(" ");
    }
}

void Typewindow::setText() {

    //std::cout << s.toStdString() << std::endl;

    ui->lessonText->setText(s);
}

bool Typewindow::checkInput(QString pressed) {

    //std::cout << "gedrück: " << pressed.toStdString() << " erwartet: "  << s.at(position).toLatin1() << std::endl;

    if( position < s.length() - 1 ) {

        if( pressed != s.at(position) ) {
            ui->label->setStyleSheet("QLabel{ background-color:red }");
        } else {
            ui->label->setStyleSheet("QLabel{ background-color:green }");
            s.remove(0,1);
            setText();
        }

    } else {

        Typewindow::close();
    }

    return true;
}
