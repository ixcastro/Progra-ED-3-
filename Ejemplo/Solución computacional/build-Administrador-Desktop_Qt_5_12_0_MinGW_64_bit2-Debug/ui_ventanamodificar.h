/********************************************************************************
** Form generated from reading UI file 'ventanamodificar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAMODIFICAR_H
#define UI_VENTANAMODIFICAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaModificar
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *modificarPrecio;
    QPushButton *btCancelarPrecio;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *txtCodPaisPrecio;
    QLineEdit *txtCodCiudadPrecio;
    QLineEdit *txtCodConexionPrecio;
    QLineEdit *txtPrecioNuevo;
    QPushButton *btAceptarPrecio;
    QWidget *modificarTiempo;
    QPushButton *btCancelarTiempo;
    QPushButton *btAceptarTiempo;
    QTextEdit *txtCodConexion;
    QLabel *label_7;
    QLabel *label_6;
    QTextEdit *txtCodCiudadSalida;
    QLabel *label;
    QLabel *label_8;
    QTextEdit *txtCodPaisSalida;
    QLineEdit *txtNuevoTiempo;
    QWidget *modificarAsientos;
    QPushButton *btCancelarAsientos;
    QLineEdit *txtCodTipoTrenAsientos;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *txtCodTrenAsientos;
    QLabel *label_11;
    QLineEdit *txtNumAsientos;
    QPushButton *btAceptarNumAsientos;
    QWidget *modificarRuta;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *btCancelarRuta;
    QLineEdit *txtCodTipoTrenRuta;
    QLineEdit *txtCodTrenRuta;
    QLineEdit *txtCodRuta;
    QLineEdit *txtNuevoPrecioRuta;
    QPushButton *btAceptarRuta;
    QWidget *modificaTren;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *txtCodTipoTren;
    QLineEdit *txtCodTren;
    QLineEdit *txtNombreTren;
    QPushButton *btCancelarTren;
    QPushButton *btAceptarTren;
    QWidget *modificarEstadoMigratorio;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *txtPasaporte;
    QComboBox *comboEstado;
    QPushButton *btCancelarTren_2;
    QPushButton *btAceptarEstadoMigratorio;

    void setupUi(QMainWindow *VentanaModificar)
    {
        if (VentanaModificar->objectName().isEmpty())
            VentanaModificar->setObjectName(QString::fromUtf8("VentanaModificar"));
        VentanaModificar->resize(700, 479);
        centralwidget = new QWidget(VentanaModificar);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        modificarPrecio = new QWidget();
        modificarPrecio->setObjectName(QString::fromUtf8("modificarPrecio"));
        btCancelarPrecio = new QPushButton(modificarPrecio);
        btCancelarPrecio->setObjectName(QString::fromUtf8("btCancelarPrecio"));
        btCancelarPrecio->setGeometry(QRect(10, 390, 80, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(14);
        btCancelarPrecio->setFont(font);
        btCancelarPrecio->setCursor(QCursor(Qt::PointingHandCursor));
        label_12 = new QLabel(modificarPrecio);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 120, 195, 22));
        label_12->setFont(font);
        label_13 = new QLabel(modificarPrecio);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(70, 170, 228, 22));
        label_13->setFont(font);
        label_14 = new QLabel(modificarPrecio);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(50, 220, 247, 22));
        label_14->setFont(font);
        label_15 = new QLabel(modificarPrecio);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(120, 270, 181, 22));
        label_15->setFont(font);
        txtCodPaisPrecio = new QLineEdit(modificarPrecio);
        txtCodPaisPrecio->setObjectName(QString::fromUtf8("txtCodPaisPrecio"));
        txtCodPaisPrecio->setGeometry(QRect(400, 120, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(12);
        txtCodPaisPrecio->setFont(font1);
        txtCodCiudadPrecio = new QLineEdit(modificarPrecio);
        txtCodCiudadPrecio->setObjectName(QString::fromUtf8("txtCodCiudadPrecio"));
        txtCodCiudadPrecio->setGeometry(QRect(400, 170, 151, 31));
        txtCodCiudadPrecio->setFont(font1);
        txtCodConexionPrecio = new QLineEdit(modificarPrecio);
        txtCodConexionPrecio->setObjectName(QString::fromUtf8("txtCodConexionPrecio"));
        txtCodConexionPrecio->setGeometry(QRect(400, 220, 151, 31));
        txtCodConexionPrecio->setFont(font1);
        txtPrecioNuevo = new QLineEdit(modificarPrecio);
        txtPrecioNuevo->setObjectName(QString::fromUtf8("txtPrecioNuevo"));
        txtPrecioNuevo->setGeometry(QRect(400, 270, 151, 31));
        txtPrecioNuevo->setFont(font1);
        btAceptarPrecio = new QPushButton(modificarPrecio);
        btAceptarPrecio->setObjectName(QString::fromUtf8("btAceptarPrecio"));
        btAceptarPrecio->setGeometry(QRect(580, 390, 80, 31));
        btAceptarPrecio->setFont(font);
        btAceptarPrecio->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(modificarPrecio, QString());
        modificarTiempo = new QWidget();
        modificarTiempo->setObjectName(QString::fromUtf8("modificarTiempo"));
        btCancelarTiempo = new QPushButton(modificarTiempo);
        btCancelarTiempo->setObjectName(QString::fromUtf8("btCancelarTiempo"));
        btCancelarTiempo->setGeometry(QRect(10, 390, 80, 31));
        btCancelarTiempo->setFont(font);
        btCancelarTiempo->setCursor(QCursor(Qt::PointingHandCursor));
        btAceptarTiempo = new QPushButton(modificarTiempo);
        btAceptarTiempo->setObjectName(QString::fromUtf8("btAceptarTiempo"));
        btAceptarTiempo->setGeometry(QRect(580, 390, 80, 31));
        btAceptarTiempo->setFont(font);
        btAceptarTiempo->setCursor(QCursor(Qt::PointingHandCursor));
        txtCodConexion = new QTextEdit(modificarTiempo);
        txtCodConexion->setObjectName(QString::fromUtf8("txtCodConexion"));
        txtCodConexion->setGeometry(QRect(450, 190, 171, 31));
        txtCodConexion->setFont(font1);
        label_7 = new QLabel(modificarTiempo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 90, 270, 22));
        label_7->setFont(font);
        label_6 = new QLabel(modificarTiempo);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 140, 301, 22));
        label_6->setFont(font);
        txtCodCiudadSalida = new QTextEdit(modificarTiempo);
        txtCodCiudadSalida->setObjectName(QString::fromUtf8("txtCodCiudadSalida"));
        txtCodCiudadSalida->setGeometry(QRect(450, 140, 171, 31));
        txtCodCiudadSalida->setFont(font1);
        label = new QLabel(modificarTiempo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(102, 242, 189, 22));
        label->setFont(font);
        label_8 = new QLabel(modificarTiempo);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 190, 251, 22));
        label_8->setFont(font);
        txtCodPaisSalida = new QTextEdit(modificarTiempo);
        txtCodPaisSalida->setObjectName(QString::fromUtf8("txtCodPaisSalida"));
        txtCodPaisSalida->setGeometry(QRect(450, 90, 171, 31));
        txtCodPaisSalida->setFont(font1);
        txtNuevoTiempo = new QLineEdit(modificarTiempo);
        txtNuevoTiempo->setObjectName(QString::fromUtf8("txtNuevoTiempo"));
        txtNuevoTiempo->setGeometry(QRect(450, 240, 170, 30));
        txtNuevoTiempo->setFont(font);
        tabWidget->addTab(modificarTiempo, QString());
        modificarAsientos = new QWidget();
        modificarAsientos->setObjectName(QString::fromUtf8("modificarAsientos"));
        btCancelarAsientos = new QPushButton(modificarAsientos);
        btCancelarAsientos->setObjectName(QString::fromUtf8("btCancelarAsientos"));
        btCancelarAsientos->setGeometry(QRect(10, 390, 80, 31));
        btCancelarAsientos->setFont(font);
        btCancelarAsientos->setCursor(QCursor(Qt::PointingHandCursor));
        txtCodTipoTrenAsientos = new QLineEdit(modificarAsientos);
        txtCodTipoTrenAsientos->setObjectName(QString::fromUtf8("txtCodTipoTrenAsientos"));
        txtCodTipoTrenAsientos->setGeometry(QRect(420, 120, 151, 31));
        txtCodTipoTrenAsientos->setFont(font1);
        label_9 = new QLabel(modificarAsientos);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(80, 130, 252, 22));
        label_9->setFont(font);
        label_10 = new QLabel(modificarAsientos);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(140, 190, 195, 22));
        label_10->setFont(font);
        txtCodTrenAsientos = new QLineEdit(modificarAsientos);
        txtCodTrenAsientos->setObjectName(QString::fromUtf8("txtCodTrenAsientos"));
        txtCodTrenAsientos->setGeometry(QRect(420, 180, 151, 31));
        txtCodTrenAsientos->setFont(font1);
        label_11 = new QLabel(modificarAsientos);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 240, 286, 22));
        label_11->setFont(font);
        txtNumAsientos = new QLineEdit(modificarAsientos);
        txtNumAsientos->setObjectName(QString::fromUtf8("txtNumAsientos"));
        txtNumAsientos->setGeometry(QRect(420, 240, 151, 31));
        txtNumAsientos->setFont(font1);
        btAceptarNumAsientos = new QPushButton(modificarAsientos);
        btAceptarNumAsientos->setObjectName(QString::fromUtf8("btAceptarNumAsientos"));
        btAceptarNumAsientos->setGeometry(QRect(580, 390, 80, 31));
        btAceptarNumAsientos->setFont(font);
        btAceptarNumAsientos->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(modificarAsientos, QString());
        modificarRuta = new QWidget();
        modificarRuta->setObjectName(QString::fromUtf8("modificarRuta"));
        label_16 = new QLabel(modificarRuta);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(80, 80, 252, 22));
        label_16->setFont(font);
        label_17 = new QLabel(modificarRuta);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(140, 140, 195, 22));
        label_17->setFont(font);
        label_18 = new QLabel(modificarRuta);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(130, 200, 208, 22));
        label_18->setFont(font);
        label_19 = new QLabel(modificarRuta);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(80, 260, 256, 22));
        label_19->setFont(font);
        btCancelarRuta = new QPushButton(modificarRuta);
        btCancelarRuta->setObjectName(QString::fromUtf8("btCancelarRuta"));
        btCancelarRuta->setGeometry(QRect(10, 390, 80, 31));
        btCancelarRuta->setFont(font);
        btCancelarRuta->setCursor(QCursor(Qt::PointingHandCursor));
        txtCodTipoTrenRuta = new QLineEdit(modificarRuta);
        txtCodTipoTrenRuta->setObjectName(QString::fromUtf8("txtCodTipoTrenRuta"));
        txtCodTipoTrenRuta->setGeometry(QRect(420, 80, 151, 31));
        txtCodTipoTrenRuta->setFont(font1);
        txtCodTrenRuta = new QLineEdit(modificarRuta);
        txtCodTrenRuta->setObjectName(QString::fromUtf8("txtCodTrenRuta"));
        txtCodTrenRuta->setGeometry(QRect(420, 140, 151, 31));
        txtCodTrenRuta->setFont(font1);
        txtCodRuta = new QLineEdit(modificarRuta);
        txtCodRuta->setObjectName(QString::fromUtf8("txtCodRuta"));
        txtCodRuta->setGeometry(QRect(420, 200, 151, 31));
        txtCodRuta->setFont(font1);
        txtNuevoPrecioRuta = new QLineEdit(modificarRuta);
        txtNuevoPrecioRuta->setObjectName(QString::fromUtf8("txtNuevoPrecioRuta"));
        txtNuevoPrecioRuta->setGeometry(QRect(420, 260, 151, 31));
        txtNuevoPrecioRuta->setFont(font1);
        btAceptarRuta = new QPushButton(modificarRuta);
        btAceptarRuta->setObjectName(QString::fromUtf8("btAceptarRuta"));
        btAceptarRuta->setGeometry(QRect(580, 390, 80, 31));
        btAceptarRuta->setFont(font);
        btAceptarRuta->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(modificarRuta, QString());
        modificaTren = new QWidget();
        modificaTren->setObjectName(QString::fromUtf8("modificaTren"));
        label_20 = new QLabel(modificaTren);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(80, 140, 252, 22));
        label_20->setFont(font);
        label_21 = new QLabel(modificaTren);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(130, 200, 195, 22));
        label_21->setFont(font);
        label_22 = new QLabel(modificaTren);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(70, 260, 257, 22));
        label_22->setFont(font);
        txtCodTipoTren = new QLineEdit(modificaTren);
        txtCodTipoTren->setObjectName(QString::fromUtf8("txtCodTipoTren"));
        txtCodTipoTren->setGeometry(QRect(440, 140, 151, 31));
        txtCodTipoTren->setFont(font1);
        txtCodTren = new QLineEdit(modificaTren);
        txtCodTren->setObjectName(QString::fromUtf8("txtCodTren"));
        txtCodTren->setGeometry(QRect(440, 200, 151, 31));
        txtCodTren->setFont(font1);
        txtNombreTren = new QLineEdit(modificaTren);
        txtNombreTren->setObjectName(QString::fromUtf8("txtNombreTren"));
        txtNombreTren->setGeometry(QRect(440, 250, 151, 31));
        txtNombreTren->setFont(font1);
        btCancelarTren = new QPushButton(modificaTren);
        btCancelarTren->setObjectName(QString::fromUtf8("btCancelarTren"));
        btCancelarTren->setGeometry(QRect(10, 390, 80, 31));
        btCancelarTren->setFont(font);
        btCancelarTren->setCursor(QCursor(Qt::PointingHandCursor));
        btAceptarTren = new QPushButton(modificaTren);
        btAceptarTren->setObjectName(QString::fromUtf8("btAceptarTren"));
        btAceptarTren->setGeometry(QRect(580, 390, 80, 31));
        btAceptarTren->setFont(font);
        btAceptarTren->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(modificaTren, QString());
        modificarEstadoMigratorio = new QWidget();
        modificarEstadoMigratorio->setObjectName(QString::fromUtf8("modificarEstadoMigratorio"));
        label_23 = new QLabel(modificarEstadoMigratorio);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(130, 160, 158, 22));
        label_23->setFont(font);
        label_24 = new QLabel(modificarEstadoMigratorio);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(146, 220, 142, 22));
        label_24->setFont(font);
        txtPasaporte = new QLineEdit(modificarEstadoMigratorio);
        txtPasaporte->setObjectName(QString::fromUtf8("txtPasaporte"));
        txtPasaporte->setGeometry(QRect(360, 160, 151, 31));
        txtPasaporte->setFont(font1);
        comboEstado = new QComboBox(modificarEstadoMigratorio);
        comboEstado->addItem(QString());
        comboEstado->addItem(QString());
        comboEstado->setObjectName(QString::fromUtf8("comboEstado"));
        comboEstado->setGeometry(QRect(360, 220, 150, 30));
        comboEstado->setFont(font);
        comboEstado->setCursor(QCursor(Qt::PointingHandCursor));
        btCancelarTren_2 = new QPushButton(modificarEstadoMigratorio);
        btCancelarTren_2->setObjectName(QString::fromUtf8("btCancelarTren_2"));
        btCancelarTren_2->setGeometry(QRect(10, 390, 80, 31));
        btCancelarTren_2->setFont(font);
        btCancelarTren_2->setCursor(QCursor(Qt::PointingHandCursor));
        btAceptarEstadoMigratorio = new QPushButton(modificarEstadoMigratorio);
        btAceptarEstadoMigratorio->setObjectName(QString::fromUtf8("btAceptarEstadoMigratorio"));
        btAceptarEstadoMigratorio->setGeometry(QRect(580, 390, 80, 31));
        btAceptarEstadoMigratorio->setFont(font);
        btAceptarEstadoMigratorio->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(modificarEstadoMigratorio, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        VentanaModificar->setCentralWidget(centralwidget);

        retranslateUi(VentanaModificar);
        QObject::connect(btCancelarPrecio, SIGNAL(clicked()), VentanaModificar, SLOT(close()));
        QObject::connect(btCancelarTiempo, SIGNAL(clicked()), VentanaModificar, SLOT(close()));
        QObject::connect(btCancelarAsientos, SIGNAL(clicked()), VentanaModificar, SLOT(close()));
        QObject::connect(btCancelarRuta, SIGNAL(clicked()), VentanaModificar, SLOT(close()));
        QObject::connect(btCancelarTren, SIGNAL(clicked()), VentanaModificar, SLOT(close()));
        QObject::connect(btCancelarTren_2, SIGNAL(clicked()), VentanaModificar, SLOT(close()));

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(VentanaModificar);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaModificar)
    {
        VentanaModificar->setWindowTitle(QApplication::translate("VentanaModificar", "MainWindow", nullptr));
        btCancelarPrecio->setText(QApplication::translate("VentanaModificar", "Salir", nullptr));
        label_12->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del pa\303\255s:", nullptr));
        label_13->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo de la ciudad:", nullptr));
        label_14->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo de la conexi\303\263n:", nullptr));
        label_15->setText(QApplication::translate("VentanaModificar", "Ingrese el nuevo precio:", nullptr));
        btAceptarPrecio->setText(QApplication::translate("VentanaModificar", "Aceptar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modificarPrecio), QApplication::translate("VentanaModificar", "Precio", nullptr));
        btCancelarTiempo->setText(QApplication::translate("VentanaModificar", "Salir", nullptr));
        btAceptarTiempo->setText(QApplication::translate("VentanaModificar", "Aceptar", nullptr));
        label_7->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del pa\303\255s de salida: ", nullptr));
        label_6->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo de la ciudad de salida: ", nullptr));
        label->setText(QApplication::translate("VentanaModificar", "Ingrese el nuevo tiempo:", nullptr));
        label_8->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo de la conexi\303\263n: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modificarTiempo), QApplication::translate("VentanaModificar", "Tiempo", nullptr));
        btCancelarAsientos->setText(QApplication::translate("VentanaModificar", "Salir", nullptr));
        label_9->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del tipo de tren:", nullptr));
        label_10->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del tren:", nullptr));
        label_11->setText(QApplication::translate("VentanaModificar", "Ingrese el nuevo n\303\272mero de asientos:", nullptr));
        btAceptarNumAsientos->setText(QApplication::translate("VentanaModificar", "Aceptar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modificarAsientos), QApplication::translate("VentanaModificar", "N\303\272mero de asientos", nullptr));
        label_16->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del tipo de tren:", nullptr));
        label_17->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del tren:", nullptr));
        label_18->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo de la ruta:", nullptr));
        label_19->setText(QApplication::translate("VentanaModificar", "Ingrese el nuevo precio de la ruta:", nullptr));
        btCancelarRuta->setText(QApplication::translate("VentanaModificar", "Salir", nullptr));
        btAceptarRuta->setText(QApplication::translate("VentanaModificar", "Aceptar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modificarRuta), QApplication::translate("VentanaModificar", "Ruta", nullptr));
        label_20->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del tipo de tren:", nullptr));
        label_21->setText(QApplication::translate("VentanaModificar", "Ingrese el c\303\263digo del tren:", nullptr));
        label_22->setText(QApplication::translate("VentanaModificar", "Ingrese el nuevo nombre del tren:", nullptr));
        btCancelarTren->setText(QApplication::translate("VentanaModificar", "Salir", nullptr));
        btAceptarTren->setText(QApplication::translate("VentanaModificar", "Aceptar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modificaTren), QApplication::translate("VentanaModificar", "Tren", nullptr));
        label_23->setText(QApplication::translate("VentanaModificar", "Ingrese el pasaporte:", nullptr));
        label_24->setText(QApplication::translate("VentanaModificar", "Estado migratorio:", nullptr));
        comboEstado->setItemText(0, QApplication::translate("VentanaModificar", "0", nullptr));
        comboEstado->setItemText(1, QApplication::translate("VentanaModificar", "1", nullptr));

        btCancelarTren_2->setText(QApplication::translate("VentanaModificar", "Salir", nullptr));
        btAceptarEstadoMigratorio->setText(QApplication::translate("VentanaModificar", "Aceptar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modificarEstadoMigratorio), QApplication::translate("VentanaModificar", "Estado migratorio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaModificar: public Ui_VentanaModificar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAMODIFICAR_H
