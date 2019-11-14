/********************************************************************************
** Form generated from reading UI file 'window_insert_client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_INSERT_CLIENT_H
#define UI_WINDOW_INSERT_CLIENT_H

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

class Ui_window_insert_client
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *tel;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *name;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *ced;
    QLineEdit *correo;
    QLabel *label_3;
    QLineEdit *city;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_insert_client)
    {
        if (window_insert_client->objectName().isEmpty())
            window_insert_client->setObjectName(QString::fromUtf8("window_insert_client"));
        window_insert_client->resize(366, 416);
        centralwidget = new QWidget(window_insert_client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 241, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        tel = new QLineEdit(centralwidget);
        tel->setObjectName(QString::fromUtf8("tel"));
        tel->setGeometry(QRect(140, 180, 201, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 121, 31));
        QFont font1;
        font1.setPointSize(12);
        label_5->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 330, 151, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 130, 121, 31));
        label_2->setFont(font1);
        name = new QLineEdit(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(140, 80, 201, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 330, 151, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 180, 121, 31));
        label_4->setFont(font1);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 280, 121, 31));
        label_6->setFont(font1);
        ced = new QLineEdit(centralwidget);
        ced->setObjectName(QString::fromUtf8("ced"));
        ced->setGeometry(QRect(140, 130, 201, 31));
        correo = new QLineEdit(centralwidget);
        correo->setObjectName(QString::fromUtf8("correo"));
        correo->setGeometry(QRect(140, 230, 201, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 121, 31));
        label_3->setFont(font1);
        city = new QLineEdit(centralwidget);
        city->setObjectName(QString::fromUtf8("city"));
        city->setGeometry(QRect(140, 280, 201, 31));
        window_insert_client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_insert_client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 366, 17));
        window_insert_client->setMenuBar(menubar);
        statusbar = new QStatusBar(window_insert_client);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_insert_client->setStatusBar(statusbar);

        retranslateUi(window_insert_client);

        QMetaObject::connectSlotsByName(window_insert_client);
    } // setupUi

    void retranslateUi(QMainWindow *window_insert_client)
    {
        window_insert_client->setWindowTitle(QApplication::translate("window_insert_client", "MainWindow", nullptr));
        label->setText(QApplication::translate("window_insert_client", "Insertar cliente", nullptr));
        label_5->setText(QApplication::translate("window_insert_client", "Correo", nullptr));
        pushButton->setText(QApplication::translate("window_insert_client", "Atras", nullptr));
        label_2->setText(QApplication::translate("window_insert_client", "C\303\251dula", nullptr));
        pushButton_2->setText(QApplication::translate("window_insert_client", "Guardar", nullptr));
        label_4->setText(QApplication::translate("window_insert_client", "Telefono", nullptr));
        label_6->setText(QApplication::translate("window_insert_client", "Ciudad", nullptr));
        label_3->setText(QApplication::translate("window_insert_client", "Nombre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_insert_client: public Ui_window_insert_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_INSERT_CLIENT_H
