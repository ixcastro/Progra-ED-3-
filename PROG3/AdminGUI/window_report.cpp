#include "window_report.h"
#include "ui_window_report.h"
#include "window_report_brandprod.h"
#include "window_report_moresoldprod.h"
#include "window_report_prodpas.h"

window_report::window_report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_report)
{
    ui->setupUi(this);
}

window_report::~window_report()
{
    delete ui;
}

void window_report::on_back_clicked()
{
    hide();
}

void window_report::on_pasilloMasVisitado_clicked(){
    QJsonObject obj;
    obj.insert("Reporte","PasilloMasVisitado");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_pasilloMenosVisitado_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","PasilloMenosVisitado");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_marcaMasVendida_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","MarcaMasVendida");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_ClienteMasCompro_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","ClienteMasCompro");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_ClienteMenosCompro_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","ClienteMenosCompro");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_prodCargadoGond_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","ProductoMasCargoGondola");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_clientMasFacturo_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","ClienteMasFacturo");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_facturaMayorMonto_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","FacturaMayorMonto");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_clientes_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","ClientesSuper");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_pasillo_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","PasillosSuper");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_invent_clicked()
{
    QJsonObject obj;
    obj.insert("Reporte","InventarioSuper");
    QJsonDocument doc(obj);
    QJsonDocument resp = socketAdmin::getInstance()->request(doc);
    QMessageBox *q = new QMessageBox();
    QJsonObject objResp = resp.object();
    q->setText(objResp.take("Respuesta").toString());
    q->show();
}

void window_report::on_marcasProd_clicked()
{
    window_report_brandProd*w = new window_report_brandProd();
    w->show();
}

void window_report::on_prods_clicked()
{
    window_report_prodPas*w = new window_report_prodPas();
    w->show();
}

void window_report::on_prodMasVendido_clicked()
{
    window_report_moreSoldProd*w = new window_report_moreSoldProd();
    w->show();
}
