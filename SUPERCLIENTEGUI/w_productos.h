#ifndef W_PRODUCTOS_H
#define W_PRODUCTOS_H

#include <QMainWindow>
#include "library.h"

namespace Ui {
class W_Productos;
}

class W_Productos : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_Productos(QWidget *parent = nullptr);
    ~W_Productos();
    void shareButton(QJsonArray pData,int pNum,string path);

public slots:
    void commonSlot();

private:
    Ui::W_Productos *ui;
    int NUM;
    string PATH;
};

#endif // W_PRODUCTOS_H
