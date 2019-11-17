#ifndef WINDOW_DELETE_HALL_H
#define WINDOW_DELETE_HALL_H

#include <QMainWindow>

namespace Ui {
class window_delete_hall;
}

class window_delete_hall : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_delete_hall(QWidget *parent = nullptr);
    ~window_delete_hall();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    QString name;
    Ui::window_delete_hall *ui;
};

#endif // WINDOW_DELETE_HALL_H
