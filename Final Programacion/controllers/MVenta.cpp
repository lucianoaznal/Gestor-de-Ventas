#include"MVenta.h"

MVenta::MVenta()
{
}

void MVenta::cargar(){
    clearW();
    Venta registro;
    Cliente cliente;
    Empleado empleado;
    MDetalle detalle;
    int add;
    registro.setId(archivo.cantidadRegistros()+1);
    int id_cliente = cargarInt("Ingrese el DNI del cliente: ");
    cliente = mcliente.buscar(id_cliente);
    if(cliente.getId() == -1){
        std::cout << "El Dni Ingresado no esta registrado." << std::endl;

        if(cargarBool("¿Registrar nuevo cliente?")){
            mcliente.cargar();
            FCliente fcliente;
            cliente = fcliente.leer(fcliente.cantidadRegistros()-1);
        }else{
            return;
        }

    }

    clearW();
    registro.setFecha(registro.getFecha().getFechaActual());
    std::cout << "=======================" << std::endl;
    std::cout << "      NUEVA VENTA" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Venta #" << registro.getId() << std::endl;
    std::cout << "Vendedor: " << Sesion::getEmpleado().getApellido() << ", "
    << Sesion::getEmpleado().getNombre() << std::endl;
    std::cout << "Cliente: " << cliente.getApellido() << ", " << cliente.getNombre() << std::endl;
    registro.getFecha().mostrar();
    std::cout << std::endl;
    registro.setIdCliente(cliente.getId());
    registro.setIdEmpleado(Sesion::getEmpleado().getId());
    do{
        detalle.cargar(registro.getId());
        if(add = cargarBool("¿Debe ingresar otro producto?"));
    }while(add != 0);
    archivo.guardaryreportar(registro);
}


void MVenta::listar(){
    clearW();
    Venta registro;
    int paginador = archivo.cantidadRegistros();
    if(paginador == 0){
            std::cout << "No hay registros para mostrar";
    return;
    }

    int c = 0;
    UIVenta::showHeader();
    for(int i = 0; i < paginador; i++){
        registro = archivo.leer(i);
        if(registro.getEstado() == true){
            UIVenta::showRow(registro);
            c++;
        }

        if(c == 10){
            c = 0;
            pause();
            clearW();
            UIVenta::showHeader();
        }
    }
    pause();
}
void MVenta::eliminar(){
    clearW();
    Venta registro;
    int _id = cargarInt("Ingrese el ID: ");
    registro = archivo.buscarPorId(_id);
    clearW();
    if(registro.getId() != -1 && registro.getEstado() == true){

        UIVenta::showRegister(registro);

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


void MVenta::buscarPorId(){
    UIBase::clearW();
    Venta registro;
    registro = archivo.buscarPorId(cargarInt("Ingrese el ID: "));
    clearW();
    if(registro.getId() != -1){
        UIVenta::showRegister(registro);

    }else{
        std::cout << "No hay resultados a tu busqueda." << std::endl;
    }
    pause();
        }
        void MVenta::editar(){}
        void MVenta::ordenar(int){}

    void MVenta::run(){

    std::string opciones[6] = {
     "1. Nuevo venta",
     "2. Listar ventas",
     "3. Buscar por Id",
     "4. Modificar venta",
     "5. Eliminar venta",
     "0.   << Atras"};
     Menu menu("Ventas", opciones, 6);

     int seleccion = 0;
     do{
        clearW();
        menu.dibujar();
        seleccion = menu.seleccionar();
        switch(seleccion){
            case 0:return; break;
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
    }while(seleccion != 0);
    clearW();
}
