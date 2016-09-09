#ifndef TIPO_H
#define TIPO_H

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Tipo
{
    public:
        Tipo();
        Tipo(sql::ResultSet*);
        virtual ~Tipo();
        int getTipID();
        void setTipID(int);
        string getNombre();
        void setNombre(string);
        void fillObject(sql::ResultSet*);
        string toString();
    protected:
    private:
        int tipID;
        string nombre;
};

#endif // TIPO_H
