/********************************************************************************
** Form generated from reading UI file 'reservar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVAR_H
#define UI_RESERVAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reservar
{
public:
    QLabel *label_24;
    QTextEdit *txtCodR;
    QTextEdit *txtCodTT;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_18;
    QTextEdit *txtCodT;
    QTextEdit *txtCodNA;
    QTextEdit *txtCodNP;
    QLabel *label_20;
    QLabel *label_23;
    QPushButton *btSalir;
    QPushButton *btAP;
    QPushButton *btReservar;
    QLabel *label_22;
    QTextEdit *txtCodPas;

    void setupUi(QWidget *Reservar)
    {
        if (Reservar->objectName().isEmpty())
            Reservar->setObjectName(QString::fromUtf8("Reservar"));
        Reservar->resize(757, 475);
        label_24 = new QLabel(Reservar);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(340, 20, 131, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label_24->setFont(font);
        txtCodR = new QTextEdit(Reservar);
        txtCodR->setObjectName(QString::fromUtf8("txtCodR"));
        txtCodR->setGeometry(QRect(490, 140, 171, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(12);
        txtCodR->setFont(font1);
        txtCodTT = new QTextEdit(Reservar);
        txtCodTT->setObjectName(QString::fromUtf8("txtCodTT"));
        txtCodTT->setGeometry(QRect(490, 60, 171, 31));
        txtCodTT->setFont(font1);
        label_19 = new QLabel(Reservar);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(100, 110, 270, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(14);
        label_19->setFont(font2);
        label_21 = new QLabel(Reservar);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(100, 150, 270, 22));
        label_21->setFont(font2);
        label_18 = new QLabel(Reservar);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(100, 70, 270, 22));
        label_18->setFont(font2);
        txtCodT = new QTextEdit(Reservar);
        txtCodT->setObjectName(QString::fromUtf8("txtCodT"));
        txtCodT->setGeometry(QRect(490, 100, 171, 31));
        txtCodT->setFont(font1);
        txtCodNA = new QTextEdit(Reservar);
        txtCodNA->setObjectName(QString::fromUtf8("txtCodNA"));
        txtCodNA->setGeometry(QRect(490, 220, 171, 31));
        txtCodNA->setFont(font1);
        txtCodNP = new QTextEdit(Reservar);
        txtCodNP->setObjectName(QString::fromUtf8("txtCodNP"));
        txtCodNP->setGeometry(QRect(490, 180, 171, 31));
        txtCodNP->setFont(font1);
        label_20 = new QLabel(Reservar);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(100, 230, 270, 22));
        label_20->setFont(font2);
        label_23 = new QLabel(Reservar);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(100, 190, 331, 22));
        label_23->setFont(font2);
        btSalir = new QPushButton(Reservar);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(40, 420, 80, 31));
        btSalir->setFont(font2);
        btSalir->setCursor(QCursor(Qt::PointingHandCursor));
        btAP = new QPushButton(Reservar);
        btAP->setObjectName(QString::fromUtf8("btAP"));
        btAP->setGeometry(QRect(290, 380, 181, 31));
        btAP->setFont(font2);
        btAP->setCursor(QCursor(Qt::PointingHandCursor));
        btReservar = new QPushButton(Reservar);
        btReservar->setObjectName(QString::fromUtf8("btReservar"));
        btReservar->setGeometry(QRect(630, 420, 80, 31));
        btReservar->setFont(font2);
        btReservar->setCursor(QCursor(Qt::PointingHandCursor));
        label_22 = new QLabel(Reservar);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(100, 270, 371, 22));
        label_22->setFont(font2);
        txtCodPas = new QTextEdit(Reservar);
        txtCodPas->setObjectName(QString::fromUtf8("txtCodPas"));
        txtCodPas->setGeometry(QRect(490, 260, 171, 31));
        txtCodPas->setFont(font1);

        retranslateUi(Reservar);

        QMetaObject::connectSlotsByName(Reservar);
    } // setupUi

    void retranslateUi(QWidget *Reservar)
    {
        Reservar->setWindowTitle(QApplication::translate("Reservar", "Form", nullptr));
        label_24->setText(QApplication::translate("Reservar", "RESERVAR", nullptr));
        label_19->setText(QApplication::translate("Reservar", "Ingrese el c\303\263digo del tren: ", nullptr));
        label_21->setText(QApplication::translate("Reservar", "Ingrese el c\303\263digo de la ruta: ", nullptr));
        label_18->setText(QApplication::translate("Reservar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        label_20->setText(QApplication::translate("Reservar", "Ingrese el n\303\272mero de asientos: ", nullptr));
        label_23->setText(QApplication::translate("Reservar", "Ingrese el n\303\272mero de personas que viajan: ", nullptr));
        btSalir->setText(QApplication::translate("Reservar", "Salir", nullptr));
        btAP->setText(QApplication::translate("Reservar", "AGREGAR PASAJEROS", nullptr));
        btReservar->setText(QApplication::translate("Reservar", "Reservar", nullptr));
        label_22->setText(QApplication::translate("Reservar", "Ingrese el n\303\272mero de pasaporte del comprador: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reservar: public Ui_Reservar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVAR_H
