#include "producto.h"
#include <QFile>
#include <QTextStream>

void guardarProductos(const vector<Producto>& productos)
{
    QFile archivo("productos.txt");

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&archivo);

    for (int i = 0; i < productos.size(); i++) {
        out << productos[i].id << "|"
            << productos[i].nombre << "|"
            << productos[i].categoria << "|"
            << productos[i].precio << "\n";
    }

    archivo.close();
}

vector<Producto> cargarProductos()
{
    vector<Producto> productos;
    QFile archivo("productos.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return productos;

    QTextStream in(&archivo);

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datos = linea.split("|");

        if (datos.size() == 4) {
            Producto p;
            p.id = datos[0].toInt();
            p.nombre = datos[1];
            p.categoria = datos[2];
            p.precio = datos[3].toDouble();

            productos.push_back(p);
        }
    }

    archivo.close();
    return productos;
}
