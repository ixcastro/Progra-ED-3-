#ifndef WINDOW_REPORT_H
#define WINDOW_REPORT_H

#include <QMainWindow>
#include "library.h"
#include "socketadmin.h"

namespace Ui {
class window_report;
}

class window_report : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_report(QWidget *parent = nullptr);
    ~window_report();

private slots:


    void on_back_clicked();

    void on_pasilloMasVisitado_clicked();

    void on_pasilloMenosVisitado_clicked();

    void on_marcaMasVendida_clicked();

    void on_ClienteMasCompro_clicked();

    void on_ClienteMenosCompro_clicked();

    void on_prodCargadoGond_clicked();

    void on_clientMasFacturo_clicked();

    void on_facturaMayorMonto_clicked();

    void on_clientes_clicked();

    void on_pasillo_clicked();

    void on_invent_clicked();

private:
    Ui::window_report *ui;
};

#endif // WINDOW_REPORT_H
