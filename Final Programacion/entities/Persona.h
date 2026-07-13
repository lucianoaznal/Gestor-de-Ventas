#pragma once
#include"Domicilio.h"
#include"Fecha.h"

class Persona{
    public:
        Persona();
        void setDni(int);
        void setNombre(char*);
        void setApellido(char*);
        void setEmail(char*);
        void setDomicilio(Domicilio&);
        void setFecha(Fecha&);
        void setTelefono(int);
        void setEstado(bool);

        int getDni();
        char* getNombre();
        char* getApellido();
        char* getEmail();
        Domicilio getDomicilio();
        Fecha getFecha();
        int getTelefono();
        bool getEstado();

        int getEdad(Fecha);
        const char* getLocalidad();

    protected:
        int dni;
        char nombre[50];
        char apellido[50];
        char email[50];
        Domicilio domicilio;
        Fecha f_nacimiento;
        int telefono;
        bool estado;
};

