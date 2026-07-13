#include"UICliente.h"

void UICliente::showHeader(){
    std::cout << "CLIENTES" << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << std::left
    << std::setw(5) << "ID"
    << std::setw(15) << "Nombre"
    << std::setw(15) << "Apellido"
    << std::setw(15) << "Localidad"
    << std::setw(8) << "Edad"
    << std::setw(25) << "Email"
    << std::endl;
    std::cout << "========================================================================" << std::endl;
}

void UICliente::showRow(Cliente& registro){
    std::cout << std::left
    << std::setw(5) << registro.getId()
    << std::setw(15) << registro.getNombre()
    << std::setw(15) << registro.getApellido()
    << std::setw(15) << registro.getLocalidad()
    << std::setw(8) << registro.getEdad(registro.getFecha())
    << std::setw(25) << registro.getEmail()
    << std::endl;
    }

void UICliente::showRegister(Cliente& reg){
    std::cout << "\n ========================================" << std::endl;
    std::cout << "          FICHA TECNICA DEL CLIENTE      " << std::endl;
    std::cout << " ========================================" << std::endl;

    // Datos heredados de Persona
    std::cout << " ID Cliente : " << reg.getId() << std::endl; // Específico de Cliente
    std::cout << " DNI        : " << reg.getDni() << std::endl;
    std::cout << " Nombre     : " << reg.getNombre() << std::endl;
    std::cout << " Apellido   : " << reg.getApellido() << std::endl;

    std::cout << " ----------------------------------------" << std::endl;

    std::cout << " Email      : " << reg.getEmail() << std::endl;
    std::cout << " Telefono   : " << reg.getTelefono() << std::endl;

    // Aquí puedes llamar al mostrar del domicilio si Domicilio tiene su propio mostrar()
    std::cout << " Domicilio  : ";
    //reg.getDomicilio().mostrar();
    std::cout << std::endl;

    std::cout << " Fecha Nac. : ";
    reg.getFecha().mostrar();
    std::cout << std::endl;

    std::cout << " ========================================\n" << std::endl;
}

