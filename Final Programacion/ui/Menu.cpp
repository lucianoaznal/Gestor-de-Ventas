#include"Menu.h"



Menu::Menu(){

}
Menu::~Menu(){

}

void Menu::run(){
    int seleccion = 0;
    do{
        dibujar();
        seleccion = seleccionar();
        ejecutar(seleccion);

    }while(seleccion != 0);
    UIBase::message("Saliendo del sistema...", 0);
}
/*
int Menu::seleccionar(){
    int i;
    std::cin >> i;
    return i;
}
*/
void Menu::ejecutar(int seleccion){
    switch(seleccion){
    case 0:return;
    break;
    }

}
void Menu::dibujar(){

}
int Menu::seleccionar(){
    int seleccion;
    switch(rlutil::getkey()){
        case rlutil::KEY_UP:
            return -1;
            break;
        case rlutil::KEY_DOWN:
            return 1;
            break;
        case rlutil::KEY_ENTER:
            return -2;
            break;
        case rlutil::KEY_ESCAPE:
            return 0;
            break;
    }



    return seleccion;
}
