#ifndef WINDOW_INSERT_CLIENT_H
#define WINDOW_INSERT_CLIENT_H

#include <QMainWindow>

namespace Ui {
class window_insert_client;
}

class window_insert_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_insert_client(QWidget *parent = nullptr);
    ~window_insert_client();

private slots:
    void on_pushButton_clicked();

private:
    Ui::window_insert_client *ui;
};

#endif // WINDOW_INSERT_CLIENT_H
