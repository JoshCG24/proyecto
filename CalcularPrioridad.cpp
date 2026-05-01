//
// Created by joshu on 4/24/2026.
//

#include "CalcularPrioridad.h"

double CalcularPrioridad::calcularPrioridad(Equipo* e) {
    int incidenciasActivas = e->getIncidenciaActivas();

    double prioridad =
        (e->getCriticidad() * 0.5) +
        (incidenciasActivas * 0.3) +
        (e->getTiempoInactivo() * 0.2);

    return prioridad;
}
