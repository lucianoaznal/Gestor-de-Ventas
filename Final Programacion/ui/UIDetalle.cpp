#include"UIDetalle.h"

void UIDetalle::showHeader(){

    std::cout << "==========================" << std::endl;
    std::cout << "          DETALLE" << std::endl;
    std::cout << "==========================" << std::endl;
}

void UIDetalle::showRow(Detalle& registro){
    MProducto producto;
    std::cout << "Producto: ";
    producto.buscar(registro.getIdProducto()).mostrar();
}

void UIDetalle::showRegister(Detalle& registro){

    std::cout << "\n ========================================" << std::endl;
    std::cout << "               DETALLE" << std::endl;
    std::cout << " ========================================" << std::endl;

}


