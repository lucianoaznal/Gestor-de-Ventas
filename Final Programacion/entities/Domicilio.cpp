
#include "Domicilio.h"


using namespace std;

Domicilio::Domicilio(){
    strcpy(calle, "S/N");
    altura = 0;
    strcpy(localidad, "S/N");
    strcpy(provincia, "S/N");
    strcpy(codigoPostal, "S/N");
    strcpy(codigoPostal,"S/N");
}

void Domicilio::Cargar(){
    cargarChar("Calle: ", calle,50);
    altura = cargarInt("Altura: ");
    cargarChar("Localidad: ", localidad,50);
    cargarChar("Provincia: ", provincia, 50);
    cargarChar("Cod. Postal: ", codigoPostal,6);
}

void Domicilio::Mostrar(){
    cout << calle <<" "<< altura << ", " << localidad << ", " << provincia << ", " << codigoPostal<< "." << endl;
}

void Domicilio::setCalle(const char *c){
    strcpy(calle, c);
}

void Domicilio::setAltura(int a){
    altura = a;
}

void Domicilio::setLocalidad(const char *l){
    strcpy(localidad, l);
}

void Domicilio::setProvincia(const char *p){
    strcpy(provincia, p);
}

void Domicilio::setCodigoPostal(const char *cP){
    strcpy(codigoPostal, cP);
}

const char *Domicilio::getCalle(){
    return calle;
}

int Domicilio::getAltura(){
    return altura;
}

const char *Domicilio::getLocalidad(){
    return localidad;
}

const char *Domicilio::getProvincia(){
    return provincia;
}

const char *Domicilio::getCodigoPostal(){
    return codigoPostal;
}

void Domicilio::cargarChar(string _msg, char* cadena, int _size){
    std::cout << _msg;
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    std::cin.getline(cadena, _size);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

}

int Domicilio::cargarInt(string _msg){
    int numero;
    std::cout << _msg;
    while(!(std::cin >> numero)){
        std::cout << "[ERROR! El valor ingresado es incorrecto.]";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return numero;
}
