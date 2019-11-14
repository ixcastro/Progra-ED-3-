/********************************************************************************
** Form generated from reading UI file 'facturar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACTURAR_H
#define UI_FACTURAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Facturar
{
public:
    QLabel *label_24;
    QTextEdit *txtCodFactura;
    QLabel *label_18;
    QPushButton *btSalir;
    QPushButton *btFacturar;

    void setupUi(QWidget *Facturar)
    {
        if (Facturar->objectName().isEmpty())
            Facturar->setObjectName(QString::fromUtf8("Facturar"));
        Facturar->resize(748, 472);
        label_24 = new QLabel(Facturar);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(320, 40, 131, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label_24->setFont(font);
        txtCodFactura = new QTextEdit(Facturar);
        txtCodFactura->setObjectName(QString::fromUtf8("txtCodFactura"));
        txtCodFactura->setGeometry(QRect(460, 150, 191, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(12);
        txtCodFactura->setFont(font1);
        label_18 = new QLabel(Facturar);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(90, 150, 270, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(14);
        label_18->setFont(font2);
        btSalir = new QPushButton(Facturar);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(40, 390, 80, 31));
        btSalir->setFont(font2);
        btSalir->setCursor(QCursor(Qt::PointingHandCursor));
        btFacturar = new QPushButton(Facturar);
        btFacturar->setObjectName(QString::fromUtf8("btFacturar"));
        btFacturar->setGeometry(QRect(630, 390, 80, 31));
        btFacturar->setFont(font2);
        btFacturar->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(Facturar);

        QMetaObject::connectSlotsByName(Facturar);
    } // setupUi

    void retranslateUi(QWidget *Facturar)
    {
        Facturar->setWindowTitle(QApplication::translate("Facturar", "Form", nullptr));
        label_24->setText(QApplication::translate("Facturar", "FACTURAR", nullptr));
        label_18->setText(QApplication::translate("Facturar", "Ingrese el c\303\263digo de su factura:", nullptr));
        btSalir->setText(QApplication::translate("Facturar", "Salir", nullptr));
        btFacturar->setText(QApplication::translate("Facturar", "Facturar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Facturar: public Ui_Facturar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACTURAR_H
