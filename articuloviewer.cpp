#include "articuloviewer.h"
#include <iostream>

using namespace std;

ArticuloViewer::ArticuloViewer()
{
    //ctor
}

ArticuloViewer::~ArticuloViewer()
{
    //dtor
}

int ArticuloViewer::menu()
{
    int opcion;

    cout << endl << endl << "MENU" << endl << endl;
    cout << "1. Listar ARTICULOS" << endl;
    cout << "2. Buscar ARTICULO" << endl;
    cout << "3. Agregar ARTICULO" << endl;
    cout << "4. Modificar ARTICULO" << endl;
    cout << "5. Eliminar ARTICULO" << endl;
    cout << endl << "6. Salir" << endl;
    cout << endl << "Elija OPCION: ";

    cin >> opcion;

    return opcion;
}

void ArticuloViewer::listar(ArticuloQueue* queue)
{
    cout << endl << endl << "Lista ARTICULOS" << endl << endl;
    cout << "ID\tNombre\t\tPrecio" << endl;
    queue->show();
}

int ArticuloViewer::buscar()
{
    int artID;

    cout << endl << endl << "Buscar ARTICULO" << endl;
    cout << "Ingrese ID Articulo: ";
    cin >> artID;

    return artID;
}

void ArticuloViewer::mostrar(Articulo* ar)
{
    cout << endl << "ID\tNombre\t\tPrecio" << endl;
    cout << ar->toString() << endl << endl;
}

void ArticuloViewer::cargar(Articulo* ar, string msg)
{
    cout << endl << endl << msg << endl;

    if (ar->getArtID() == 0)
    {
        int artID;
        cout << "Ingrese ID: ";
        cin >> artID;

        ar->setArtID(artID);
    }
    string dato;
    cout << "Ingrese Nombre: ";
    cin >> dato;
    ar->setNombre(dato);

    double precio;
    cout << "Ingrese Precio: ";
    cin >> precio;
    ar->setPrecio(precio);
}

void ArticuloViewer::mensaje(string msg)
{
    cout << endl << msg << endl;
}
