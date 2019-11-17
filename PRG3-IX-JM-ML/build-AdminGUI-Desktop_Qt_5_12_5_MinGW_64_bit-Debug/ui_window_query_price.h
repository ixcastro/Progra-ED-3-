/********************************************************************************
** Form generated from reading UI file 'window_query_price.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_QUERY_PRICE_H
#define UI_WINDOW_QUERY_PRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_query_price
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QComboBox *halls;
    QLabel *label_2;
    QPushButton *pasilloButton;
    QComboBox *prods;
    QLabel *label_3;
    QPushButton *prodButton;
    QComboBox *marca;
    QLabel *label_4;
    QPushButton *marcaButton;
    QPushButton *pushButton;
    QPushButton *start;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_query_price)
    {
        if (window_query_price->objectName().isEmpty())
            window_query_price->setObjectName(QString::fromUtf8("window_query_price"));
        window_query_price->resize(481, 560);
        centralwidget = new QWidget(window_query_price);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 231, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 110, 211, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 211, 21));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 110, 201, 51));
        prods = new QComboBox(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(20, 210, 211, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 179, 211, 31));
        label_3->setFont(font1);
        prodButton = new QPushButton(centralwidget);
        prodButton->setObjectName(QString::fromUtf8("prodButton"));
        prodButton->setGeometry(QRect(250, 210, 201, 51));
        marca = new QComboBox(centralwidget);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setGeometry(QRect(20, 310, 211, 61));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 211, 21));
        label_4->setFont(font1);
        marcaButton = new QPushButton(centralwidget);
        marcaButton->setObjectName(QString::fromUtf8("marcaButton"));
        marcaButton->setGeometry(QRect(250, 310, 201, 61));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 490, 131, 31));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 20, 201, 51));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 390, 431, 81));
        window_query_price->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_query_price);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 481, 17));
        window_query_price->setMenuBar(menubar);
        statusbar = new QStatusBar(window_query_price);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_query_price->setStatusBar(statusbar);

        retranslateUi(window_query_price);

        QMetaObject::connectSlotsByName(window_query_price);
    } // setupUi

    void retranslateUi(QMainWindow *window_query_price)
    {
        window_query_price->setWindowTitle(QApplication::translate("window_query_price", "MainWindow", nullptr));
        label->setText(QApplication::translate("window_query_price", "Consulta precio", nullptr));
        label_2->setText(QApplication::translate("window_query_price", "Seleccione el pasillo", nullptr));
        pasilloButton->setText(QApplication::translate("window_query_price", "Seleccionar", nullptr));
        label_3->setText(QApplication::translate("window_query_price", "Seleccione el producto", nullptr));
        prodButton->setText(QApplication::translate("window_query_price", "Seleccionar", nullptr));
        label_4->setText(QApplication::translate("window_query_price", "Seleccione el marca", nullptr));
        marcaButton->setText(QApplication::translate("window_query_price", "Seleccionar", nullptr));
        pushButton->setText(QApplication::translate("window_query_price", "Atr\303\241s", nullptr));
        start->setText(QApplication::translate("window_query_price", "Iniciar consulta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_query_price: public Ui_window_query_price {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_QUERY_PRICE_H
