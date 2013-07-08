/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORE_H
#define UI_HIGHSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Highscore
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QCustomPlot *plot0;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QCustomPlot *plot1;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QCustomPlot *plot2;

    void setupUi(QDialog *Highscore)
    {
        if (Highscore->objectName().isEmpty())
            Highscore->setObjectName(QStringLiteral("Highscore"));
        Highscore->resize(970, 520);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Highscore->sizePolicy().hasHeightForWidth());
        Highscore->setSizePolicy(sizePolicy);
        Highscore->setMinimumSize(QSize(456, 229));
        Highscore->setMaximumSize(QSize(16777215, 16777215));
        Highscore->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(Highscore);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(Highscore);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setRowCount(10);
        tableWidget->horizontalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(Highscore);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        sizePolicy2.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy2);
        tab->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        plot0 = new QCustomPlot(tab);
        plot0->setObjectName(QStringLiteral("plot0"));
        sizePolicy2.setHeightForWidth(plot0->sizePolicy().hasHeightForWidth());
        plot0->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(plot0, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        sizePolicy2.setHeightForWidth(tab_3->sizePolicy().hasHeightForWidth());
        tab_3->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        plot1 = new QCustomPlot(tab_3);
        plot1->setObjectName(QStringLiteral("plot1"));
        sizePolicy2.setHeightForWidth(plot1->sizePolicy().hasHeightForWidth());
        plot1->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(plot1, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy2.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        plot2 = new QCustomPlot(tab_2);
        plot2->setObjectName(QStringLiteral("plot2"));
        sizePolicy2.setHeightForWidth(plot2->sizePolicy().hasHeightForWidth());
        plot2->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(plot2, 0, 0, 1, 1);

        QIcon icon;
        QString iconThemeName = QStringLiteral("sxsx");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        tabWidget->addTab(tab_2, icon, QString());

        horizontalLayout->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Highscore);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Highscore);
    } // setupUi

    void retranslateUi(QDialog *Highscore)
    {
        Highscore->setWindowTitle(QApplication::translate("Highscore", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Highscore", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Highscore", "Score", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Highscore", "Historie", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Highscore", "Chart1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Highscore", "Chart2", 0));
    } // retranslateUi

};

namespace Ui {
    class Highscore: public Ui_Highscore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
