#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QApplication>
#include <QVBoxLayout>
#include <QListView>
#include <QLineEdit>
#include <QPushButton>
#include <QStringList>
#include <QStringListModel>

class TestWidget : public QWidget {

    Q_OBJECT

private:
    QListView*   m_plv;
    QLineEdit*   m_ple;
    QPushButton* m_ppb;
    QStringList  m_slData;
public:
    TestWidget(QWidget* parent = 0);

public slots:
    void processClicked();
};

#endif
