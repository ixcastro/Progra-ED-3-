/********************************************************************************
** Form generated from reading UI file 'atracciones.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATRACCIONES_H
#define UI_ATRACCIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Atracciones
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPlainTextEdit *txtAtracciones;

    void setupUi(QWidget *Atracciones)
    {
        if (Atracciones->objectName().isEmpty())
            Atracciones->setObjectName(QString::fromUtf8("Atracciones"));
        Atracciones->resize(328, 358);
        gridLayout = new QGridLayout(Atracciones);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Atracciones);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(14);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtAtracciones = new QPlainTextEdit(Atracciones);
        txtAtracciones->setObjectName(QString::fromUtf8("txtAtracciones"));
        txtAtracciones->setReadOnly(true);

        gridLayout->addWidget(txtAtracciones, 1, 0, 1, 1);


        retranslateUi(Atracciones);

        QMetaObject::connectSlotsByName(Atracciones);
    } // setupUi

    void retranslateUi(QWidget *Atracciones)
    {
        Atracciones->setWindowTitle(QApplication::translate("Atracciones", "Form", nullptr));
        label->setText(QApplication::translate("Atracciones", "ATRACCIONES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Atracciones: public Ui_Atracciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATRACCIONES_H
