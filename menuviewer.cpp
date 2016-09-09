#include "menuviewer.h"

MenuViewer::MenuViewer()
{
    //ctor
}

MenuViewer::~MenuViewer()
{
    //dtor
}

int MenuViewer::menu()
{
    int opcion;

    cout << endl << endl << "MENU" << endl << endl;
    cout << "1. Articulos" << endl;
    cout << "2. Clientes" << endl;
    cout << "3. Tipos" << endl;
    cout << "4. Ventas" << endl;
    cout << endl << "5. Salir" << endl;
    cout << endl << "Elija OPCION: ";

    cin >> opcion;

    return opcion;
}

