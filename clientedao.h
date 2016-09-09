#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H

#include "cliente.h"
#include "clientequeue.h"

class ClienteDAO
{
    public:
        ClienteDAO();
        virtual ~ClienteDAO();
        void add(Cliente*);
        void update(Cliente*);
        bool exist(Cliente*);
        void save(Cliente*);
        void del(Cliente*);
        Cliente* find(int);
        ClienteQueue* collection();
    protected:
    private:
};

#endif // CLIENTEDAO_H
