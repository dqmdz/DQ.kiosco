#include "clientedao.h"
#include "myconnection.h"
#include <sstream>

ClienteDAO::ClienteDAO()
{
    //ctor
}

ClienteDAO::~ClienteDAO()
{
    //dtor
}

ClienteQueue* ClienteDAO::collection()
{
    ClienteQueue* queue = new ClienteQueue();
    sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM cliente ORDER BY cli_id");

    while (res->next())
        queue->add(new Cliente(res));

    delete res;

    return queue;
}

void ClienteDAO::del(Cliente* cliente)
{
    string stringSQL;

    stringstream ss;
    ss << cliente->getCliID();

    stringSQL = "DELETE FROM cliente WHERE cli_id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void ClienteDAO::save(Cliente* cliente)
{
    if (exist(cliente))
        update(cliente);
    else
        add(cliente);
}

bool ClienteDAO::exist(Cliente* cliente)
{
    string stringSQL;

    stringstream ss;
    ss << cliente->getCliID();

    stringSQL = "SELECT * FROM cliente WHERE cli_id = " + ss.str();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    return res->next();
}

void ClienteDAO::update(Cliente* cliente)
{
    string stringSQL;

    stringstream ss;
    ss << cliente->getCliID();

    stringSQL = "UPDATE cliente SET cli_nombre = '" + cliente->getNombre() + "' WHERE cli_id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void ClienteDAO::add(Cliente* cliente)
{
    stringstream ss;

    string stringSQL;

    ss << cliente->getCliID();

    stringSQL = "INSERT INTO cliente (cli_id, cli_nombre) VALUES (" + ss.str() + ", '" + cliente->getNombre() + "')";
    MyConnection::instance()->execute(stringSQL);
}

Cliente* ClienteDAO::find(int cliID)
{
    string stringSQL;

    stringstream ss;
    ss << cliID;

    stringSQL = "SELECT * FROM cliente WHERE cli_id = " + ss.str();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    if (res->next())
    {
        Cliente* cliente = new Cliente(res);
        delete res;
        return cliente;
    }

    delete res;
    return new Cliente();
}

