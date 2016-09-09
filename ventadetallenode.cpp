#include "ventadetallenode.h"
#include <cstddef>

VentaDetalleNode::VentaDetalleNode()
{
    //ctor
    ventaDetalle = NULL;
    next = NULL;
}

VentaDetalleNode::VentaDetalleNode(VentaDetalle* ventaDetalle)
{
    //ctor
    this->setVentaDetalle(ventaDetalle);
    next = NULL;
}

VentaDetalleNode::~VentaDetalleNode()
{
    //dtor
}

VentaDetalleNode* VentaDetalleNode::getNext()
{
    return next;
}

void VentaDetalleNode::setNext(VentaDetalleNode* next)
{
    this->next = next;
}

VentaDetalle* VentaDetalleNode::getVentaDetalle()
{
    return ventaDetalle;
}

void VentaDetalleNode::setVentaDetalle(VentaDetalle* ventaDetalle)
{
    this->ventaDetalle = ventaDetalle;
}

void VentaDetalleNode::show()
{
    cout << ventaDetalle->toString();
}
