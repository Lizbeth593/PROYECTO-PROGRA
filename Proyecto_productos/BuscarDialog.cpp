#include "buscardialog.h"
#include "ui_buscardialog.h"

BuscarDialog::BuscarDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BuscarDialog)
{
    ui->setupUi(this);
}

BuscarDialog::~BuscarDialog()
{
    delete ui;
}

void BuscarDialog::setDatos(QString id, QString cliente, QString modelo, QString precio)
{
    ui->lblId->setText(id);
    ui->lblCliente->setText(cliente);
    ui->lblModelo->setText(modelo);
    ui->lblPrecio->setText(precio);
}

void BuscarDialog::on_btnCerrar_clicked()
{
    close();
}
