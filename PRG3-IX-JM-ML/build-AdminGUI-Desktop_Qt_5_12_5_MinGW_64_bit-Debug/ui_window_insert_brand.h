/********************************************************************************
** Form generated from reading UI file 'window_insert_brand.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_INSERT_BRAND_H
#define UI_WINDOW_INSERT_BRAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_insert_brand
{
public:
    QWidget *centralwidget;
    QPushButton *save;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *code;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *price;
    QLineEdit *name;
    QLineEdit *basket;
    QLineEdit *gondola;
    QLineEdit *stock;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_insert_brand)
    {
        if (window_insert_brand->objectName().isEmpty())
            window_insert_brand->setObjectName(QString::fromUtf8("window_insert_brand"));
        window_insert_brand->resize(343, 411);
        centralwidget = new QWidget(window_insert_brand);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(170, 340, 121, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 340, 101, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 45, 121, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        code = new QLineEdit(centralwidget);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(150, 40, 181, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 301, 16));
        QFont font1;
        font1.setPointSize(14);
        label_7->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 90, 131, 31));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 140, 131, 31));
        label_9->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 240, 121, 31));
        label_10->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 190, 121, 31));
        label_11->setFont(font);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 290, 121, 31));
        label_12->setFont(font);
        price = new QLineEdit(centralwidget);
        price->setObjectName(QString::fromUtf8("price"));
        price->setGeometry(QRect(150, 140, 181, 31));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(150, 90, 181, 31));
        basket = new QLineEdit(centralwidget);
        basket->setObjectName(QString::fromUtf8("basket"));
        basket->setGeometry(QRect(150, 190, 181, 31));
        gondola = new QLineEdit(centralwidget);
        gondola->setObjectName(QString::fromUtf8("gondola"));
        gondola->setGeometry(QRect(150, 240, 181, 31));
        stock = new QLineEdit(centralwidget);
        stock->setObjectName(QString::fromUtf8("stock"));
        stock->setGeometry(QRect(150, 290, 181, 31));
        window_insert_brand->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_insert_brand);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 343, 17));
        window_insert_brand->setMenuBar(menubar);
        statusbar = new QStatusBar(window_insert_brand);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_insert_brand->setStatusBar(statusbar);

        retranslateUi(window_insert_brand);

        QMetaObject::connectSlotsByName(window_insert_brand);
    } // setupUi

    void retranslateUi(QMainWindow *window_insert_brand)
    {
        window_insert_brand->setWindowTitle(QApplication::translate("window_insert_brand", "MainWindow", nullptr));
        save->setText(QApplication::translate("window_insert_brand", "Guardar", nullptr));
        pushButton_2->setText(QApplication::translate("window_insert_brand", "Atras", nullptr));
        label->setText(QApplication::translate("window_insert_brand", "Codigo marca", nullptr));
        label_7->setText(QApplication::translate("window_insert_brand", "Insertar Marca", nullptr));
        label_8->setText(QApplication::translate("window_insert_brand", "Nombre", nullptr));
        label_9->setText(QApplication::translate("window_insert_brand", "Precio", nullptr));
        label_10->setText(QApplication::translate("window_insert_brand", "Cantidad gondola", nullptr));
        label_11->setText(QApplication::translate("window_insert_brand", "Canasta basica", nullptr));
        label_12->setText(QApplication::translate("window_insert_brand", "Cantidad inventario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_insert_brand: public Ui_window_insert_brand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_INSERT_BRAND_H
