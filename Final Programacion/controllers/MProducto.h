#include"Manager.h"
#include"../repositories/FProducto.h"
#include"../entities/producto.h"
#include"../ui/UIProducto.h"

class MProducto : public Manager{
    private:
        FProducto archivo;
    public:
        MProducto();
        ~MProducto();
        void listar() override;
        void cargar() override;
        void eliminar() override;
        void buscarPorId() override;
        void editar() override;
        void ordenar(int) override;


        void ordenarFecha(Producto*,int);
        void listar(Producto*,int);
        void ordenarPrecio(Producto*,int);
        void ordenarNombre(Producto*,int);

};

