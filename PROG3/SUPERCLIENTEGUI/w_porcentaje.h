#ifndef W_PORCENTAJE_H
#define W_PORCENTAJE_H
#include "library.h"
#include <QMainWindow>

namespace Ui {
class W_PORCENTAJE;
}

class W_PORCENTAJE : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_PORCENTAJE(QWidget *parent = nullptr);
    ~W_PORCENTAJE();
     void shareButton(QJsonArray pData,string path);

public slots:
    void commonSlot();

private:
    Ui::W_PORCENTAJE *ui;
    string PATH;
};

#endif // W_PORCENTAJE_H
