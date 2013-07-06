#include "typewindow.h"
#include "ui_typewindow.h"
#include "QKeyEvent"
#include "QChar"
#include "iostream"
#include "QLCDNumber"

using namespace std;

Typewindow::Typewindow(QWidget *parent, QString string) :
    QDialog(parent), s(string), errors(0), hits(0), rowCount(0), doubleEvasion(0), ui(new Ui::Typewindow) {

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
        doubleEvasion++;
        if(ke->key() == Qt::Key_Space && doubleEvasion % 2 == 0) {
            ui->btnSpace->animateClick(100);
            lessonControl(" ");
            return true;
        } else if(ke->key() == Qt::Key_Return && doubleEvasion % 2 == 0) {
            ui->btnEnter->animateClick(100);
            lessonControl("¶");

            if(row.length() == 0) {
                nextRow();
                setKeyStyle();
            }

            return true;
        }
    }
    event->ignore();
    return false;
}

void Typewindow::nextRow() {
    if(rowCount < list.length()) {
        row = list.at(rowCount).toLower();
        rowCount++;
        ui->lessonText->setText(row);
        ui->lessonText->setCursorPosition(0);
    } else {
        rowCount = 0;
        mixList();
        nextRow();
    }
}

void Typewindow::startLesson(QStringList liste) {
    list = liste;
    nextRow();
    ui->lessonText->setText(row);
    ui->lessonText->setCursorPosition(0);
    setKeyStyle();
    timer.start();
}

void Typewindow::lessonControl(QString pressed) {       
    if(checkInput(pressed)) {
        ui->colorBox->setStyleSheet("QGroupBox{ background-color:#00ff00 }");
        hits++;
        row.remove(0,1);
        setKeyStyle();
        ui->lessonText->setText(row);
        ui->lessonText->setCursorPosition(0);
    } else {
        ui->colorBox->setStyleSheet("QGroupBox{ background-color:#ff0000 }");
        hits++;
        errors++;
    }
}

bool Typewindow::checkInput(QString key) {
    if(timer.elapsed() / 60000 < 1) {
        if( key != row.at(0) ) {
            return false;
        } else {
            return true;
        }
    } else { // Lesson ist fertig
        cout << "Anschläge: " << hits << endl;
        cout << "Fehler: " << errors << endl;
        cout << "Fehlerquote: " << (errors * 100) / hits << "%" << endl;
        cout << "APM: " << hits / (timer.elapsed() / 60000) << endl;
        Typewindow::close();
    }
    return false;
}

void Typewindow::mixList() {
    for(int i = 0; i < list.length(); i++) {
        int j = rand() % list.length();
        list.swap(i, j);
    }
}

void Typewindow::setKeyStyle() {
    if(row.startsWith("a")) {
        ui->btnA->setFocus();
    } else if(row.startsWith("e")) {
        ui->btnE->setFocus();
    } else if(row.startsWith("n")) {
        ui->btnN->setFocus();
    } else if(row.startsWith("r")) {
        ui->btnR->setFocus();
    } else if(row.startsWith("i")) {
        ui->btnI->setFocus();
    } else if(row.startsWith("s")) {
        ui->btnS->setFocus();
    } else if(row.startsWith("d")) {
        ui->btnD->setFocus();
    } else if(row.startsWith("f")) {
        ui->btnF->setFocus();
    } else if(row.startsWith("g")) {
        ui->btnG->setFocus();
    } else if(row.startsWith("h")) {
        ui->btnH->setFocus();
    } else if(row.startsWith("j")) {
        ui->btnJ->setFocus();
    } else if(row.startsWith("k")) {
        ui->btnK->setFocus();
    } else if(row.startsWith("l")) {
        ui->btnL->setFocus();
    } else if(row.startsWith("ö")) {
        ui->btnOe->setFocus();
    } else if(row.startsWith("ä")) {
        ui->btnAe->setFocus();
    } else if(row.startsWith(" ")) {
        ui->btnSpace->setFocus();
    } else if(row.startsWith("¶")) {
        ui->btnEnter->setFocus();
    }
}

