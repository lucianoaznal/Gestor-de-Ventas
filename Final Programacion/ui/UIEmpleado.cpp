#include"UIEmpleado.h"

void UIEmpleado::showHeader(){
    std::cout << "EMPLEADOS" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    std::cout << std::left
    << std::setw(5) << "ID"
    << std::setw(15) << "Nombre"
    << std::setw(15) << "Apellido"
    << std::setw(20) << "Localidad"
    << std::setw(15) << "Antiguedad"
    << std::setw(8) << "Cat. "
    << std::endl;
    std::cout << "==================================================================================" << std::endl;
}

void UIEmpleado::showRow(Empleado& registro){
    std::cout << std::left
    << std::setw(5) << registro.getId()
    << std::setw(15) << registro.getNombre()
    << std::setw(15) << registro.getApellido()
    << std::setw(20) << registro.getLocalidad()
    << std::setw(2) << registro.getEdad(registro.getFechaIngreso())
    << std::setw(13) << " años"
    << std::setw(8) << registro.getCategoria()
    << std::endl;
    }

void UIEmpleado::showRegister(Empleado& reg){
    std::cout << "\n ========================================" << std::endl;
    std::cout << "          FICHA TECNICA DEL EMPLEADO      " << std::endl;
    std::cout << " ========================================" << std::endl;


    std::cout << " ID Cliente : " << reg.getId() << std::endl;
    std::cout << " Categoria  : " << reg.getCategoria() << std::endl;
    std::cout << " DNI        : " << reg.getDni() << std::endl;
    std::cout << " Nombre     : " << reg.getNombre() << std::endl;
    std::cout << " Apellido   : " << reg.getApellido() << std::endl;

    std::cout << " ----------------------------------------" << std::endl;

    std::cout << " Email      : " << reg.getEmail() << std::endl;
    std::cout << " Telefono   : " << reg.getTelefono() << std::endl;

    std::cout << " Domicilio  : ";
    reg.getDomicilio().Mostrar();
    std::cout << std::endl;

    std::cout << " Fecha Nac. : ";
    reg.getFecha().mostrar();
    std::cout << std::endl;

    std::cout << " Ingreso    : ";
    reg.getFechaIngreso().mostrar();
    std::cout << std::endl;

    std::cout << " ========================================\n" << std::endl;

}

