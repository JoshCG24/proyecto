//
// Created by joshu on 4/24/2026.
//

#include "Incidencia.h"

Incidencia::Incidencia(string id, string descripcion, int dia, int severidad) {
     this->id = id;
     this->descripcion = descripcion;
     this->diaAparicion = dia;
     this->severidad = severidad;
}

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
