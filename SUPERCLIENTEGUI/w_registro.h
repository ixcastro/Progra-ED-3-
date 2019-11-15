#ifndef W_REGISTRO_H
#define W_REGISTRO_H

#include <QMainWindow>

namespace Ui {
class W_REGISTRO;
}

class W_REGISTRO : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_REGISTRO(QWidget *parent = nullptr);
    ~W_REGISTRO();

private slots:
    void on_pushButton_clicked();

private:
    Ui::W_REGISTRO *ui;
};

#endif // W_REGISTRO_H
