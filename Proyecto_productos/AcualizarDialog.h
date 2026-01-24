#ifndef ACUALIZARDIALOG_H
#define ACUALIZARDIALOG_H

#include <QDialog>
#include <QString>


namespace Ui {
class Dialog;

}

class actualizarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ActualizarDialog(QWidget *parent = nullptr);
    ~ActualizarDialog();

    void setDatos(QString cliente, QString modelo, double precio);
    QString getCliente() const;
    QString getModelo() const;
    double getPrecio() const;

private:
    Ui::ActualizarDialog *ui;
};


#endif // ACUALIZARDIALOG_H
