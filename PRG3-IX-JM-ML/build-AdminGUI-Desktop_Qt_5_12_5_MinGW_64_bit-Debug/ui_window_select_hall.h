/********************************************************************************
** Form generated from reading UI file 'window_select_hall.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_SELECT_HALL_H
#define UI_WINDOW_SELECT_HALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_select_hall
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_select_hall)
    {
        if (window_select_hall->objectName().isEmpty())
            window_select_hall->setObjectName(QString::fromUtf8("window_select_hall"));
        window_select_hall->resize(800, 600);
        centralwidget = new QWidget(window_select_hall);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 20, 221, 41));
        window_select_hall->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_select_hall);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        window_select_hall->setMenuBar(menubar);
        statusbar = new QStatusBar(window_select_hall);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_select_hall->setStatusBar(statusbar);

        retranslateUi(window_select_hall);

        QMetaObject::connectSlotsByName(window_select_hall);
    } // setupUi

    void retranslateUi(QMainWindow *window_select_hall)
    {
        window_select_hall->setWindowTitle(QApplication::translate("window_select_hall", "MainWindow", nullptr));
        label->setText(QApplication::translate("window_select_hall", "Escoja un pasillo", nullptr));
        pushButton->setText(QApplication::translate("window_select_hall", "Mostrar pasillos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_select_hall: public Ui_window_select_hall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_SELECT_HALL_H
