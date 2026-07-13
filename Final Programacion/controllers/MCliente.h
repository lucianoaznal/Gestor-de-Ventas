#pragma once
#include"Manager.h"
#include"../repositories/FCliente.h"
#include"../entities/Cliente.h"
#include"../ui/UICliente.h"

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

};
