#ifndef W_PASILLOS_H
#define W_PASILLOS_H

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
    void shareButton(QJsonArray pData);

public slots:
    void commonSlot();

private:
    Ui::W_PASILLOS *ui;
};

#endif // W_PASILLOS_H
