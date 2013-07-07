#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "typewindow.h"
#include "ui_typewindow.h"
#include "iostream"
#include "QKeyEvent"

using namespace std;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), u(""), c(0) {

    ui->setupUi(this);
    connect(ui->startLessonButton, SIGNAL(clicked()), this, SLOT(startLessonClicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

QStringList MainWindow::getEasyString() {
    u = "marco";
    c = 0;
    QString a("asdf jklö lass all salsa la da fass ja kalk¶");
    QString b("as skala saal das kafka öl la asdf jklö da¶");
    QString c("als ja fall as las saal jölö kafka alf la¶");
    QString d("kalk da fasd kja falls flak as klös als dj¶");
    QString e("skala jölö saal da all ja falls das öl fad¶");
    QString f("salsa dj kafka jölö klös da alf ja das dsl¶");
    QString g("falls öl fad dj fass jölö flak lös kafka ja¶");
    QString h("das klös as öl kalk fall saal la skala jölö¶");

//    QString a("asdf¶");
//    QString b("as¶");
//    QString c("als¶");
//    QString d("kalk¶");
//    QString e("skala¶");
//    QString f("salsa¶");
//    QString g("falls¶");
//    QString h("das¶");

    QStringList st;

    st.append(a);
    st.append(b);
    st.append(c);
    st.append(d);
    st.append(e);
    st.append(f);
    st.append(g);
    st.append(h);

    return st;
}

QStringList MainWindow::getMediumString() {
    u= "marco";
    c = 1;
    QString a("freier fördern friede kreis seiner rief¶");
    QString b("radikalen frei irren freie leider riefen¶");
    QString c("er fördern erinnern freier freien rief¶");
    QString d("riri irir fördern darin kreis drei kinder¶");
    QString e("riefen kreise kleinere keiner reisen¶");
    QString f("klarer rinnen fördern nieder kreis nie¶");
    QString g("kinder allerlei kreise innere keiner¶");
    QString h("kleiner klarer kleineren fördern freier¶");
    QString i("kreis leider kinder derer kreis aneinander¶");
    QString j("keiner anderer klarer allerlei fördern¶");
    QString k("nie kreis risse kinder riefen kreise¶");
    QString l("definieren keiner friedens klarer leider¶");
    QString m("fördern leiser kreis drin kinder einer¶");
    QString n("kreise rinnen keiner realisieren klarer¶");

    QStringList st;

    st.append(a);
    st.append(b);
    st.append(c);
    st.append(d);
    st.append(e);
    st.append(f);
    st.append(g);
    st.append(h);
    st.append(i);
    st.append(j);
    st.append(k);
    st.append(l);
    st.append(m);
    st.append(n);

    return st;
}

QString MainWindow::getHardString() {
    u = "marco";
    c = 2;
    QString s[] = { "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "Y", "X", "C", "V", "B", "N", "M", "1", "2", "3", "5", "6", "7", "8", "9", "0"};
    QString st = "";

    for(int i = 0; i < 40; i++) {
        st = st + s[rand() % 37];
    }

    return st;
}

void MainWindow::startLessonClicked() {    
    Typewindow* t = new Typewindow(this);
    t->setUser(u, c);
    int limit = ui->timeBox->value();

    if (ui->easy->isChecked()) {        
        // wichtig zum abfangen von space & enter
        t->installEventFilter(t);

        t->startLesson(getEasyString(), limit);
        t->show();
    } else if (ui->medium->isChecked()) {
        // wichtig zum abfangen von space & enter
        t->installEventFilter(t);

        t->startLesson(getMediumString(), limit);
        t->show();
    } /*else if (ui->hard->isChecked()) {
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
