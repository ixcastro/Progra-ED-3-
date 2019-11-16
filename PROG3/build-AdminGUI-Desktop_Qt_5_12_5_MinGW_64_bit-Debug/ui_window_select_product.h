/********************************************************************************
** Form generated from reading UI file 'window_select_product.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_SELECT_PRODUCT_H
#define UI_WINDOW_SELECT_PRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_select_product
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_select_product)
    {
        if (window_select_product->objectName().isEmpty())
            window_select_product->setObjectName(QString::fromUtf8("window_select_product"));
        window_select_product->resize(800, 600);
        menubar = new QMenuBar(window_select_product);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        window_select_product->setMenuBar(menubar);
        centralwidget = new QWidget(window_select_product);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        window_select_product->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(window_select_product);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_select_product->setStatusBar(statusbar);

        retranslateUi(window_select_product);

        QMetaObject::connectSlotsByName(window_select_product);
    } // setupUi

    void retranslateUi(QMainWindow *window_select_product)
    {
        window_select_product->setWindowTitle(QApplication::translate("window_select_product", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_select_product: public Ui_window_select_product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_SELECT_PRODUCT_H
