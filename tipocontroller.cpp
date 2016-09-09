#include "tipocontroller.h"
#include "tipoviewer.h"
#include "tipodao.h"

TipoController::TipoController()
{
    //ctor
}

TipoController::~TipoController()
{
    //dtor
}

void TipoController::abm()
{
    TipoViewer* tv = new TipoViewer();

    bool salir = false;

    while (!salir)
    {
        switch (tv->menu())
        {
            case 1:
                listar();
                break;
            case 2:
                buscar();
                break;
            case 3:
                agregar();
                break;
            case 4:
                modificar();
                break;
            case 5:
                eliminar();
                break;
            case 6:
                salir = true;
                break;
        }
    }
}

void TipoController::listar()
{
    (new TipoViewer())->listar((new TipoDAO())->collection());
}

void TipoController::buscar()
{
    TipoViewer* tv = new TipoViewer();
    tv->mostrar((new TipoDAO())->find(tv->buscar()));
}

void TipoController::agregar()
{
    Tipo* tp = new Tipo();
    (new TipoViewer())->cargar(tp, "Agregar TIPO");
    (new TipoDAO())->add(tp);
}

void TipoController::modificar()
{
    Tipo* tp = new Tipo();
    TipoViewer* tv = new TipoViewer();

    tv->mostrar(tp = (new TipoDAO())->find(tv->buscar()));
    (new TipoViewer())->cargar(tp, "Modificar TIPO");
    (new TipoDAO())->update(tp);
}

void TipoController::eliminar()
{
    Tipo* tp = new Tipo();
    TipoViewer* tv = new TipoViewer();

    tv->mensaje("Eliminar TIPO");
    tv->mostrar(tp = (new TipoDAO())->find(tv->buscar()));
    (new TipoDAO())->del(tp);
}

