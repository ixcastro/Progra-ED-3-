/********************************************************************************
** Form generated from reading UI file 'window_modify_price.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MODIFY_PRICE_H
#define UI_WINDOW_MODIFY_PRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_modify_price
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_2;
    QComboBox *halls;
    QPushButton *marcaButton;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pasilloButton;
    QComboBox *prods;
    QPushButton *start;
    QComboBox *marca;
    QPushButton *prodButton;
    QPushButton *back;
    QPushButton *save;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_modify_price)
    {
        if (window_modify_price->objectName().isEmpty())
            window_modify_price->setObjectName(QString::fromUtf8("window_modify_price"));
        window_modify_price->resize(475, 600);
        centralwidget = new QWidget(window_modify_price);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 290, 211, 21));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 211, 21));
        label_2->setFont(font);
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 120, 211, 51));
        marcaButton = new QPushButton(centralwidget);
        marcaButton->setObjectName(QString::fromUtf8("marcaButton"));
        marcaButton->setGeometry(QRect(250, 320, 201, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 189, 211, 31));
        label_3->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 120, 201, 51));
        prods = new QComboBox(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(20, 220, 211, 51));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 30, 201, 51));
        marca = new QComboBox(centralwidget);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setGeometry(QRect(20, 320, 211, 61));
        prodButton = new QPushButton(centralwidget);
        prodButton->setObjectName(QString::fromUtf8("prodButton"));
        prodButton->setGeometry(QRect(250, 220, 201, 51));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 500, 211, 31));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(250, 500, 201, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 400, 431, 21));
        label_5->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 430, 431, 41));
        window_modify_price->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_modify_price);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 475, 17));
        window_modify_price->setMenuBar(menubar);
        statusbar = new QStatusBar(window_modify_price);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_modify_price->setStatusBar(statusbar);

        retranslateUi(window_modify_price);

        QMetaObject::connectSlotsByName(window_modify_price);
    } // setupUi

    void retranslateUi(QMainWindow *window_modify_price)
    {
        window_modify_price->setWindowTitle(QApplication::translate("window_modify_price", "MainWindow", nullptr));
        label_4->setText(QApplication::translate("window_modify_price", "Seleccione el marca", nullptr));
        label_2->setText(QApplication::translate("window_modify_price", "Seleccione el pasillo", nullptr));
        marcaButton->setText(QApplication::translate("window_modify_price", "Seleccionar", nullptr));
        label_3->setText(QApplication::translate("window_modify_price", "Seleccione el producto", nullptr));
        label->setText(QApplication::translate("window_modify_price", "Modificar precio", nullptr));
        pasilloButton->setText(QApplication::translate("window_modify_price", "Seleccionar", nullptr));
        start->setText(QApplication::translate("window_modify_price", "Iniciar modificacion", nullptr));
        prodButton->setText(QApplication::translate("window_modify_price", "Seleccionar", nullptr));
        back->setText(QApplication::translate("window_modify_price", "Atr\303\241s", nullptr));
        save->setText(QApplication::translate("window_modify_price", "Guardar", nullptr));
        label_5->setText(QApplication::translate("window_modify_price", "Ingrese el nuevo precio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_modify_price: public Ui_window_modify_price {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MODIFY_PRICE_H
