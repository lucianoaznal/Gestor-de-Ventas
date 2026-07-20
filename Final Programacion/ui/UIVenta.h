#pragma once
#include"UIBase.h"
#include"../entities/Venta.h"
#include"../controllers/MCliente.h"
#include"../controllers/MEmpleado.h"

#include"../controllers/MDetalle.h"
#include<iomanip>
#include<iostream>

class UIVenta{
    public:
        static void showHeader();
        static void showRow(Venta&);
        static void showRegister(Venta&);

};

