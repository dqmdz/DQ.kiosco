#include "tiponode.h"
#include <cstddef>

TipoNode::TipoNode()
{
    //ctor
    tipo = NULL;
    next = NULL;
}

TipoNode::TipoNode(Tipo* tipo)
{
    //ctor
    this->setTipo(tipo);
    next = NULL;
}

TipoNode::~TipoNode()
{
    //dtor
}

TipoNode* TipoNode::getNext()
{
    return next;
}

void TipoNode::setNext(TipoNode* next)
{
    this->next = next;
}

Tipo* TipoNode::getTipo()
{
    return tipo;
}

void TipoNode::setTipo(Tipo* tipo)
{
    this->tipo = tipo;
}

void TipoNode::show()
{
    cout << tipo->toString();
}
