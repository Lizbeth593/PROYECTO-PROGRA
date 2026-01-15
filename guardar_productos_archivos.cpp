#include <iostream>
#include <string>
#include<vector>
#include<fstream> //Esta es la libreria que maneja los archivos 

using namespace std;
struct Producto {
    int id;
    string nombre;
    string categoria;
    double precio;
};

void guardarProductos(vector<Producto>& productos) {
    ofstream archivo("productos.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    for (int i = 0; i < (int)productos.size(); i++) {
        archivo << productos[i].id << "|"
                << productos[i].nombre << "|"
                << productos[i].categoria << "|"
                << productos[i].precio << endl;
    }

    archivo.close();
}
