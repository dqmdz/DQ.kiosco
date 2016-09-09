#ifndef VENTA_H
#define VENTA_H

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Venta
{
    public:
        Venta();
        Venta(sql::ResultSet*);
        virtual ~Venta();
        int getVenID();
        void setVenID(int);
        int getCliID();
        void setCliID(int);
        int getTipID();
        void setTipID(int);
        double getImporte();
        void setImporte(double);
        void fillObject(sql::ResultSet*);
        string toString();
    protected:
    private:
        int venID;
        int cliID;
        int tipID;
        double importe;
};

#endif // VENTA_H
