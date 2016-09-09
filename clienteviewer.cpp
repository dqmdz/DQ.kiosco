#include "clienteviewer.h"
#include <iostream>

using namespace std;

ClienteViewer::ClienteViewer()
{
    //ctor
}

ClienteViewer::~ClienteViewer()
{
    //dtor
}

int ClienteViewer::menu()
{
    int opcion;

    cout << endl << endl << "MENU" << endl << endl;
    cout << "1. Listar CLIENTES" << endl;
    cout << "2. Buscar CLIENTE" << endl;
    cout << "3. Agregar CLIENTE" << endl;
    cout << "4. Modificar CLIENTE" << endl;
    cout << "5. Eliminar CLIENTE" << endl;
    cout << endl << "6. Salir" << endl;
    cout << endl << "Elija OPCION: ";

    cin >> opcion;

    return opcion;
}

void ClienteViewer::listar(ClienteQueue* queue)
{
    cout << endl << endl << "Lista CLIENTES" << endl << endl;
    cout << "ID\tNombre" << endl;
    queue->show();
}

int ClienteViewer::buscar()
{
    int cliID;

    cout << endl << endl << "Buscar CLIENTE" << endl;
    cout << "Ingrese ID Cliente: ";
    cin >> cliID;

    return cliID;
}

void ClienteViewer::mostrar(Cliente* cl)
{
    cout << endl << "ID\tNombre" << endl;
    cout << cl->toString() << endl << endl;
}

void ClienteViewer::cargar(Cliente* cl, string msg)
{
    cout << endl << endl << msg << endl;

    if (cl->getCliID() == 0)
    {
        int cliID;
        cout << "Ingrese ID: ";
        cin >> cliID;

        cl->setCliID(cliID);
    }
    string dato;
    cout << "Ingrese Nombre: ";
    cin >> dato;
    cl->setNombre(dato);
}

void ClienteViewer::mensaje(string msg)
{
    cout << endl << msg << endl;
}
