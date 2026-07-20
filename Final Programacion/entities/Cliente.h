#pragma once
#include"Persona.h"


class Cliente : public Persona{
    public:
        Cliente();
        void setId(int);
        int getId();
        bool isValido()const;
        void mostrar();
    private:
        int ID;
};
