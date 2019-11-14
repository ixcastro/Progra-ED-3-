#ifndef W_PASILLOS_H
#define W_PASILLOS_H
#include "library.h"
#include <QMainWindow>
#include <QJsonArray>
#include "string"

namespace Ui {
class W_PASILLOS;
}

class W_PASILLOS : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_PASILLOS(QWidget *parent = nullptr);
    ~W_PASILLOS();
    void shareButton(QJsonArray pData,int pNum);
    void ced(string ced);

public slots:
    void commonSlot();

private:
    Ui::W_PASILLOS *ui;
    int NUM;
    string CED;
};

#endif // W_PASILLOS_H
