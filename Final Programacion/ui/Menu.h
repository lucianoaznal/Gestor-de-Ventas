#pragma once
#include<iostream>
#include"UIBase.h"



class Menu : public UIBase{
    private:
        std::string _titulo;
        std::string* _opciones;
        int _cantidad;
        int _seleccion;
    public:
        Menu();
        Menu(std::string titulo, std::string* opciones, int cantidad);
        ~Menu();
        void run();
        void ejecutar(int);
        int seleccionar();
        void dibujar();

};
