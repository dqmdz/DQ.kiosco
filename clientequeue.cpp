#include "clientequeue.h"
#include <cstddef>

ClienteQueue::ClienteQueue()
{
    //ctor
    this->start = NULL;
    this->end = NULL;
}

ClienteQueue::~ClienteQueue()
{
    //dtor
    this->free();
}

Cliente* ClienteQueue::retrieve()
{
    if (!start)
        return NULL;

    Cliente* value = start->getCliente();
    ClienteNode* aux = start;

    start = start->getNext();

    delete aux;

    if (!start)
        end = NULL;

    return value;
}

void ClienteQueue::add(Cliente* cliente)
{
    ClienteNode* newClienteNode = new ClienteNode(cliente);

    if (!start)
    {
        start = end = newClienteNode;
        return;
    }

    end->setNext(newClienteNode);
    end = newClienteNode;
}

ClienteNode* ClienteQueue::getStart()
{
    return start;
}

void ClienteQueue::setStart(ClienteNode* start)
{
    this->start = start;
}

ClienteNode* ClienteQueue::getEnd()
{
    return end;
}

void ClienteQueue::setEnd(ClienteNode* end)
{
    this->end = end;
}

void ClienteQueue::free()
{
    while (ClienteNode* aux = start)
    {
        start = start->getNext();
        delete aux;
    }
}

void ClienteQueue::show()
{
    ClienteNode* aux = start;
    while (aux)
    {
        aux->show();
        cout << endl;
        aux = aux->getNext();
    }
    cout << endl << endl;
}

