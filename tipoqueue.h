#ifndef TIPOQUEUE_H
#define TIPOQUEUE_H

#include "tiponode.h"

class TipoQueue
{
    public:
        TipoQueue();
        virtual ~TipoQueue();
        void setStart(TipoNode*);
        TipoNode* getStart();
        void setEnd(TipoNode*);
        TipoNode* getEnd();
        void add(Tipo*);
        Tipo* retrieve();
        void free();
        void show();
    protected:
        TipoNode* start;
        TipoNode* end;
    private:
};

#endif // TIPOQUEUE_H
