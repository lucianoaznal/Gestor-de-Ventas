#pragma once
#include"../entities/Cliente.h"

class FCliente{
    private:
        std::string nombre;
    public:
        FCliente();
        bool guardar(const Cliente&);
        Cliente leer(int);
        void leer(Cliente*);
        int cantidadRegistros();
        Cliente buscarPorId(int);
        bool modificar(const Cliente,int pos);
        void guardaryreportar(const Cliente&);
        int buscarPosicionPorId(int);
        int cantidadDeActivos();

};
