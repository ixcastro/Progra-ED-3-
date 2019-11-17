#ifndef WINDOW_INSERT_HALL_H
#define WINDOW_INSERT_HALL_H

#include <QMainWindow>

namespace Ui {
class window_insert_hall;
}

class window_insert_hall : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_insert_hall(QWidget *parent = nullptr);
    ~window_insert_hall();

private slots:
    void on_back_clicked();

    void on_save_clicked();

private:
    Ui::window_insert_hall *ui;
};

#endif // WINDOW_INSERT_HALL_H
