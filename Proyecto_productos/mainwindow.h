#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Celular{
    int id;
    QString cliente;
    QString modelo;
    double precio;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:  //Este es el boton de agregar
    void on_btnAgregar_clicked();

private slots:  //Este es el boton de elimiminar
    void on_btnBuscar_clicked();

private slots:  //Este es el boton de eliminar
    void on_btnEliminar_clicked();

private slots:  //Este es el boton de actualizar
    void on_btnActualizar_clicked();

private slots:
    void on_tablaOrdenes_cellClicked(int row, int column);


private:
    Ui::MainWindow *ui;

    vector<Celular> celulares;

    void cargarCelulares();
    void guardarCelulares();
    void cargarTabla();
};

#endif // MAINWINDOW_H
