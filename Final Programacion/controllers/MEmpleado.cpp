#include"MEmpleado.h"
#include"../ui/UIEmpleado.h"
MEmpleado::MEmpleado(){}



void MEmpleado::listar(){
    clearW();
    Empleado registro;
    int paginador = archivo.cantidadRegistros();
    if(paginador == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }

    int c;
    UIEmpleado::showHeader();
    for(int i = 0; i < paginador; i++){
        registro = archivo.leer(i);
        if(registro.getEstado() == true){
            UIEmpleado::showRow(registro);
            c++;
        }

        if(c == 10){
            c = 0;
            pause();
            clearW();
            UIEmpleado::showHeader();
        }
    }
}



void MEmpleado::cargar(){
    clearW();
    Empleado registro;
    Fecha nacimiento, ingreso;
    Domicilio domicilio;
    registro.setId(archivo.cantidadRegistros()+1001);
    std::cout << "ID #" << registro.getId()<< std::endl;
    registro.setCategoria(cargarInt("Categoria: "));
    registro.setDni(cargarInt("Dni: "));
    cargarChar("Nombre: ", registro.getNombre(),50);
    cargarChar("Apellido: ", registro.getApellido(),50);
    cargarChar("Email: ", registro.getEmail(),50);
    registro.setTelefono(cargarInt("Telefono: "));
    std::cout << "Fecha de nacimiento" << std:: endl;
    nacimiento.cargar();
    registro.setFecha(nacimiento);
    domicilio.Cargar();
    registro.setDomicilio(domicilio);
    std::cout << "Fecha de ingreso" << std:: endl;
    ingreso.cargar();
    registro.setFecha(ingreso);

    archivo.guardaryreportar(registro);
    pause();
}


void MEmpleado::eliminar(){
    clearW();
    Empleado registro;
    int _id = cargarInt("Ingrese el ID: ");
    registro = archivo.buscarPorId(_id);
    clearW();
    if(registro.getId() != -1 && registro.getEstado() == true){

        UIEmpleado::showRegister(registro);

        if(!UIBase::confirm("Esta seguro que desea eliminar el registro ?")){
            UIBase::clearW();
            std::cout << "No se elimino el registro." << std::endl;
        }else{
            UIBase::clearW();
            registro.setEstado(false);
            archivo.modificar(registro,archivo.buscarPosicionPorId(_id));
            std::cout << "Registro eliminado." << std::endl;
        }
    }
    else{
        std::cout << "No se encontró el registro." << std::endl;
    }
    pause();
}


void MEmpleado::buscarPorId(){
    UIBase::clearW();
    Empleado registro;
    registro = archivo.buscarPorId(cargarInt("Ingrese el ID: "));
    clearW();
    if(registro.getId() != -1){
        UIEmpleado::showRegister(registro);

    }else{
        std::cout << "No hay resultados a tu busqueda." << std::endl;
    }
    pause();
}




void MEmpleado::editar(){}



void MEmpleado::ordenar(int orden){
}


void MEmpleado::run(){

    std::string opciones[6] = {
     "1. Nuevo Empleado",
     "2. Listar Empleados",
     "3. Buscar por Id",
     "4. Modificar Empleado",
     "5. Eliminar Empleado",
     "0.   << Atras"};
     Menu menu("Empleados", opciones, 6);

     int seleccion = 0;
     do{
        system("cls");
        menu.dibujar();
        seleccion = menu.seleccionar();
        switch(seleccion){
            case 0: break;
            case 1: cargar();
            break;
            case 2: listar();
            break;
            case 3: buscarPorId();
            break;
            case 4: editar();
            break;
            case 5: eliminar();
            break;
            default: break;
        }
        pause();
    }while(seleccion != 0);
    clearW();
}


Empleado MEmpleado::buscar(int _busqueda){
    Empleado registro;
    int cantidad = archivo.cantidadRegistros();
    for(int i = 0; i < cantidad;i++){
        registro = archivo.leer(i);
        if(registro.getId() == _busqueda || registro.getDni() == _busqueda){
            return registro;
        }
    }
    registro.setId(-1);
    return registro;


}

