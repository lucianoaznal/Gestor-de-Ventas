#pragma once
#include"UIBase.h"
#include"../entities/producto.h"
#include<iomanip>
#include<iostream>

class UIProductos{
    public:
        static void showHeader();
        static void showRow(Producto&);
        static void showRegister(Producto&);
};
