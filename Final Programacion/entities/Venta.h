#pragma once
#include"Fecha.h"

class Venta{
    public:
        Venta();

        void setEstado(bool);
        void setId(int);
        void setIdCliente(int);
        void setIdEmpleado(int);
        void setFecha(Fecha);

        bool isValido();

        bool getEstado();
        int getId();
        int getIdCliente();
        int getIdEmpleado();
        Fecha getFecha();

    private:
        bool estado;
        int idVenta;
        int idCliente;
        int idEmpleado;
        Fecha fecha;

};
