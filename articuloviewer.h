#ifndef ARTICULOVIEWER_H
#define ARTICULOVIEWER_H

#include "articuloqueue.h"

class ArticuloViewer
{
    public:
        ArticuloViewer();
        virtual ~ArticuloViewer();
        int menu();
        void listar(ArticuloQueue*);
        int buscar();
        void mostrar(Articulo*);
        void cargar(Articulo*, string);
        void mensaje(string);
    protected:
    private:
};

#endif // ARTICULOVIEWER_H
