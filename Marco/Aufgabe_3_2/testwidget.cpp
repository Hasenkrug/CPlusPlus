#include "testwidget.h"


TestWidget::TestWidget(QWidget* parent) : QWidget(parent){
    QVBoxLayout *layout = new QVBoxLayout();
    m_ple = new QLineEdit();
    m_ppb = new QPushButton("Insert");
    m_slData.append("Test String");
    m_plv = new QListView();
    m_plv->setModel(new QStringListModel(m_slData));
    layout->addWidget(m_plv);
    layout->addWidget(m_ple);
    layout->addWidget(m_ppb);
    setLayout(layout);

    QObject::connect(m_ppb, SIGNAL(clicked()), this, SLOT(processClicked()));
}

void TestWidget::processClicked() {
    m_slData.append(m_ple->text());
    ((QStringListModel*) m_plv->model())->setStringList(m_slData);

//I guess here needs to happen more
}


