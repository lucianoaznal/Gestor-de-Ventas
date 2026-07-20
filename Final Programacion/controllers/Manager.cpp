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

void Manager::cambiar(std::string _msg,  char * cadena, int _size){
    char aux[_size];

    std::cout << _msg << cadena << ". Nuevo(o '-' para mantener): ";
    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }
    std::cin.getline(aux, _size);
    if(aux[0] != '-'){
        strcpy(cadena,aux);
    }

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}
int Manager::cambiar(std::string _msg, int actual){
    char aux[5];
    std::cout << _msg << actual << ". Nuevo(o '-' para mantener): ";

    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }

    std::cin.getline(aux,5);
    if(aux[0] != '-'){
        return std::stoi(aux);
    }

    return actual;
}

bool Manager::cambiar(std::string _msg, bool actual){
    char aux[5];
    std::cout << _msg << actual << ". Nuevo (o '-' para mantener): ";

    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }

    std::cin.getline(aux, 5);

    if (aux[0] != '-') {
        try {
            int valor = std::stoi(aux);
            return (valor != 0); // Devuelve true si es distinto de 0, false si es 0
        } catch (...) {
            return actual; // Si ingresan letras por error, mantiene el valor viejo
        }
    }

    return actual; // Si mandó '-', devuelve el valor actual

}
float Manager::cambiar(std::string _msg, float actual){
    char aux[10]; // Un poquito más grande por si el float tiene varios dígitos
    std::cout << _msg << actual << ". Nuevo (o '-' para mantener): ";

    if (std::cin.peek() == '\n') {
        std::cin.ignore();
    }

    std::cin.getline(aux, 10);

    if (aux[0] != '-') {
        try {
            return std::stof(aux); // Convierte correctamente a float con std::stof
        } catch (...) {
            return actual; // Si ingresan letras por error, mantiene el valor viejo
        }
    }

    return actual; // Si mandó '-', devuelve el valor actual
}
