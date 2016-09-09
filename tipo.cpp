#include "tipo.h"
#include <sstream>

Tipo::Tipo()
{
    tipID = 0;
    nombre = "";
}

Tipo::Tipo(sql::ResultSet* rs)
{
    this->fillObject(rs);
}

Tipo::~Tipo()
{
}

void Tipo::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Tipo::getNombre()
{
    return this->nombre;
}

void Tipo::setTipID(int tipID)
{
    this->tipID = tipID;
}

int Tipo::getTipID()
{
    return this->tipID;
}

void Tipo::fillObject(sql::ResultSet* rs)
{
    this->setTipID(rs->getInt("tip_id"));
    this->setNombre(rs->getString("tip_nombre"));
}

string Tipo::toString()
{
    stringstream ss;
    ss << this->getTipID();
    return ss.str() + "\t" + this->getNombre();
}

