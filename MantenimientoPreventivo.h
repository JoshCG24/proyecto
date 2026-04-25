//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_MANTENIMIENTOPREVENTIVO_H
#define PROYECTO_MANTENIMIENTOPREVENTIVO_H
#include "Equipo.h"
#include "Mantenimiento.h"
class MantenimientoPreventivo :public Mantenimiento{
private:
    double mejorEstado;
public:
    void aplicar(Equipo& e) override;

};


#endif //PROYECTO_MANTENIMIENTOPREVENTIVO_H