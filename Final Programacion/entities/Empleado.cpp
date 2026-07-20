#include"Empleado.h"

Empleado::Empleado()
{

}

void Empleado::setId(int _id){ID = _id;}
int Empleado::getId(){return ID;}
bool Empleado::isValido()const {
    return true;
    ///TODO: logica incompleta
}


void Empleado::setCategoria(int _categoria){categoria = _categoria;}
void Empleado::setFechaIngreso(Fecha& _fecha){fechaIngreso = _fecha;}

int Empleado::getCategoria(){return categoria;}
Fecha Empleado::getFechaIngreso(){return fechaIngreso;}

void Empleado::mostrar(){
    std::cout << "ID #" << ID << ". " <<  nombre << ", " << apellido << std::endl;

}
