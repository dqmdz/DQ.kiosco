#ifndef VENTADETALLEQUEUE_H
#define VENTADETALLEQUEUE_H

#include "ventadetallenode.h"

class VentaDetalleQueue
{
    public:
        VentaDetalleQueue();
        virtual ~VentaDetalleQueue();
        void setStart(VentaDetalleNode*);
        VentaDetalleNode* getStart();
        void setEnd(VentaDetalleNode*);
        VentaDetalleNode* getEnd();
        void add(VentaDetalle*);
        VentaDetalle* retrieve();
        void free();
        void show();
    protected:
        VentaDetalleNode* start;
        VentaDetalleNode* end;
    private:
};

#endif // VENTADETALLEQUEUE_H
