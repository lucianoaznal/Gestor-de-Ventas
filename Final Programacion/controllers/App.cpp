#include"App.h"


void App::run(){
    while(true){
        if(!Sesion::estaIniciada()){
            logueo();
        }else{
            menuPrincipal();
            break;
        }
    }
}

bool App::logueo(){
    system("cls");
    int op;
    std::cout << "BIENVENIDO AL SISTEMA DE GESTION!" << std::endl
              << "---------------------------------" << std::endl
              << "Ingrese su Id: ";
    std::cin >> op;
    FEmpleado archivo;
    Empleado registro = archivo.buscarPorId(op);
    if(registro.getId() != -1){
        std::cout << "Bienvenido  " << registro.getApellido() << ", " << registro.getNombre() << "."
        << std::endl << std::endl;
        Sesion::setEmpleado(registro);
        system("pause");
        return true;
    }else{
        system("cls");
        std::cout << "El Id Ingresado no se encuentra registrado."
        << std::endl << std::endl;

    }
    return false;
}

void App::menuPrincipal(){
    std::string opciones[7] = {
        "1. Ventas",
        "2. Productos",
        "3. Clientes",
        "4. Empleados",
        "5. Reportes",
        "6. Configuracion",
        "0. Salir"};
     Menu menu("Menu Principal", opciones, 7);
     int seleccion = 0;
     do{
        system("cls");
        menu.dibujar();
        seleccion = menu.seleccionar();
        switch(seleccion){
            case 0: break;
            case 1: venta.run();
            break;
            case 2: producto.run();
            break;
            case 3: cliente.run();
            break;
            case 4: empleado.run();
            break;
            case 5: //reportes.run();
            break;
            case 6: //configuracion.run();
            break;
            default: break;
        }
    }while(seleccion != 0);
    system("cls");
    std::cout << "Saliendo del sistema...." << std::endl << std::endl;
}


