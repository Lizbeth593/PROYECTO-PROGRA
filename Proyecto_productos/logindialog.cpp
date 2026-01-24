#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_bntIngresar_clicked()
{
    QString usuario = ui->txtUsuario->text();
    QString clave = ui->txtClave->text();

    // Credenciales (simples para clases)
    if (usuario == "liz" && clave == "1234") {
        accept();   // login correcto
    } else {
        QMessageBox::warning(this, "NEGATIVO EL ACCESO MI SUB", "Usuario o contraseña incorrectos ☠️☠️️");
    }
}

