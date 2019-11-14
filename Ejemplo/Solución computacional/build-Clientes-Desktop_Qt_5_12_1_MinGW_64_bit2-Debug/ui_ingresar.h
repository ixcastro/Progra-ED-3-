/********************************************************************************
** Form generated from reading UI file 'ingresar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGRESAR_H
#define UI_INGRESAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ingresar
{
public:
    QTextEdit *txtId;
    QPushButton *salir;
    QPushButton *ingresar;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *Ingresar)
    {
        if (Ingresar->objectName().isEmpty())
            Ingresar->setObjectName(QString::fromUtf8("Ingresar"));
        Ingresar->resize(411, 236);
        txtId = new QTextEdit(Ingresar);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setGeometry(QRect(195, 101, 165, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(12);
        txtId->setFont(font);
        salir = new QPushButton(Ingresar);
        salir->setObjectName(QString::fromUtf8("salir"));
        salir->setGeometry(QRect(50, 170, 80, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(14);
        salir->setFont(font1);
        salir->setCursor(QCursor(Qt::PointingHandCursor));
        ingresar = new QPushButton(Ingresar);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));
        ingresar->setGeometry(QRect(280, 170, 80, 31));
        ingresar->setFont(font1);
        ingresar->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(Ingresar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(31, 101, 158, 19));
        label_2->setFont(font);
        label = new QLabel(Ingresar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 251, 36));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(22);
        label->setFont(font2);

        retranslateUi(Ingresar);
        QObject::connect(salir, SIGNAL(clicked()), Ingresar, SLOT(close()));

        QMetaObject::connectSlotsByName(Ingresar);
    } // setupUi

    void retranslateUi(QWidget *Ingresar)
    {
        Ingresar->setWindowTitle(QApplication::translate("Ingresar", "Form", nullptr));
        salir->setText(QApplication::translate("Ingresar", "Salir", nullptr));
        ingresar->setText(QApplication::translate("Ingresar", "Ingresar", nullptr));
        label_2->setText(QApplication::translate("Ingresar", "Ingrese su identificaci\303\263n:", nullptr));
        label->setText(QApplication::translate("Ingresar", "BIENVENIDO USUARIO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ingresar: public Ui_Ingresar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGRESAR_H
