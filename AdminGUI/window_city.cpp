#include "window_city.h"
#include "ui_window_city.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "socketadmin.h"


window_city::window_city(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_city)
{
    ui->setupUi(this);
    mapa = new QGraphicsScene(this);
    ui->graphicsView->setScene(mapa);
}

window_city::~window_city()
{
    delete ui;
}

void window_city::on_back_clicked()
{
    hide();
}

void window_city::on_insertarPas_2_clicked(){

    QJsonObject ob;
    ob.insert("Kruskal",0);

    QJsonDocument d(ob);
    QJsonDocument doc = socketAdmin::getInstance()->request(d);

    QJsonObject docObj = doc.object();

    int peso = docObj.take("Peso").toInt();
    int numCities = docObj.take("NumCities").toInt();

    QJsonArray arr = docObj.take("Connections").toArray();

    QJsonArray city = docObj.take("Codigos").toArray();

    std::vector<window_city::connection> connections;
    for(int i = 0; i < arr.size(); i++){
        QJsonObject obj = arr[i].toObject();
        int a = obj.take("A").toInt();
        int b = obj.take("B").toInt();
        int p = obj.take("P").toInt();
        cout<<"A "<<a<<"  B "<<b<<"  P "<<p<<endl;
        connections.push_back(connection(p,a,b));
    }
    drawMST(numCities,connections,city);


}

void window_city::drawMST(int cities, std::vector<window_city::connection> connections,QJsonArray city){
    double angle = 2 * 3.1415 / cities;
    int radius = 6 * cities;

    for (connection connection : connections){
        int x1, y1, x2, y2;

        y1 = radius * sin(angle * connection.a);
        x1 = radius * cos(angle * connection.a);

        y2 = radius * sin(angle * connection.b);
        x2 = radius * cos(angle * connection.b);
        mapa->addLine(x1,y1,x2,y2, QPen(Qt::black));
    }

    for (int i = 0; i < cities; i++){

        int x, y;

        y = radius * sin(angle * i);
        x = radius * cos(angle * i);

        y = y - 8;
        x = x - 8;

        mapa->addEllipse(x,y,16,16, QPen(Qt::blue),QBrush(Qt::blue));
    }

    int i = 0;
    for (int i=0; i<city.size(); i++){

        QGraphicsTextItem * io = new QGraphicsTextItem;
        int x, y;

        y = radius * sin(angle * i);
        x = radius * cos(angle * i);

        y = y - 8;
        x = x - 8;

        io->setPos(x + 1,y - 2);
        int s = city[i].toInt();
        std::string str = std::to_string(s);
        io->setPlainText(str.c_str());
        io->setDefaultTextColor(Qt::red);
        mapa->addItem(io);
    }

    ui->graphicsView->update();
}





void window_city::on_insertarPas_clicked()
{
    QJsonObject ob;
    ob.insert("Kruskal",0);

    QJsonDocument d(ob);
    QJsonDocument doc = socketAdmin::getInstance()->request(d);

    QJsonObject docObj = doc.object();

    int peso = docObj.take("Peso").toInt();
    int numCities = docObj.take("NumCities").toInt();

    QJsonArray arr = docObj.take("Connections").toArray();

    QJsonArray city = docObj.take("Codigos").toArray();

    std::vector<window_city::connection> connections;
    for(int i = 0; i < arr.size(); i++){
        QJsonObject obj = arr[i].toObject();
        int a = obj.take("A").toInt();
        int b = obj.take("B").toInt();
        int p = obj.take("P").toInt();
        cout<<"A "<<a<<"  B "<<b<<"  P "<<p<<endl;
        connections.push_back(connection(p,a,b));
    }
    drawMST(numCities,connections,city);
}
