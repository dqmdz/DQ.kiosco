#include "ventadetalle.h"
#include <sstream>

VentaDetalle::VentaDetalle()
{
    venID = 0;
    artID = 0;
    cantidad = 0;
}

VentaDetalle::VentaDetalle(sql::ResultSet* rs)
{
    this->fillObject(rs);
}

VentaDetalle::~VentaDetalle()
{
    //dtor
}

int VentaDetalle::getVenID()
{
    return this->venID;
}

void VentaDetalle::setVenID(int venID)
{
    this->venID = venID;
}

int VentaDetalle::getArtID()
{
    return this->artID;
}

void VentaDetalle::setArtID(int artID)
{
    this->artID = artID;
}

int VentaDetalle::getCantidad()
{
    return this->cantidad;
}

void VentaDetalle::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

void VentaDetalle::fillObject(sql::ResultSet* rs)
{
    this->setVenID(rs->getInt("vde_ven_id"));
    this->setArtID(rs->getInt("vde_art_id"));
    this->setCantidad(rs->getInt("vde_cantidad"));
}

string VentaDetalle::toString()
{
    stringstream ss;
    ss << this->getVenID() << "\t" << this->getArtID() << "\t" << this->getCantidad();
    return ss.str();
}
