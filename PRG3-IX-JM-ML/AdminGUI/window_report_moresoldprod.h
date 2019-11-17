#ifndef WINDOW_REPORT_MORESOLDPROD_H
#define WINDOW_REPORT_MORESOLDPROD_H

#include <QMainWindow>

namespace Ui {
class window_report_moreSoldProd;
}

class window_report_moreSoldProd : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_report_moreSoldProd(QWidget *parent = nullptr);
    ~window_report_moreSoldProd();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_back_clicked();

    void on_save_clicked();

private:
    Ui::window_report_moreSoldProd *ui;
    int pasillo;
};

#endif // WINDOW_REPORT_MORESOLDPROD_H
