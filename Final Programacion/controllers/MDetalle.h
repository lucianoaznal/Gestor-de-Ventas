#pragma once
#include"Manager.h"
#include"../entities/DetalleVenta.h"
#include"../repositories/FDetalle.h"
#include"../repositories/FProducto.h"
#include"../ui/Menu.h"
#include"../ui/UIDetalle.h"

class MDetalle : public Manager{
    private:
        FDetalle archivo;
        FProducto producto;
    public:
        MDetalle();
        void listar() override;
        void listar(int);
        void cargar() override;
        void eliminar() override;
        void buscarPorId() override;
        void editar() override;
        void ordenar(int) override;
        void run();
        void cargar(int idVenta);

};
