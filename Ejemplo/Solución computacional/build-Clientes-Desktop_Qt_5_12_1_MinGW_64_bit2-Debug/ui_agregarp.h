/********************************************************************************
** Form generated from reading UI file 'agregarp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARP_H
#define UI_AGREGARP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgregarP
{
public:
    QLabel *label_24;
    QLabel *label_18;
    QPushButton *btSalir;
    QPushButton *btAceptar;
    QTextEdit *txtId;

    void setupUi(QWidget *AgregarP)
    {
        if (AgregarP->objectName().isEmpty())
            AgregarP->setObjectName(QString::fromUtf8("AgregarP"));
        AgregarP->resize(750, 472);
        label_24 = new QLabel(AgregarP);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(250, 30, 261, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label_24->setFont(font);
        label_18 = new QLabel(AgregarP);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(100, 170, 270, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(14);
        label_18->setFont(font1);
        btSalir = new QPushButton(AgregarP);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(30, 410, 80, 31));
        btSalir->setFont(font1);
        btSalir->setCursor(QCursor(Qt::PointingHandCursor));
        btAceptar = new QPushButton(AgregarP);
        btAceptar->setObjectName(QString::fromUtf8("btAceptar"));
        btAceptar->setGeometry(QRect(640, 410, 80, 31));
        btAceptar->setFont(font1);
        btAceptar->setCursor(QCursor(Qt::PointingHandCursor));
        txtId = new QTextEdit(AgregarP);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setGeometry(QRect(470, 170, 191, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(12);
        txtId->setFont(font2);

        retranslateUi(AgregarP);
        QObject::connect(btSalir, SIGNAL(clicked()), AgregarP, SLOT(close()));

        QMetaObject::connectSlotsByName(AgregarP);
    } // setupUi

    void retranslateUi(QWidget *AgregarP)
    {
        AgregarP->setWindowTitle(QApplication::translate("AgregarP", "Form", nullptr));
        label_24->setText(QApplication::translate("AgregarP", "AGREGAR PASAJEROS", nullptr));
        label_18->setText(QApplication::translate("AgregarP", "Ingrese el n\303\272mero de pasaporte: ", nullptr));
        btSalir->setText(QApplication::translate("AgregarP", "Salir", nullptr));
        btAceptar->setText(QApplication::translate("AgregarP", "Aceptar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgregarP: public Ui_AgregarP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARP_H
