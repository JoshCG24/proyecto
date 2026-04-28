//
// Created by joshu on 4/24/2026.
//

#include "MantenimientoPreventivo.h"

void MantenimientoPreventivo::aplicar(Equipo &e) {

    double mejora = 25;

    double nuevoEstado = e.getEstado() + mejora;

    if (nuevoEstado > 100) {
        nuevoEstado = 100;
    }

    e.setEstado(nuevoEstado);
    e.setTiempoInactivo(0);

}
