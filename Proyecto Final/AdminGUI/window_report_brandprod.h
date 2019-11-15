#ifndef WINDOW_REPORT_BRANDPROD_H
#define WINDOW_REPORT_BRANDPROD_H

#include <QMainWindow>

namespace Ui {
class window_report_brandProd;
}

class window_report_brandProd : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_report_brandProd(QWidget *parent = nullptr);
    ~window_report_brandProd();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_prodButton_clicked();

    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::window_report_brandProd *ui;
    int pasillo;
    int producto;
};

#endif // WINDOW_REPORT_BRANDPROD_H
