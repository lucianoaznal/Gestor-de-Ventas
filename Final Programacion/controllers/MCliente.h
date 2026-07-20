#pragma once
#include"Manager.h"
#include"../repositories/FCliente.h"
#include"../entities/Cliente.h"
#include"../ui/UICliente.h"
#include"../ui/menu.h"

class MCliente : public Manager{
    private:
        FCliente archivo;
    public:
        MCliente();
        void listar() override;
        void cargar() override;
        void eliminar() override;
        void buscarPorId() override;
        void editar() override;
        void ordenar(int) override;
        Cliente buscar(int);
        void run();

        void listar(Cliente*,int);
        void ordenarPorNombre(Cliente*,int);
        void ordenarPorEdad(Cliente*,int);

};
