#pragma once
#include"UIBase.h"
#include"../entities/DetalleVenta.h"
#include"../controllers/MProducto.h"

#include<iomanip>
#include<iostream>

class UIDetalle{
    public:
        static void showHeader();
        static void showRow(Detalle&);
        static void showRegister(Detalle&);

};


