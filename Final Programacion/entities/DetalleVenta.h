#pragma once


class Detalle{
    public:

        Detalle();
        void setIdDetalle(int);
        void setIdVenta(int);
        void setIdProducto(int);
        void setCantidad(int);
        void setPrecio(float);
        void setEstado(bool);

        int getIdDetalle();
        int getIdVenta();
        int getIdProducto();
        int getCantidad();
        float getPrecio();
        bool getEstado();
        bool isValido();

    private:
        int idDetalle;
        int idVenta;
        int idProducto;
        int cantidad;
        float precioUnitario;
        bool estado;

};
