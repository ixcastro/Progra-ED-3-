#ifndef WINDOW_REPORT_PRODPAS_H
#define WINDOW_REPORT_PRODPAS_H

#include <QMainWindow>

namespace Ui {
class window_report_prodPas;
}

class window_report_prodPas : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_report_prodPas(QWidget *parent = nullptr);
    ~window_report_prodPas();

private slots:
    void on_start_clicked();

    void on_pasilloButton_clicked();

    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::window_report_prodPas *ui;
    int pasillo;

};

#endif // WINDOW_REPORT_PRODPAS_H
