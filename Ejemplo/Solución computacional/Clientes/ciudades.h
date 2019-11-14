#ifndef CIUDADES_H
#define CIUDADES_H

#include <QWidget>
#include <vector>
#include <QLabel>
#include <QMessageBox>
#include <iostream>
#include "clickablelabel.h"
#include "atracciones.h"
#include "socket.h"

using namespace std;

namespace Ui {
class Ciudades;
}

class Ciudades : public QWidget
{
    Q_OBJECT

public:
    explicit Ciudades(string &pPais, string &ciudades, QWidget *parent = nullptr);
    ~Ciudades();
    void agregarCiudades();

private slots:
    void mostrarAtracciones(QString pNombre);

private:
    Ui::Ciudades *ui;
    string pais;
    string ciudades;
    Socket *socket;
//    QLabel* *etiquetasPaises;
};

#endif // CIUDADES_H
