#ifndef WINDOW_MAIN_H
#define WINDOW_MAIN_H

#include <QMainWindow>

namespace Ui {
class window_main;
}

class window_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_main(QWidget *parent = nullptr);
    ~window_main();

private slots:
    void on_insert_clicked();

    void on_modify_clicked();

    void on_delete_2_clicked();

    void on_query_clicked();

    void on_check_clicked();

    void on_stock_clicked();

    void on_report_clicked();

    void on_city_clicked();

    void on_close_clicked();

private:
    Ui::window_main *ui;
};

#endif // WINDOW_MAIN_H
