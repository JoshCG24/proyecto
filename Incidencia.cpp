//
// Created by joshu on 4/24/2026.
//

#include "Incidencia.h"

void Incidencia::resolver() {
     activa=false;
}

bool Incidencia::estaActiva() {
     activa=true;
}

int Incidencia::getSeveridad() {
     return severidad;
}

int Incidencia::getDiaAparicion() {
     return diaAparicion;
}
