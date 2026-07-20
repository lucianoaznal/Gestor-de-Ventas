#pragma once
#include"Manager.h"
#include"../repositories/FVenta.h"
#include"../repositories/FEmpleado.h"
#include"MCliente.h"
#include"../ui/Menu.h"
#include"../ui/UIVenta.h"
#include"../entities/Empleado.h"
#include"../entities/Cliente.h"
#include"../entities/Sesion.h"
#include"MDetalle.h"


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
        void run();

};
