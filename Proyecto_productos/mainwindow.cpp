#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "actualizardialog.h"
#include "buscardialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configurar tabla
    ui->tablaOrdenes->setColumnCount(4);

    QStringList encabezados;
    encabezados << "ID" << "CLIENTE" << "MODELO" << "PRECIO";
    ui->tablaOrdenes->setHorizontalHeaderLabels(encabezados);

    QFont fuenteHeader;
    fuenteHeader.setPointSize(15);
    ui->tablaOrdenes->horizontalHeader()->setFont(fuenteHeader);

    ui->tablaOrdenes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaOrdenes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablaOrdenes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablaOrdenes->setSelectionMode(QAbstractItemView::SingleSelection);

    // Cargar datos desde archivo
    cargarCelulares();
    cargarTabla();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//  ARCHIVOS

void MainWindow::cargarCelulares()
{
    QFile archivo("celulares.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&archivo);
    celulares.clear();

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split("|");

        if (datos.size() == 4) {
            Celular c;
            c.id = datos[0].toInt();
            c.cliente = datos[1];
            c.modelo = datos[2];
            c.precio = datos[3].toDouble();

            celulares.push_back(c);
        }
    }

    archivo.close();
}

void MainWindow::guardarCelulares()
{
    QFile archivo("celulares.txt");

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo guardar el archivo");
        return;
    }

    QTextStream out(&archivo);

    for (int i = 0; i < celulares.size(); i++) {
        out << celulares[i].id << "|"
            << celulares[i].cliente << "|"
            << celulares[i].modelo << "|"
            << celulares[i].precio << "\n";
    }

    archivo.close();
}

// TABLA

void MainWindow::cargarTabla()
{
    ui->tablaOrdenes->setRowCount(0);

    for (int i = 0; i < celulares.size(); i++) {
        int fila = ui->tablaOrdenes->rowCount();
        ui->tablaOrdenes->insertRow(fila);

        ui->tablaOrdenes->setItem(fila, 0, new QTableWidgetItem(QString::number(celulares[i].id)));
        ui->tablaOrdenes->setItem(fila, 1, new QTableWidgetItem(celulares[i].cliente));
        ui->tablaOrdenes->setItem(fila, 2, new QTableWidgetItem(celulares[i].modelo));
        ui->tablaOrdenes->setItem(fila, 3, new QTableWidgetItem(QString::number(celulares[i].precio)));
    }
}

//  BOTÓN AGREGAR
void MainWindow::on_btnAgregar_clicked()
{
    if (ui->txtId->text().isEmpty() ||
        ui->txtCliente->text().isEmpty() ||
        ui->txtModelo->text().isEmpty() ||
        ui->txtPrecio->text().isEmpty()) {

        QMessageBox::warning(this, "AGREGANDING", "Complete todos los campos pues ️😤");
        return;
    }

    int id = ui->txtId->text().toInt();
    double precio = ui->txtPrecio->text().toDouble();

    if (precio <= 0) {
        QMessageBox::warning(this, "NO ME FALLE ", "El precio debe ser mayor a 0 📈");
        return;
    }

   for (int i = 0; i < celulares.size(); i++) {
    if (celulares[i].id == id) {
        QMessageBox::warning(this, "ERROR", "El ID ya existe 👀");
        return;
    }
}


    Celular c;
    c.id = id;
    c.cliente = ui->txtCliente->text();
    c.modelo = ui->txtModelo->text();
    c.precio = precio;

    celulares.push_back(c);
    guardarCelulares();
    cargarTabla();

    ui->txtId->clear();
    ui->txtCliente->clear();
    ui->txtModelo->clear();
    ui->txtPrecio->clear();
}

//  BOTÓN BUSCAR

void MainWindow::on_btnBuscar_clicked()
{
    int idBuscado = ui->txtId->text().toInt();

    for (int i = 0; i < celulares.size(); i++) {
        if (celulares[i].id == idBuscado) {
            BuscarDialog dialog(this);
            dialog.setDatos(
                QString::number(celulares[i].id),
                celulares[i].cliente,
                celulares[i].modelo,
                QString::number(celulares[i].precio)
                );
            dialog.exec();
            return;
        }
    }

    QMessageBox::warning(this, "BUSCANDING", "ID no encontrado 🥲");
}

//  BOTÓN ELIMINAR

void MainWindow::on_btnEliminar_clicked()
{
    int fila = ui->tablaOrdenes->currentRow();

    if (fila < 0) {
        QMessageBox::warning(this, "ELIMINANDING", "Seleccione una fila ");
        return;
    }

    celulares.erase(celulares.begin() + fila);
    guardarCelulares();
    cargarTabla();
}

//  BOTÓN ACTUALIZAR

void MainWindow::on_btnActualizar_clicked()
{
    int fila = ui->tablaOrdenes->currentRow();

    if (fila < 0) {
        QMessageBox::warning(this, "PILAS PUES", "Seleccione una fila");
        return;
    }

    ActualizarDialog dialog(this);
    dialog.setDatos(
        celulares[fila].cliente,
        celulares[fila].modelo,
        celulares[fila].precio
        );

    if (dialog.exec() == QDialog::Accepted) {
        celulares[fila].cliente = dialog.getCliente();
        celulares[fila].modelo = dialog.getModelo();
        celulares[fila].precio = dialog.getPrecio();

        guardarCelulares();
        cargarTabla();
    }
}

//  CLICK TABLA

void MainWindow::on_tablaOrdenes_cellClicked(int row, int)
{
    ui->txtId->setText(ui->tablaOrdenes->item(row, 0)->text());
    ui->txtCliente->setText(ui->tablaOrdenes->item(row, 1)->text());
    ui->txtModelo->setText(ui->tablaOrdenes->item(row, 2)->text());
    ui->txtPrecio->setText(ui->tablaOrdenes->item(row, 3)->text());
}
