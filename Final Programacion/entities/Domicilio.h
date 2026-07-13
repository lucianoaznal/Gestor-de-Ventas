#pragma once
#include <iostream>
#include<cstring>

class Domicilio{
    private:
        char calle[50];
        int altura;
        char localidad[50];
        char provincia[30];
        char codigoPostal[6];
    public:
        Domicilio();
        void Cargar();
        void Mostrar();
        void setCalle(const char *);
        void setAltura(int);
        void setLocalidad(const char *);
        void setProvincia(const char *);
        void setCodigoPostal(const char *);
        const char *getCalle();
        int getAltura();
        const char *getLocalidad();
        const char *getProvincia();
        const char *getCodigoPostal();
        void cargarChar(std::string _msg, char* _char, int c);
        int cargarInt(std::string _msg);
};

