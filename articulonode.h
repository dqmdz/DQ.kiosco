#ifndef ARTICULONODE_H
#define ARTICULONODE_H

#include "articulo.h"

class ArticuloNode
{
    public:
        ArticuloNode();
        ArticuloNode(Articulo*);
        virtual ~ArticuloNode();
        void setArticulo(Articulo*);
        Articulo* getArticulo();
        void setNext(ArticuloNode*);
        ArticuloNode* getNext();
        void show();
    protected:
        Articulo* articulo;
        ArticuloNode* next;
    private:
};

#endif // ARTICULONODE_H
