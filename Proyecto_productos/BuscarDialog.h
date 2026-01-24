#ifndef BUSCARDIALOG_H
#define BUSCARDIALOG_H

#include <QDialog>

namespace Ui {
class BuscarDialog;
}

class BuscarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuscarDialog(QWidget *parent = nullptr);
    ~BuscarDialog();

    void setDatos(QString id, QString cliente, QString modelo, QString precio);

private:
    Ui::BuscarDialog *ui;


private slots:
    void on_btnCerrar_clicked();

};

#endif
