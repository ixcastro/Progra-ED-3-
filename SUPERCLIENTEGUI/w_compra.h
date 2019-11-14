#ifndef W_COMPRA_H
#define W_COMPRA_H
#include "library.h"
#include <QMainWindow>

namespace Ui {
class W_COMPRA;
}

class W_COMPRA : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_COMPRA(QWidget *parent = nullptr);
    ~W_COMPRA();
     void shareButton(QJsonArray pData,string path);

public slots:
    void commonSlot();

private:
    Ui::W_COMPRA *ui;
     string PATH;
};

#endif // W_COMPRA_H
