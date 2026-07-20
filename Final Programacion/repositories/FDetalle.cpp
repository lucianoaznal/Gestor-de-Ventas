#include"FDetalle.h"


FDetalle::FDetalle()
:nombre("data/detalle.dat")
{

}

bool FDetalle::guardar(const Detalle& registro){
        FILE * file = fopen(nombre.c_str(),"ab");
        if(file == nullptr){
            return false;
        }
        fwrite(&registro,sizeof(registro), 1, file);
        fclose(file);
        return true;
    }

Detalle FDetalle::leer(int pos){
        Detalle registro;
        registro.setIdDetalle(-1);
        FILE * file = fopen(nombre.c_str(), "rb");
        if(file == nullptr){
            return registro;
        }
        fseek(file, sizeof registro * pos, SEEK_SET);
        fread(&registro, sizeof registro, 1, file);
        fclose(file);
        return registro;
    }

int FDetalle::cantidadRegistros(){
        Detalle registro;
        FILE * file = fopen(nombre.c_str(), "rb");
        if(file == nullptr){
            return 0;
        }
        fseek(file, 0, SEEK_END);
        int tam = ftell(file) / sizeof registro;
        fclose(file);
        return tam;
    }

Detalle FDetalle::buscarPorId(int _id){
    Detalle registro;
    int cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        registro = leer(i);
        if(registro.getIdDetalle() == _id){
            return registro;
        }
    }
    registro.setIdDetalle(-1);
    return registro;
}


bool FDetalle::modificar(const Detalle registro,int pos){
    FILE * file = fopen(nombre.c_str(), "rb+");
    if(file == nullptr){
        return false;
    }
    fseek(file, sizeof registro * pos, SEEK_SET);
    fwrite(&registro, sizeof registro, 1, file);
    fclose(file);
    return true;
}
void FDetalle::guardaryreportar(Detalle& registro){
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

int FDetalle::buscarPosicionPorId(int _id){
    Detalle registro;
    int cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        registro = leer(i);
        if(_id == registro.getIdDetalle()){
            return i;
        }
    }
    return -1;
}
int FDetalle::cantidadDeActivos(){
    Detalle registro;
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

void FDetalle::leer(Detalle* registro){
    Detalle aux;
    int index = 0, cantidad = cantidadRegistros();
    for(int i = 0; i < cantidad; i++){
        aux = leer(i);
        if(aux.getEstado() == true){
            registro[index] = aux;
            index++;
        }
    }
}




