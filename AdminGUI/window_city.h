#ifndef WINDOW_CITY_H
#define WINDOW_CITY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <math.h>

namespace Ui {
class window_city;
}

class window_city : public QMainWindow
{
    Q_OBJECT

public:
    struct connection {
        int peso, a, b;
        connection(int peso, int a, int b){
            this->peso = peso;
            this->a = a;
            this->b = b;
        }
    };

    explicit window_city(QWidget *parent = nullptr);
    ~window_city();

    void drawMST(int cities, std::vector<window_city::connection> connections, QJsonArray city);
private slots:
    void on_back_clicked();

    void on_insertarPas_2_clicked();

    void on_insertarPas_clicked();

private:
    Ui::window_city *ui;
    QGraphicsScene *mapa;
};

#endif // WINDOW_CITY_H
