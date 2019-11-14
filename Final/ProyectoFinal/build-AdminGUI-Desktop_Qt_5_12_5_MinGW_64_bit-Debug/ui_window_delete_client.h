/********************************************************************************
** Form generated from reading UI file 'window_delete_client.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_DELETE_CLIENT_H
#define UI_WINDOW_DELETE_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_window_delete_client
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *window_delete_client)
    {
        if (window_delete_client->objectName().isEmpty())
            window_delete_client->setObjectName(QString::fromUtf8("window_delete_client"));
        window_delete_client->resize(400, 300);
        lineEdit = new QLineEdit(window_delete_client);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(210, 100, 161, 31));
        label = new QLabel(window_delete_client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 100, 121, 41));
        pushButton = new QPushButton(window_delete_client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 220, 100, 30));
        pushButton_2 = new QPushButton(window_delete_client);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 220, 100, 30));

        retranslateUi(window_delete_client);

        QMetaObject::connectSlotsByName(window_delete_client);
    } // setupUi

    void retranslateUi(QDialog *window_delete_client)
    {
        window_delete_client->setWindowTitle(QApplication::translate("window_delete_client", "Dialog", nullptr));
        label->setText(QApplication::translate("window_delete_client", "Cedula a eliminar", nullptr));
        pushButton->setText(QApplication::translate("window_delete_client", "Eliminar", nullptr));
        pushButton_2->setText(QApplication::translate("window_delete_client", "Atr\303\241s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_delete_client: public Ui_window_delete_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_DELETE_CLIENT_H
