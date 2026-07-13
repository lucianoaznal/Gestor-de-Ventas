#include"Fecha.h"

Fecha::Fecha()
:dia(1),mes(1),anio(1900)
{

}

Fecha::Fecha(int _dia, int _mes,int _anio){
    if(esFechaValida(_dia,_mes,_anio)){
        anio = _anio;
        mes = _mes;
        dia = _dia;
    }else{
        dia = 1;
        mes = 1;
        anio = 1900;
    }

}
void Fecha::mostrar(){
    std::cout << dia << "/" << mes << "/" << anio;
}
    void Fecha::setDia(int _dia){ dia = _dia;}
    void Fecha::setMes(int _mes){ mes = _mes;}
    void Fecha::setAnio(int _anio){ anio = _anio;}
    int Fecha::getDia(){ return dia;}
    int Fecha::getMes(){ return mes;}
    int Fecha::getAnio(){ return anio;}


bool Fecha::esFechaValida(int dia, int mes, int anio) const {
    if (anio < 1900) return false;
    if (mes < 1 || mes > 12) return false;
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasPorMes[2] = 29;
    }
    return (dia >= 1 && dia <= diasPorMes[mes]);
}

void Fecha::cargar(){
    int _dia, _mes, _anio;
    do{
        std::cout << "Dia: "; std::cin >> _dia;
        std::cout << "Mes: "; std::cin >> _mes;
        std::cout << "Anio: "; std::cin >> _anio;

    }while(!esFechaValida(_dia,_mes,_anio));
}


void Fecha::setFechaActual() {
    time_t t = time(0);   // Obtiene el tiempo actual en segundos
    tm* now = localtime(&t); // Convierte a la estructura local

    dia = now->tm_mday;
    mes = now->tm_mon + 1; // tm_mon va de 0 a 11, por eso sumamos 1
    anio = now->tm_year + 1900; // tm_year cuenta los años desde 1900
}

Fecha Fecha::getFechaActual(){
    Fecha hoy;
    hoy.setFechaActual();
    return hoy;
}

int Fecha::getEdad(Fecha fecha){
    int edad;
    Fecha hoy;
    hoy.getFechaActual();
    edad = hoy.getAnio() - fecha.getAnio();
    if(fecha.getMes() > hoy.getMes()) return edad;
    if(fecha.getMes() <= hoy.getMes() && fecha.getDia() <= hoy.getDia()) return edad-1;
    return edad;

}
