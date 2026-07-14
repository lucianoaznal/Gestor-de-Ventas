#pragma once
#include"Manager.h"
#include"../repositories/FVenta.h"
#include"../repositories/FEmpleado.h"
#include"MCliente.h"
#include"../entities/Empleado.h"
#include"../entities/Cliente.h"
#include"../entities/Sesion.h"


class MVenta : public Manager{
    private:
        FVenta archivo;
        MCliente mcliente;
    public:
        MVenta();
        void listar() override;
        void cargar() override;
        void eliminar() override;
        void buscarPorId() override;
        void editar() override;
        void ordenar(int) override;

};
