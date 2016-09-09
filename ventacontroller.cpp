#include "ventacontroller.h"
#include "ventaviewer.h"
#include "venta.h"
#include "clientedao.h"
#include "tipodao.h"
#include "ventadetallequeue.h"
#include "articulodao.h"
#include "ventadetalledao.h"
#include "ventadao.h"

VentaController::VentaController()
{
    //ctor
}

VentaController::~VentaController()
{
    //dtor
}

void VentaController::menu()
{
    bool salir = false;

    while (!salir)
    {
        switch ((new VentaViewer())->menu())
        {
            case 1:
                vender();
                break;
            case 2:
                mostrarVenta();
                break;
            case 3:
                salir = true;
                break;
        }
    }
}

void VentaController::vender()
{
    Venta* venta = new Venta();
    VentaViewer* vv = new VentaViewer();
    VentaDetalleQueue* vdq = new VentaDetalleQueue();
    VentaDetalle*vd;

    ArticuloQueue* aq = (new ArticuloDAO())->collection();

    vv->leerFacturayCliente(venta, (new ClienteDAO())->collection());
    while ((vd = vv->leerArticuloyCantidad(venta->getVenID(), aq)) != NULL)
        vdq->add(vd);
    vv->leerTipoPago(venta, (new TipoDAO())->collection());

    double totalVenta = 0;

    while ((vd = vdq->retrieve()) != NULL)
    {
        (new VentaDetalleDAO())->save(vd);
        totalVenta += vd->getCantidad() * ((new ArticuloDAO())->find(vd->getArtID()))->getPrecio();
    }

    venta->setImporte(totalVenta);
    (new VentaDAO())->save(venta);
}

void VentaController::mostrarVenta()
{
    VentaViewer* vv = new VentaViewer();

    Venta* venta = (new VentaDAO())->find(vv->leerFactura());
    vv->mostrarFactura(venta, (new ClienteDAO())->find(venta->getCliID()), (new TipoDAO())->find(venta->getTipID()));
    vv->mostrarDetalle((new VentaDetalleDAO())->collectionByVenID(venta->getVenID()));
}
