#ifndef FACTURAR_H
#define FACTURAR_H

#include <QWidget>
#include <QMessageBox>
#include "socket.h"

using namespace std;

namespace Ui {
class Facturar;
}

class Facturar : public QWidget
{
    Q_OBJECT

public:
    explicit Facturar(QWidget *parent = nullptr);
    ~Facturar();

private slots:
    void on_btFacturar_clicked();

private:
    Ui::Facturar *ui;
    Socket *socket;
};

#endif // FACTURAR_H
