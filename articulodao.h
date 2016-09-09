#ifndef ARTICULODAO_H
#define ARTICULODAO_H

#include "articulo.h"
#include "articuloqueue.h"

class ArticuloDAO
{
    public:
        ArticuloDAO();
        virtual ~ArticuloDAO();
        void add(Articulo*);
        void update(Articulo*);
        bool exist(Articulo*);
        void save(Articulo*);
        void del(Articulo*);
        Articulo* find(int);
        ArticuloQueue* collection();
    protected:
    private:
};

#endif // ARTICULODAO_H
