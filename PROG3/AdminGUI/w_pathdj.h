#ifndef W_PATHDJ_H
#define W_PATHDJ_H

#include <QMainWindow>

namespace Ui {
class W_PATHDJ;
}

class W_PATHDJ : public QMainWindow
{
    Q_OBJECT

public:
    explicit W_PATHDJ(QWidget *parent = nullptr);
    ~W_PATHDJ();

private slots:
    void on_pushButton_clicked();

private:
    Ui::W_PATHDJ *ui;
};

#endif // W_PATHDJ_H
