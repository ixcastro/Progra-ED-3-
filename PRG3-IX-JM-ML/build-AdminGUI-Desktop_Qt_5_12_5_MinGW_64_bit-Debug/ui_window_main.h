/********************************************************************************
** Form generated from reading UI file 'window_main.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MAIN_H
#define UI_WINDOW_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_main
{
public:
    QWidget *centralWidget;
    QPushButton *check;
    QPushButton *stock;
    QPushButton *query;
    QPushButton *city;
    QPushButton *bill;
    QPushButton *delete_2;
    QLabel *label;
    QLabel *label_2;
    QListWidget *queueClient;
    QPushButton *report;
    QPushButton *close;
    QPushButton *insert;
    QPushButton *modify;
    QPushButton *refresh;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *window_main)
    {
        if (window_main->objectName().isEmpty())
            window_main->setObjectName(QString::fromUtf8("window_main"));
        window_main->resize(1119, 867);
        centralWidget = new QWidget(window_main);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        check = new QPushButton(centralWidget);
        check->setObjectName(QString::fromUtf8("check"));
        check->setGeometry(QRect(20, 440, 531, 81));
        QFont font;
        font.setPointSize(14);
        check->setFont(font);
        stock = new QPushButton(centralWidget);
        stock->setObjectName(QString::fromUtf8("stock"));
        stock->setGeometry(QRect(20, 530, 531, 81));
        stock->setFont(font);
        query = new QPushButton(centralWidget);
        query->setObjectName(QString::fromUtf8("query"));
        query->setGeometry(QRect(20, 350, 531, 81));
        query->setFont(font);
        city = new QPushButton(centralWidget);
        city->setObjectName(QString::fromUtf8("city"));
        city->setGeometry(QRect(20, 710, 531, 81));
        city->setFont(font);
        bill = new QPushButton(centralWidget);
        bill->setObjectName(QString::fromUtf8("bill"));
        bill->setGeometry(QRect(840, 670, 251, 81));
        bill->setFont(font);
        delete_2 = new QPushButton(centralWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(20, 260, 531, 81));
        delete_2->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 10, 461, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(16);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(570, 10, 321, 31));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        queueClient = new QListWidget(centralWidget);
        queueClient->setObjectName(QString::fromUtf8("queueClient"));
        queueClient->setGeometry(QRect(570, 50, 521, 581));
        queueClient->setFont(font);
        report = new QPushButton(centralWidget);
        report->setObjectName(QString::fromUtf8("report"));
        report->setGeometry(QRect(20, 620, 531, 81));
        report->setFont(font);
        close = new QPushButton(centralWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(880, 780, 201, 41));
        insert = new QPushButton(centralWidget);
        insert->setObjectName(QString::fromUtf8("insert"));
        insert->setGeometry(QRect(20, 80, 531, 81));
        insert->setFont(font);
        modify = new QPushButton(centralWidget);
        modify->setObjectName(QString::fromUtf8("modify"));
        modify->setGeometry(QRect(20, 170, 531, 81));
        modify->setFont(font);
        refresh = new QPushButton(centralWidget);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(580, 670, 251, 81));
        refresh->setFont(font);
        window_main->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(window_main);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1119, 21));
        window_main->setMenuBar(menuBar);
        mainToolBar = new QToolBar(window_main);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        window_main->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(window_main);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        window_main->setStatusBar(statusBar);

        retranslateUi(window_main);

        QMetaObject::connectSlotsByName(window_main);
    } // setupUi

    void retranslateUi(QMainWindow *window_main)
    {
        window_main->setWindowTitle(QApplication::translate("window_main", "window_main", nullptr));
        check->setText(QApplication::translate("window_main", "Revisar gondolas", nullptr));
        stock->setText(QApplication::translate("window_main", "Inventario", nullptr));
        query->setText(QApplication::translate("window_main", "Consultar", nullptr));
        city->setText(QApplication::translate("window_main", "Ciudad", nullptr));
        bill->setText(QApplication::translate("window_main", "Facturar", nullptr));
        delete_2->setText(QApplication::translate("window_main", "Eliminar", nullptr));
        label->setText(QApplication::translate("window_main", "Menu Principal Adminstrador", nullptr));
        label_2->setText(QApplication::translate("window_main", "Clientes en cola", nullptr));
        report->setText(QApplication::translate("window_main", "Reportes", nullptr));
        close->setText(QApplication::translate("window_main", "Cerrar programa", nullptr));
        insert->setText(QApplication::translate("window_main", "Insertar", nullptr));
        modify->setText(QApplication::translate("window_main", "Modificar", nullptr));
        refresh->setText(QApplication::translate("window_main", "Refrescar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_main: public Ui_window_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MAIN_H
