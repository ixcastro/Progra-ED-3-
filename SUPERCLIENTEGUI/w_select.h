#ifndef W_SELECT_H
#define W_SELECT_H

#include <QMainWindow>

namespace Ui {
class W_SELECT;
}

class W_SELECT : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_SELECT(QWidget *parent = nullptr);
    ~W_SELECT();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::W_SELECT *ui;
};

#endif // W_SELECT_H
