#ifndef SESION_H
#define SESION_H
#include "Empleado.h"

class Sesion {
private:
    Sesion();
    static Empleado _empleadoLogueado;
    static bool _iniciada;

public:
    static void setEmpleado(Empleado e) { _empleadoLogueado = e; _iniciada = true; }
    static Empleado getEmpleado() { return _empleadoLogueado; }
    static bool estaIniciada() { return _iniciada; }
};




#endif
