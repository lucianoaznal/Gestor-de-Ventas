#pragma once
#include"../ui/UIBase.h"
#include<iostream>

class Manager : public UIBase{
    public:
        Manager();
        virtual ~Manager();

        virtual void listar() = 0;
        virtual void cargar() = 0;
        virtual void editar() = 0;
        virtual void eliminar() = 0;
        virtual void buscarPorId() = 0;
        virtual void ordenar(int) = 0;

    protected:
        int cargarInt(std::string _msg);
        float cargarFloat(std::string _msg);
        void cargarChar(std::string _msg, char*, int _size);
        bool cargarBool(std::string);


};
