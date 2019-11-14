/********************************************************************************
** Form generated from reading UI file 'ventanareportes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAREPORTES_H
#define UI_VENTANAREPORTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaReportes
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTextEdit *txtPaises;
    QPushButton *btGenerarReportePaises;
    QPushButton *pushButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QTextEdit *txtCiudades;
    QPushButton *btGenerarReporteCiudades;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QTextEdit *txtConexiones;
    QPushButton *btGenerarReporteConexiones;
    QPushButton *pushButton_3;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QTextEdit *txtTrenes;
    QPushButton *btGenerarReporteTrenes;
    QPushButton *pushButton_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QTextEdit *txtPrecio;
    QLabel *label_3;
    QLineEdit *txtCodCiudad;
    QPushButton *btGenerarReportePrecios;
    QLineEdit *txtCodPais;
    QLabel *label;
    QPushButton *pushButton_5;
    QFrame *line;
    QLineEdit *txtCodConexion;
    QWidget *tab_6;
    QGridLayout *gridLayout_35;
    QGridLayout *gridLayout_7;
    QTextEdit *txtPrecio_2;
    QLabel *label_6;
    QFrame *line_2;
    QPushButton *btGenerarReportePrecios_2;
    QLabel *label_4;
    QLineEdit *txtCodTipoTren;
    QPushButton *pushButton_6;
    QLineEdit *txtCodTren;
    QWidget *tab7;
    QGridLayout *gridLayout_8;
    QTextEdit *txtUltimoPais;
    QPushButton *btGenerarReporteUltimoPais;
    QPushButton *pushButton_7;
    QWidget *tab_7;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QTextEdit *txtUltimaCiudad;
    QPushButton *btGenerarReporteUltimaCiudad;
    QPushButton *pushButton_8;
    QWidget *tab_8;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_11;
    QTextEdit *txtUltimaConexion;
    QPushButton *btGenerarReporteUltimaConexion;
    QPushButton *pushButton_9;
    QWidget *tab_10;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_15;
    QTextEdit *txtUltimoTipo;
    QPushButton *btGenerarReporteUltimoTipo;
    QPushButton *pushButton_11;
    QWidget *tab_9;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_13;
    QTextEdit *txtUltimoTren;
    QPushButton *btGenerarReporteUltimoTren;
    QPushButton *pushButton_10;
    QWidget *tab_11;
    QGridLayout *gridLayout_18;
    QGridLayout *gridLayout_17;
    QTextEdit *txtUltimoRutaMas;
    QPushButton *btGenerarReporteRutaMas;
    QPushButton *pushButton_12;
    QWidget *tab_12;
    QGridLayout *gridLayout_20;
    QGridLayout *gridLayout_19;
    QTextEdit *txtRutaMenos;
    QPushButton *btGenerarReporteRutaMenos;
    QPushButton *pushButton_13;
    QWidget *tab_13;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_21;
    QTextEdit *txtPaisMas;
    QPushButton *btGenerarReportePaisMas;
    QPushButton *pushButton_14;
    QWidget *tab_14;
    QGridLayout *gridLayout_24;
    QGridLayout *gridLayout_23;
    QTextEdit *txtCiudadMas;
    QPushButton *btGenerarReporteCiudadMas;
    QPushButton *pushButton_15;
    QWidget *tab_15;
    QGridLayout *gridLayout_26;
    QGridLayout *gridLayout_25;
    QTextEdit *txtUsuarioMas;
    QPushButton *btGenerarReporteUsuarioMas;
    QPushButton *pushButton_16;
    QWidget *tab_16;
    QGridLayout *gridLayout_28;
    QGridLayout *gridLayout_27;
    QTextEdit *txtUsuarioMenos;
    QPushButton *btGenerarReporteUsuarioMenos;
    QPushButton *pushButton_17;
    QWidget *tab_17;
    QGridLayout *gridLayout_30;
    QGridLayout *gridLayout_29;
    QTextEdit *txtCantComprasUsuario;
    QPushButton *btGenerarReporteCantComprasUsuario;
    QPushButton *pushButton_18;
    QWidget *tab_18;
    QGridLayout *gridLayout_32;
    QGridLayout *gridLayout_31;
    QTextEdit *txtTrenMas;
    QPushButton *btGenerarReporteTrenMas;
    QPushButton *pushButton_19;
    QWidget *tab_19;
    QGridLayout *gridLayout_34;
    QGridLayout *gridLayout_33;
    QTextEdit *txtTrenMenos;
    QPushButton *btGenerarReporteTrenMenos;
    QPushButton *pushButton_20;

    void setupUi(QWidget *VentanaReportes)
    {
        if (VentanaReportes->objectName().isEmpty())
            VentanaReportes->setObjectName(QString::fromUtf8("VentanaReportes"));
        VentanaReportes->resize(516, 479);
        gridLayout = new QGridLayout(VentanaReportes);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(VentanaReportes);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtPaises = new QTextEdit(tab);
        txtPaises->setObjectName(QString::fromUtf8("txtPaises"));
        txtPaises->setReadOnly(true);

        verticalLayout->addWidget(txtPaises);

        btGenerarReportePaises = new QPushButton(tab);
        btGenerarReportePaises->setObjectName(QString::fromUtf8("btGenerarReportePaises"));

        verticalLayout->addWidget(btGenerarReportePaises);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtCiudades = new QTextEdit(tab_2);
        txtCiudades->setObjectName(QString::fromUtf8("txtCiudades"));
        txtCiudades->setReadOnly(true);

        gridLayout_2->addWidget(txtCiudades, 0, 0, 1, 1);

        btGenerarReporteCiudades = new QPushButton(tab_2);
        btGenerarReporteCiudades->setObjectName(QString::fromUtf8("btGenerarReporteCiudades"));

        gridLayout_2->addWidget(btGenerarReporteCiudades, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        txtConexiones = new QTextEdit(tab_3);
        txtConexiones->setObjectName(QString::fromUtf8("txtConexiones"));
        txtConexiones->setReadOnly(true);

        gridLayout_4->addWidget(txtConexiones, 0, 0, 1, 1);

        btGenerarReporteConexiones = new QPushButton(tab_3);
        btGenerarReporteConexiones->setObjectName(QString::fromUtf8("btGenerarReporteConexiones"));

        gridLayout_4->addWidget(btGenerarReporteConexiones, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_4->addWidget(pushButton_3, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        txtTrenes = new QTextEdit(tab_4);
        txtTrenes->setObjectName(QString::fromUtf8("txtTrenes"));
        txtTrenes->setReadOnly(true);

        gridLayout_5->addWidget(txtTrenes, 0, 0, 1, 1);

        btGenerarReporteTrenes = new QPushButton(tab_4);
        btGenerarReporteTrenes->setObjectName(QString::fromUtf8("btGenerarReporteTrenes"));

        gridLayout_5->addWidget(btGenerarReporteTrenes, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(tab_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_5->addWidget(pushButton_4, 2, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(12);
        label_2->setFont(font);

        gridLayout_6->addWidget(label_2, 3, 0, 1, 1);

        txtPrecio = new QTextEdit(tab_5);
        txtPrecio->setObjectName(QString::fromUtf8("txtPrecio"));
        txtPrecio->setReadOnly(true);

        gridLayout_6->addWidget(txtPrecio, 8, 0, 1, 1);

        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout_6->addWidget(label_3, 5, 0, 1, 1);

        txtCodCiudad = new QLineEdit(tab_5);
        txtCodCiudad->setObjectName(QString::fromUtf8("txtCodCiudad"));

        gridLayout_6->addWidget(txtCodCiudad, 4, 0, 1, 1);

        btGenerarReportePrecios = new QPushButton(tab_5);
        btGenerarReportePrecios->setObjectName(QString::fromUtf8("btGenerarReportePrecios"));

        gridLayout_6->addWidget(btGenerarReportePrecios, 9, 0, 1, 1);

        txtCodPais = new QLineEdit(tab_5);
        txtCodPais->setObjectName(QString::fromUtf8("txtCodPais"));

        gridLayout_6->addWidget(txtCodPais, 2, 0, 1, 1);

        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_6->addWidget(label, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_6->addWidget(pushButton_5, 10, 0, 1, 1);

        line = new QFrame(tab_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 7, 0, 1, 1);

        txtCodConexion = new QLineEdit(tab_5);
        txtCodConexion->setObjectName(QString::fromUtf8("txtCodConexion"));

        gridLayout_6->addWidget(txtCodConexion, 6, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_35 = new QGridLayout(tab_6);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        txtPrecio_2 = new QTextEdit(tab_6);
        txtPrecio_2->setObjectName(QString::fromUtf8("txtPrecio_2"));
        txtPrecio_2->setReadOnly(true);

        gridLayout_7->addWidget(txtPrecio_2, 5, 0, 1, 1);

        label_6 = new QLabel(tab_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_7->addWidget(label_6, 2, 0, 1, 1);

        line_2 = new QFrame(tab_6);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_2, 4, 0, 1, 1);

        btGenerarReportePrecios_2 = new QPushButton(tab_6);
        btGenerarReportePrecios_2->setObjectName(QString::fromUtf8("btGenerarReportePrecios_2"));

        gridLayout_7->addWidget(btGenerarReportePrecios_2, 6, 0, 1, 1);

        label_4 = new QLabel(tab_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout_7->addWidget(label_4, 0, 0, 1, 1);

        txtCodTipoTren = new QLineEdit(tab_6);
        txtCodTipoTren->setObjectName(QString::fromUtf8("txtCodTipoTren"));

        gridLayout_7->addWidget(txtCodTipoTren, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(tab_6);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_7->addWidget(pushButton_6, 7, 0, 1, 1);

        txtCodTren = new QLineEdit(tab_6);
        txtCodTren->setObjectName(QString::fromUtf8("txtCodTren"));

        gridLayout_7->addWidget(txtCodTren, 3, 0, 1, 1);


        gridLayout_35->addLayout(gridLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab7 = new QWidget();
        tab7->setObjectName(QString::fromUtf8("tab7"));
        gridLayout_8 = new QGridLayout(tab7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        txtUltimoPais = new QTextEdit(tab7);
        txtUltimoPais->setObjectName(QString::fromUtf8("txtUltimoPais"));
        txtUltimoPais->setReadOnly(true);

        gridLayout_8->addWidget(txtUltimoPais, 0, 0, 1, 1);

        btGenerarReporteUltimoPais = new QPushButton(tab7);
        btGenerarReporteUltimoPais->setObjectName(QString::fromUtf8("btGenerarReporteUltimoPais"));

        gridLayout_8->addWidget(btGenerarReporteUltimoPais, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(tab7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout_8->addWidget(pushButton_7, 2, 0, 1, 1);

        tabWidget->addTab(tab7, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_10 = new QGridLayout(tab_7);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        txtUltimaCiudad = new QTextEdit(tab_7);
        txtUltimaCiudad->setObjectName(QString::fromUtf8("txtUltimaCiudad"));
        txtUltimaCiudad->setReadOnly(true);

        gridLayout_9->addWidget(txtUltimaCiudad, 0, 0, 1, 1);

        btGenerarReporteUltimaCiudad = new QPushButton(tab_7);
        btGenerarReporteUltimaCiudad->setObjectName(QString::fromUtf8("btGenerarReporteUltimaCiudad"));

        gridLayout_9->addWidget(btGenerarReporteUltimaCiudad, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(tab_7);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout_9->addWidget(pushButton_8, 2, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        gridLayout_12 = new QGridLayout(tab_8);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        txtUltimaConexion = new QTextEdit(tab_8);
        txtUltimaConexion->setObjectName(QString::fromUtf8("txtUltimaConexion"));
        txtUltimaConexion->setReadOnly(true);

        gridLayout_11->addWidget(txtUltimaConexion, 0, 0, 1, 1);

        btGenerarReporteUltimaConexion = new QPushButton(tab_8);
        btGenerarReporteUltimaConexion->setObjectName(QString::fromUtf8("btGenerarReporteUltimaConexion"));

        gridLayout_11->addWidget(btGenerarReporteUltimaConexion, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(tab_8);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_11->addWidget(pushButton_9, 2, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 0, 0, 1, 1);

        tabWidget->addTab(tab_8, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        gridLayout_16 = new QGridLayout(tab_10);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        txtUltimoTipo = new QTextEdit(tab_10);
        txtUltimoTipo->setObjectName(QString::fromUtf8("txtUltimoTipo"));
        txtUltimoTipo->setReadOnly(true);

        gridLayout_15->addWidget(txtUltimoTipo, 0, 0, 1, 1);

        btGenerarReporteUltimoTipo = new QPushButton(tab_10);
        btGenerarReporteUltimoTipo->setObjectName(QString::fromUtf8("btGenerarReporteUltimoTipo"));

        gridLayout_15->addWidget(btGenerarReporteUltimoTipo, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(tab_10);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout_15->addWidget(pushButton_11, 2, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);

        tabWidget->addTab(tab_10, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        gridLayout_14 = new QGridLayout(tab_9);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        txtUltimoTren = new QTextEdit(tab_9);
        txtUltimoTren->setObjectName(QString::fromUtf8("txtUltimoTren"));
        txtUltimoTren->setReadOnly(true);

        gridLayout_13->addWidget(txtUltimoTren, 0, 0, 1, 1);

        btGenerarReporteUltimoTren = new QPushButton(tab_9);
        btGenerarReporteUltimoTren->setObjectName(QString::fromUtf8("btGenerarReporteUltimoTren"));

        gridLayout_13->addWidget(btGenerarReporteUltimoTren, 1, 0, 1, 1);

        pushButton_10 = new QPushButton(tab_9);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_13->addWidget(pushButton_10, 2, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 0, 0, 1, 1);

        tabWidget->addTab(tab_9, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        gridLayout_18 = new QGridLayout(tab_11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        txtUltimoRutaMas = new QTextEdit(tab_11);
        txtUltimoRutaMas->setObjectName(QString::fromUtf8("txtUltimoRutaMas"));
        txtUltimoRutaMas->setReadOnly(true);

        gridLayout_17->addWidget(txtUltimoRutaMas, 0, 0, 1, 1);

        btGenerarReporteRutaMas = new QPushButton(tab_11);
        btGenerarReporteRutaMas->setObjectName(QString::fromUtf8("btGenerarReporteRutaMas"));

        gridLayout_17->addWidget(btGenerarReporteRutaMas, 1, 0, 1, 1);

        pushButton_12 = new QPushButton(tab_11);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_17->addWidget(pushButton_12, 2, 0, 1, 1);


        gridLayout_18->addLayout(gridLayout_17, 0, 0, 1, 1);

        tabWidget->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        gridLayout_20 = new QGridLayout(tab_12);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        txtRutaMenos = new QTextEdit(tab_12);
        txtRutaMenos->setObjectName(QString::fromUtf8("txtRutaMenos"));
        txtRutaMenos->setReadOnly(true);

        gridLayout_19->addWidget(txtRutaMenos, 0, 0, 1, 1);

        btGenerarReporteRutaMenos = new QPushButton(tab_12);
        btGenerarReporteRutaMenos->setObjectName(QString::fromUtf8("btGenerarReporteRutaMenos"));

        gridLayout_19->addWidget(btGenerarReporteRutaMenos, 1, 0, 1, 1);

        pushButton_13 = new QPushButton(tab_12);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout_19->addWidget(pushButton_13, 2, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_19, 0, 0, 1, 1);

        tabWidget->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName(QString::fromUtf8("tab_13"));
        gridLayout_22 = new QGridLayout(tab_13);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        txtPaisMas = new QTextEdit(tab_13);
        txtPaisMas->setObjectName(QString::fromUtf8("txtPaisMas"));
        txtPaisMas->setReadOnly(true);

        gridLayout_21->addWidget(txtPaisMas, 0, 0, 1, 1);

        btGenerarReportePaisMas = new QPushButton(tab_13);
        btGenerarReportePaisMas->setObjectName(QString::fromUtf8("btGenerarReportePaisMas"));

        gridLayout_21->addWidget(btGenerarReportePaisMas, 1, 0, 1, 1);

        pushButton_14 = new QPushButton(tab_13);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout_21->addWidget(pushButton_14, 2, 0, 1, 1);


        gridLayout_22->addLayout(gridLayout_21, 0, 0, 1, 1);

        tabWidget->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QString::fromUtf8("tab_14"));
        gridLayout_24 = new QGridLayout(tab_14);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        txtCiudadMas = new QTextEdit(tab_14);
        txtCiudadMas->setObjectName(QString::fromUtf8("txtCiudadMas"));
        txtCiudadMas->setReadOnly(true);

        gridLayout_23->addWidget(txtCiudadMas, 0, 0, 1, 1);

        btGenerarReporteCiudadMas = new QPushButton(tab_14);
        btGenerarReporteCiudadMas->setObjectName(QString::fromUtf8("btGenerarReporteCiudadMas"));

        gridLayout_23->addWidget(btGenerarReporteCiudadMas, 1, 0, 1, 1);

        pushButton_15 = new QPushButton(tab_14);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout_23->addWidget(pushButton_15, 2, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_23, 0, 0, 1, 1);

        tabWidget->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QString::fromUtf8("tab_15"));
        gridLayout_26 = new QGridLayout(tab_15);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_25 = new QGridLayout();
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        txtUsuarioMas = new QTextEdit(tab_15);
        txtUsuarioMas->setObjectName(QString::fromUtf8("txtUsuarioMas"));
        txtUsuarioMas->setReadOnly(true);

        gridLayout_25->addWidget(txtUsuarioMas, 0, 0, 1, 1);

        btGenerarReporteUsuarioMas = new QPushButton(tab_15);
        btGenerarReporteUsuarioMas->setObjectName(QString::fromUtf8("btGenerarReporteUsuarioMas"));

        gridLayout_25->addWidget(btGenerarReporteUsuarioMas, 1, 0, 1, 1);

        pushButton_16 = new QPushButton(tab_15);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        gridLayout_25->addWidget(pushButton_16, 2, 0, 1, 1);


        gridLayout_26->addLayout(gridLayout_25, 0, 0, 1, 1);

        tabWidget->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName(QString::fromUtf8("tab_16"));
        gridLayout_28 = new QGridLayout(tab_16);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_27 = new QGridLayout();
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        txtUsuarioMenos = new QTextEdit(tab_16);
        txtUsuarioMenos->setObjectName(QString::fromUtf8("txtUsuarioMenos"));
        txtUsuarioMenos->setReadOnly(true);

        gridLayout_27->addWidget(txtUsuarioMenos, 0, 0, 1, 1);

        btGenerarReporteUsuarioMenos = new QPushButton(tab_16);
        btGenerarReporteUsuarioMenos->setObjectName(QString::fromUtf8("btGenerarReporteUsuarioMenos"));

        gridLayout_27->addWidget(btGenerarReporteUsuarioMenos, 1, 0, 1, 1);

        pushButton_17 = new QPushButton(tab_16);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout_27->addWidget(pushButton_17, 2, 0, 1, 1);


        gridLayout_28->addLayout(gridLayout_27, 0, 0, 1, 1);

        tabWidget->addTab(tab_16, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName(QString::fromUtf8("tab_17"));
        gridLayout_30 = new QGridLayout(tab_17);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_29 = new QGridLayout();
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        txtCantComprasUsuario = new QTextEdit(tab_17);
        txtCantComprasUsuario->setObjectName(QString::fromUtf8("txtCantComprasUsuario"));
        txtCantComprasUsuario->setReadOnly(true);

        gridLayout_29->addWidget(txtCantComprasUsuario, 0, 0, 1, 1);

        btGenerarReporteCantComprasUsuario = new QPushButton(tab_17);
        btGenerarReporteCantComprasUsuario->setObjectName(QString::fromUtf8("btGenerarReporteCantComprasUsuario"));

        gridLayout_29->addWidget(btGenerarReporteCantComprasUsuario, 1, 0, 1, 1);

        pushButton_18 = new QPushButton(tab_17);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout_29->addWidget(pushButton_18, 2, 0, 1, 1);


        gridLayout_30->addLayout(gridLayout_29, 0, 0, 1, 1);

        tabWidget->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QString::fromUtf8("tab_18"));
        gridLayout_32 = new QGridLayout(tab_18);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_31 = new QGridLayout();
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        txtTrenMas = new QTextEdit(tab_18);
        txtTrenMas->setObjectName(QString::fromUtf8("txtTrenMas"));
        txtTrenMas->setReadOnly(true);

        gridLayout_31->addWidget(txtTrenMas, 0, 0, 1, 1);

        btGenerarReporteTrenMas = new QPushButton(tab_18);
        btGenerarReporteTrenMas->setObjectName(QString::fromUtf8("btGenerarReporteTrenMas"));

        gridLayout_31->addWidget(btGenerarReporteTrenMas, 1, 0, 1, 1);

        pushButton_19 = new QPushButton(tab_18);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

        gridLayout_31->addWidget(pushButton_19, 2, 0, 1, 1);


        gridLayout_32->addLayout(gridLayout_31, 0, 0, 1, 1);

        tabWidget->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName(QString::fromUtf8("tab_19"));
        gridLayout_34 = new QGridLayout(tab_19);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        gridLayout_33 = new QGridLayout();
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        txtTrenMenos = new QTextEdit(tab_19);
        txtTrenMenos->setObjectName(QString::fromUtf8("txtTrenMenos"));
        txtTrenMenos->setReadOnly(true);

        gridLayout_33->addWidget(txtTrenMenos, 0, 0, 1, 1);

        btGenerarReporteTrenMenos = new QPushButton(tab_19);
        btGenerarReporteTrenMenos->setObjectName(QString::fromUtf8("btGenerarReporteTrenMenos"));

        gridLayout_33->addWidget(btGenerarReporteTrenMenos, 1, 0, 1, 1);

        pushButton_20 = new QPushButton(tab_19);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));

        gridLayout_33->addWidget(pushButton_20, 2, 0, 1, 1);


        gridLayout_34->addLayout(gridLayout_33, 0, 0, 1, 1);

        tabWidget->addTab(tab_19, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(VentanaReportes);
        QObject::connect(pushButton, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_14, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_16, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_17, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_18, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_19, SIGNAL(clicked()), VentanaReportes, SLOT(close()));
        QObject::connect(pushButton_20, SIGNAL(clicked()), VentanaReportes, SLOT(close()));

        tabWidget->setCurrentIndex(9);


        QMetaObject::connectSlotsByName(VentanaReportes);
    } // setupUi

    void retranslateUi(QWidget *VentanaReportes)
    {
        VentanaReportes->setWindowTitle(QApplication::translate("VentanaReportes", "Form", nullptr));
        btGenerarReportePaises->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("VentanaReportes", "Pa\303\255ses", nullptr));
        btGenerarReporteCiudades->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_2->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("VentanaReportes", "Ciudades", nullptr));
        btGenerarReporteConexiones->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_3->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("VentanaReportes", "Conexiones", nullptr));
        btGenerarReporteTrenes->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_4->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("VentanaReportes", "Trenes", nullptr));
        label_2->setText(QApplication::translate("VentanaReportes", "Ingrese el c\303\263digo de ciudad:", nullptr));
        label_3->setText(QApplication::translate("VentanaReportes", "Ingrese el c\303\263digo de la conexi\303\263n:", nullptr));
        btGenerarReportePrecios->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        label->setText(QApplication::translate("VentanaReportes", "Ingrese el c\303\263digo de pa\303\255s:", nullptr));
        pushButton_5->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("VentanaReportes", "Precios", nullptr));
        label_6->setText(QApplication::translate("VentanaReportes", "Ingrese el c\303\263digo del tren:", nullptr));
        btGenerarReportePrecios_2->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        label_4->setText(QApplication::translate("VentanaReportes", "Ingrese el c\303\263digo del tipo de tren:", nullptr));
        pushButton_6->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("VentanaReportes", "N\303\272mero de asientos", nullptr));
        btGenerarReporteUltimoPais->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_7->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab7), QApplication::translate("VentanaReportes", "\303\232ltimo pa\303\255s", nullptr));
        btGenerarReporteUltimaCiudad->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_8->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("VentanaReportes", "\303\232ltima ciudad", nullptr));
        btGenerarReporteUltimaConexion->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_9->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("VentanaReportes", "\303\232ltima conexi\303\263n", nullptr));
        btGenerarReporteUltimoTipo->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_11->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("VentanaReportes", "\303\232ltimo tipo de tren", nullptr));
        btGenerarReporteUltimoTren->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_10->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("VentanaReportes", "\303\232ltimo tren", nullptr));
        btGenerarReporteRutaMas->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_12->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("VentanaReportes", "Ruta m\303\241s utilizada", nullptr));
        btGenerarReporteRutaMenos->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_13->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QApplication::translate("VentanaReportes", "Ruta nunca utilizada", nullptr));
        btGenerarReportePaisMas->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_14->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_13), QApplication::translate("VentanaReportes", "Pa\303\255s m\303\241s visitado", nullptr));
        btGenerarReporteCiudadMas->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_15->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_14), QApplication::translate("VentanaReportes", "Ciudad m\303\241s visitada", nullptr));
        btGenerarReporteUsuarioMas->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_16->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_15), QApplication::translate("VentanaReportes", "Usuario m\303\241s activo", nullptr));
        btGenerarReporteUsuarioMenos->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_17->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_16), QApplication::translate("VentanaReportes", "Usuario menos activo", nullptr));
        btGenerarReporteCantComprasUsuario->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_18->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_17), QApplication::translate("VentanaReportes", "Cant. compras x usuario", nullptr));
        btGenerarReporteTrenMas->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_19->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_18), QApplication::translate("VentanaReportes", "Tren m\303\241s utilizado", nullptr));
        btGenerarReporteTrenMenos->setText(QApplication::translate("VentanaReportes", "Generar Reporte", nullptr));
        pushButton_20->setText(QApplication::translate("VentanaReportes", "Salir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_19), QApplication::translate("VentanaReportes", "Tren menos utilizado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaReportes: public Ui_VentanaReportes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAREPORTES_H
