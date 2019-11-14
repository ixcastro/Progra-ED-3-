#ifndef W_MARCA_H
#define W_MARCA_H
#include "library.h"
#include <QMainWindow>

namespace Ui {
class W_MARCA;
}

class W_MARCA : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_MARCA(QWidget *parent = nullptr);
    ~W_MARCA();
      void shareButton(QJsonArray pData,string path);

public slots:
    void commonSlot();

private:
    Ui::W_MARCA *ui;
    string PATH;
};

#endif // W_MARCA_H
