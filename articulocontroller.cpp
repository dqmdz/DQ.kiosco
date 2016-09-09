#include "articulocontroller.h"
#include "articuloviewer.h"
#include "articulodao.h"

ArticuloController::ArticuloController()
{
    //ctor
}

ArticuloController::~ArticuloController()
{
    //dtor
}

void ArticuloController::abm()
{
    ArticuloViewer* av = new ArticuloViewer();

    bool salir = false;

    while (!salir)
    {
        switch (av->menu())
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

void ArticuloController::listar()
{
    (new ArticuloViewer())->listar((new ArticuloDAO())->collection());
}

void ArticuloController::buscar()
{
    ArticuloViewer* av = new ArticuloViewer();
    av->mostrar((new ArticuloDAO())->find(av->buscar()));
}

void ArticuloController::agregar()
{
    Articulo* ar = new Articulo();
    (new ArticuloViewer())->cargar(ar, "Agregar ARTICULO");
    (new ArticuloDAO())->add(ar);
}

void ArticuloController::modificar()
{
    Articulo* ar = new Articulo();
    ArticuloViewer* av = new ArticuloViewer();

    av->mostrar(ar = (new ArticuloDAO())->find(av->buscar()));
    (new ArticuloViewer())->cargar(ar, "Modificar ARTICULO");
    (new ArticuloDAO())->update(ar);
}

void ArticuloController::eliminar()
{
    Articulo* ar = new Articulo();
    ArticuloViewer* av = new ArticuloViewer();

    av->mensaje("Eliminar ARTICULO");
    av->mostrar(ar = (new ArticuloDAO())->find(av->buscar()));
    (new ArticuloDAO())->del(ar);
}

