#pragma once
#include"../repositories/FEmpleado.h"
#include"../entities/Sesion.h"
#include"MCliente.h"
#include"MEmpleado.h"
#include"MVenta.h"
#include"MProducto.h"
#include"../ui/Menu.h"


class App{
    public:
        void run();
        bool logueo();
        void menuPrincipal();
    private:
        MCliente cliente;
        MEmpleado empleado;
        MProducto producto;
        MVenta venta;
        Menu menu;
};
