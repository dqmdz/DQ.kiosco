#ifndef TIPOCONTROLLER_H
#define TIPOCONTROLLER_H

class TipoController
{
    public:
        TipoController();
        virtual ~TipoController();
        void abm();
    protected:
    private:
        void listar();
        void buscar();
        void agregar();
        void modificar();
        void eliminar();
};

#endif // TIPOCONTROLLER_H
