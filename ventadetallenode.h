#ifndef VENTADETALLENODE_H
#define VENTADETALLENODE_H

#include "ventadetalle.h"

class VentaDetalleNode
{
    public:
        VentaDetalleNode();
        VentaDetalleNode(VentaDetalle*);
        virtual ~VentaDetalleNode();
        void setVentaDetalle(VentaDetalle*);
        VentaDetalle* getVentaDetalle();
        void setNext(VentaDetalleNode*);
        VentaDetalleNode* getNext();
        void show();
    protected:
        VentaDetalle* ventaDetalle;
        VentaDetalleNode* next;
    private:
};

#endif // VENTADETALLENODE_H
