/********************************************************************************
** Form generated from reading UI file 'window_insert_hall.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_INSERT_HALL_H
#define UI_WINDOW_INSERT_HALL_H

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

class Ui_window_insert_hall
{
public:
    QWidget *centralwidget;
    QLineEdit *nameLine;
    QPushButton *save;
    QLineEdit *codeLine;
    QLabel *label_2;
    QLabel *label;
    QPushButton *back;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_insert_hall)
    {
        if (window_insert_hall->objectName().isEmpty())
            window_insert_hall->setObjectName(QString::fromUtf8("window_insert_hall"));
        window_insert_hall->resize(370, 261);
        centralwidget = new QWidget(window_insert_hall);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        nameLine = new QLineEdit(centralwidget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(140, 80, 201, 31));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(190, 180, 151, 31));
        codeLine = new QLineEdit(centralwidget);
        codeLine->setObjectName(QString::fromUtf8("codeLine"));
        codeLine->setGeometry(QRect(140, 130, 201, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 130, 121, 31));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 241, 41));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 180, 151, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 121, 31));
        label_3->setFont(font);
        window_insert_hall->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_insert_hall);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 370, 17));
        window_insert_hall->setMenuBar(menubar);
        statusbar = new QStatusBar(window_insert_hall);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_insert_hall->setStatusBar(statusbar);

        retranslateUi(window_insert_hall);

        QMetaObject::connectSlotsByName(window_insert_hall);
    } // setupUi

    void retranslateUi(QMainWindow *window_insert_hall)
    {
        window_insert_hall->setWindowTitle(QApplication::translate("window_insert_hall", "MainWindow", nullptr));
        save->setText(QApplication::translate("window_insert_hall", "Guardar", nullptr));
        label_2->setText(QApplication::translate("window_insert_hall", "C\303\263digo", nullptr));
        label->setText(QApplication::translate("window_insert_hall", "Insertar pasillo", nullptr));
        back->setText(QApplication::translate("window_insert_hall", "Atr\303\241s", nullptr));
        label_3->setText(QApplication::translate("window_insert_hall", "Nombre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_insert_hall: public Ui_window_insert_hall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_INSERT_HALL_H