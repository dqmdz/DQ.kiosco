#include "cliente.h"
#include <sstream>

Cliente::Cliente()
{
    cliID = 0;
    nombre = "";
}

Cliente::Cliente(sql::ResultSet* rs)
{
    this->fillObject(rs);
}

Cliente::~Cliente()
{
}

void Cliente::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Cliente::getNombre()
{
    return this->nombre;
}

void Cliente::setCliID(int cliID)
{
    this->cliID = cliID;
}

int Cliente::getCliID()
{
    return this->cliID;
}

void Cliente::fillObject(sql::ResultSet* rs)
{
    this->setCliID(rs->getInt("cli_id"));
    this->setNombre(rs->getString("cli_nombre"));
}

string Cliente::toString()
{
    stringstream ss;
    ss << this->getCliID();
    return ss.str() + "\t" + this->getNombre();
}

