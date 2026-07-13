#pragma once
#include"UIBase.h"
#include"../entities/Cliente.h"
#include<iomanip>
#include<iostream>

class UICliente{
    public:
        static void showHeader();
        static void showRow(Cliente&);
        static void showRegister(Cliente&);
};
