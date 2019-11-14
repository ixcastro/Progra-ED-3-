#ifndef BUSCARR_H
#define BUSCARR_H

#include <QWidget>
#include <QMessageBox>
#include "socket.h"

namespace Ui {
class BuscarR;
}

class BuscarR : public QWidget
{
    Q_OBJECT

public:
    explicit BuscarR(QWidget *parent = nullptr);
    ~BuscarR();

private slots:
    void on_btCancelarPrecio_5_clicked();

private:
    Ui::BuscarR *ui;
    Socket *socket;
};

#endif // BUSCARR_H
