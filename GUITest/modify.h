#ifndef MODIFY_H
#define MODIFY_H

#include <QMainWindow>

namespace Ui {
class modify;
}

class modify : public QMainWindow
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = nullptr);
    ~modify();

private:
    Ui::modify *ui;
};

#endif // MODIFY_H
