#ifndef VENTANAREPORTES_H
#define VENTANAREPORTES_H

#include <QWidget>
#include <QMessageBox>
#include <QIntValidator>
#include <string>
#include <sstream>
#include <fstream>
#include "socket.h"

namespace Ui {
class VentanaReportes;
}

class VentanaReportes : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaReportes(QWidget *parent = nullptr);
    ~VentanaReportes();

private slots:
    void on_btGenerarReportePaises_clicked();

    void on_btGenerarReporteCiudades_clicked();

    void on_btGenerarReporteConexiones_clicked();

    void on_btGenerarReporteTrenes_clicked();

    void on_btGenerarReportePrecios_clicked();

    void on_btGenerarReportePrecios_2_clicked();

    void on_btGenerarReporteUltimoPais_clicked();

    void on_btGenerarReporteUltimaCiudad_clicked();

    void on_btGenerarReporteUltimaConexion_clicked();

    void on_btGenerarReporteUltimoTipo_clicked();

    void on_btGenerarReporteUltimoTren_clicked();

    void on_btGenerarReporteRutaMas_clicked();

    void on_btGenerarReporteRutaMenos_clicked();

    void on_btGenerarReportePaisMas_clicked();

    void on_btGenerarReporteCiudadMas_clicked();

    void on_btGenerarReporteUsuarioMas_clicked();

    void on_btGenerarReporteUsuarioMenos_clicked();

    void on_btGenerarReporteCantComprasUsuario_clicked();

    void on_btGenerarReporteTrenMas_clicked();

    void on_btGenerarReporteTrenMenos_clicked();

private:
    Ui::VentanaReportes *ui;
    Socket *socket;
};

#endif // VENTANAREPORTES_H
