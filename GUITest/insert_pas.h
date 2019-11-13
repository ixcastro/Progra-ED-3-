#ifndef INSERT_PAS_H
#define INSERT_PAS_H

#include <QMainWindow>

namespace Ui {
class insert_Pas;
}

class insert_Pas : public QMainWindow
{
    Q_OBJECT

public:
    explicit insert_Pas(QWidget *parent = nullptr);
    ~insert_Pas();


private slots:
    void on_back_clicked();

private:
    Ui::insert_Pas *ui;
};

#endif // INSERT_PAS_H
