#ifndef W_CONSULTA_H
#define W_CONSULTA_H

#include <QMainWindow>

namespace Ui {
class W_CONSULTA;
}

class W_CONSULTA : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_CONSULTA(QWidget *parent = nullptr);
    ~W_CONSULTA();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::W_CONSULTA *ui;
};

#endif // W_CONSULTA_H
