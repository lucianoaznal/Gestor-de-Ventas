#include"UIVenta.h"

void UIVenta::showHeader(){

    std::cout << "VENTAS" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    std::cout << std::left
    << std::setw(5) << "ID"
    << std::setw(15) << "Cliente"
    << std::setw(15) << "Empleado"
    << std::setw(12) << "Fecha"
    << std::setw(20) << "Detalle"
    << std::endl;
    std::cout << "==================================================================================" << std::endl;
}

void UIVenta::showRow(Venta& registro){
MCliente cliente;
        MEmpleado empleado;

    std::cout << std::left
    << std::setw(5) << registro.getId()
    << std::setw(15) << cliente.buscar(registro.getIdCliente()).getApellido()
    << std::setw(15) << registro.getIdEmpleado()
    << std::setw(2) << registro.getFecha().getDia()
    << std::setw(1) << "/"
    << std::setw(2) << registro.getFecha().getMes()
    << std::setw(1) << "/"
    << std::setw(4) << registro.getFecha().getAnio()
    << std::endl;
}

void UIVenta::showRegister(Venta& registro){
    MCliente cliente;
    MEmpleado empleado;
    MDetalle detalle;
    std::cout << "\n ========================================" << std::endl;
    std::cout << "          REGISTRO DE VENTA #"<<registro.getId() << std::endl;
    std::cout << " ========================================" << std::endl;
    registro.getFecha().mostrar(); std::cout << std::endl;
    std::cout << "Empleado: "; empleado.buscar(registro.getIdEmpleado()).mostrar();
    std::cout << "Cliente: "; cliente.buscar(registro.getIdCliente()).mostrar();
    detalle.listar(registro.getId());
    std::cout << std::endl;
}


