/********************************************************************************
** Form generated from reading UI file 'window_delete_brand.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_DELETE_BRAND_H
#define UI_WINDOW_DELETE_BRAND_H

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

class Ui_window_delete_brand
{
public:
    QWidget *centralwidget;
    QComboBox *halls;
    QLabel *label_2;
    QPushButton *prodButton;
    QPushButton *pasilloButton;
    QLabel *label_3;
    QComboBox *prods;
    QPushButton *save;
    QPushButton *back;
    QLabel *label;
    QLabel *label_4;
    QComboBox *marca;
    QPushButton *marcaButton;
    QPushButton *start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_delete_brand)
    {
        if (window_delete_brand->objectName().isEmpty())
            window_delete_brand->setObjectName(QString::fromUtf8("window_delete_brand"));
        window_delete_brand->resize(478, 481);
        centralwidget = new QWidget(window_delete_brand);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        halls = new QComboBox(centralwidget);
        halls->setObjectName(QString::fromUtf8("halls"));
        halls->setGeometry(QRect(20, 110, 211, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 211, 21));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        prodButton = new QPushButton(centralwidget);
        prodButton->setObjectName(QString::fromUtf8("prodButton"));
        prodButton->setGeometry(QRect(250, 210, 201, 51));
        pasilloButton = new QPushButton(centralwidget);
        pasilloButton->setObjectName(QString::fromUtf8("pasilloButton"));
        pasilloButton->setGeometry(QRect(250, 110, 201, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 179, 211, 31));
        label_3->setFont(font);
        prods = new QComboBox(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(20, 210, 211, 51));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(250, 390, 201, 41));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 390, 211, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 211, 21));
        label_4->setFont(font);
        marca = new QComboBox(centralwidget);
        marca->setObjectName(QString::fromUtf8("marca"));
        marca->setGeometry(QRect(20, 310, 211, 51));
        marcaButton = new QPushButton(centralwidget);
        marcaButton->setObjectName(QString::fromUtf8("marcaButton"));
        marcaButton->setGeometry(QRect(250, 310, 201, 51));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 20, 201, 51));
        window_delete_brand->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_delete_brand);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 478, 17));
        window_delete_brand->setMenuBar(menubar);
        statusbar = new QStatusBar(window_delete_brand);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_delete_brand->setStatusBar(statusbar);

        retranslateUi(window_delete_brand);

        QMetaObject::connectSlotsByName(window_delete_brand);
    } // setupUi

    void retranslateUi(QMainWindow *window_delete_brand)
    {
        window_delete_brand->setWindowTitle(QApplication::translate("window_delete_brand", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("window_delete_brand", "Seleccione el pasillo", nullptr));
        prodButton->setText(QApplication::translate("window_delete_brand", "Seleccionar", nullptr));
        pasilloButton->setText(QApplication::translate("window_delete_brand", "Seleccionar", nullptr));
        label_3->setText(QApplication::translate("window_delete_brand", "Seleccione el producto", nullptr));
        save->setText(QApplication::translate("window_delete_brand", "Confimar", nullptr));
        back->setText(QApplication::translate("window_delete_brand", "Atr\303\241s", nullptr));
        label->setText(QApplication::translate("window_delete_brand", "Eliminar marca", nullptr));
        label_4->setText(QApplication::translate("window_delete_brand", "Seleccione el marca", nullptr));
        marcaButton->setText(QApplication::translate("window_delete_brand", "Eliminar", nullptr));
        start->setText(QApplication::translate("window_delete_brand", "Iniciar eliminacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_delete_brand: public Ui_window_delete_brand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_DELETE_BRAND_H