void Typewindow::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_A) {
        ui->btnA->animateClick(100);
        lessonControl("a");
    } else if (e->key() == Qt::Key_B) {
        ui->btnB->animateClick(100);
        lessonControl("b");
    } else if (e->key() == Qt::Key_C) {
        ui->btnC->animateClick(100);
        lessonControl("c");
    } else if (e->key() == Qt::Key_D) {
        ui->btnD->animateClick(100);
        lessonControl("d");
    } else if (e->key() == Qt::Key_E) {
        ui->btnE->animateClick(100);
        lessonControl("e");
    } else if (e->key() == Qt::Key_F) {
        ui->btnF->animateClick(100);
        lessonControl("f");
    } else if (e->key() == Qt::Key_G) {
        ui->btnG->animateClick(100);
        lessonControl("g");
    } else if (e->key() == Qt::Key_H) {
        ui->btnH->animateClick(100);
        lessonControl("h");
    } else if (e->key() == Qt::Key_I) {
        ui->btnI->animateClick(100);
        lessonControl("i");
    } else if (e->key() == Qt::Key_J) {
        ui->btnJ->animateClick(100);
        lessonControl("j");
    } else if (e->key() == Qt::Key_K) {
        ui->btnK->animateClick(100);
        lessonControl("k");
    } else if (e->key() == Qt::Key_L) {
        ui->btnL->animateClick(100);
        lessonControl("l");
    } else if (e->key() == Qt::Key_M) {
        ui->btnM->animateClick(100);
        lessonControl("m");
    } else if (e->key() == Qt::Key_N) {
        ui->btnN->animateClick(100);
        lessonControl("n");
    } else if (e->key() == Qt::Key_O) {
        ui->btnO->animateClick(100);
        lessonControl("o");
    } else if (e->key() == Qt::Key_P) {
        ui->btnP->animateClick(100);
        lessonControl("p");
    } else if (e->key() == Qt::Key_Q) {
        ui->btnQ->animateClick(100);
        lessonControl("q");
    } else if (e->key() == Qt::Key_R) {
        ui->btnR->animateClick(100);
        lessonControl("r");
    } else if (e->key() == Qt::Key_S) {
        ui->btnS->animateClick(100);
        lessonControl("s");
    } else if (e->key() == Qt::Key_T) {
        ui->btnT->animateClick(100);
        lessonControl("t");
    } else if (e->key() == Qt::Key_U) {
        ui->btnU->animateClick(100);
        lessonControl("u");
    } else if (e->key() == Qt::Key_V) {
        ui->btnV->animateClick(100);
        lessonControl("v");
    } else if (e->key() == Qt::Key_W) {
        ui->btnW->animateClick(100);
        lessonControl("w");
    } else if (e->key() == Qt::Key_X) {
        ui->btnX->animateClick(100);
        lessonControl("x");
    } else if (e->key() == Qt::Key_Y) {
        ui->btnY->animateClick(100);
        lessonControl("y");
    } else if (e->key() == Qt::Key_Z) {
        ui->btnZ->animateClick(100);
        lessonControl("z");
    } else if (e->key() == 196) { // Ä
        ui->btnAe->animateClick(100);
        lessonControl("ä");
    } else if (e->key() == 214) { // Ö
        ui->btnOe->animateClick(100);
        lessonControl("ö");
    } else if (e->key() == 220) { // Ü
        ui->btnUe->animateClick(100);
        lessonControl("ü");
    }
//    else if(e->key() == Qt::Key_Space) {
//        ui->btnSpace->animateClick(100);
//        lessonControl(" ");
//    } else if(e->key() == Qt::Key_Return) {
//        ui->btnEnter->animateClick(100);
//        lessonControl("¶");
//        nextRow();
//    }
}
