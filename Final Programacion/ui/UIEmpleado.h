#pragma once
#include"UIBase.h"
#include"../entities/Empleado.h"
#include<iomanip>
#include<iostream>

class UIEmpleado{
    public:
        static void showHeader();
        static void showRow(Empleado&);
        static void showRegister(Empleado&);
};
