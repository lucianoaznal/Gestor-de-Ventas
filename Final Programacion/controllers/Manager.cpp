#include"Manager.h"


Manager::Manager(){

}
Manager::~Manager(){
}

int Manager::cargarInt(std::string _msg){
    int numero;
    std::cout << _msg;
    while(!(std::cin >> numero)){
        std::cout << "[ERROR! El valor ingresado es incorrecto.]";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return numero;
}

void Manager::cargarChar(std::string _msg, char * cadena, int _size){
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

float Manager::cargarFloat(std::string _msg){
    float numero;
    std::cout << _msg;
    while(!(std::cin >> numero)){
        std::cout << "[ERROR! El valor ingresado es incorrecto.]";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return numero;
}
bool Manager::cargarBool(std::string _msg){
    char op;
    bool valido = false;
    bool resultado = false;

    do {
        std::cout << _msg << " (s/n): ";
        std::cin >> op;
        if (std::cin.peek() == '\n') std::cin.ignore();

        if (op == 's' || op == 'S') {
            resultado = true;
            valido = true;
        } else if (op == 'n' || op == 'N') {
            resultado = false;
            valido = true;
        } else {
            std::cout << "Opcion invalida." << std::endl;
        }
    } while (!valido);

    return resultado;

}


