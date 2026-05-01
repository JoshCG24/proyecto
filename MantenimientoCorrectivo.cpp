//
// Created by joshu on 4/24/2026.
//

#include "MantenimientoCorrectivo.h"
MantenimientoCorrectivo::MantenimientoCorrectivo(int reduccion, double mejora) {
    reduccionIncidencias = reduccion;
    mejoraEstado = mejora;
}

void MantenimientoCorrectivo::aplicar(Equipo& e) {

    double nuevoEstado = e.getEstado() + mejoraEstado;
    if (nuevoEstado > 100.0) nuevoEstado = 100.0;
    e.setEstado(nuevoEstado);


    reducirIncidencias(e);
}

void MantenimientoCorrectivo::reducirIncidencias(Equipo& e) {

    for (int i = 0; i < reduccionIncidencias; i++) {
        e.resolverIncidencia();
    }
}