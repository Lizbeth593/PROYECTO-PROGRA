#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <Qstring>
#include <vector>

using namespace std;

struct Producto {
    int id;
    QString nombre;
    QString categoria;
    double precio;
};

void guardarProductos(const vector<Producto>& productos);
vector<Producto> cargarProductos();

#endif
