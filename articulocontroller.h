#ifndef ARTICULOCONTROLLER_H
#define ARTICULOCONTROLLER_H

class ArticuloController
{
    public:
        ArticuloController();
        virtual ~ArticuloController();
        void abm();
    protected:
    private:
        void listar();
        void buscar();
        void agregar();
        void modificar();
        void eliminar();
};

#endif // ARTICULOCONTROLLER_H
