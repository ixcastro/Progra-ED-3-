#ifndef WPASILLOS_H
#define WPASILLOS_H

#include <QMainWindow>
#include <QJsonArray>
#include "string"

using namespace std;

namespace Ui {
class wPasillos;
}

class wPasillos : public QMainWindow
{
    Q_OBJECT

public:
    explicit wPasillos(QWidget *parent = nullptr);
    ~wPasillos();

    void shareButton(QJsonArray pData);

public slots:
    void commonSlot();

private:
    Ui::wPasillos *ui;
};

#endif // WPASILLOS_H
