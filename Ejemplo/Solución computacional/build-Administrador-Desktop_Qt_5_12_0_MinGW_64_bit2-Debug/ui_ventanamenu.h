/********************************************************************************
** Form generated from reading UI file 'ventanamenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAMENU_H
#define UI_VENTANAMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaMenu
{
public:
    QWidget *centralwidget;
    QLabel *fondo;
    QLabel *label;
    QFrame *line;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btInsertar;
    QPushButton *btModificar;
    QPushButton *btConsultar;
    QPushButton *btReportes;
    QPushButton *btSalir;

    void setupUi(QMainWindow *VentanaMenu)
    {
        if (VentanaMenu->objectName().isEmpty())
            VentanaMenu->setObjectName(QString::fromUtf8("VentanaMenu"));
        VentanaMenu->resize(910, 600);
        VentanaMenu->setMinimumSize(QSize(910, 600));
        VentanaMenu->setMaximumSize(QSize(910, 600));
        centralwidget = new QWidget(VentanaMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        fondo = new QLabel(centralwidget);
        fondo->setObjectName(QString::fromUtf8("fondo"));
        fondo->setGeometry(QRect(10, 10, 631, 571));
        fondo->setStyleSheet(QString::fromUtf8("border-image: url(:/MAPA.jpg) 0 0 0 0 stretch stretch;\n"
"border-bottom-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        fondo->setFrameShape(QFrame::WinPanel);
        fondo->setFrameShadow(QFrame::Raised);
        fondo->setWordWrap(false);
        fondo->setMargin(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 20, 193, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("HP Simplified Light"));
        font.setPointSize(22);
        label->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(640, 10, 20, 571));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(660, 80, 241, 371));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btInsertar = new QPushButton(layoutWidget);
        btInsertar->setObjectName(QString::fromUtf8("btInsertar"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("HP Simplified Light"));
        font1.setPointSize(16);
        btInsertar->setFont(font1);
        btInsertar->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(btInsertar, 0, 0, 1, 1);

        btModificar = new QPushButton(layoutWidget);
        btModificar->setObjectName(QString::fromUtf8("btModificar"));
        btModificar->setFont(font1);
        btModificar->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(btModificar, 1, 0, 1, 1);

        btConsultar = new QPushButton(layoutWidget);
        btConsultar->setObjectName(QString::fromUtf8("btConsultar"));
        btConsultar->setFont(font1);
        btConsultar->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(btConsultar, 2, 0, 1, 1);

        btReportes = new QPushButton(layoutWidget);
        btReportes->setObjectName(QString::fromUtf8("btReportes"));
        btReportes->setFont(font1);
        btReportes->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(btReportes, 3, 0, 1, 1);

        btSalir = new QPushButton(centralwidget);
        btSalir->setObjectName(QString::fromUtf8("btSalir"));
        btSalir->setGeometry(QRect(660, 550, 239, 32));
        btSalir->setFont(font1);
        btSalir->setCursor(QCursor(Qt::PointingHandCursor));
        VentanaMenu->setCentralWidget(centralwidget);

        retranslateUi(VentanaMenu);
        QObject::connect(btSalir, SIGNAL(clicked()), VentanaMenu, SLOT(close()));

        QMetaObject::connectSlotsByName(VentanaMenu);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaMenu)
    {
        VentanaMenu->setWindowTitle(QApplication::translate("VentanaMenu", "Menu", nullptr));
        fondo->setText(QString());
        label->setText(QApplication::translate("VentanaMenu", "MENU PRINCIPAL", nullptr));
        btInsertar->setText(QApplication::translate("VentanaMenu", "AGREGAR DATOS", nullptr));
        btModificar->setText(QApplication::translate("VentanaMenu", "MODIFICAR DATOS", nullptr));
        btConsultar->setText(QApplication::translate("VentanaMenu", "CONSULTAR DATOS", nullptr));
        btReportes->setText(QApplication::translate("VentanaMenu", "GENERAR REPORTES", nullptr));
        btSalir->setText(QApplication::translate("VentanaMenu", "SALIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaMenu: public Ui_VentanaMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAMENU_H
