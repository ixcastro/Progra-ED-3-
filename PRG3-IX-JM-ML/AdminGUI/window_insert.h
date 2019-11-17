#ifndef WINDOW_INSERT_H
#define WINDOW_INSERT_H

#include <QMainWindow>

namespace Ui {
class window_insert;
}

class window_insert : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_insert(QWidget *parent = nullptr);
    ~window_insert();

private slots:
    void on_insertarPas_clicked();

    void on_insertarProd_clicked();

    void on_insertarMarca_clicked();

    void on_insertarCliente_clicked();

    void on_back_clicked();

    void on_solicitudes_clicked();

private:
    Ui::window_insert *ui;
};

#endif // WINDOW_INSERT_H
