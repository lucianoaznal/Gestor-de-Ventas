#include"Menu.h"



Menu::Menu(){

}

Menu::Menu(std::string titulo, std::string* opciones, int cantidad){
    _titulo = titulo;
    _cantidad = cantidad;
    _opciones = new std::string[_cantidad];
    for(int i = 0; i < _cantidad; i ++){
        _opciones[i] = opciones[i];
    }
    _seleccion = 0;
}
Menu::~Menu(){
    //delete[] _opciones;
}

void Menu::run(){
    int seleccion = 0;
    do{
        dibujar();
        seleccion = seleccionar();
        ejecutar(seleccion);

    }while(seleccion != 0);

}

int Menu::seleccionar(){
    int i;
    std::cout << std::endl <<  "> ";
    std::cin >> i;
    return i;
}

void Menu::ejecutar(int seleccion){
    switch(seleccion){
    case 0:return;
    break;
    }

}


void Menu::dibujar(){
    clearW();
    std::cout << _titulo << std::endl
    << "=====================" << std::endl;
    for(int i = 0; i < _cantidad; i++){
        if(i == _cantidad -1){
            std::cout << std::endl
            << "=====================" << std::endl;
        }
        std::cout << _opciones[i] << std::endl;
    }

}


