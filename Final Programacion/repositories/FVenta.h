#pragma once
#include"../entities/Venta.h"

class FVenta{
    private:
        std::string nombre;
    public:
        FVenta();
        bool guardar(const Venta&);
        Venta leer(int);
        void leer(Venta*);
        int cantidadRegistros();
        Venta buscarPorId(int);
        bool modificar(const Venta,int pos);
        void guardaryreportar(Venta&);
        int buscarPosicionPorId(int);
        int cantidadDeActivos();

};

