#pragma once
#include<iostream>
#include<ctime>
#include"../controllers/Manager.h"

class Fecha{
    public:
        Fecha();
        Fecha(int,int,int);
        void mostrar();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia();
        int getMes();
        int getAnio();
        bool esFechaValida(int,int,int)const;
        void setFechaActual();
        Fecha getFechaActual();
        void cargar();
        int getEdad(Fecha);
    private:
        int dia, mes, anio;

};
