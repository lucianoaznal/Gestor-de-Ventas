#pragma once
#include"Persona.h"


class Empleado : public Persona{
    public:
        Empleado();
        void setId(int);
        void setCategoria(int);
        void setFechaIngreso(Fecha&);

        int getId();
        int getCategoria();
        Fecha getFechaIngreso();

        bool isValido()const;
    private:
        int ID;
        int categoria;
        Fecha fechaIngreso;
};
