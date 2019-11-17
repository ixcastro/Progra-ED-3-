/********************************************************************************
** Form generated from reading UI file 'window_report_moresoldprod.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_REPORT_MORESOLDPROD_H
#define UI_WINDOW_REPORT_MORESOLDPROD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_report_moreSoldProd
{
public:
    QWidget *centralwidget;
    QPushButton *start;
    QPushButton *save;
    QComboBox *halls;
    QLabel *label;
    QLabel *label_2;
    QPushButton *back;
    QPushButton *pasilloButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_report_moreSoldProd)
    {
        if (window_report_moreSoldProd->objectName().isEmpty())
            window_report_moreSoldProd->setObjectName(QString::fromUtf8("window_report_moreSoldProd"));
        window_report_moreSoldProd->resize(476, 267);
        centralwidget = new QWidget(window_report_moreSoldProd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 20, 201, 51));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(250, 180, 201, 31));
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 110, 211, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 211, 21));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 180, 211, 31));
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 110, 201, 51));
        window_report_moreSoldProd->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_report_moreSoldProd);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 476, 17));
        window_report_moreSoldProd->setMenuBar(menubar);
        statusbar = new QStatusBar(window_report_moreSoldProd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_report_moreSoldProd->setStatusBar(statusbar);

        retranslateUi(window_report_moreSoldProd);

        QMetaObject::connectSlotsByName(window_report_moreSoldProd);
    } // setupUi

    void retranslateUi(QMainWindow *window_report_moreSoldProd)
    {
        window_report_moreSoldProd->setWindowTitle(QApplication::translate("window_report_moreSoldProd", "MainWindow", nullptr));
        start->setText(QApplication::translate("window_report_moreSoldProd", "Cargar pasillos", nullptr));
        save->setText(QApplication::translate("window_report_moreSoldProd", "Crear reporte", nullptr));
        label->setText(QApplication::translate("window_report_moreSoldProd", "Producto m\303\241s vendido", nullptr));
        label_2->setText(QApplication::translate("window_report_moreSoldProd", "Seleccione el pasillo", nullptr));
        back->setText(QApplication::translate("window_report_moreSoldProd", "Atr\303\241s", nullptr));
        pasilloButton->setText(QApplication::translate("window_report_moreSoldProd", "Seleccionar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_report_moreSoldProd: public Ui_window_report_moreSoldProd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_REPORT_MORESOLDPROD_H
