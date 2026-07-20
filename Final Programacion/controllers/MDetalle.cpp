#include"MDetalle.h"

MDetalle::MDetalle(){}

void MDetalle::listar(){
    clearW();
    Detalle registro;
    int paginador = archivo.cantidadRegistros();
    if(paginador == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }

    int c = 0;
    //UIProductos::showHeader();
    for(int i = 0; i < paginador; i++){
        registro = archivo.leer(i);
        if(registro.getEstado() == true){
            //UIProductos::showRow(registro);
            c++;
        }

        if(c == 10){
            c = 0;
            pause();
            clearW();
            //UIProductos::showHeader();
        }
    }
}
void MDetalle::listar(int id){
    Detalle registro;
    int paginador = archivo.cantidadRegistros();
    int total = 0;
    UIDetalle::showHeader();
    for(int i = 0; i < paginador; i ++){
        registro = archivo.leer(i);
        if(registro.getIdVenta() == id){
            UIDetalle::showRow(registro);
            total += registro.getPrecio();
        }
    }
    std::cout << "Total: $" << total << std::endl;


}
void MDetalle::cargar(){
    Detalle registro;
    /*
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
    */
}
void MDetalle::eliminar(){
    clearW();
    Detalle registro;
    int _id = cargarInt("Ingrese el ID: ");
    registro = archivo.buscarPorId(_id);
    clearW();
    if(registro.getIdDetalle() != -1){
       // UIProductos::showRegister(registro);
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
}


void MDetalle::buscarPorId(){
    UIBase::clearW();
    Detalle registro;
    registro = archivo.buscarPorId(cargarInt("Ingrese el ID: "));
    clearW();
    if(registro.getIdDetalle() != -1){
    //    UIProductos::showRegister(registro);

    }else{
        std::cout << "No hay resultados a tu busqueda." << std::endl;
    }
}
void MDetalle::editar(){


}
void MDetalle::ordenar(int seleccion){
    int cantidad = archivo.cantidadDeActivos();
    Detalle* registro = new Detalle[cantidad];
    archivo.leer(registro);
    switch(seleccion){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
    }
    delete[] registro;
}


void MDetalle::run(){

    std::string opciones[6] = {
     "1. Nuevo producto",
     "2. Listar Producto",
     "3. Buscar por Id",
     "4. Modificar Producto",
     "5. Eliminar Producto",
     "0.   << Atras"};
     Menu menu("Productos", opciones, 6);

     int seleccion = 0;
     do{
        system("cls");
        menu.dibujar();
        seleccion = menu.seleccionar();
        switch(seleccion){
            case 0: return; break;
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


void MDetalle::cargar(int idVenta){
    Detalle registro;

    registro.setIdVenta(idVenta);
    registro.setIdDetalle(archivo.cantidadRegistros() + 1);
    std::cout << "Ingrese producto por numero de ID" << std::endl;
    registro.setIdProducto(cargarInt("Producto: "));
    registro.setCantidad(cargarInt("Cantidad: "));
    registro.setEstado(true);
    registro.setPrecio(producto.buscarPorId(registro.getIdProducto()).getPrecio() * registro.getCantidad());
    archivo.guardar(registro);
}



