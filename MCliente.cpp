#include"MCliente.h"
#include"../ui/UICliente.h"
MCliente::MCliente(){}



void MCliente::listar(){
    clearW();
    Cliente registro;
    int paginador = archivo.cantidadRegistros();
    if(paginador == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }

    int c;
    UICliente::showHeader();
    for(int i = 0; i < paginador; i++){
        registro = archivo.leer(i);
        if(registro.getEstado() == true){
            UICliente::showRow(registro);
            c++;
        }

        if(c == 5){
            c = 0;
            pause();
            clearW();
            UICliente::showHeader();
        }
    }
}



void MCliente::cargar(){
    Cliente registro;
    Fecha fecha;
    Domicilio domicilio;
    registro.setId(archivo.cantidadRegistros()+1);
    registro.setDni(cargarInt("Dni: "));
    cargarChar("Nombre: ", registro.getNombre(),50);
    cargarChar("Apellido: ", registro.getApellido(),50);
    cargarChar("Email: ", registro.getEmail(),50);
    registro.setTelefono(cargarInt("Telefono: "));
    fecha.cargar();
    registro.setFecha(fecha);
    domicilio.Cargar();
    registro.setDomicilio(domicilio);
    archivo.guardaryreportar(registro);
    pause();
}


void MCliente::eliminar(){
    clearW();
    Cliente registro;
    int _id = cargarInt("Ingrese el ID: ");
    registro = archivo.buscarPorId(_id);
    clearW();
    if(registro.getId() != -1){
        std::cout << "==================================================================" << std::endl;
        UICliente::showRow(registro);
        std::cout << "==================================================================" << std::endl;
        if(!UIBase::confirm("Esta seguro que desea eliminar el registro ?")){
            UIBase::clearW();
            std::cout << "No se elimino el registro." << std::endl;
            UIBase::pause();
        }else{
            UIBase::clearW();
            registro.setEstado(false);
            archivo.modificar(registro,archivo.buscarPosicionPorId(_id));
            std::cout << "Registro eliminado." << std::endl;
            UIBase::pause();
        }
    }
    else{
        std::cout << "No se encontr� el registro." << std::endl;
    }
}


void MCliente::buscarPorId(){
    UIBase::clearW();
    Cliente registro;
    registro = archivo.buscarPorId(cargarInt("Ingrese el ID: "));
    clearW();
    if(registro.getId() != -1){
        UICliente::showRegister(registro);

    }else{
        std::cout << "No hay resultados a tu busqueda." << std::endl;
    }
    pause();
}




void MCliente::editar(){}




void MCliente::ordenar(int seleccion){
    int cantidad = archivo.cantidadDeActivos();
    Cliente* registro = new Cliente[cantidad];
    archivo.leer(registro);
    switch(seleccion){
        case 0: //ordenarNombre(registro,cantidad);
                //listar(registro,cantidad);
            break;
        case 1: //ordenarEdad(registro,cantidad);
                //listar(registro,cantidad);
            break;
    }
    delete[] registro;
}
