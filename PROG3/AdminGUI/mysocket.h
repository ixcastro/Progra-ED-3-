#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QtDebug>
#include <iostream>
#include <string>

using namespace std;


class mysocket : public QObject
{
    Q_OBJECT
public:
    explicit mysocket(QObject *parent = nullptr);
    void doConnect();

    //Con GUI
    bool insertHall(int, string);



    //QByteArray leer();
    //void escribir(QByteArray escritura);
    void close();
    void consultPrice();
    void consultTaxes();
    void consultIsBasket();
    void insertHall();
    void insertProduct();
    void insertBrand();
    void setPrice();
    void serPorcent();
    void setBasket();
    void insertClient();

    //Otros
    void modificar();
    void consultar();
    void reportes();

    void registrarClientes();
    void facturar();
    void verificarInventario();

    //Reportes
    void pasilloMasVisitado(); //Done
    void pasilloMenosVisitado(); //Done
    void marcasMasVendidas(); //Done
    void productosMasVendidosPasillo(); //Done
    void clienteMasCompro(); //Done
    void clienteMenosCompro(); //Done
    void productoMasCargoGondola(); //Done
    void clienteMasFacturo(); //Done
    void marcasProducto();
    void facturaMayorMonto(); //Done
    void productosPasillo(); //Done
    void clientesSuper(); //Done
    void pasillosSuper(); //Done
    void inventarioSuper(); //Done

signals:

public slots:
    void readyRead();
    void connected();
    void disconnected();
    void bytesWritten(qint64);

private:
    QTcpSocket *socket;
    int ced;
};

#endif // MYSOCKET_H
