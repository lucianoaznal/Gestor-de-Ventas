#pragma once
#include"../entities/Empleado.h"

class FEmpleado{
    private:
        std::string nombre;
    public:
        FEmpleado();
        bool guardar(const Empleado&);
        Empleado leer(int);
        void leer(Empleado*);
        int cantidadRegistros();
        Empleado buscarPorId(int);
        bool modificar(const Empleado,int pos);
        void guardaryreportar(const Empleado&);
        int buscarPosicionPorId(int);
        int cantidadDeActivos();

};
