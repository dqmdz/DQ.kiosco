#include "ventadetallequeue.h"
#include <cstddef>

VentaDetalleQueue::VentaDetalleQueue()
{
    //ctor
    this->start = NULL;
    this->end = NULL;
}

VentaDetalleQueue::~VentaDetalleQueue()
{
    //dtor
    this->free();
}

VentaDetalle* VentaDetalleQueue::retrieve()
{
    if (!start)
        return NULL;

    VentaDetalle* value = start->getVentaDetalle();
    VentaDetalleNode* aux = start;

    start = start->getNext();

    delete aux;

    if (!start)
        end = NULL;

    return value;
}

void VentaDetalleQueue::add(VentaDetalle* ventaDetalle)
{
    VentaDetalleNode* newVentaDetalleNode = new VentaDetalleNode(ventaDetalle);

    if (!start)
    {
        start = end = newVentaDetalleNode;
        return;
    }

    end->setNext(newVentaDetalleNode);
    end = newVentaDetalleNode;
}

VentaDetalleNode* VentaDetalleQueue::getStart()
{
    return start;
}

void VentaDetalleQueue::setStart(VentaDetalleNode* start)
{
    this->start = start;
}

VentaDetalleNode* VentaDetalleQueue::getEnd()
{
    return end;
}

void VentaDetalleQueue::setEnd(VentaDetalleNode* end)
{
    this->end = end;
}

void VentaDetalleQueue::free()
{
    while (VentaDetalleNode* aux = start)
    {
        start = start->getNext();
        delete aux;
    }
}

void VentaDetalleQueue::show()
{
    VentaDetalleNode* aux = start;
    while (aux)
    {
        aux->show();
        cout << endl;
        aux = aux->getNext();
    }
    cout << endl << endl;
}

