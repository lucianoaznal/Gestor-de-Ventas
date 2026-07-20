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

        if(c == 10){
            c = 0;
            pause();
            clearW();
            UICliente::showHeader();
        }
    }
}



void MCliente::cargar(){
    clearW();
    Cliente registro;
    Fecha fecha;
    Domicilio domicilio;
    registro.setId(archivo.cantidadRegistros()+1);
    std::cout << "ID #" << registro.getId()<< std::endl;
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
    if(registro.getId() != -1 && registro.getEstado() == true){

        UICliente::showRegister(registro);

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
        case 0: ordenarPorNombre(registro,cantidad);
                listar(registro,cantidad);
            break;
        case 1: ordenarPorEdad(registro,cantidad);
                listar(registro,cantidad);
            break;
    }
    delete[] registro;
}

void MCliente::ordenarPorNombre(Cliente* registro, int cantidad){
    Cliente aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = 0; j < cantidad - 1; j++){
            if(strcmp(registro[j].getNombre(), registro[j + 1].getNombre())> 0){
                aux = registro[j];
                registro[j] = registro[j+1];
                registro[j+1] = aux;
            }
        }
    }

}
void MCliente::ordenarPorEdad(Cliente* registro, int cantidad){
    Cliente aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = 0; j < cantidad - 1; j++){
            if(registro[j].getFecha().getEdad(registro[j].getFecha()) > registro[j+1].getFecha().getEdad(registro[j+1].getFecha())){
                aux = registro[j];
                registro[j] = registro[j+1];
                registro[j+1] = aux;
            }
        }
    }

}
void MCliente::listar(Cliente* registro, int cantidad){
    clearW();
    UICliente::showHeader();
    if(cantidad == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }
    int c = 0;
    for(int i = 0; i < cantidad; i ++){
        UICliente::showRow(registro[i]);
        c++;
        if(c == 10){
            c = 0;
            pause();
            clearW();
            UICliente::showHeader();
        }
    }

}

Cliente MCliente::buscar(int _busqueda){
    Cliente registro;
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
void MCliente::run(){

    std::string opciones[6] = {
     "1. Nuevo Cliente",
     "2. Listar Clientes",
     "3. Buscar por Id",
     "4. Modificar Cliente",
     "5. Eliminar Cliente",
     "0.   << Atras"};
     Menu menu("Clientes", opciones, 6);

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
