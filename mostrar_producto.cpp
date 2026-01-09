#include <iostream>
#include <string>
#include<vector>

using namespace std;

//Lo que hago aqui es definir el cascaron de como va ser 

using namespace std;

struct Producto {
    int id;
    string nombre; //Este vendria a ser como el modelo 
    string categoria;//Este el daño 
    double precio;
};

// Crear producto
void crearProducto(vector<Producto>& productos) {
    Producto p;

    cout << "ID: ";
    cin >> p.id;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, p.nombre);
    cout << "Categoria: ";
    getline(cin, p.categoria);
    cout << "Precio: ";
    cin >> p.precio;

    productos.push_back(p);

    cout << "Producto agregado correctamente.\n";
}

// Mostrar productos
void mostrarProductos( vector<Producto>& productos) {
    cout << "\nLISTA DE PRODUCTOS\n";

    for (int i = 0; i <(int) productos.size(); i++) {
        cout << "ID: " << productos[i].id
             << " | Nombre: " << productos[i].nombre
             << " | Categoria: " << productos[i].categoria
             << " | Precio: $" << productos[i].precio << endl;
    }
}
