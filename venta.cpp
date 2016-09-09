#include "venta.h"
#include <sstream>

Venta::Venta()
{
    venID = 0;
    cliID = 0;
    tipID = 0;
    importe = 0;
}

Venta::Venta(sql::ResultSet* rs)
{
    this->fillObject(rs);
}

Venta::~Venta()
{
    //dtor
}

int Venta::getVenID()
{
    return this->venID;
}

void Venta::setVenID(int venID)
{
    this->venID = venID;
}

int Venta::getCliID()
{
    return this->cliID;
}

void Venta::setCliID(int cliID)
{
    this->cliID = cliID;
}

int Venta::getTipID()
{
    return this->tipID;
}

void Venta::setTipID(int tipID)
{
    this->tipID = tipID;
}

double Venta::getImporte()
{
    return this->importe;
}

void Venta::setImporte(double importe)
{
    this->importe = importe;
}

void Venta::fillObject(sql::ResultSet* rs)
{
    this->setVenID(rs->getInt("ven_id"));
    this->setCliID(rs->getInt("ven_cli_id"));
    this->setTipID(rs->getInt("ven_tip_id"));
    this->setImporte(rs->getDouble ("ven_importe"));
}

string Venta::toString()
{
    stringstream ss;
    ss << this->getVenID() << "\t" << this->getCliID() << "\t" << "\t" << this->getTipID() << "\t" << this->getImporte();
    return ss.str();
}
