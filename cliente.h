#ifndef CLIENTE_H
#define CLIENTE_H

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Cliente
{
    public:
        Cliente();
        Cliente(sql::ResultSet*);
        virtual ~Cliente();
        int getCliID();
        void setCliID(int);
        string getNombre();
        void setNombre(string);
        void fillObject(sql::ResultSet*);
        string toString();
    protected:
    private:
        int cliID;
        string nombre;
};

#endif // CLIENTE_H
