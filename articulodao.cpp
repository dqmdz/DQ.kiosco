#include "articulodao.h"
#include "myconnection.h"
#include <sstream>

ArticuloDAO::ArticuloDAO()
{
    //ctor
}

ArticuloDAO::~ArticuloDAO()
{
    //dtor
}

ArticuloQueue* ArticuloDAO::collection()
{
    ArticuloQueue* queue = new ArticuloQueue();
    sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM articulo ORDER BY art_id");

    while (res->next())
        queue->add(new Articulo(res));

    delete res;

    return queue;
}

void ArticuloDAO::del(Articulo* articulo)
{
    string stringSQL;

    stringstream ss;
    ss << articulo->getArtID();

    stringSQL = "DELETE FROM articulo WHERE art_id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void ArticuloDAO::save(Articulo* articulo)
{
    if (exist(articulo))
        update(articulo);
    else
        add(articulo);
}

bool ArticuloDAO::exist(Articulo* articulo)
{
    string stringSQL;

    stringstream ss;
    ss << articulo->getArtID();

    stringSQL = "SELECT * FROM articulo WHERE art_id = " + ss.str();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    return res->next();
}

void ArticuloDAO::update(Articulo* articulo)
{
    stringstream stringSQL;

    stringSQL << "UPDATE articulo SET art_nombre = '" << articulo->getNombre() << "'";
    stringSQL << ", art_precio = '" << articulo->getPrecio() << "'";
    stringSQL << " WHERE art_id = " << articulo->getArtID();
    MyConnection::instance()->execute(stringSQL.str());
}

void ArticuloDAO::add(Articulo* articulo)
{
    stringstream stringSQL;

    stringSQL << "INSERT INTO articulo (art_id, art_nombre, art_precio) VALUES (";
    stringSQL << articulo->getArtID();
    stringSQL << ", '" << articulo->getNombre() << "'";
    stringSQL << ", '" << articulo->getPrecio() << "'";
    stringSQL << ")";
    MyConnection::instance()->execute(stringSQL.str());
}

Articulo* ArticuloDAO::find(int artID)
{
    string stringSQL;

    stringstream ss;
    ss << artID;

    stringSQL = "SELECT * FROM articulo WHERE art_id = " + ss.str();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    if (res->next())
    {
        Articulo* articulo = new Articulo(res);
        delete res;
        return articulo;
    }

    delete res;
    return new Articulo();
}

