#ifndef CLIENTEQUEUE_H
#define CLIENTEQUEUE_H

#include "clientenode.h"

class ClienteQueue
{
    public:
        ClienteQueue();
        virtual ~ClienteQueue();
        void setStart(ClienteNode*);
        ClienteNode* getStart();
        void setEnd(ClienteNode*);
        ClienteNode* getEnd();
        void add(Cliente*);
        Cliente* retrieve();
        void free();
        void show();
    protected:
        ClienteNode* start;
        ClienteNode* end;
    private:
};

#endif // CLIENTEQUEUE_H
