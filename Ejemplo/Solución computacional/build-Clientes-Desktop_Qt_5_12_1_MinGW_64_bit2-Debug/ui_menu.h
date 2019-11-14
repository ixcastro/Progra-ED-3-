/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QLabel *label_2;
    QPushButton *botCons;
    QPushButton *botRes;
    QPushButton *botFac;
    QPushButton *botBR;
    QLabel *fondo;
    QPushButton *btSalir;
    QPushButton *botBR_2;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(981, 600);
        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(740, 10, 193, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label_2->setFont(font);
        botCons = new QPushButton(Menu);
        botCons->setObjectName(QString::fromUtf8("botCons"));
        botCons->setGeometry(QRect(720, 160, 239, 34));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(16);
        botCons->setFont(font1);
        botCons->setCursor(QCursor(Qt::PointingHandCursor));
        botRes = new QPushButton(Menu);
        botRes->setObjectName(QString::fromUtf8("botRes"));
        botRes->setGeometry(QRect(720, 200, 239, 34));
        botRes->setFont(font1);
        botRes->setCursor(QCursor(Qt::PointingHandCursor));
        botFac = new QPushButton(Menu);
        botFac->setObjectName(QString::fromUtf8("botFac"));
        botFac->setGeometry(QRect(720, 240, 239, 34));
        botFac->setFont(font1);
        botFac->setCursor(QCursor(Qt::PointingHandCursor));
        botBR = new QPushButton(Menu);
        botBR->setObjectName(QString::fromUtf8("botBR"));
        botBR->setGeometry(QRect(720, 280, 239, 34));
        botBR->setFont(font1);
        botBR->setCursor(QCursor(Qt::PointingHandCursor));
        fondo = new QLabel(Menu);
        fondo->setObjectName(QString::fromUtf8("fondo"));
        fondo->setGeometry(QRect(10, 10, 631, 571));
        fondo->setStyleSheet(QString::fromUtf8("border-image: url(:/MAPA.jpg) 0 0 0 0 stretch stretch;\n"
"border-bottom-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        btSalir = new QPushButton(Menu);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(720, 500, 239, 34));
        btSalir->setFont(font1);
        btSalir->setCursor(QCursor(Qt::PointingHandCursor));
        botBR_2 = new QPushButton(Menu);
        botBR_2->setObjectName(QString::fromUtf8("botBR_2"));
        botBR_2->setGeometry(QRect(720, 320, 239, 34));
        botBR_2->setFont(font1);
        botBR_2->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(Menu);
        QObject::connect(btSalir, SIGNAL(clicked()), Menu, SLOT(close()));

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", nullptr));
        label_2->setText(QApplication::translate("Menu", "MENU PRINCIPAL", nullptr));
        botCons->setText(QApplication::translate("Menu", "CONSULTAR", nullptr));
        botRes->setText(QApplication::translate("Menu", "RESERVAR", nullptr));
        botFac->setText(QApplication::translate("Menu", "FACTURAR", nullptr));
        botBR->setText(QApplication::translate("Menu", "BUSCAR RUTA", nullptr));
        fondo->setText(QString());
        btSalir->setText(QApplication::translate("Menu", "SALIR", nullptr));
        botBR_2->setText(QApplication::translate("Menu", "NUEVA RUTA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
