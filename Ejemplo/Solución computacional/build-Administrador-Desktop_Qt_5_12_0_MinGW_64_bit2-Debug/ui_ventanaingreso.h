/********************************************************************************
** Form generated from reading UI file 'ventanaingreso.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAINGRESO_H
#define UI_VENTANAINGRESO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaIngreso
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *ingresar;
    QPushButton *salir;
    QLabel *label_2;
    QTextEdit *txtId;

    void setupUi(QMainWindow *VentanaIngreso)
    {
        if (VentanaIngreso->objectName().isEmpty())
            VentanaIngreso->setObjectName(QString::fromUtf8("VentanaIngreso"));
        VentanaIngreso->resize(421, 228);
        VentanaIngreso->setMinimumSize(QSize(421, 228));
        VentanaIngreso->setMaximumSize(QSize(421, 228));
        centralWidget = new QWidget(VentanaIngreso);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 340, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label->setFont(font);
        ingresar = new QPushButton(centralWidget);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));
        ingresar->setGeometry(QRect(280, 170, 80, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(14);
        ingresar->setFont(font1);
        ingresar->setCursor(QCursor(Qt::PointingHandCursor));
        salir = new QPushButton(centralWidget);
        salir->setObjectName(QString::fromUtf8("salir"));
        salir->setGeometry(QRect(50, 170, 80, 31));
        salir->setFont(font1);
        salir->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(31, 101, 158, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        txtId = new QTextEdit(centralWidget);
        txtId->setObjectName(QString::fromUtf8("txtId"));
        txtId->setGeometry(QRect(195, 101, 165, 31));
        txtId->setFont(font2);
        VentanaIngreso->setCentralWidget(centralWidget);
        QWidget::setTabOrder(txtId, salir);
        QWidget::setTabOrder(salir, ingresar);

        retranslateUi(VentanaIngreso);
        QObject::connect(salir, SIGNAL(clicked()), VentanaIngreso, SLOT(close()));

        QMetaObject::connectSlotsByName(VentanaIngreso);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaIngreso)
    {
        VentanaIngreso->setWindowTitle(QApplication::translate("VentanaIngreso", "Ventana Ingreso", nullptr));
        label->setText(QApplication::translate("VentanaIngreso", "BIENVENIDO ADMINISTRADOR", nullptr));
        ingresar->setText(QApplication::translate("VentanaIngreso", "Ingresar", nullptr));
        salir->setText(QApplication::translate("VentanaIngreso", "Salir", nullptr));
        label_2->setText(QApplication::translate("VentanaIngreso", "Ingrese su identificaci\303\263n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaIngreso: public Ui_VentanaIngreso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAINGRESO_H
