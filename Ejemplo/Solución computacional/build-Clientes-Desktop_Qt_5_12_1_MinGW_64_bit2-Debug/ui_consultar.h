/********************************************************************************
** Form generated from reading UI file 'consultar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTAR_H
#define UI_CONSULTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Consultar
{
public:
    QTabWidget *Paises;
    QWidget *consultarPaises;
    QPushButton *btSalir;
    QLabel *label_3;
    QTextEdit *txtConsultarPaises;
    QPushButton *btConsPaises;
    QWidget *modificarTiempo;
    QPushButton *btCancelarTiempo;
    QTextEdit *textEdit_2;
    QLabel *label_9;
    QTextEdit *txtCodPaisSalida_2;
    QLabel *label_2;
    QPushButton *btCancelarPrecio_5;
    QWidget *tab;
    QTextEdit *textEdit_3;
    QLabel *label_10;
    QTextEdit *txtCodPaisSalida_3;
    QLabel *label_4;
    QPushButton *btCancelarPrecio_2;
    QPushButton *btCancelarPrecio_4;
    QWidget *modificarAsientos;
    QPushButton *btSali2;
    QPushButton *btnConsT;
    QLabel *label_5;
    QTextEdit *txtCodT;
    QTextEdit *txtConsultarT;
    QLabel *label_12;
    QWidget *tab_2;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *btConsPre;
    QTextEdit *txtCiudad;
    QTextEdit *txtPais;
    QLabel *label_20;
    QPushButton *btSalir_3;
    QTextEdit *txtConsPrec;
    QLabel *label_21;
    QTextEdit *txtCone;
    QWidget *tab_5;
    QTextEdit *txtCodTT;
    QPushButton *btSalir6;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *btConsNA;
    QTextEdit *txtCNA;
    QLabel *label_26;
    QTextEdit *txtCodT_2;
    QWidget *tab_6;
    QTextEdit *txtCodTTren;
    QPushButton *btSalir_2;
    QLabel *label_24;
    QLabel *label_25;
    QPushButton *btConsR;
    QTextEdit *txtRutas;
    QLabel *label_27;
    QTextEdit *txtCodTren;

    void setupUi(QWidget *Consultar)
    {
        if (Consultar->objectName().isEmpty())
            Consultar->setObjectName(QString::fromUtf8("Consultar"));
        Consultar->resize(762, 473);
        Paises = new QTabWidget(Consultar);
        Paises->setObjectName(QString::fromUtf8("Paises"));
        Paises->setGeometry(QRect(10, 10, 731, 461));
        consultarPaises = new QWidget();
        consultarPaises->setObjectName(QString::fromUtf8("consultarPaises"));
        btSalir = new QPushButton(consultarPaises);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(30, 390, 80, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(14);
        btSalir->setFont(font);
        btSalir->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(consultarPaises);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 10, 81, 36));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(22);
        label_3->setFont(font1);
        txtConsultarPaises = new QTextEdit(consultarPaises);
        txtConsultarPaises->setObjectName(QString::fromUtf8("txtConsultarPaises"));
        txtConsultarPaises->setGeometry(QRect(100, 50, 501, 301));
        btConsPaises = new QPushButton(consultarPaises);
        btConsPaises->setObjectName(QString::fromUtf8("btConsPaises"));
        btConsPaises->setGeometry(QRect(600, 390, 81, 32));
        btConsPaises->setFont(font);
        btConsPaises->setCursor(QCursor(Qt::PointingHandCursor));
        Paises->addTab(consultarPaises, QString());
        modificarTiempo = new QWidget();
        modificarTiempo->setObjectName(QString::fromUtf8("modificarTiempo"));
        btCancelarTiempo = new QPushButton(modificarTiempo);
        btCancelarTiempo->setObjectName(QString::fromUtf8("btCancelarTiempo"));
        btCancelarTiempo->setGeometry(QRect(30, 390, 80, 31));
        btCancelarTiempo->setFont(font);
        btCancelarTiempo->setCursor(QCursor(Qt::PointingHandCursor));
        textEdit_2 = new QTextEdit(modificarTiempo);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(110, 150, 501, 161));
        label_9 = new QLabel(modificarTiempo);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(110, 100, 270, 22));
        label_9->setFont(font);
        txtCodPaisSalida_2 = new QTextEdit(modificarTiempo);
        txtCodPaisSalida_2->setObjectName(QString::fromUtf8("txtCodPaisSalida_2"));
        txtCodPaisSalida_2->setGeometry(QRect(410, 100, 171, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(12);
        txtCodPaisSalida_2->setFont(font2);
        label_2 = new QLabel(modificarTiempo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 30, 121, 36));
        label_2->setFont(font1);
        btCancelarPrecio_5 = new QPushButton(modificarTiempo);
        btCancelarPrecio_5->setObjectName(QString::fromUtf8("btCancelarPrecio_5"));
        btCancelarPrecio_5->setGeometry(QRect(620, 390, 80, 31));
        btCancelarPrecio_5->setFont(font);
        btCancelarPrecio_5->setCursor(QCursor(Qt::PointingHandCursor));
        Paises->addTab(modificarTiempo, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit_3 = new QTextEdit(tab);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(110, 180, 501, 161));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 100, 199, 22));
        label_10->setFont(font);
        txtCodPaisSalida_3 = new QTextEdit(tab);
        txtCodPaisSalida_3->setObjectName(QString::fromUtf8("txtCodPaisSalida_3"));
        txtCodPaisSalida_3->setGeometry(QRect(440, 90, 171, 31));
        txtCodPaisSalida_3->setFont(font2);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 20, 151, 36));
        label_4->setFont(font1);
        btCancelarPrecio_2 = new QPushButton(tab);
        btCancelarPrecio_2->setObjectName(QString::fromUtf8("btCancelarPrecio_2"));
        btCancelarPrecio_2->setGeometry(QRect(30, 380, 80, 31));
        btCancelarPrecio_2->setFont(font);
        btCancelarPrecio_2->setCursor(QCursor(Qt::PointingHandCursor));
        btCancelarPrecio_4 = new QPushButton(tab);
        btCancelarPrecio_4->setObjectName(QString::fromUtf8("btCancelarPrecio_4"));
        btCancelarPrecio_4->setGeometry(QRect(600, 380, 80, 31));
        btCancelarPrecio_4->setFont(font);
        btCancelarPrecio_4->setCursor(QCursor(Qt::PointingHandCursor));
        Paises->addTab(tab, QString());
        modificarAsientos = new QWidget();
        modificarAsientos->setObjectName(QString::fromUtf8("modificarAsientos"));
        btSali2 = new QPushButton(modificarAsientos);
        btSali2->setObjectName(QString::fromUtf8("btSali2"));
        btSali2->setGeometry(QRect(10, 390, 80, 31));
        btSali2->setFont(font);
        btSali2->setCursor(QCursor(Qt::PointingHandCursor));
        btnConsT = new QPushButton(modificarAsientos);
        btnConsT->setObjectName(QString::fromUtf8("btnConsT"));
        btnConsT->setGeometry(QRect(620, 380, 80, 31));
        btnConsT->setFont(font);
        btnConsT->setCursor(QCursor(Qt::PointingHandCursor));
        label_5 = new QLabel(modificarAsientos);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(320, 30, 91, 36));
        label_5->setFont(font1);
        txtCodT = new QTextEdit(modificarAsientos);
        txtCodT->setObjectName(QString::fromUtf8("txtCodT"));
        txtCodT->setGeometry(QRect(450, 100, 171, 31));
        txtCodT->setFont(font2);
        txtConsultarT = new QTextEdit(modificarAsientos);
        txtConsultarT->setObjectName(QString::fromUtf8("txtConsultarT"));
        txtConsultarT->setGeometry(QRect(90, 160, 501, 161));
        label_12 = new QLabel(modificarAsientos);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(90, 100, 270, 22));
        label_12->setFont(font);
        Paises->addTab(modificarAsientos, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(50, 80, 270, 22));
        label_18->setFont(font);
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 120, 270, 22));
        label_19->setFont(font);
        btConsPre = new QPushButton(tab_2);
        btConsPre->setObjectName(QString::fromUtf8("btConsPre"));
        btConsPre->setGeometry(QRect(600, 380, 80, 31));
        btConsPre->setFont(font);
        btConsPre->setCursor(QCursor(Qt::PointingHandCursor));
        txtCiudad = new QTextEdit(tab_2);
        txtCiudad->setObjectName(QString::fromUtf8("txtCiudad"));
        txtCiudad->setGeometry(QRect(440, 110, 171, 31));
        txtCiudad->setFont(font2);
        txtPais = new QTextEdit(tab_2);
        txtPais->setObjectName(QString::fromUtf8("txtPais"));
        txtPais->setGeometry(QRect(440, 70, 171, 31));
        txtPais->setFont(font2);
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(320, 20, 91, 36));
        label_20->setFont(font1);
        btSalir_3 = new QPushButton(tab_2);
        btSalir_3->setObjectName(QString::fromUtf8("btSalir_3"));
        btSalir_3->setGeometry(QRect(30, 380, 80, 31));
        btSalir_3->setFont(font);
        btSalir_3->setCursor(QCursor(Qt::PointingHandCursor));
        txtConsPrec = new QTextEdit(tab_2);
        txtConsPrec->setObjectName(QString::fromUtf8("txtConsPrec"));
        txtConsPrec->setGeometry(QRect(110, 190, 501, 161));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(50, 160, 270, 22));
        label_21->setFont(font);
        txtCone = new QTextEdit(tab_2);
        txtCone->setObjectName(QString::fromUtf8("txtCone"));
        txtCone->setGeometry(QRect(440, 150, 171, 31));
        txtCone->setFont(font2);
        Paises->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        txtCodTT = new QTextEdit(tab_5);
        txtCodTT->setObjectName(QString::fromUtf8("txtCodTT"));
        txtCodTT->setGeometry(QRect(450, 90, 171, 31));
        txtCodTT->setFont(font2);
        btSalir6 = new QPushButton(tab_5);
        btSalir6->setObjectName(QString::fromUtf8("btSalir6"));
        btSalir6->setGeometry(QRect(20, 380, 80, 31));
        btSalir6->setFont(font);
        btSalir6->setCursor(QCursor(Qt::PointingHandCursor));
        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(220, 20, 261, 36));
        label_22->setFont(font1);
        label_23 = new QLabel(tab_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(90, 90, 270, 22));
        label_23->setFont(font);
        btConsNA = new QPushButton(tab_5);
        btConsNA->setObjectName(QString::fromUtf8("btConsNA"));
        btConsNA->setGeometry(QRect(650, 380, 80, 31));
        btConsNA->setFont(font);
        btConsNA->setCursor(QCursor(Qt::PointingHandCursor));
        txtCNA = new QTextEdit(tab_5);
        txtCNA->setObjectName(QString::fromUtf8("txtCNA"));
        txtCNA->setGeometry(QRect(90, 190, 551, 171));
        label_26 = new QLabel(tab_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(90, 140, 270, 22));
        label_26->setFont(font);
        txtCodT_2 = new QTextEdit(tab_5);
        txtCodT_2->setObjectName(QString::fromUtf8("txtCodT_2"));
        txtCodT_2->setGeometry(QRect(450, 130, 171, 31));
        txtCodT_2->setFont(font2);
        Paises->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        txtCodTTren = new QTextEdit(tab_6);
        txtCodTTren->setObjectName(QString::fromUtf8("txtCodTTren"));
        txtCodTTren->setGeometry(QRect(420, 90, 171, 31));
        txtCodTTren->setFont(font2);
        btSalir_2 = new QPushButton(tab_6);
        btSalir_2->setObjectName(QString::fromUtf8("btSalir_2"));
        btSalir_2->setGeometry(QRect(10, 380, 80, 31));
        btSalir_2->setFont(font);
        btSalir_2->setCursor(QCursor(Qt::PointingHandCursor));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(320, 20, 81, 36));
        label_24->setFont(font1);
        label_25 = new QLabel(tab_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(100, 90, 270, 22));
        label_25->setFont(font);
        btConsR = new QPushButton(tab_6);
        btConsR->setObjectName(QString::fromUtf8("btConsR"));
        btConsR->setGeometry(QRect(620, 370, 80, 31));
        btConsR->setFont(font);
        btConsR->setCursor(QCursor(Qt::PointingHandCursor));
        txtRutas = new QTextEdit(tab_6);
        txtRutas->setObjectName(QString::fromUtf8("txtRutas"));
        txtRutas->setGeometry(QRect(100, 200, 501, 161));
        label_27 = new QLabel(tab_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(100, 130, 270, 22));
        label_27->setFont(font);
        txtCodTren = new QTextEdit(tab_6);
        txtCodTren->setObjectName(QString::fromUtf8("txtCodTren"));
        txtCodTren->setGeometry(QRect(420, 130, 171, 31));
        txtCodTren->setFont(font2);
        Paises->addTab(tab_6, QString());

        retranslateUi(Consultar);
        QObject::connect(btSalir, SIGNAL(clicked()), Consultar, SLOT(close()));
        QObject::connect(btCancelarTiempo, SIGNAL(clicked()), Consultar, SLOT(close()));
        QObject::connect(btCancelarPrecio_2, SIGNAL(clicked()), Consultar, SLOT(close()));
        QObject::connect(btSali2, SIGNAL(clicked()), Consultar, SLOT(close()));
        QObject::connect(btSalir_3, SIGNAL(clicked()), Consultar, SLOT(close()));
        QObject::connect(btSalir6, SIGNAL(clicked()), Consultar, SLOT(close()));
        QObject::connect(btSalir_2, SIGNAL(clicked()), Consultar, SLOT(close()));

        Paises->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Consultar);
    } // setupUi

    void retranslateUi(QWidget *Consultar)
    {
        Consultar->setWindowTitle(QApplication::translate("Consultar", "Form", nullptr));
        btSalir->setText(QApplication::translate("Consultar", "Salir", nullptr));
        label_3->setText(QApplication::translate("Consultar", "PAISES", nullptr));
        btConsPaises->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        Paises->setTabText(Paises->indexOf(consultarPaises), QApplication::translate("Consultar", "Paises", nullptr));
        btCancelarTiempo->setText(QApplication::translate("Consultar", "Salir", nullptr));
        label_9->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del pa\303\255s: ", nullptr));
        label_2->setText(QApplication::translate("Consultar", "CIUDADES", nullptr));
        btCancelarPrecio_5->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        Paises->setTabText(Paises->indexOf(modificarTiempo), QApplication::translate("Consultar", "Ciudades", nullptr));
        label_10->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del pa\303\255s: ", nullptr));
        label_4->setText(QApplication::translate("Consultar", "CONEXIONES", nullptr));
        btCancelarPrecio_2->setText(QApplication::translate("Consultar", "Salir", nullptr));
        btCancelarPrecio_4->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        Paises->setTabText(Paises->indexOf(tab), QApplication::translate("Consultar", "Conexiones", nullptr));
        btSali2->setText(QApplication::translate("Consultar", "Salir", nullptr));
        btnConsT->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        label_5->setText(QApplication::translate("Consultar", "TRENES", nullptr));
        label_12->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        Paises->setTabText(Paises->indexOf(modificarAsientos), QApplication::translate("Consultar", "Trenes", nullptr));
        label_18->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del pa\303\255s: ", nullptr));
        label_19->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo de la ciudad: ", nullptr));
        btConsPre->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        label_20->setText(QApplication::translate("Consultar", "PRECIO", nullptr));
        btSalir_3->setText(QApplication::translate("Consultar", "Salir", nullptr));
        label_21->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo de la conexi\303\263n: ", nullptr));
        Paises->setTabText(Paises->indexOf(tab_2), QApplication::translate("Consultar", "Precio", nullptr));
        btSalir6->setText(QApplication::translate("Consultar", "Salir", nullptr));
        label_22->setText(QApplication::translate("Consultar", "N\303\232MERO DE ASIENTOS", nullptr));
        label_23->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        btConsNA->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        label_26->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del tren: ", nullptr));
        Paises->setTabText(Paises->indexOf(tab_5), QApplication::translate("Consultar", "N\303\272mero de asientos", nullptr));
        btSalir_2->setText(QApplication::translate("Consultar", "Salir", nullptr));
        label_24->setText(QApplication::translate("Consultar", "RUTAS", nullptr));
        label_25->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        btConsR->setText(QApplication::translate("Consultar", "Consultar", nullptr));
        label_27->setText(QApplication::translate("Consultar", "Ingrese el c\303\263digo del tren: ", nullptr));
        Paises->setTabText(Paises->indexOf(tab_6), QApplication::translate("Consultar", "Rutas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Consultar: public Ui_Consultar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTAR_H
