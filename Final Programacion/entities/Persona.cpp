#include"Persona.h"

    Persona::Persona()
    :estado(true)
    {


    }

    void Persona::setDni(int _dni){dni = _dni;}
    void Persona::setNombre(char* _nombre){strcpy(nombre,_nombre);}
    void Persona::setApellido(char* _apellido){strcpy(apellido,apellido);}
    void Persona::setEmail(char* _email){strcpy(email,_email);}
    void Persona::setDomicilio(Domicilio& _domicilio){domicilio = _domicilio;}
    void Persona::setFecha(Fecha& _f_nacimiento){f_nacimiento = _f_nacimiento;}
    void Persona::setTelefono(int _telefono){telefono = _telefono;}
    void Persona::setEstado(bool _estado){estado = _estado;}

    int Persona::getDni(){return dni;}
    char* Persona::getNombre(){return nombre;}
    char* Persona::getApellido(){return apellido;}
    char* Persona::getEmail(){return email;}
    Domicilio Persona::getDomicilio(){return domicilio;}
    Fecha Persona::getFecha(){return f_nacimiento;}
    int Persona::getTelefono(){return telefono;}
    bool Persona::getEstado(){return estado;}
    const char* Persona::getLocalidad(){return domicilio.getLocalidad();}
    int Persona::getEdad(Fecha fecha){
        return f_nacimiento.getEdad(fecha);
}
