#ifndef WINDOW_SELECT_PRODUCT_H
#define WINDOW_SELECT_PRODUCT_H

#include <QMainWindow>

namespace Ui {
class window_select_product;
}

class window_select_product : public QMainWindow
{
    Q_OBJECT

public:

    explicit window_select_product(QWidget *parent = nullptr);
    ~window_select_product();
    void addButtonsProds(QJsonArray);
    void setSelectedHall(int);

public slots:
    void commonSlot();
    void commonSlotProds();


private:
    Ui::window_select_product *ui;
    int selectedHall = 0;

};

#endif // WINDOW_SELECT_PRODUCT_H
