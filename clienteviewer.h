#ifndef CLIENTEVIEWER_H
#define CLIENTEVIEWER_H

#include "clientequeue.h"

class ClienteViewer
{
    public:
        ClienteViewer();
        virtual ~ClienteViewer();
        int menu();
        void listar(ClienteQueue*);
        int buscar();
        void mostrar(Cliente*);
        void cargar(Cliente*, string);
        void mensaje(string);
    protected:
    private:
};

#endif // CLIENTEVIEWER_H
