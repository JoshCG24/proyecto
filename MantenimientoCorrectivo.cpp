//
// Created by joshu on 4/24/2026.
//

#include "MantenimientoCorrectivo.h"
void MantenimientoCorrectivo::aplicar(Equipo& e) {
    e.setEstado(100.0);
    e.resolverIncidencia();
    e.setTiempoInactivo(0);
}