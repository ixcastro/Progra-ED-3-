#ifndef INSER_CLIENT_H
#define INSER_CLIENT_H

#include <QMainWindow>

namespace Ui {
class inser_client;
}

class inser_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit inser_client(QWidget *parent = nullptr);
    ~inser_client();

private:
    Ui::inser_client *ui;
};

#endif // INSER_CLIENT_H
