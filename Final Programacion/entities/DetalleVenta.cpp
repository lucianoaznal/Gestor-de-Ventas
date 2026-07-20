#include"DetalleVenta.h"


    Detalle::Detalle()
    :estado(true){}

    void Detalle::setIdDetalle(int aux){idDetalle=aux;}
    void Detalle::setIdVenta(int aux){idVenta  = aux;}
    void Detalle::setIdProducto(int aux){idProducto = aux;}
    void Detalle::setCantidad(int aux){cantidad = aux;}
    void Detalle::setPrecio(float aux){precioUnitario = aux;}
    void Detalle::setEstado(bool aux){estado = aux;}

    int Detalle::getIdDetalle(){return idDetalle;}
    int Detalle::getIdVenta(){return idVenta;}
    int Detalle::getIdProducto(){return idProducto;}
    int Detalle::getCantidad(){return cantidad;}
    float Detalle::getPrecio(){return precioUnitario;}
    bool Detalle::getEstado(){return estado;}
    bool Detalle::isValido(){return true;}
