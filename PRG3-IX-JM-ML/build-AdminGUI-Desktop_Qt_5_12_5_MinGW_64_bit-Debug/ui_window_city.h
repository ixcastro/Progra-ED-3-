/********************************************************************************
** Form generated from reading UI file 'window_city.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_CITY_H
#define UI_WINDOW_CITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_city
{
public:
    QWidget *centralwidget;
    QPushButton *insertarPas_2;
    QPushButton *insertarPas_4;
    QLabel *label;
    QPushButton *back;
    QPushButton *insertarPas_3;
    QPushButton *insertarPas;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_city)
    {
        if (window_city->objectName().isEmpty())
            window_city->setObjectName(QString::fromUtf8("window_city"));
        window_city->resize(939, 480);
        centralwidget = new QWidget(window_city);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        insertarPas_2 = new QPushButton(centralwidget);
        insertarPas_2->setObjectName(QString::fromUtf8("insertarPas_2"));
        insertarPas_2->setGeometry(QRect(20, 120, 441, 71));
        insertarPas_4 = new QPushButton(centralwidget);
        insertarPas_4->setObjectName(QString::fromUtf8("insertarPas_4"));
        insertarPas_4->setGeometry(QRect(20, 300, 441, 71));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(500, 30, 201, 31));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 390, 171, 41));
        insertarPas_3 = new QPushButton(centralwidget);
        insertarPas_3->setObjectName(QString::fromUtf8("insertarPas_3"));
        insertarPas_3->setGeometry(QRect(20, 210, 441, 71));
        insertarPas = new QPushButton(centralwidget);
        insertarPas->setObjectName(QString::fromUtf8("insertarPas"));
        insertarPas->setGeometry(QRect(20, 30, 441, 71));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(500, 60, 411, 341));
        window_city->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_city);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 939, 17));
        window_city->setMenuBar(menubar);
        statusbar = new QStatusBar(window_city);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_city->setStatusBar(statusbar);

        retranslateUi(window_city);

        QMetaObject::connectSlotsByName(window_city);
    } // setupUi

    void retranslateUi(QMainWindow *window_city)
    {
        window_city->setWindowTitle(QApplication::translate("window_city", "MainWindow", nullptr));
        insertarPas_2->setText(QApplication::translate("window_city", "Kruskal", nullptr));
        insertarPas_4->setText(QApplication::translate("window_city", "Puntos de articuulaci\303\263n", nullptr));
        label->setText(QApplication::translate("window_city", "Algoritmo", nullptr));
        back->setText(QApplication::translate("window_city", "Atr\303\241s", nullptr));
        insertarPas_3->setText(QApplication::translate("window_city", "Dijkstra", nullptr));
        insertarPas->setText(QApplication::translate("window_city", "Prim", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_city: public Ui_window_city {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CITY_H
