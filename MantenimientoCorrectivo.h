//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_MANTENIMIENTOCORRECTIVO_H
#define PROYECTO_MANTENIMIENTOCORRECTIVO_H
#include "Equipo.h"
#include "Mantenimiento.h"

class MantenimientoCorrectivo :public Mantenimiento{
private:
    int reduccionIncidencias;
    double mejoraEstado;
public:
    void aplicar(Equipo& e) override;
    void reducirIncidencias(Equipo& e);

};


#endif //PROYECTO_MANTENIMIENTOCORRECTIVO_H