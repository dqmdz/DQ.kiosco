#ifndef ARTICULO_H
#define ARTICULO_H

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Articulo
{
    public:
        Articulo();
        Articulo(sql::ResultSet*);
        virtual ~Articulo();
        int getArtID();
        void setArtID(int);
        string getNombre();
        void setNombre(string);
        double getPrecio();
        void setPrecio(double);
        void fillObject(sql::ResultSet*);
        string toString();
    protected:
    private:
        int artID;
        string nombre;
        double precio;
};

#endif // ARTICULO_H
