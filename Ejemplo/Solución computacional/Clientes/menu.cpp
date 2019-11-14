#include "menu.h"
#include "consultar.h"
#include "reservar.h"
#include "facturar.h"
#include "buscarr.h"
#include "nuevar.h"
#include "ui_menu.h"

Menu::Menu(string &pPaises, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    socket=new Socket();
    paises = pPaises;
    agregarPaises();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::agregarPaises(){
    string paises[18] = {"PORTUGAL","ESPANA","FRANCIA","SUIZA","GRAN BRETANA",
                                "HOLANDA","TURQUIA","BELGICA","ITALIA","GRECIA","REPUBLICA CHECA",
                                "POLONIA","RUMANIA","UCRANIA","BULGARIA","FINLANDIA","SUECIA",
                                 "ALEMANIA"};
    int x[18] = {40,110,170,219,118,190,470,183,273,355,250,300,364,400,371,320,270,230};
    int y[18] = {490,480,390,385,249,266,480,300,490,535,320,270,388,300,446,40,107,280};
    ClickableLabel *etiquetas[50];
    string arr[50];
    for (int i = 0;i<50;i++) {
        arr[i] = "";
    }
    char separador = '\n';
    int contador = 0;
    for(size_t p=0, q=0; p!=this->paises.npos; p=q){
        arr[contador] = this->paises.substr(p+(p!=0),(q=this->paises.find(separador, p+1))-p-(p!=0));
        cout<<arr[contador]<<endl;
        contador++;
    }

    int i = 1;
    while(arr[i]!= "" && i<50){
        for(int j = 0;j<18;j++){
            if(arr[i] == paises[j]){
                etiquetas[i] = new ClickableLabel(QString::fromStdString(paises[j]),this);
                etiquetas[i]->setGeometry(x[j],y[j],0,0);
                etiquetas[i]->adjustSize();
                etiquetas[i]->setCursor(Qt::PointingHandCursor);
                QObject::connect(etiquetas[i],&ClickableLabel::clicked,this,&Menu::MostrarInfoPais);
                break;
            }
        }
        i++;
    }
}

void Menu::MostrarInfoPais(QString pNombre){
    socket->conexion();
    string nombre = pNombre.toUtf8().constData();
    string ciudades = socket->controlador("-2;"+nombre);
    cout<<ciudades<<endl;
    if(ciudades != "El pais no tiene ciudades" && ciudades != "El pais no existe"){
        QMessageBox::information(this,"Info","Presionaste el país: "+pNombre);
        Ciudades *ventana = new Ciudades(nombre,ciudades);
        ventana->show();
    }else{
        QMessageBox::information(this,"Info",pNombre+" "+QString::fromStdString(ciudades));
    }
}


void Menu::on_botCons_clicked()
{
    Consultar *ventana = new Consultar;
    ventana->show();
    //socket->conexion();
    //socket->controlador("50;"+"vgb"+";");
}

void Menu::on_botRes_clicked()
{
    Reservar *ventana = new Reservar;
    ventana->show();
}

void Menu::on_botFac_clicked()
{
    Facturar *ventana = new Facturar;
    ventana->show();
}

void Menu::on_botBR_clicked()
{
    BuscarR *ventana = new BuscarR;
    ventana->show();
}

void Menu::on_botBR_2_clicked()
{
    NuevaR *ventana = new NuevaR;
    ventana->show();
}
