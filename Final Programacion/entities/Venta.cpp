#include"Venta.h"


Venta::Venta()
:estado(true)
{


}

    void Venta::setEstado(bool _estado){estado = _estado;}
    void Venta::setId(int _id){idVenta = _id;}
    void Venta::setIdCliente(int _id){idCliente = _id;}
    void Venta::setIdEmpleado(int _id){idEmpleado = _id;}
    void Venta::setFecha(Fecha _fecha){fecha = _fecha;}

    bool Venta::getEstado(){return estado;}
    int Venta::getId(){return idVenta;}
    int Venta::getIdCliente(){return idCliente;}
    int Venta::getIdEmpleado(){return idEmpleado;}
    Fecha Venta::getFecha(){return fecha;}

    bool Venta::isValido(){
        return true;
    }
