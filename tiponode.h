#ifndef TIPONODE_H
#define TIPONODE_H

#include "tipo.h"

class TipoNode
{
    public:
        TipoNode();
        TipoNode(Tipo*);
        virtual ~TipoNode();
        void setTipo(Tipo*);
        Tipo* getTipo();
        void setNext(TipoNode*);
        TipoNode* getNext();
        void show();
    protected:
        Tipo* tipo;
        TipoNode* next;
    private:
};

#endif // TIPONODE_H
