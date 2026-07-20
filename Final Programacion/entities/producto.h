#pragma once
#include<iostream>
#include<cstring>

class Producto{
    private:
        int id_producto;
        char nombre[50];
        char marca[50];
        char modelo[50];
        int anio;
        float precio;
        int color;
        bool zurda;
        char tipo[50];
        char madera[50];
        int stock;
        bool estado;
    public:
        Producto();
        bool isValido() const;
        void mostrar();

        void setId(int);
        void setNombre(const char*);
        void setMarca(const char*);
        void setModelo(const char*);
        void setAnio(int);
        void setPrecio(float);
        void setColor(int);
        void setZurda(bool);
        void setTipo(const char*);
        void setMadera(const char*);
        void setStock(int);
        void setEstado(bool);

        int getId();
        char* getNombre();
        char* getMarca();
        char* getModelo();
        int getAnio();
        float getPrecio();
        int getColor();
        bool getZurda();
        char* getTipo();
        char* getMadera();
        int getStock();
        bool getEstado();

        bool operator>(const Producto&)const;
        bool operator<(const Producto&)const;
};
