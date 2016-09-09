#ifndef TIPODAO_H
#define TIPODAO_H

#include "tipo.h"
#include "tipoqueue.h"

class TipoDAO
{
    public:
        TipoDAO();
        virtual ~TipoDAO();
        void add(Tipo*);
        void update(Tipo*);
        bool exist(Tipo*);
        void save(Tipo*);
        void del(Tipo*);
        Tipo* find(int);
        TipoQueue* collection();
    protected:
    private:
};

#endif // TIPODAO_H
