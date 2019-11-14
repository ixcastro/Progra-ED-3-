#ifndef ATRACCIONES_H
#define ATRACCIONES_H

#include <QWidget>

using namespace std;

namespace Ui {
class Atracciones;
}

class Atracciones : public QWidget
{
    Q_OBJECT

public:
    explicit Atracciones(QWidget *parent = nullptr);
    ~Atracciones();
    void mostrarAtracciones(string pAtracciones);

private:
    Ui::Atracciones *ui;
};

#endif // ATRACCIONES_H
