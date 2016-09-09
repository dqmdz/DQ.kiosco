#include "articulonode.h"
#include <cstddef>

ArticuloNode::ArticuloNode()
{
    //ctor
    articulo = NULL;
    next = NULL;
}

ArticuloNode::ArticuloNode(Articulo* articulo)
{
    //ctor
    this->setArticulo(articulo);
    next = NULL;
}

ArticuloNode::~ArticuloNode()
{
    //dtor
}

ArticuloNode* ArticuloNode::getNext()
{
    return next;
}

void ArticuloNode::setNext(ArticuloNode* next)
{
    this->next = next;
}

Articulo* ArticuloNode::getArticulo()
{
    return articulo;
}

void ArticuloNode::setArticulo(Articulo* articulo)
{
    this->articulo = articulo;
}

void ArticuloNode::show()
{
    cout << articulo->toString();
}
