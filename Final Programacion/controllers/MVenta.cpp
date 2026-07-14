#include"MVenta.h"

MVenta::MVenta()
{
}

void MVenta::cargar(){
    clearW();
    Venta registro;
    Cliente cliente;
    Empleado empleado;
    registro.setId(archivo.cantidadRegistros()+1);
    int id_cliente = cargarInt("Ingrese el DNI del cliente: ");
    cliente = mcliente.buscar(id_cliente);
    if(cliente.getId() == -1){
        std::cout << "El Dni Ingresado no esta registrado." << std::endl;
        mcliente.cargar();
        FCliente fcliente;
        cliente = fcliente.leer(fcliente.cantidadRegistros()-1);
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
    archivo.guardaryreportar(registro);
}


void MVenta::listar(){}
        void MVenta::eliminar(){}
        void MVenta::buscarPorId(){}
        void MVenta::editar(){}
        void MVenta::ordenar(int){}
