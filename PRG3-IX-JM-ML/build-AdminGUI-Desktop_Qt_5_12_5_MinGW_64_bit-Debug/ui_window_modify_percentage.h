/********************************************************************************
** Form generated from reading UI file 'window_modify_percentage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MODIFY_PERCENTAGE_H
#define UI_WINDOW_MODIFY_PERCENTAGE_H

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

class Ui_window_modify_percentage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *back;
    QLabel *label_4;
    QPushButton *pasilloButton;
    QLabel *label_3;
    QPushButton *save;
    QPushButton *marcaButton;
    QComboBox *marca;
    QLabel *label_5;
    QPushButton *prodButton;
    QLabel *label_2;
    QComboBox *prods;
    QComboBox *halls;
    QPushButton *start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_modify_percentage)
    {
        if (window_modify_percentage->objectName().isEmpty())
            window_modify_percentage->setObjectName(QString::fromUtf8("window_modify_percentage"));
        window_modify_percentage->resize(478, 577);
        centralwidget = new QWidget(window_modify_percentage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 420, 431, 41));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 490, 211, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 211, 21));
        QFont font1;
        font1.setPointSize(10);
        label_4->setFont(font1);
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 110, 201, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 179, 211, 31));
        label_3->setFont(font1);
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(250, 490, 201, 31));
        marcaButton = new QPushButton(centralwidget);
        marcaButton->setObjectName(QString::fromUtf8("marcaButton"));
        marcaButton->setGeometry(QRect(250, 310, 201, 61));
        marca = new QComboBox(centralwidget);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setGeometry(QRect(20, 310, 211, 61));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 390, 421, 21));
        label_5->setFont(font1);
        prodButton = new QPushButton(centralwidget);
        prodButton->setObjectName(QString::fromUtf8("prodButton"));
        prodButton->setGeometry(QRect(250, 210, 201, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 211, 21));
        label_2->setFont(font1);
        prods = new QComboBox(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(20, 210, 211, 51));
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 110, 211, 51));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 20, 201, 51));
        window_modify_percentage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_modify_percentage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 478, 17));
        window_modify_percentage->setMenuBar(menubar);
        statusbar = new QStatusBar(window_modify_percentage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_modify_percentage->setStatusBar(statusbar);

        retranslateUi(window_modify_percentage);

        QMetaObject::connectSlotsByName(window_modify_percentage);
    } // setupUi

    void retranslateUi(QMainWindow *window_modify_percentage)
    {
        window_modify_percentage->setWindowTitle(QApplication::translate("window_modify_percentage", "MainWindow", nullptr));
        label->setText(QApplication::translate("window_modify_percentage", "Modificar porcentaje", nullptr));
        back->setText(QApplication::translate("window_modify_percentage", "Atr\303\241s", nullptr));
        label_4->setText(QApplication::translate("window_modify_percentage", "Seleccione el marca", nullptr));
        pasilloButton->setText(QApplication::translate("window_modify_percentage", "Seleccionar", nullptr));
        label_3->setText(QApplication::translate("window_modify_percentage", "Seleccione el producto", nullptr));
        save->setText(QApplication::translate("window_modify_percentage", "Guardar", nullptr));
        marcaButton->setText(QApplication::translate("window_modify_percentage", "Seleccionar", nullptr));
        label_5->setText(QApplication::translate("window_modify_percentage", "Ingrese el nuevo porcentaje", nullptr));
        prodButton->setText(QApplication::translate("window_modify_percentage", "Seleccionar", nullptr));
        label_2->setText(QApplication::translate("window_modify_percentage", "Seleccione el pasillo", nullptr));
        start->setText(QApplication::translate("window_modify_percentage", "Iniciar modificacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_modify_percentage: public Ui_window_modify_percentage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MODIFY_PERCENTAGE_H
