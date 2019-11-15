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

    void setCities(QJsonArray a);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::window_insert_client *ui;

};

#endif // WINDOW_INSERT_CLIENT_H
