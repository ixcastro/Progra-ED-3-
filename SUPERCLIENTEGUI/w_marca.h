#ifndef W_MARCA_H
#define W_MARCA_H

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
      void shareButton(QJsonArray pData);

public slots:
    void commonSlot();

private:
    Ui::W_MARCA *ui;
};

#endif // W_MARCA_H
