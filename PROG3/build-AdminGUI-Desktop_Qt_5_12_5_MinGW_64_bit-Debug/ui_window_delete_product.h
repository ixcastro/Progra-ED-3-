/********************************************************************************
** Form generated from reading UI file 'window_delete_product.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_DELETE_PRODUCT_H
#define UI_WINDOW_DELETE_PRODUCT_H

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

class Ui_window_delete_product
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
    QPushButton *start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_delete_product)
    {
        if (window_delete_product->objectName().isEmpty())
            window_delete_product->setObjectName(QString::fromUtf8("window_delete_product"));
        window_delete_product->resize(476, 380);
        centralwidget = new QWidget(window_delete_product);
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
        save->setGeometry(QRect(250, 290, 201, 41));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 290, 211, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(250, 20, 201, 51));
        window_delete_product->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_delete_product);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 476, 17));
        window_delete_product->setMenuBar(menubar);
        statusbar = new QStatusBar(window_delete_product);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_delete_product->setStatusBar(statusbar);

        retranslateUi(window_delete_product);

        QMetaObject::connectSlotsByName(window_delete_product);
    } // setupUi

    void retranslateUi(QMainWindow *window_delete_product)
    {
        window_delete_product->setWindowTitle(QApplication::translate("window_delete_product", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("window_delete_product", "Seleccione el pasillo", nullptr));
        prodButton->setText(QApplication::translate("window_delete_product", "Eliminar", nullptr));
        pasilloButton->setText(QApplication::translate("window_delete_product", "Seleccionar", nullptr));
        label_3->setText(QApplication::translate("window_delete_product", "Seleccione el producto", nullptr));
        save->setText(QApplication::translate("window_delete_product", "Confirmar", nullptr));
        back->setText(QApplication::translate("window_delete_product", "Atr\303\241s", nullptr));
        label->setText(QApplication::translate("window_delete_product", "Eliminar producto", nullptr));
        start->setText(QApplication::translate("window_delete_product", "Iniciar eliminacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_delete_product: public Ui_window_delete_product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_DELETE_PRODUCT_H
