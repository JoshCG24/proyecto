//
// Created by joshu on 4/24/2026.
//

#include "MantenimientoPreventivo.h"

void MantenimientoPreventivo::aplicar(Equipo &e) {

    double mejora = 0.15;

    double nuevoEstado = e.getEstado() + mejora;

    if (nuevoEstado > 1.0) {
        nuevoEstado = 1.0;
    }

    e.setEstado(nuevoEstado);
    e.getTiempoInactivo();


}
