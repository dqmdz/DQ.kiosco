#include "tipoviewer.h"
#include <iostream>

using namespace std;

TipoViewer::TipoViewer()
{
    //ctor
}

TipoViewer::~TipoViewer()
{
    //dtor
}

int TipoViewer::menu()
{
    int opcion;

    cout << endl << endl << "MENU" << endl << endl;
    cout << "1. Listar TIPOS" << endl;
    cout << "2. Buscar TIPO" << endl;
    cout << "3. Agregar TIPO" << endl;
    cout << "4. Modificar TIPO" << endl;
    cout << "5. Eliminar TIPO" << endl;
    cout << endl << "6. Salir" << endl;
    cout << endl << "Elija OPCION: ";

    cin >> opcion;

    return opcion;
}

void TipoViewer::listar(TipoQueue* queue)
{
    cout << endl << endl << "Lista TIPOS" << endl << endl;
    cout << "ID\tNombre" << endl;
    queue->show();
}

int TipoViewer::buscar()
{
    int tipID;

    cout << endl << endl << "Buscar TIPO" << endl;
    cout << "Ingrese ID Tipo: ";
    cin >> tipID;

    return tipID;
}

void TipoViewer::mostrar(Tipo* tp)
{
    cout << endl << "ID\tNombre" << endl;
    cout << tp->toString() << endl << endl;
}

void TipoViewer::cargar(Tipo* tp, string msg)
{
    cout << endl << endl << msg << endl;

    if (tp->getTipID() == 0)
    {
        int tipID;
        cout << "Ingrese ID: ";
        cin >> tipID;

        tp->setTipID(tipID);
    }
    string dato;
    cout << "Ingrese Nombre: ";
    cin >> dato;
    tp->setNombre(dato);
}

void TipoViewer::mensaje(string msg)
{
    cout << endl << msg << endl;
}
