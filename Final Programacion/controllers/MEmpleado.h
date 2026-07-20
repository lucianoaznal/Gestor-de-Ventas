#pragma once
#include"Manager.h"
#include"../repositories/FEmpleado.h"
#include"../entities/Empleado.h"
#include"../ui/UIEmpleado.h"
#include"../ui/menu.h"

class MEmpleado : public Manager{
    private:
        FEmpleado archivo;
    public:
        MEmpleado();
        void listar() override;
        void cargar() override;
        void eliminar() override;
        void buscarPorId() override;
        void editar() override;
        void ordenar(int) override;
        void run();
        Empleado buscar(int);



};
