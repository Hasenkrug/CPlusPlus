#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "typewindow.h"
#include "ui_typewindow.h"
#include "iostream"
#include "QKeyEvent"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    connect(ui->startLessonButton, SIGNAL(clicked()), this, SLOT(startLessonClicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

QString getEasyString() {
//    QString s[] = { "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä" };
//    QString st = "";

//    // ACHTUNG von 40 auf 10 geändert (zum testen)
//    for(int i = 0; i < 10; i++) {
//        st = st + s[rand() % 10];
//    }

    QString s("ASDF JKLÖ LASS ALL SALSA LA DA FASS JA KALK AS SKALA SAAL DAS KAFKA ÖL LA ASDF JKLÖ DA ALS JA FALL AS LAS SAAL JÖLÖ KAFKA ALF LA KALK DA FASD KJA FALLS FLAK AS KLÖS ALS DJ SKALA JÖLÖ SAAL DA ALL JA FALLS DAS ÖL FAD SALSA DJ KAFKA JÖLÖ KLÖS DA ALF JA DAS DSL FALLS ÖL FAD DJ FASS JÖLÖ FLAK LÖS KAFKA JA DAS KLÖS AS ÖL KALK");
    QString st;
    QStringList list = s.toLower().split(" ");

    for(int i = 0; i < list.length(); i++) {
        if(i == list.length()-1) {
            st += list[rand() % 75];
        } else {
            st += list[rand() % 75] + QString(" ");
        }
    }

    return st;
}

QString getMediumString() {
    QString s[] = { "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü"};
    QString st = "";

    for(int i = 0; i < 40; i++) {
        st = st + s[rand() % 21];
    }

    return st;
}

QString getHardString() {
    QString s[] = { "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "Y", "X", "C", "V", "B", "N", "M", "1", "2", "3", "5", "6", "7", "8", "9", "0"};
    QString st = "";

    for(int i = 0; i < 40; i++) {
        st = st + s[rand() % 37];
    }

    return st;
}

void MainWindow::startLessonClicked() {    

    if (ui->easy->isChecked()) {
        Typewindow* t = new Typewindow(this, getEasyString());
        // wichtig zum abfangen von space & enter
        t->installEventFilter(t);

        t->startLesson();
        t->show();

    } /* else if (ui->medium->isChecked()) {
        t->ui->lessonText->setText(getMediumString());
        t->show();
    } else if (ui->hard->isChecked()) {
        t->ui->lessonText->setText(getHardString());
        t->show();
    } */ else {
        QWidget *dialog = new QWidget();
        dialog->setWindowTitle("Achtung");
        QLabel *label = new QLabel("Bitte wähle erst die Schwierigkeit!");

        QPushButton *ok = new QPushButton("OK");
        QObject::connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(label);
        layout->addWidget(ok);

        dialog->setLayout(layout);
        dialog->show();
    }
}
