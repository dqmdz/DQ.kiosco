#ifndef CLIENTENODE_H
#define CLIENTENODE_H

#include "cliente.h"

class ClienteNode
{
    public:
        ClienteNode();
        ClienteNode(Cliente*);
        virtual ~ClienteNode();
        void setCliente(Cliente*);
        Cliente* getCliente();
        void setNext(ClienteNode*);
        ClienteNode* getNext();
        void show();
    protected:
        Cliente* cliente;
        ClienteNode* next;
    private:
};

#endif // CLIENTENODE_H
