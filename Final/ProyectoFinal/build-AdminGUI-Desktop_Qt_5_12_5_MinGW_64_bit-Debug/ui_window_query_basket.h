/********************************************************************************
** Form generated from reading UI file 'window_query_basket.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_QUERY_BASKET_H
#define UI_WINDOW_QUERY_BASKET_H

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

class Ui_window_query_basket
{
public:
    QWidget *centralwidget;
    QComboBox *halls;
    QPushButton *prodButton;
    QPushButton *pushButton;
    QPushButton *marcaButton;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pasilloButton;
    QComboBox *prods;
    QLabel *label;
    QComboBox *marca;
    QLabel *label_3;
    QPushButton *start;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_query_basket)
    {
        if (window_query_basket->objectName().isEmpty())
            window_query_basket->setObjectName(QString::fromUtf8("window_query_basket"));
        window_query_basket->resize(800, 600);
        centralwidget = new QWidget(window_query_basket);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 121, 211, 51));
        prodButton = new QPushButton(centralwidget);
        prodButton->setObjectName(QString::fromUtf8("prodButton"));
        prodButton->setGeometry(QRect(250, 221, 201, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 501, 131, 31));
        marcaButton = new QPushButton(centralwidget);
        marcaButton->setObjectName(QString::fromUtf8("marcaButton"));
        marcaButton->setGeometry(QRect(250, 321, 201, 61));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 91, 211, 21));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 291, 211, 21));
        label_4->setFont(font);
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 121, 201, 51));
        prods = new QComboBox(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(20, 221, 211, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 21, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        marca = new QComboBox(centralwidget);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setGeometry(QRect(20, 321, 211, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 190, 211, 31));
        label_3->setFont(font);
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 31, 201, 51));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 400, 431, 81));
        window_query_basket->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_query_basket);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        window_query_basket->setMenuBar(menubar);
        statusbar = new QStatusBar(window_query_basket);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_query_basket->setStatusBar(statusbar);

        retranslateUi(window_query_basket);

        QMetaObject::connectSlotsByName(window_query_basket);
    } // setupUi

    void retranslateUi(QMainWindow *window_query_basket)
    {
        window_query_basket->setWindowTitle(QApplication::translate("window_query_basket", "MainWindow", nullptr));
        prodButton->setText(QApplication::translate("window_query_basket", "Seleccionar", nullptr));
        pushButton->setText(QApplication::translate("window_query_basket", "Atr\303\241s", nullptr));
        marcaButton->setText(QApplication::translate("window_query_basket", "Seleccionar", nullptr));
        label_2->setText(QApplication::translate("window_query_basket", "Seleccione el pasillo", nullptr));
        label_4->setText(QApplication::translate("window_query_basket", "Seleccione el marca", nullptr));
        pasilloButton->setText(QApplication::translate("window_query_basket", "Seleccionar", nullptr));
        label->setText(QApplication::translate("window_query_basket", "Consulta si pertenece a canasta basica", nullptr));
        label_3->setText(QApplication::translate("window_query_basket", "Seleccione el producto", nullptr));
        start->setText(QApplication::translate("window_query_basket", "Iniciar consulta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_query_basket: public Ui_window_query_basket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_QUERY_BASKET_H
