#ifndef CLIENTECONTROLLER_H
#define CLIENTECONTROLLER_H

class ClienteController
{
    public:
        ClienteController();
        virtual ~ClienteController();
        void abm();
    protected:
    private:
        void listar();
        void buscar();
        void agregar();
        void modificar();
        void eliminar();
};

#endif // CLIENTECONTROLLER_H
