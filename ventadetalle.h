#ifndef VENTADETALLE_H
#define VENTADETALLE_H

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class VentaDetalle
{
    public:
        VentaDetalle();
        VentaDetalle(sql::ResultSet*);
        virtual ~VentaDetalle();
        int getVenID();
        void setVenID(int);
        int getArtID();
        void setArtID(int);
        int getCantidad();
        void setCantidad(int);
        void fillObject(sql::ResultSet*);
        string toString();
    protected:
    private:
        int venID;
        int artID;
        int cantidad;
};

#endif // VENTADETALLE_H
