#pragma once
#include<iostream>
#include"../entities/DetalleVenta.h"

class FDetalle{
    private:
        std::string nombre;
    public:
        FDetalle();
        bool guardar(const Detalle&);
        Detalle leer(int);
        void leer(Detalle*);
        int cantidadRegistros();
        Detalle buscarPorId(int);
        bool modificar(const Detalle,int pos);
        void guardaryreportar(Detalle&);
        int buscarPosicionPorId(int);
        int cantidadDeActivos();

};

