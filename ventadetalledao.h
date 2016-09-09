#ifndef VENTADETALLEDAO_H
#define VENTADETALLEDAO_H

#include "ventadetalle.h"
#include "ventadetallequeue.h"

class VentaDetalleDAO
{
    public:
        VentaDetalleDAO();
        virtual ~VentaDetalleDAO();
        void add(VentaDetalle*);
        void update(VentaDetalle*);
        bool exist(VentaDetalle*);
        void save(VentaDetalle*);
        void del(VentaDetalle*);
        VentaDetalle* find(int, int);
        VentaDetalleQueue* collectionByVenID(int);
    protected:
    private:
};

#endif // VENTADETALLEDAO_H
