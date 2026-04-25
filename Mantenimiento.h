//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_MANTENIMIENTO_H
#define PROYECTO_MANTENIMIENTO_H

#include "Equipo.h"
class Mantenimiento {
    public:
    virtual void aplicar(Equipo& e) =0;
    virtual ~Mantenimiento()=default;
};


#endif //PROYECTO_MANTENIMIENTO_H