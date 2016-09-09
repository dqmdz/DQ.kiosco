#include "ventadao.h"
#include "myconnection.h"
#include <sstream>

VentaDAO::VentaDAO()
{
    //ctor
}

VentaDAO::~VentaDAO()
{
    //dtor
}

void VentaDAO::add(Venta* venta)
{
    stringstream stringSQL;

    stringSQL << "INSERT INTO venta (ven_id, ven_cli_id, ven_tip_id, ven_importe) VALUES (";
    stringSQL << venta->getVenID();
    stringSQL << ", " << venta->getCliID();
    stringSQL << ", " << venta->getTipID();
    stringSQL << ", '" << venta->getImporte() << "'";
    stringSQL << ")";
    MyConnection::instance()->execute(stringSQL.str());
}

void VentaDAO::update(Venta* venta)
{
    stringstream stringSQL;

    stringSQL << "UPDATE venta";
    stringSQL << " SET ven_cli_id = " << venta->getCliID();
    stringSQL << ", ven_tip_id = " << venta->getTipID();
    stringSQL << ", ven_importe = " << venta->getImporte();
    stringSQL << " WHERE ven_id = '" << venta->getVenID() << "'";

    MyConnection::instance()->execute(stringSQL.str());
}

bool VentaDAO::exist(Venta* venta)
{
    stringstream stringSQL;

    stringSQL << "SELECT * FROM venta";
    stringSQL << " WHERE ven_id = " << venta->getVenID();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL.str());

    return res->next();
}

void VentaDAO::save(Venta* venta)
{
    if (exist(venta))
        update(venta);
    else
        add(venta);
}

void VentaDAO::del(Venta* venta)
{
    stringstream stringSQL;

    stringSQL << "DELETE FROM venta";
    stringSQL << " WHERE ven_id = " << venta->getVenID();

    MyConnection::instance()->execute(stringSQL.str());
}

Venta* VentaDAO::find(int venID)
{
    stringstream stringSQL;

    stringSQL << "SELECT * FROM venta";
    stringSQL << " WHERE ven_id = " << venID;

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL.str());

    if (res->next())
    {
        Venta* venta = new Venta(res);
        delete res;
        return venta;
    }

    delete res;
    return new Venta();
}
