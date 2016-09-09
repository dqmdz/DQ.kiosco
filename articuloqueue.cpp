#include "articuloqueue.h"
#include <cstddef>

ArticuloQueue::ArticuloQueue()
{
    //ctor
    this->start = NULL;
    this->end = NULL;
}

ArticuloQueue::~ArticuloQueue()
{
    //dtor
    this->free();
}

Articulo* ArticuloQueue::retrieve()
{
    if (!start)
        return NULL;

    Articulo* value = start->getArticulo();
    ArticuloNode* aux = start;

    start = start->getNext();

    delete aux;

    if (!start)
        end = NULL;

    return value;
}

void ArticuloQueue::add(Articulo* articulo)
{
    ArticuloNode* newArticuloNode = new ArticuloNode(articulo);

    if (!start)
    {
        start = end = newArticuloNode;
        return;
    }

    end->setNext(newArticuloNode);
    end = newArticuloNode;
}

ArticuloNode* ArticuloQueue::getStart()
{
    return start;
}

void ArticuloQueue::setStart(ArticuloNode* start)
{
    this->start = start;
}

ArticuloNode* ArticuloQueue::getEnd()
{
    return end;
}

void ArticuloQueue::setEnd(ArticuloNode* end)
{
    this->end = end;
}

void ArticuloQueue::free()
{
    while (ArticuloNode* aux = start)
    {
        start = start->getNext();
        delete aux;
    }
}

void ArticuloQueue::show()
{
    ArticuloNode* aux = start;
    while (aux)
    {
        aux->show();
        cout << endl;
        aux = aux->getNext();
    }
    cout << endl << endl;
}

