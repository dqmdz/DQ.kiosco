#include "ventaviewer.h"
#include "clienteviewer.h"
#include "tipoviewer.h"
#include "articuloviewer.h"
#include "articulodao.h"

VentaViewer::VentaViewer()
{
    //ctor
}

VentaViewer::~VentaViewer()
{
    //dtor
}

int VentaViewer::menu()
{
    int opcion;

    cout << endl << endl << "MENU" << endl << endl;
    cout << "1. Vender" << endl;
    cout << "2. Mostrar Venta" << endl;
    cout << endl << "3. Salir" << endl;
    cout << endl << "Elija OPCION: ";

    cin >> opcion;

    return opcion;
}

void VentaViewer::leerFacturayCliente(Venta* venta, ClienteQueue* queue)
{
    int factura;
    int cliente;

    cout << endl << endl << "Nueva VENTA" << endl << endl;
    cout << "Ingrese Número de FACTURA: ";
    cin >> factura;

    venta->setVenID(factura);

    cout << "Elija CLIENTE:" << endl;

    (new ClienteViewer())->listar(queue);

    cout << "Ingrese Número de CLIENTE: ";
    cin >> cliente;

    venta->setCliID(cliente);
}

void VentaViewer::leerTipoPago(Venta* venta, TipoQueue* queue)
{
    int tipo;

    cout << "Elija TIPO de PAGO:" << endl;

    (new TipoViewer())->listar(queue);

    cout << "Ingrese Número de TIPO de PAGO: ";
    cin >> tipo;

    venta->setTipID(tipo);
}

VentaDetalle* VentaViewer::leerArticuloyCantidad(int venID, ArticuloQueue* queue)
{
    int art;

    cout << "Elija ARTICULO:" << endl;

    (new ArticuloViewer())->listar(queue);

    cout << "Ingrese Codigo de ARTICULO (0 para terminar): ";
    cin >> art;

    if (art == 0)
        return NULL;

    int cantidad;
    cout << "Ingrese Cantidad: ";
    cin >> cantidad;

    VentaDetalle* vd = new VentaDetalle();
    vd->setVenID(venID);
    vd->setArtID(art);
    vd->setCantidad(cantidad);

    return vd;
}

int VentaViewer::leerFactura()
{
    int factura;

    cout << endl << endl << "Mostrar FACTURA" << endl << endl;
    cout << "Ingrese Número de FACTURA: ";
    cin >> factura;

    return factura;
}

void VentaViewer::mostrarFactura(Venta* venta, Cliente* cliente, Tipo* tipo)
{
    cout << "Factura: " << venta->getVenID() << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Tipo de Pago: " << tipo->getNombre() << endl;
    cout << "Total Venta: " << venta->getImporte() << endl;
}

void VentaViewer::mostrarDetalle(VentaDetalleQueue* queue)
{
    VentaDetalle* vd;
    Articulo* ar;

    cout << endl << "Detalle FACTURA" << endl;

    while ((vd = queue->retrieve()) != NULL)
    {
        ar = (new ArticuloDAO())->find(vd->getArtID());
        cout << "Articulo: " << ar->getNombre() << " Cantidad: " << vd->getCantidad() << " Precio: " << ar->getPrecio() << endl;
    }
}
