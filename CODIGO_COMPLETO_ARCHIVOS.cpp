#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Producto {
    int id;
    string nombre;
    string categoria;
    double precio;
};

void guardarProductos(vector<Producto>& productos) {
    ofstream archivo("productos.txt");

    for (int i = 0; i < (int)productos.size(); i++) {
        archivo << productos[i].id << "|"
                << productos[i].nombre << "|"
                << productos[i].categoria << "|"
                << productos[i].precio << endl;
    }

    archivo.close();
}

void cargarProductos(vector<Producto>& productos) {
    ifstream archivo("productos.txt");
    Producto p;
    char sep;

    productos.clear();

    while (archivo >> p.id >> sep) {
        getline(archivo, p.nombre, '|');
        getline(archivo, p.categoria, '|');
        archivo >> p.precio;
        archivo.ignore();

        productos.push_back(p);
    }

    archivo.close();
}

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
    guardarProductos(productos); // aqui se guardan los datos ya en el archivoooo

    cout << "Producto agregado correctamente.\n";
}

void mostrarProductos(vector<Producto>& productos) {
	
	if(productos.empty()){
		cout<<"No hay productos registrados ";
		return;
	}
	
	cout << "\nLISTA DE PRODUCTOS\n";
    for (int i = 0; i < (int)productos.size(); i++) {
        cout << "ID: " << productos[i].id
             << " | Nombre: " << productos[i].nombre
             << " | Categoria: " << productos[i].categoria
             << " | Precio: $" << productos[i].precio << endl;
    }
}

void buscarProducto(vector<Producto>& productos) {
    int idBuscar;
    cout << "ID a buscar: ";
    cin >> idBuscar;

    for (int i = 0; i < (int)productos.size(); i++) {
        if (productos[i].id == idBuscar) {
            cout << "Producto encontrado:\n";
            cout << "ID: " << productos[i].id
                 << " | Nombre: " << productos[i].nombre
                 << " | Categoria: " << productos[i].categoria
                 << " | Precio: $" << productos[i].precio << endl;
            return;
        }
    }

    cout << "Producto no encontrado.\n";
}

void actualizarProducto(vector<Producto>& productos) {
    int idBuscar;
    cout << "ID a actualizar: ";
    cin >> idBuscar;
    cin.ignore();

    for (int i = 0; i < (int)productos.size(); i++) {
        if (productos[i].id == idBuscar) {
            cout << "Nuevo nombre: ";
            getline(cin, productos[i].nombre);
            cout << "Nueva categoria: ";
            getline(cin, productos[i].categoria);
            cout << "Nuevo precio: ";
            cin >> productos[i].precio;
            guardarProductos(productos);
            cout << "Producto actualizado.\n";
            return;
        }
    }

    cout << "Producto no encontrado.\n";
}

void eliminarProducto(vector<Producto>& productos) {
    int idEliminar;
    cout << "ID a eliminar: ";
    cin >> idEliminar;

    for (int i = 0; i < (int)productos.size(); i++) {
        if (productos[i].id == idEliminar) {
            productos.erase(productos.begin() + i);
            guardarProductos(productos);
            cout << "Producto eliminado.\n";
            return;
        }
    }

    cout << "Producto no encontrado.\n";
}

int main() {
    vector<Producto> productos;
    cargarProductos(productos);

    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Crear producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto\n";
        cout << "4. Actualizar producto\n";
        cout << "5. Eliminar producto\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearProducto(productos); break;
            case 2: mostrarProductos(productos); break;
            case 3: buscarProducto(productos); break;
            case 4: actualizarProducto(productos); break;
            case 5: eliminarProducto(productos); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}
