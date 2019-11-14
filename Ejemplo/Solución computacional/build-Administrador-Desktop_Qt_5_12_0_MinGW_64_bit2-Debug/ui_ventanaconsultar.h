/********************************************************************************
** Form generated from reading UI file 'ventanaconsultar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANACONSULTAR_H
#define UI_VENTANACONSULTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaConsultar
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *consultarRutas;
    QPushButton *btConsR_3;
    QPushButton *btSalir_8;
    QTextEdit *txtCodTTren_3;
    QLabel *label_49;
    QTextEdit *txtRutas_3;
    QLabel *label_47;
    QLabel *label_48;
    QTextEdit *txtCodTren_3;
    QWidget *consultarPrecio;
    QPushButton *btConsPre_2;
    QLabel *label_29;
    QTextEdit *txtR;
    QPushButton *btSalir_4;
    QTextEdit *txtConsPrec_2;
    QLabel *label_30;
    QTextEdit *txtT;
    QTextEdit *txtTT;
    QLabel *label_31;
    QLabel *label_28;
    QWidget *consultarCiudades;
    QTextEdit *textEdit_5;
    QPushButton *btCancelarTiempo_2;
    QPushButton *btCancelarPrecio_7;
    QLabel *label_7;
    QTextEdit *txtCodPaisSalida_7;
    QLabel *label_15;
    QWidget *consultarConexiones;
    QLabel *label_6;
    QPushButton *btCancelarPrecio_3;
    QLabel *label_14;
    QPushButton *btCancelarPrecio_6;
    QTextEdit *textEdit_4;
    QTextEdit *txtCodPaisSalida_5;
    QWidget *consultarTrenes;
    QPushButton *btSali2_3;
    QPushButton *btnConsT_3;
    QLabel *label_51;
    QTextEdit *txtConsultarT_3;
    QLabel *label_50;
    QTextEdit *txtCodT_5;

    void setupUi(QWidget *VentanaConsultar)
    {
        if (VentanaConsultar->objectName().isEmpty())
            VentanaConsultar->setObjectName(QString::fromUtf8("VentanaConsultar"));
        VentanaConsultar->resize(761, 462);
        gridLayout = new QGridLayout(VentanaConsultar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(VentanaConsultar);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        consultarRutas = new QWidget();
        consultarRutas->setObjectName(QString::fromUtf8("consultarRutas"));
        btConsR_3 = new QPushButton(consultarRutas);
        btConsR_3->setObjectName(QString::fromUtf8("btConsR_3"));
        btConsR_3->setGeometry(QRect(640, 360, 80, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(14);
        btConsR_3->setFont(font);
        btConsR_3->setCursor(QCursor(Qt::PointingHandCursor));
        btSalir_8 = new QPushButton(consultarRutas);
        btSalir_8->setObjectName(QString::fromUtf8("btSalir_8"));
        btSalir_8->setGeometry(QRect(30, 370, 80, 31));
        btSalir_8->setFont(font);
        btSalir_8->setCursor(QCursor(Qt::PointingHandCursor));
        txtCodTTren_3 = new QTextEdit(consultarRutas);
        txtCodTTren_3->setObjectName(QString::fromUtf8("txtCodTTren_3"));
        txtCodTTren_3->setGeometry(QRect(440, 80, 171, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(12);
        txtCodTTren_3->setFont(font1);
        label_49 = new QLabel(consultarRutas);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(340, 10, 81, 36));
        QFont font2;
        font2.setFamily(QString::fromUtf8("HP Simplified Light"));
        font2.setPointSize(22);
        label_49->setFont(font2);
        txtRutas_3 = new QTextEdit(consultarRutas);
        txtRutas_3->setObjectName(QString::fromUtf8("txtRutas_3"));
        txtRutas_3->setGeometry(QRect(120, 190, 501, 161));
        label_47 = new QLabel(consultarRutas);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(120, 120, 270, 22));
        label_47->setFont(font);
        label_48 = new QLabel(consultarRutas);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(120, 80, 270, 22));
        label_48->setFont(font);
        txtCodTren_3 = new QTextEdit(consultarRutas);
        txtCodTren_3->setObjectName(QString::fromUtf8("txtCodTren_3"));
        txtCodTren_3->setGeometry(QRect(440, 120, 171, 31));
        txtCodTren_3->setFont(font1);
        tabWidget->addTab(consultarRutas, QString());
        consultarPrecio = new QWidget();
        consultarPrecio->setObjectName(QString::fromUtf8("consultarPrecio"));
        btConsPre_2 = new QPushButton(consultarPrecio);
        btConsPre_2->setObjectName(QString::fromUtf8("btConsPre_2"));
        btConsPre_2->setGeometry(QRect(630, 380, 80, 31));
        btConsPre_2->setFont(font);
        btConsPre_2->setCursor(QCursor(Qt::PointingHandCursor));
        label_29 = new QLabel(consultarPrecio);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(80, 120, 270, 22));
        label_29->setFont(font);
        txtR = new QTextEdit(consultarPrecio);
        txtR->setObjectName(QString::fromUtf8("txtR"));
        txtR->setGeometry(QRect(470, 150, 171, 31));
        txtR->setFont(font1);
        btSalir_4 = new QPushButton(consultarPrecio);
        btSalir_4->setObjectName(QString::fromUtf8("btSalir_4"));
        btSalir_4->setGeometry(QRect(60, 380, 80, 31));
        btSalir_4->setFont(font);
        btSalir_4->setCursor(QCursor(Qt::PointingHandCursor));
        txtConsPrec_2 = new QTextEdit(consultarPrecio);
        txtConsPrec_2->setObjectName(QString::fromUtf8("txtConsPrec_2"));
        txtConsPrec_2->setGeometry(QRect(120, 190, 501, 161));
        label_30 = new QLabel(consultarPrecio);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(80, 160, 270, 22));
        label_30->setFont(font);
        txtT = new QTextEdit(consultarPrecio);
        txtT->setObjectName(QString::fromUtf8("txtT"));
        txtT->setGeometry(QRect(470, 110, 171, 31));
        txtT->setFont(font1);
        txtTT = new QTextEdit(consultarPrecio);
        txtTT->setObjectName(QString::fromUtf8("txtTT"));
        txtTT->setGeometry(QRect(470, 70, 171, 31));
        txtTT->setFont(font1);
        label_31 = new QLabel(consultarPrecio);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(350, 20, 91, 36));
        label_31->setFont(font2);
        label_28 = new QLabel(consultarPrecio);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(80, 80, 270, 22));
        label_28->setFont(font);
        tabWidget->addTab(consultarPrecio, QString());
        consultarCiudades = new QWidget();
        consultarCiudades->setObjectName(QString::fromUtf8("consultarCiudades"));
        textEdit_5 = new QTextEdit(consultarCiudades);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(130, 130, 501, 161));
        btCancelarTiempo_2 = new QPushButton(consultarCiudades);
        btCancelarTiempo_2->setObjectName(QString::fromUtf8("btCancelarTiempo_2"));
        btCancelarTiempo_2->setGeometry(QRect(50, 370, 80, 31));
        btCancelarTiempo_2->setFont(font);
        btCancelarTiempo_2->setCursor(QCursor(Qt::PointingHandCursor));
        btCancelarPrecio_7 = new QPushButton(consultarCiudades);
        btCancelarPrecio_7->setObjectName(QString::fromUtf8("btCancelarPrecio_7"));
        btCancelarPrecio_7->setGeometry(QRect(640, 360, 80, 31));
        btCancelarPrecio_7->setFont(font);
        btCancelarPrecio_7->setCursor(QCursor(Qt::PointingHandCursor));
        label_7 = new QLabel(consultarCiudades);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 10, 121, 36));
        label_7->setFont(font2);
        txtCodPaisSalida_7 = new QTextEdit(consultarCiudades);
        txtCodPaisSalida_7->setObjectName(QString::fromUtf8("txtCodPaisSalida_7"));
        txtCodPaisSalida_7->setGeometry(QRect(480, 80, 171, 31));
        txtCodPaisSalida_7->setFont(font1);
        label_15 = new QLabel(consultarCiudades);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(90, 90, 270, 22));
        label_15->setFont(font);
        tabWidget->addTab(consultarCiudades, QString());
        consultarConexiones = new QWidget();
        consultarConexiones->setObjectName(QString::fromUtf8("consultarConexiones"));
        label_6 = new QLabel(consultarConexiones);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 10, 151, 36));
        label_6->setFont(font2);
        btCancelarPrecio_3 = new QPushButton(consultarConexiones);
        btCancelarPrecio_3->setObjectName(QString::fromUtf8("btCancelarPrecio_3"));
        btCancelarPrecio_3->setGeometry(QRect(60, 370, 80, 31));
        btCancelarPrecio_3->setFont(font);
        btCancelarPrecio_3->setCursor(QCursor(Qt::PointingHandCursor));
        label_14 = new QLabel(consultarConexiones);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 90, 270, 22));
        label_14->setFont(font);
        btCancelarPrecio_6 = new QPushButton(consultarConexiones);
        btCancelarPrecio_6->setObjectName(QString::fromUtf8("btCancelarPrecio_6"));
        btCancelarPrecio_6->setGeometry(QRect(630, 370, 80, 31));
        btCancelarPrecio_6->setFont(font);
        btCancelarPrecio_6->setCursor(QCursor(Qt::PointingHandCursor));
        textEdit_4 = new QTextEdit(consultarConexiones);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(140, 170, 501, 161));
        txtCodPaisSalida_5 = new QTextEdit(consultarConexiones);
        txtCodPaisSalida_5->setObjectName(QString::fromUtf8("txtCodPaisSalida_5"));
        txtCodPaisSalida_5->setGeometry(QRect(470, 80, 171, 31));
        txtCodPaisSalida_5->setFont(font1);
        tabWidget->addTab(consultarConexiones, QString());
        consultarTrenes = new QWidget();
        consultarTrenes->setObjectName(QString::fromUtf8("consultarTrenes"));
        btSali2_3 = new QPushButton(consultarTrenes);
        btSali2_3->setObjectName(QString::fromUtf8("btSali2_3"));
        btSali2_3->setGeometry(QRect(40, 370, 80, 31));
        btSali2_3->setFont(font);
        btSali2_3->setCursor(QCursor(Qt::PointingHandCursor));
        btnConsT_3 = new QPushButton(consultarTrenes);
        btnConsT_3->setObjectName(QString::fromUtf8("btnConsT_3"));
        btnConsT_3->setGeometry(QRect(650, 360, 80, 31));
        btnConsT_3->setFont(font);
        btnConsT_3->setCursor(QCursor(Qt::PointingHandCursor));
        label_51 = new QLabel(consultarTrenes);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(120, 80, 270, 22));
        label_51->setFont(font);
        txtConsultarT_3 = new QTextEdit(consultarTrenes);
        txtConsultarT_3->setObjectName(QString::fromUtf8("txtConsultarT_3"));
        txtConsultarT_3->setGeometry(QRect(120, 140, 501, 161));
        label_50 = new QLabel(consultarTrenes);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(350, 10, 91, 36));
        label_50->setFont(font2);
        txtCodT_5 = new QTextEdit(consultarTrenes);
        txtCodT_5->setObjectName(QString::fromUtf8("txtCodT_5"));
        txtCodT_5->setGeometry(QRect(480, 80, 171, 31));
        txtCodT_5->setFont(font1);
        tabWidget->addTab(consultarTrenes, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(VentanaConsultar);
        QObject::connect(btSalir_8, SIGNAL(clicked()), VentanaConsultar, SLOT(close()));
        QObject::connect(btSalir_4, SIGNAL(clicked()), VentanaConsultar, SLOT(close()));
        QObject::connect(btCancelarTiempo_2, SIGNAL(clicked()), VentanaConsultar, SLOT(close()));
        QObject::connect(btCancelarPrecio_3, SIGNAL(clicked()), VentanaConsultar, SLOT(close()));
        QObject::connect(btSali2_3, SIGNAL(clicked()), VentanaConsultar, SLOT(close()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(VentanaConsultar);
    } // setupUi

    void retranslateUi(QWidget *VentanaConsultar)
    {
        VentanaConsultar->setWindowTitle(QApplication::translate("VentanaConsultar", "Consultar datos", nullptr));
        btConsR_3->setText(QApplication::translate("VentanaConsultar", "Consultar", nullptr));
        btSalir_8->setText(QApplication::translate("VentanaConsultar", "Salir", nullptr));
        label_49->setText(QApplication::translate("VentanaConsultar", "RUTAS", nullptr));
        label_47->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del tren: ", nullptr));
        label_48->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(consultarRutas), QApplication::translate("VentanaConsultar", "Rutas de un tren", nullptr));
        btConsPre_2->setText(QApplication::translate("VentanaConsultar", "Consultar", nullptr));
        label_29->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del tren: ", nullptr));
        btSalir_4->setText(QApplication::translate("VentanaConsultar", "Salir", nullptr));
        label_30->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo de la ruta: ", nullptr));
        label_31->setText(QApplication::translate("VentanaConsultar", "PRECIO", nullptr));
        label_28->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(consultarPrecio), QApplication::translate("VentanaConsultar", "Precio de una ruta", nullptr));
        btCancelarTiempo_2->setText(QApplication::translate("VentanaConsultar", "Salir", nullptr));
        btCancelarPrecio_7->setText(QApplication::translate("VentanaConsultar", "Consultar", nullptr));
        label_7->setText(QApplication::translate("VentanaConsultar", "CIUDADES", nullptr));
        label_15->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del pa\303\255s: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(consultarCiudades), QApplication::translate("VentanaConsultar", "Ciudades", nullptr));
        label_6->setText(QApplication::translate("VentanaConsultar", "CONEXIONES", nullptr));
        btCancelarPrecio_3->setText(QApplication::translate("VentanaConsultar", "Salir", nullptr));
        label_14->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del pa\303\255s: ", nullptr));
        btCancelarPrecio_6->setText(QApplication::translate("VentanaConsultar", "Consultar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(consultarConexiones), QApplication::translate("VentanaConsultar", "Conexiones", nullptr));
        btSali2_3->setText(QApplication::translate("VentanaConsultar", "Salir", nullptr));
        btnConsT_3->setText(QApplication::translate("VentanaConsultar", "Consultar", nullptr));
        label_51->setText(QApplication::translate("VentanaConsultar", "Ingrese el c\303\263digo del tipo de tren: ", nullptr));
        label_50->setText(QApplication::translate("VentanaConsultar", "TRENES", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(consultarTrenes), QApplication::translate("VentanaConsultar", "Trenes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaConsultar: public Ui_VentanaConsultar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANACONSULTAR_H
