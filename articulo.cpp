#include "articulo.h"
#include <sstream>

Articulo::Articulo()
{
    artID = 0;
    nombre = "";
    precio = 0;
}

Articulo::Articulo(sql::ResultSet* rs)
{
    this->fillObject(rs);
}

Articulo::~Articulo()
{
}

void Articulo::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Articulo::getNombre()
{
    return this->nombre;
}

void Articulo::setArtID(int artID)
{
    this->artID = artID;
}

int Articulo::getArtID()
{
    return this->artID;
}

void Articulo::setPrecio(double precio)
{
    this->precio = precio;
}

double Articulo::getPrecio()
{
    return this->precio;
}

void Articulo::fillObject(sql::ResultSet* rs)
{
    this->setArtID(rs->getInt("art_id"));
    this->setNombre(rs->getString("art_nombre"));
    this->setPrecio(rs->getDouble("art_precio"));
}

string Articulo::toString()
{
    stringstream ss;
    ss << this->getArtID() << "\t" << this->getNombre() << "\t" << this->getPrecio();
    return ss.str();
}

