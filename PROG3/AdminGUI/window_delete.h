#ifndef WINDOW_DELETE_H
#define WINDOW_DELETE_H

#include <QMainWindow>

namespace Ui {
class window_delete;
}

class window_delete : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_delete(QWidget *parent = nullptr);
    ~window_delete();

private slots:
    void on_back_clicked();

    void on_insertarCliente_clicked();

    void on_insertarPas_clicked();

    void on_insertarProd_clicked();

    void on_insertarMarca_clicked();

private:
    Ui::window_delete *ui;
};

#endif // WINDOW_DELETE_H
