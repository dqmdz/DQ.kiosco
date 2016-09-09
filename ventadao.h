#ifndef VENTADAO_H
#define VENTADAO_H

#include "venta.h"

class VentaDAO
{
    public:
        VentaDAO();
        virtual ~VentaDAO();
        void add(Venta*);
        void update(Venta*);
        bool exist(Venta*);
        void save(Venta*);
        void del(Venta*);
        Venta* find(int);
    protected:
    private:
};

#endif // VENTADAO_H
