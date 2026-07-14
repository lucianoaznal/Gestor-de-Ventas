#include"../repositories/FEmpleado.h"

FEmpleado::FEmpleado()
:nombre("data/empleados.dat")
{

}

bool FEmpleado::guardar(const Empleado& registro){
        FILE * file = fopen(nombre.c_str(),"ab");
        if(file == nullptr){
            return false;
        }
        fwrite(&registro,sizeof(registro), 1, file);
        fclose(file);
        return true;
    }

Empleado FEmpleado::leer(int pos){
        Empleado registro;
        registro.setId(-1);
        FILE * file = fopen(nombre.c_str(), "rb");
        if(file == nullptr){
            return registro;
        }
        fseek(file, sizeof registro * pos, SEEK_SET);
        fread(&registro, sizeof registro, 1, file);
        fclose(file);
        return registro;
    }

int FEmpleado::cantidadRegistros(){
        Empleado registro;
        FILE * file = fopen(nombre.c_str(), "rb");
        if(file == nullptr){
            return 0;
        }
        fseek(file, 0, SEEK_END);
        int tam = ftell(file) / sizeof registro;
        fclose(file);
        return tam;
    }

Empleado FEmpleado::buscarPorId(int _id){
    Empleado registro;
    int cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        registro = leer(i);
        if(registro.getId() == _id){
            return registro;
        }
    }
    registro.setId(-1);
    return registro;
}


bool FEmpleado::modificar(const Empleado registro,int pos){
    FILE * file = fopen(nombre.c_str(), "rb+");
    if(file == nullptr){
        return false;
    }
    fseek(file, sizeof registro * pos, SEEK_SET);
    fwrite(&registro, sizeof registro, 1, file);
    fclose(file);
    return true;
}
void FEmpleado::guardaryreportar(const Empleado& registro){
    if(!registro.isValido()){
        std::cout << "Los datos ingresados son invalidos!" << std::endl;
        return;
    }
    if(guardar(registro)){
        std::cout << "Registro exitoso!" << std::endl;
    }else{
        std::cout << "Error critico al leer el disco!" << std::endl;
    }

}

int FEmpleado::buscarPosicionPorId(int _id){
    Empleado registro;
    int cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        registro = leer(i);
        if(_id == registro.getId()){
            return i;
        }
    }
    return -1;
}
int FEmpleado::cantidadDeActivos(){
    Empleado registro;
    int cantidad = cantidadRegistros(), contador = 0;
    if(cantidad == 0){
        return cantidad;
    }
    for(int i = 0; i < cantidad; i++){
        registro = leer(i);
        if(registro.getEstado() == true){
            contador++;
        }
    }
    return contador;
}

void FEmpleado::leer(Empleado* registro){
    Empleado aux;
    int index = 0, cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        aux = leer(i);
        if(aux.getEstado() == true){
            registro[index] = aux;
            index++;
        }
    }
}

