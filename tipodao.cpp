#include "tipodao.h"
#include "myconnection.h"
#include <sstream>

TipoDAO::TipoDAO()
{
    //ctor
}

TipoDAO::~TipoDAO()
{
    //dtor
}

TipoQueue* TipoDAO::collection()
{
    TipoQueue* queue = new TipoQueue();
    sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM tipo ORDER BY tip_id");

    while (res->next())
        queue->add(new Tipo(res));

    delete res;

    return queue;
}

void TipoDAO::del(Tipo* tipo)
{
    string stringSQL;

    stringstream ss;
    ss << tipo->getTipID();

    stringSQL = "DELETE FROM tipo WHERE tip_id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void TipoDAO::save(Tipo* tipo)
{
    if (exist(tipo))
        update(tipo);
    else
        add(tipo);
}

bool TipoDAO::exist(Tipo* tipo)
{
    string stringSQL;

    stringstream ss;
    ss << tipo->getTipID();

    stringSQL = "SELECT * FROM tipo WHERE tip_id = " + ss.str();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    return res->next();
}

void TipoDAO::update(Tipo* tipo)
{
    string stringSQL;

    stringstream ss;
    ss << tipo->getTipID();

    stringSQL = "UPDATE tipo SET tip_nombre = '" + tipo->getNombre() + "' WHERE tip_id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void TipoDAO::add(Tipo* tipo)
{
    stringstream ss;

    string stringSQL;

    ss << tipo->getTipID();

    stringSQL = "INSERT INTO tipo (tip_id, tip_nombre) VALUES (" + ss.str() + ", '" + tipo->getNombre() + "')";
    MyConnection::instance()->execute(stringSQL);
}

Tipo* TipoDAO::find(int tipID)
{
    string stringSQL;

    stringstream ss;
    ss << tipID;

    stringSQL = "SELECT * FROM tipo WHERE tip_id = " + ss.str();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    if (res->next())
    {
        Tipo* tipo = new Tipo(res);
        delete res;
        return tipo;
    }

    delete res;
    return new Tipo();
}

