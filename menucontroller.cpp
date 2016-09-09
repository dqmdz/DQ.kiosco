#include "menucontroller.h"
#include "menuviewer.h"
#include "articulocontroller.h"
#include "clientecontroller.h"
#include "tipocontroller.h"
#include "ventacontroller.h"

MenuController::MenuController()
{
    //ctor
}

MenuController::~MenuController()
{
    //dtor
}

void MenuController::menu()
{
    bool salir = false;

    while (!salir)
    {
        switch ((new MenuViewer())->menu())
        {
            case 1:
                (new ArticuloController())->abm();
                break;
            case 2:
                (new ClienteController())->abm();
                break;
            case 3:
                (new TipoController())->abm();
                break;
            case 4:
                (new VentaController())->menu();
                break;
            case 5:
                salir = true;
                break;
        }
    }
}

