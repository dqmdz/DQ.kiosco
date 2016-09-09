#ifndef TIPOVIEWER_H
#define TIPOVIEWER_H

#include "tipoqueue.h"

class TipoViewer
{
    public:
        TipoViewer();
        virtual ~TipoViewer();
        int menu();
        void listar(TipoQueue*);
        int buscar();
        void mostrar(Tipo*);
        void cargar(Tipo*, string);
        void mensaje(string);
    protected:
    private:
};

#endif // TIPOVIEWER_H
