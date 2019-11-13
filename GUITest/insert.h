#ifndef INSERT_H
#define INSERT_H

#include <QMainWindow>

namespace Ui {
class insert;
}

class insert : public QMainWindow
{
    Q_OBJECT

public:
    explicit insert(QWidget *parent = nullptr);
    ~insert();

private slots:
    void on_back_clicked();

    void on_insertarPas_clicked();

private:
    Ui::insert *ui;
};

#endif // INSERT_H
