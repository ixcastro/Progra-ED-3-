/********************************************************************************
** Form generated from reading UI file 'window_main.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MAIN_H
#define UI_WINDOW_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_main
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *stock;
    QPushButton *insert;
    QPushButton *city;
    QPushButton *modify;
    QPushButton *report;
    QPushButton *delete_2;
    QPushButton *check;
    QPushButton *query;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *queueClient;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *refresh;
    QPushButton *close;
    QPushButton *bill;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *window_main)
    {
        if (window_main->objectName().isEmpty())
            window_main->setObjectName(QString::fromUtf8("window_main"));
        window_main->resize(1099, 405);
        window_main->setMaximumSize(QSize(16777215, 405));
        centralWidget = new QWidget(window_main);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        stock = new QPushButton(centralWidget);
        stock->setObjectName(QString::fromUtf8("stock"));
        QFont font1;
        font1.setPointSize(14);
        stock->setFont(font1);

        verticalLayout_2->addWidget(stock);

        insert = new QPushButton(centralWidget);
        insert->setObjectName(QString::fromUtf8("insert"));
        insert->setFont(font1);

        verticalLayout_2->addWidget(insert);

        city = new QPushButton(centralWidget);
        city->setObjectName(QString::fromUtf8("city"));
        city->setFont(font1);

        verticalLayout_2->addWidget(city);

        modify = new QPushButton(centralWidget);
        modify->setObjectName(QString::fromUtf8("modify"));
        modify->setFont(font1);

        verticalLayout_2->addWidget(modify);

        report = new QPushButton(centralWidget);
        report->setObjectName(QString::fromUtf8("report"));
        report->setFont(font1);

        verticalLayout_2->addWidget(report);

        delete_2 = new QPushButton(centralWidget);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setFont(font1);

        verticalLayout_2->addWidget(delete_2);

        check = new QPushButton(centralWidget);
        check->setObjectName(QString::fromUtf8("check"));
        check->setFont(font1);

        verticalLayout_2->addWidget(check);

        query = new QPushButton(centralWidget);
        query->setObjectName(QString::fromUtf8("query"));
        query->setFont(font1);

        verticalLayout_2->addWidget(query);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);

        verticalLayout_3->addWidget(label_2);

        queueClient = new QListWidget(centralWidget);
        queueClient->setObjectName(QString::fromUtf8("queueClient"));
        queueClient->setFont(font1);

        verticalLayout_3->addWidget(queueClient);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        refresh = new QPushButton(centralWidget);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setFont(font1);

        horizontalLayout_2->addWidget(refresh);

        close = new QPushButton(centralWidget);
        close->setObjectName(QString::fromUtf8("close"));

        horizontalLayout_2->addWidget(close);

        bill = new QPushButton(centralWidget);
        bill->setObjectName(QString::fromUtf8("bill"));
        bill->setFont(font1);

        horizontalLayout_2->addWidget(bill);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        window_main->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(window_main);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1099, 20));
        window_main->setMenuBar(menuBar);
        mainToolBar = new QToolBar(window_main);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        window_main->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(window_main);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        window_main->setStatusBar(statusBar);

        retranslateUi(window_main);

        QMetaObject::connectSlotsByName(window_main);
    } // setupUi

    void retranslateUi(QMainWindow *window_main)
    {
        window_main->setWindowTitle(QApplication::translate("window_main", "window_main", nullptr));
        label->setText(QApplication::translate("window_main", "Menu Principal Adminstrador", nullptr));
        stock->setText(QApplication::translate("window_main", "Inventario", nullptr));
        insert->setText(QApplication::translate("window_main", "Insertar", nullptr));
        city->setText(QApplication::translate("window_main", "Ciudad", nullptr));
        modify->setText(QApplication::translate("window_main", "Modificar", nullptr));
        report->setText(QApplication::translate("window_main", "Reportes", nullptr));
        delete_2->setText(QApplication::translate("window_main", "Eliminar", nullptr));
        check->setText(QApplication::translate("window_main", "Revisar gondolas", nullptr));
        query->setText(QApplication::translate("window_main", "Consultar", nullptr));
        label_2->setText(QApplication::translate("window_main", "Clientes en cola", nullptr));
        refresh->setText(QApplication::translate("window_main", "Refrescar", nullptr));
        close->setText(QApplication::translate("window_main", "Cerrar programa", nullptr));
        bill->setText(QApplication::translate("window_main", "Facturar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_main: public Ui_window_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MAIN_H
