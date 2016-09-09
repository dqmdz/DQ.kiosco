#include "clientecontroller.h"
#include "clienteviewer.h"
#include "clientedao.h"

ClienteController::ClienteController()
{
    //ctor
}

ClienteController::~ClienteController()
{
    //dtor
}

void ClienteController::abm()
{
    ClienteViewer* cv = new ClienteViewer();

    bool salir = false;

    while (!salir)
    {
        switch (cv->menu())
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

void ClienteController::listar()
{
    (new ClienteViewer())->listar((new ClienteDAO())->collection());
}

void ClienteController::buscar()
{
    ClienteViewer* cv = new ClienteViewer();
    cv->mostrar((new ClienteDAO())->find(cv->buscar()));
}

void ClienteController::agregar()
{
    Cliente* cl = new Cliente();
    (new ClienteViewer())->cargar(cl, "Agregar CLIENTE");
    (new ClienteDAO())->add(cl);
}

void ClienteController::modificar()
{
    Cliente* cl = new Cliente();
    ClienteViewer* cv = new ClienteViewer();

    cv->mostrar(cl = (new ClienteDAO())->find(cv->buscar()));
    (new ClienteViewer())->cargar(cl, "Modificar CLIENTE");
    (new ClienteDAO())->update(cl);
}

void ClienteController::eliminar()
{
    Cliente* cl = new Cliente();
    ClienteViewer* cv = new ClienteViewer();

    cv->mensaje("Eliminar CLIENTE");
    cv->mostrar(cl = (new ClienteDAO())->find(cv->buscar()));
    (new ClienteDAO())->del(cl);
}

