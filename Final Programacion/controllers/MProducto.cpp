#include"MProducto.h"

MProducto::MProducto(){
}
MProducto::~MProducto(){
}
void MProducto::listar(){
    clearW();
    Producto registro;
    int paginador = archivo.cantidadRegistros();
    if(paginador == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }

    int c;
    UIProductos::showHeader();
    for(int i = 0; i < paginador; i++){
        registro = archivo.leer(i);
        if(registro.getEstado() == true){
            UIProductos::showRow(registro);
            c++;
        }

        if(c == 5){
            c = 0;
            pause();
            clearW();
            UIProductos::showHeader();
        }
    }



}
void MProducto::cargar(){
    Producto registro;
    registro.setId(archivo.cantidadRegistros() + 1);
    std::cout << "ID #" << registro.getId()<< std::endl;
    cargarChar("Nombre: ", registro.getNombre(), 50);
    cargarChar("Marca: ", registro.getMarca(), 50);
    cargarChar("Modelo: ", registro.getModelo(),50);
    registro.setAnio(cargarInt("Año: "));
    registro.setPrecio(cargarFloat("Precio: "));
    registro.setColor(cargarInt("Color: "));
    registro.setZurda(cargarBool("Zurda "));
    cargarChar("Tipo: ", registro.getTipo(),50);
    cargarChar("Madera: ", registro.getMadera(),50);
    registro.setStock(cargarInt("Stock: "));
    archivo.guardaryreportar(registro);
    pause();
}
void MProducto::eliminar(){
    clearW();
    Producto registro;
    int _id = cargarInt("Ingrese el ID: ");
    registro = archivo.buscarPorId(_id);
    clearW();
    if(registro.getId() != -1){
        std::cout << "==================================================================" << std::endl;
        UIProductos::showRow(registro);
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
        std::cout << "No se encontró el registro." << std::endl;
    }

}


void MProducto::buscarPorId(){
    UIBase::clearW();
    Producto registro;
    registro = archivo.buscarPorId(cargarInt("Ingrese el ID: "));
    clearW();
    if(registro.getId() != -1){
        UIProductos::showRegister(registro);

    }else{
        std::cout << "No hay resultados a tu busqueda." << std::endl;
    }
    pause();
}
void MProducto::editar(){


}
void MProducto::ordenar(int seleccion){
    int cantidad = archivo.cantidadDeActivos();
    Producto* registro = new Producto[cantidad];
    archivo.leer(registro);
    switch(seleccion){
        case 0: ordenarFecha(registro,cantidad);
                listar(registro,cantidad);
            break;
        case 1: ordenarNombre(registro,cantidad);
                listar(registro,cantidad);
            break;
        case 2: ordenarPrecio(registro,cantidad);
                listar(registro,cantidad);
            break;
    }
    delete[] registro;
}

void MProducto::ordenarFecha(Producto* registro, int cantidad){
    Producto aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = 0; j < cantidad - 1; j++){
            if(registro[j] > registro[j+1]){
                aux = registro[j];
                registro[j] = registro[j+1];
                registro[j+1] = aux;
            }
        }
    }
}
void MProducto::ordenarPrecio(Producto* registro, int cantidad){
    Producto aux;
    for(int i = 0; i < cantidad; i++){
        for(int j = 0; j < cantidad - 1; j++){
            if(registro[j] < registro[j+1]){
                aux = registro[j];
                registro[j] = registro[j+1];
                registro[j+1] = aux;
            }
        }
    }
}
void MProducto::ordenarNombre(Producto* registro, int cantidad){
    Producto aux;
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

void MProducto::listar(Producto* registro, int cantidad){
    UIBase::clearW();
    UIProductos::showHeader();
    if(cantidad == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }
    int c = 0;
    for(int i = 0; i < cantidad; i ++){
        UIProductos::showRow(registro[i]);
        c++;
        if(c == 10){
            c = 0;
            pause();
            clearW();
            UIProductos::showHeader();
        }
    }
}
