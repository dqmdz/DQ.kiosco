#include "tipoqueue.h"
#include <cstddef>

TipoQueue::TipoQueue()
{
    //ctor
    this->start = NULL;
    this->end = NULL;
}

TipoQueue::~TipoQueue()
{
    //dtor
    this->free();
}

Tipo* TipoQueue::retrieve()
{
    if (!start)
        return NULL;

    Tipo* value = start->getTipo();
    TipoNode* aux = start;

    start = start->getNext();

    delete aux;

    if (!start)
        end = NULL;

    return value;
}

void TipoQueue::add(Tipo* tipo)
{
    TipoNode* newTipoNode = new TipoNode(tipo);

    if (!start)
    {
        start = end = newTipoNode;
        return;
    }

    end->setNext(newTipoNode);
    end = newTipoNode;
}

TipoNode* TipoQueue::getStart()
{
    return start;
}

void TipoQueue::setStart(TipoNode* start)
{
    this->start = start;
}

TipoNode* TipoQueue::getEnd()
{
    return end;
}

void TipoQueue::setEnd(TipoNode* end)
{
    this->end = end;
}

void TipoQueue::free()
{
    while (TipoNode* aux = start)
    {
        start = start->getNext();
        delete aux;
    }
}

void TipoQueue::show()
{
    TipoNode* aux = start;
    while (aux)
    {
        aux->show();
        cout << endl;
        aux = aux->getNext();
    }
    cout << endl << endl;
}

