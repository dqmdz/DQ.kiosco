#include "clientenode.h"
#include <cstddef>

ClienteNode::ClienteNode()
{
    //ctor
    cliente = NULL;
    next = NULL;
}

ClienteNode::ClienteNode(Cliente* cliente)
{
    //ctor
    this->setCliente(cliente);
    next = NULL;
}

ClienteNode::~ClienteNode()
{
    //dtor
}

ClienteNode* ClienteNode::getNext()
{
    return next;
}

void ClienteNode::setNext(ClienteNode* next)
{
    this->next = next;
}

Cliente* ClienteNode::getCliente()
{
    return cliente;
}

void ClienteNode::setCliente(Cliente* cliente)
{
    this->cliente = cliente;
}

void ClienteNode::show()
{
    cout << cliente->toString();
}
