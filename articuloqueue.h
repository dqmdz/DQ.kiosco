#ifndef ARTICULOQUEUE_H
#define ARTICULOQUEUE_H

#include "articulonode.h"

class ArticuloQueue
{
    public:
        ArticuloQueue();
        virtual ~ArticuloQueue();
        void setStart(ArticuloNode*);
        ArticuloNode* getStart();
        void setEnd(ArticuloNode*);
        ArticuloNode* getEnd();
        void add(Articulo*);
        Articulo* retrieve();
        void free();
        void show();
    protected:
        ArticuloNode* start;
        ArticuloNode* end;
    private:
};

#endif // ARTICULOQUEUE_H
