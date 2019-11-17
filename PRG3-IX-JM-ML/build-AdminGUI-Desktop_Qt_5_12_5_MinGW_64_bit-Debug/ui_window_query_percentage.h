/********************************************************************************
** Form generated from reading UI file 'window_query_percentage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_QUERY_PERCENTAGE_H
#define UI_WINDOW_QUERY_PERCENTAGE_H

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

class Ui_window_query_percentage
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

    void setupUi(QMainWindow *window_query_percentage)
    {
        if (window_query_percentage->objectName().isEmpty())
            window_query_percentage->setObjectName(QString::fromUtf8("window_query_percentage"));
        window_query_percentage->resize(480, 584);
        centralwidget = new QWidget(window_query_percentage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 120, 211, 51));
        prodButton = new QPushButton(centralwidget);
        prodButton->setObjectName(QString::fromUtf8("prodButton"));
        prodButton->setGeometry(QRect(250, 220, 201, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 500, 131, 31));
        marcaButton = new QPushButton(centralwidget);
        marcaButton->setObjectName(QString::fromUtf8("marcaButton"));
        marcaButton->setGeometry(QRect(250, 320, 201, 61));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 211, 21));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 290, 211, 21));
        label_4->setFont(font);
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 120, 201, 51));
        prods = new QComboBox(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(20, 220, 211, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 261, 41));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        marca = new QComboBox(centralwidget);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setGeometry(QRect(20, 320, 211, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 189, 211, 31));
        label_3->setFont(font);
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 30, 201, 51));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 410, 431, 81));
        window_query_percentage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_query_percentage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 17));
        window_query_percentage->setMenuBar(menubar);
        statusbar = new QStatusBar(window_query_percentage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_query_percentage->setStatusBar(statusbar);

        retranslateUi(window_query_percentage);

        QMetaObject::connectSlotsByName(window_query_percentage);
    } // setupUi

    void retranslateUi(QMainWindow *window_query_percentage)
    {
        window_query_percentage->setWindowTitle(QApplication::translate("window_query_percentage", "MainWindow", nullptr));
        prodButton->setText(QApplication::translate("window_query_percentage", "Seleccionar", nullptr));
        pushButton->setText(QApplication::translate("window_query_percentage", "Atr\303\241s", nullptr));
        marcaButton->setText(QApplication::translate("window_query_percentage", "Seleccionar", nullptr));
        label_2->setText(QApplication::translate("window_query_percentage", "Seleccione el pasillo", nullptr));
        label_4->setText(QApplication::translate("window_query_percentage", "Seleccione el marca", nullptr));
        pasilloButton->setText(QApplication::translate("window_query_percentage", "Seleccionar", nullptr));
        label->setText(QApplication::translate("window_query_percentage", "Consulta procentaje", nullptr));
        label_3->setText(QApplication::translate("window_query_percentage", "Seleccione el producto", nullptr));
        start->setText(QApplication::translate("window_query_percentage", "Iniciar consulta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_query_percentage: public Ui_window_query_percentage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_QUERY_PERCENTAGE_H
