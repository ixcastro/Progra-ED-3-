#ifndef W_CANASTA_H
#define W_CANASTA_H
#include "library.h"
#include <QMainWindow>

namespace Ui {
class W_Canasta;
}

class W_Canasta : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_Canasta(QWidget *parent = nullptr);
    ~W_Canasta();
     void shareButton(QJsonArray pData,string path);

public slots:
    void commonSlot();

private:
    Ui::W_Canasta *ui;
     string PATH;
};

#endif // W_CANASTA_H
