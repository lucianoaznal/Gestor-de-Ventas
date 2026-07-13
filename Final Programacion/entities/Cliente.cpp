#include"Cliente.h"

Cliente::Cliente()
{

}

void Cliente::setId(int _id){ID = _id;}
int Cliente::getId(){return ID;}
bool Cliente::isValido()const {
    return true;
    ///TODO: logica incompleta
}
