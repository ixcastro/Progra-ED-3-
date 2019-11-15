#ifndef WINDOW_QUERY_H
#define WINDOW_QUERY_H

#include <QMainWindow>

namespace Ui {
class window_query;
}

class window_query : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_query(QWidget *parent = nullptr);
    ~window_query();

private slots:
    void on_back_clicked();

    void on_insertarPas_clicked();

    void on_insertarProd_clicked();

    void on_insertarMarca_clicked();

private:
    Ui::window_query *ui;
};

#endif // WINDOW_QUERY_H
