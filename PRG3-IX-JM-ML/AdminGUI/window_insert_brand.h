#ifndef WINDOW_INSERT_BRAND_H
#define WINDOW_INSERT_BRAND_H

#include <QMainWindow>

namespace Ui {
class window_insert_brand;
}

class window_insert_brand : public QMainWindow
{
    Q_OBJECT

public:
    void setSelectHall(int n);
    void setSelectProd(int n);
    explicit window_insert_brand(QWidget *parent = nullptr);
    ~window_insert_brand();

private slots:
    void on_pushButton_2_clicked();

    void on_save_clicked();

private:
    Ui::window_insert_brand *ui;
    int selectedHall = 0;
    int selectedProd = 0;
};

#endif // WINDOW_INSERT_BRAND_H
