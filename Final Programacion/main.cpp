#include <iostream>
#include"controllers/MVenta.h"
#include"repositories/FEmpleado.h"
#include"entities/Empleado.h"
#include"ui/Menu.h"
#include"entities/Sesion.h"


int main()
{

    MVenta app;

    int idIngresado;
    std::cout << "--- SISTEMA DE VENTAS ---" << std::endl;
    std::cout << "Ingrese ID de empleado: ";
    std::cin >> idIngresado;

    FEmpleado mempleado;
    Empleado e = mempleado.buscarPorId(idIngresado);

    if (e.getId() != -1) {
        Sesion::setEmpleado(e);
        std::cout << "Bienvenido " << e.getApellido() <<", " << e.getNombre()<< std::endl << std::endl << std::endl;
        system("pause");
        app.cargar();
    } else {
        std::cout << "Acceso denegado." << std::endl;
    }


    return 0;
}
