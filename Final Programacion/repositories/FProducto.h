#pragma once
#include<cstring>
#include<iostream>
#include<fstream>
#include"../entities/producto.h"

class FProducto{
    public:
        FProducto();

        bool guardar(const Producto&);
        Producto leer(int);
        void leer(Producto*);
        int cantidadRegistros();
        Producto buscarPorId(int);
        bool modificar(const Producto,int pos);
        void guardaryreportar(const Producto&);
        int buscarPosicionPorId(int);
        int cantidadDeActivos();

    private:
        std::string nombre;
};
