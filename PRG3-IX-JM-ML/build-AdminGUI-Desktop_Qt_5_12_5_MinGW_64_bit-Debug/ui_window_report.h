/********************************************************************************
** Form generated from reading UI file 'window_report.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_REPORT_H
#define UI_WINDOW_REPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_report
{
public:
    QWidget *centralwidget;
    QPushButton *prods;
    QPushButton *prodMasVendido;
    QPushButton *pasilloMenosVisitado;
    QPushButton *clientMasFacturo;
    QPushButton *ClienteMenosCompro;
    QPushButton *pasilloMasVisitado;
    QPushButton *prodCargadoGond;
    QPushButton *marcaMasVendida;
    QPushButton *clientes;
    QPushButton *invent;
    QPushButton *ClienteMasCompro;
    QPushButton *facturaMayorMonto;
    QLabel *label;
    QPushButton *pasillo;
    QPushButton *back;
    QPushButton *marcasProd;
    QPushButton *pasillos;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window_report)
    {
        if (window_report->objectName().isEmpty())
            window_report->setObjectName(QString::fromUtf8("window_report"));
        window_report->resize(860, 528);
        centralwidget = new QWidget(window_report);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        prods = new QPushButton(centralwidget);
        prods->setObjectName(QString::fromUtf8("prods"));
        prods->setGeometry(QRect(580, 60, 251, 71));
        prodMasVendido = new QPushButton(centralwidget);
        prodMasVendido->setObjectName(QString::fromUtf8("prodMasVendido"));
        prodMasVendido->setGeometry(QRect(20, 200, 281, 71));
        pasilloMenosVisitado = new QPushButton(centralwidget);
        pasilloMenosVisitado->setObjectName(QString::fromUtf8("pasilloMenosVisitado"));
        pasilloMenosVisitado->setGeometry(QRect(20, 130, 281, 71));
        clientMasFacturo = new QPushButton(centralwidget);
        clientMasFacturo->setObjectName(QString::fromUtf8("clientMasFacturo"));
        clientMasFacturo->setGeometry(QRect(300, 200, 281, 71));
        ClienteMenosCompro = new QPushButton(centralwidget);
        ClienteMenosCompro->setObjectName(QString::fromUtf8("ClienteMenosCompro"));
        ClienteMenosCompro->setGeometry(QRect(300, 130, 281, 71));
        pasilloMasVisitado = new QPushButton(centralwidget);
        pasilloMasVisitado->setObjectName(QString::fromUtf8("pasilloMasVisitado"));
        pasilloMasVisitado->setGeometry(QRect(20, 60, 281, 71));
        prodCargadoGond = new QPushButton(centralwidget);
        prodCargadoGond->setObjectName(QString::fromUtf8("prodCargadoGond"));
        prodCargadoGond->setGeometry(QRect(20, 340, 281, 71));
        marcaMasVendida = new QPushButton(centralwidget);
        marcaMasVendida->setObjectName(QString::fromUtf8("marcaMasVendida"));
        marcaMasVendida->setGeometry(QRect(20, 270, 281, 71));
        clientes = new QPushButton(centralwidget);
        clientes->setObjectName(QString::fromUtf8("clientes"));
        clientes->setGeometry(QRect(580, 130, 251, 71));
        invent = new QPushButton(centralwidget);
        invent->setObjectName(QString::fromUtf8("invent"));
        invent->setGeometry(QRect(580, 270, 251, 71));
        ClienteMasCompro = new QPushButton(centralwidget);
        ClienteMasCompro->setObjectName(QString::fromUtf8("ClienteMasCompro"));
        ClienteMasCompro->setGeometry(QRect(300, 60, 281, 71));
        facturaMayorMonto = new QPushButton(centralwidget);
        facturaMayorMonto->setObjectName(QString::fromUtf8("facturaMayorMonto"));
        facturaMayorMonto->setGeometry(QRect(300, 340, 281, 71));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 321, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        pasillo = new QPushButton(centralwidget);
        pasillo->setObjectName(QString::fromUtf8("pasillo"));
        pasillo->setGeometry(QRect(580, 200, 251, 71));
        back = new QPushButton(centralwidget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 430, 281, 51));
        marcasProd = new QPushButton(centralwidget);
        marcasProd->setObjectName(QString::fromUtf8("marcasProd"));
        marcasProd->setGeometry(QRect(300, 270, 281, 71));
        pasillos = new QPushButton(centralwidget);
        pasillos->setObjectName(QString::fromUtf8("pasillos"));
        pasillos->setGeometry(QRect(580, 340, 251, 71));
        window_report->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window_report);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 860, 17));
        window_report->setMenuBar(menubar);
        statusbar = new QStatusBar(window_report);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        window_report->setStatusBar(statusbar);

        retranslateUi(window_report);

        QMetaObject::connectSlotsByName(window_report);
    } // setupUi

    void retranslateUi(QMainWindow *window_report)
    {
        window_report->setWindowTitle(QApplication::translate("window_report", "MainWindow", nullptr));
        prods->setText(QApplication::translate("window_report", "Productos de un pasillo", nullptr));
        prodMasVendido->setText(QApplication::translate("window_report", "Productos por pasillo m\303\241s vendidos", nullptr));
        pasilloMenosVisitado->setText(QApplication::translate("window_report", "Pasillo menos visitado", nullptr));
        clientMasFacturo->setText(QApplication::translate("window_report", "Cliente que m\303\241s factur\303\263", nullptr));
        ClienteMenosCompro->setText(QApplication::translate("window_report", "Cliente que menos compr\303\263", nullptr));
        pasilloMasVisitado->setText(QApplication::translate("window_report", "Pasillo m\303\241s visitado", nullptr));
        prodCargadoGond->setText(QApplication::translate("window_report", "Producto m\303\241s cargado a g\303\263ndolas", nullptr));
        marcaMasVendida->setText(QApplication::translate("window_report", "Marcas m\303\241s vendidas", nullptr));
        clientes->setText(QApplication::translate("window_report", "Clientes del supermercado", nullptr));
        invent->setText(QApplication::translate("window_report", "Inventario del supermercado", nullptr));
        ClienteMasCompro->setText(QApplication::translate("window_report", "Cliente que m\303\241s compr\303\263", nullptr));
        facturaMayorMonto->setText(QApplication::translate("window_report", "Factura de mayor monto", nullptr));
        label->setText(QApplication::translate("window_report", "Seleccione un reporte", nullptr));
        pasillo->setText(QApplication::translate("window_report", "Pasillos del supermercado", nullptr));
        back->setText(QApplication::translate("window_report", "Atr\303\241s", nullptr));
        marcasProd->setText(QApplication::translate("window_report", "Marcas de un producto", nullptr));
        pasillos->setText(QApplication::translate("window_report", "Pasillos eliminados", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_report: public Ui_window_report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_REPORT_H
