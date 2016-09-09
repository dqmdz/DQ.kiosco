#include "ventadetalledao.h"
#include "myconnection.h"
#include <sstream>

VentaDetalleDAO::VentaDetalleDAO()
{
    //ctor
}

VentaDetalleDAO::~VentaDetalleDAO()
{
    //dtor
}
void VentaDetalleDAO::add(VentaDetalle* ventaDetalle)
{
    stringstream stringSQL;

    stringSQL << "INSERT INTO ventadetalle (vde_ven_id, vde_art_id, vde_cantidad) VALUES (";
    stringSQL << ventaDetalle->getVenID();
    stringSQL << ", " << ventaDetalle->getArtID();
    stringSQL << ", " << ventaDetalle->getCantidad();
    stringSQL << ")";

    MyConnection::instance()->execute(stringSQL.str());
}

void VentaDetalleDAO::update(VentaDetalle* ventaDetalle)
{
    stringstream stringSQL;

    stringSQL << "UPDATE ventadetalle";
    stringSQL << " SET vde_cantidad = " << ventaDetalle->getCantidad();
    stringSQL << " WHERE vde_ven_id = " << ventaDetalle->getVenID();
    stringSQL << " AND vde_art_id = " << ventaDetalle->getArtID();

    MyConnection::instance()->execute(stringSQL.str());
}

bool VentaDetalleDAO::exist(VentaDetalle* ventaDetalle)
{
    stringstream stringSQL;

    stringSQL << "SELECT * FROM ventadetalle";
    stringSQL << " WHERE vde_ven_id = " << ventaDetalle->getVenID();
    stringSQL << " AND vde_art_id = " << ventaDetalle->getArtID();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL.str());

    return res->next();
}

void VentaDetalleDAO::save(VentaDetalle* ventaDetalle)
{
    if (exist(ventaDetalle))
        update(ventaDetalle);
    else
        add(ventaDetalle);
}

void VentaDetalleDAO::del(VentaDetalle* ventaDetalle)
{
    stringstream stringSQL;

    stringSQL << "DELETE FROM ventadetalle";
    stringSQL << " WHERE vde_ven_id = " << ventaDetalle->getVenID();
    stringSQL << " AND vde_art_id = " << ventaDetalle->getArtID();

    MyConnection::instance()->execute(stringSQL.str());
}

VentaDetalle* VentaDetalleDAO::find(int venID, int artID)
{
    stringstream stringSQL;

    stringSQL << "SELECT * FROM ventadetalle";
    stringSQL << " WHERE vde_ven_id = " << venID;
    stringSQL << " AND vde_art_id = " << artID;

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL.str());

    if (res->next())
    {
        VentaDetalle* ventaDetalle = new VentaDetalle(res);
        delete res;
        return ventaDetalle;
    }

    delete res;
    return new VentaDetalle();
}

VentaDetalleQueue* VentaDetalleDAO::collectionByVenID(int venID)
{
    stringstream stringSQL;
    VentaDetalleQueue* queue = new VentaDetalleQueue();

    stringSQL << "SELECT * FROM ventadetalle";
    stringSQL << " WHERE vde_ven_id = " << venID;

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL.str());

    while (res->next())
        queue->add(new VentaDetalle(res));

    delete res;

    return queue;
}
