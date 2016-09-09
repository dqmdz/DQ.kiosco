#ifndef VENTAVIEWER_H
#define VENTAVIEWER_H

#include "venta.h"
#include "clientequeue.h"
#include "tipoqueue.h"
#include "articuloqueue.h"
#include "ventadetalle.h"
#include "ventadetallequeue.h"
#include <iostream>

using namespace std;

class VentaViewer
{
    public:
        VentaViewer();
        virtual ~VentaViewer();
        int menu();
        void leerFacturayCliente(Venta*, ClienteQueue*);
        void leerTipoPago(Venta*, TipoQueue*);
        VentaDetalle* leerArticuloyCantidad(int, ArticuloQueue*);
        int leerFactura();
        void mostrarFactura(Venta*, Cliente*, Tipo*);
        void mostrarDetalle(VentaDetalleQueue*);
    protected:
    private:
};

#endif // VENTAVIEWER_H
