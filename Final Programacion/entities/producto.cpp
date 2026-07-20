#include"producto.h"

Producto::Producto()
:estado(true)
{

}

void Producto::mostrar(){
    std::cout << nombre << " " << modelo << " " << anio << " by " << marca << std::endl;

}
bool Producto::isValido()const {
    return true;
    ///TODO: logica incompleta
}


void Producto::setId(int _id){
    id_producto = _id;
}
 int Producto::getId(){
    return id_producto;
}
// Getters

    char* Producto::getNombre() { return nombre; }
    char* Producto::getMarca() { return marca; }
    char* Producto::getModelo() { return modelo; }
    int Producto::getAnio() { return anio; }
    float Producto::getPrecio() { return precio; }
    int Producto::getColor(){ return color; }
    bool Producto::getZurda(){ return zurda; }
    char* Producto::getTipo() { return tipo; }
    char* Producto::getMadera() { return madera; }
    int Producto::getStock(){ return stock; }
    bool Producto::getEstado(){return estado; }

    // Setters

    void Producto::setNombre(const char* n) { strcpy(nombre, n); }
    void Producto::setMarca(const char* m) { strcpy(marca, m); }
    void Producto::setModelo(const char* m) { strcpy(modelo, m); }
    void Producto::setAnio(int a) { anio = a; }
    void Producto::setPrecio(float p) { precio = p; }
    void Producto::setColor(int c) { color = c; }
    void Producto::setZurda(bool z) { zurda = z; }
    void Producto::setTipo(const char* t) { strcpy(tipo, t); }
    void Producto::setMadera(const char* m) { strcpy(madera, m); }
    void Producto::setStock(int s) { stock = s; }
    void Producto::setEstado(bool _estado){ estado = _estado;}

    ///sobrecarga compara fecha(>) || compara anio(<)
    bool Producto::operator>(const Producto& otro) const {
         return this->anio > otro.anio;
    }
    bool Producto::operator<(const Producto& otro) const {
        return this->precio > otro.precio;
    }
