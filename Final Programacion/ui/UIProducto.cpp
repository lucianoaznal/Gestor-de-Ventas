#include"UIProducto.h"


void UIProductos::showHeader(){
    std::cout << "PRODUCTOS" << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << std::left
    << std::setw(5) << "ID"
    << std::setw(15) << "Nombre"
    << std::setw(15) << "Marca"
    << std::setw(15) << "Modelo"
    << std::setw(11) << "Precio"
    << std::setw(6) << "Stock"
    << std::setw(6) << "Año"
    << std::endl;
    std::cout << "========================================================================" << std::endl;
}
void UIProductos::showRow(Producto& registro){
    std::cout << std::left
    << std::setw(5) << registro.getId()
    << std::setw(15) << registro.getNombre()
    << std::setw(15) << registro.getMarca()
    << std::setw(15) << registro.getModelo()
    << std::setw(1) << "$";
    std::cout << std::fixed << std::setprecision(0)
              << std::setw(10) << registro.getPrecio();
    std::cout << std::left
    << std::setw(6) << registro.getStock()
    << std::setw(6) << registro.getAnio()
    << std::endl;

}

void UIProductos::showRegister(Producto& reg){
    std::cout << "\n  ============================================" << std::endl;
    std::cout << "          FICHA TECNICA DEL PRODUCTO          " << std::endl;
    std::cout << "  ============================================" << std::endl;

    std::cout << "   ID :     " << reg.getId() << std::endl;
    std::cout << "   Nombre : " << reg.getNombre() << std::endl;
    std::cout << "   Marca :  " << reg.getMarca() << std::endl;
    std::cout << "   Modelo : " << reg.getModelo() << std::endl;

    std::cout << "  --------------------------------------------" << std::endl;

    std::cout << "   Precio : $" << reg.getPrecio() << std::endl;
    std::cout << "   Stock :  " << reg.getStock() << " unidades" << std::endl;

    std::cout << "  --------------------------------------------" << std::endl;

    std::cout << "   Anio :   " << reg.getAnio() << std::endl;
    std::cout << "   Madera : " << reg.getMadera() << std::endl;
    std::cout << "   Tipo :   " << reg.getTipo() << std::endl;
    std::cout << "   Zurda :  " << (reg.getZurda() ? "SI" : "NO") << std::endl;

    std::cout << "  ============================================\n" << std::endl;
}
