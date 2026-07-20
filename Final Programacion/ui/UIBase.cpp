#include"UIBase.h"


UIBase::UIBase(){
}
UIBase::~UIBase(){

}
void UIBase::message(std::string _msg, int c){
    rlutil::locate(0,20);
    switch(c){
        case 0: rlutil::setColor(rlutil::GREEN);
        break;
    }
    std::cout << _msg;
    rlutil::setColor(rlutil::WHITE);

}
void UIBase::clearW(){
    system("cls");
}

bool UIBase::confirm(std::string _msg){
    char op;
    std::cout << _msg << " (s/n): ";
    std::cin >> op;
    return (op == 's' || op == 'S');
}

void UIBase::pause(){
    std::cin.ignore(1000, '\n');
    std::cout << "Presione una tecla para continuar...";
    std::cin.get();
}
/*
void UIBase::footer(){
    std::cout << "Empleado: " << Sesion::getEmpleado().getApellido()
              << ", " << Sesion::getEmpleado().getNombre() <<  std::endl
              << "ID# " << Sesion::getEmpleado().getId() << std::endl
              << "---------------------------------------" << std::endl << std::endl;

}*/
