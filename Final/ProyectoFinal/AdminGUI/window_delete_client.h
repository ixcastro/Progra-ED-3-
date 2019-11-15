#ifndef WINDOW_DELETE_CLIENT_H
#define WINDOW_DELETE_CLIENT_H

#include <QDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "socketadmin.h"

namespace Ui {
class window_delete_client;
}

class window_delete_client : public QDialog
{
    Q_OBJECT

public:
    explicit window_delete_client(QWidget *parent = nullptr);
    ~window_delete_client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::window_delete_client *ui;
};

#endif // WINDOW_DELETE_CLIENT_H
