/********************************************************************************
** Form generated from reading UI file 'buscarr.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCARR_H
#define UI_BUSCARR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuscarR
{
public:
    QTextEdit *txtCodTT;
    QTextEdit *txtCodT;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_19;
    QTextEdit *txtCodCS;
    QLabel *label_24;
    QLabel *label_18;
    QTextEdit *txtCodPS;
    QPushButton *btCancelarPrecio_5;
    QPushButton *btCancelarTiempo;
    QLabel *label_25;
    QTextEdit *txtCodCL;
    QLabel *label_22;
    QTextEdit *txtCodPL;

    void setupUi(QWidget *BuscarR)
    {
        if (BuscarR->objectName().isEmpty())
            BuscarR->setObjectName(QString::fromUtf8("BuscarR"));
        BuscarR->resize(737, 478);
        txtCodTT = new QTextEdit(BuscarR);
        txtCodTT->setObjectName(QString::fromUtf8("txtCodTT"));
        txtCodTT->setGeometry(QRect(470, 90, 171, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(12);
        txtCodTT->setFont(font);
        txtCodT = new QTextEdit(BuscarR);
        txtCodT->setObjectName(QString::fromUtf8("txtCodT"));
        txtCodT->setGeometry(QRect(470, 130, 171, 31));
        txtCodT->setFont(font);
        label_21 = new QLabel(BuscarR);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(80, 180, 270, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(14);
        label_21->setFont(font1);
        label_23 = new QLabel(BuscarR);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(80, 220, 331, 22));
        label_23->setFont(font1);
        label_19 = new QLabel(BuscarR);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(80, 140, 270, 22));
        label_19->setFont(font1);
        txtCodCS = new QTextEdit(BuscarR);
        txtCodCS->setObjectName(QString::fromUtf8("txtCodCS"));
        txtCodCS->setGeometry(QRect(470, 210, 171, 31));
        txtCodCS->setFont(font);
        label_24 = new QLabel(BuscarR);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(320, 30, 171, 36));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(22);
        label_24->setFont(font2);
        label_18 = new QLabel(BuscarR);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(80, 100, 270, 22));
        label_18->setFont(font1);
        txtCodPS = new QTextEdit(BuscarR);
        txtCodPS->setObjectName(QString::fromUtf8("txtCodPS"));
        txtCodPS->setGeometry(QRect(470, 170, 171, 31));
        txtCodPS->setFont(font);
        btCancelarPrecio_5 = new QPushButton(BuscarR);
        btCancelarPrecio_5->setObjectName(QString::fromUtf8("btCancelarPrecio_5"));
        btCancelarPrecio_5->setGeometry(QRect(630, 430, 80, 31));
        btCancelarPrecio_5->setFont(font1);
        btCancelarPrecio_5->setCursor(QCursor(Qt::PointingHandCursor));
        btCancelarTiempo = new QPushButton(BuscarR);
        btCancelarTiempo->setObjectName(QString::fromUtf8("btCancelarTiempo"));
        btCancelarTiempo->setGeometry(QRect(40, 430, 80, 31));
        btCancelarTiempo->setFont(font1);
        btCancelarTiempo->setCursor(QCursor(Qt::PointingHandCursor));
        label_25 = new QLabel(BuscarR);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(80, 300, 331, 22));
        label_25->setFont(font1);
        txtCodCL = new QTextEdit(BuscarR);
        txtCodCL->setObjectName(QString::fromUtf8("txtCodCL"));
        txtCodCL->setGeometry(QRect(470, 290, 171, 31));
        txtCodCL->setFont(font);
        label_22 = new QLabel(BuscarR);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(80, 260, 270, 22));
        label_22->setFont(font1);
        txtCodPL = new QTextEdit(BuscarR);
        txtCodPL->setObjectName(QString::fromUtf8("txtCodPL"));
        txtCodPL->setGeometry(QRect(470, 250, 171, 31));
        txtCodPL->setFont(font);

        retranslateUi(BuscarR);

        QMetaObject::connectSlotsByName(BuscarR);
    } // setupUi

    void retranslateUi(QWidget *BuscarR)
    {
        BuscarR->setWindowTitle(QApplication::translate("BuscarR", "Form", nullptr));
        label_21->setText(QApplication::translate("BuscarR", "Ingrese el pais de salida: ", nullptr));
        label_23->setText(QApplication::translate("BuscarR", "Ingrese la ciudad de salida: ", nullptr));
        label_19->setText(QApplication::translate("BuscarR", "Ingrese el c\303\263digo del tren: ", nullptr));
        label_24->setText(QApplication::translate("BuscarR", "BUSCAR RUTA", nullptr));
        label_18->setText(QApplication::translate("BuscarR", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        btCancelarPrecio_5->setText(QApplication::translate("BuscarR", "Consultar", nullptr));
        btCancelarTiempo->setText(QApplication::translate("BuscarR", "Salir", nullptr));
        label_25->setText(QApplication::translate("BuscarR", "Ingrese la ciudad de llegada: ", nullptr));
        label_22->setText(QApplication::translate("BuscarR", "Ingrese el pais de llegada: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuscarR: public Ui_BuscarR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARR_H
