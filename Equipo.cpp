//
// Created by joshu on 4/24/2026.
//

#include "Equipo.h"

void Equipo::degradar() {
}

void Equipo::agregarIncidencia( Incidencia* incidencia) {
    Incidencias.push_back(incidencia);

}

void Equipo::resolverIncidencia() {
    for (int i = 0; i < Incidencias.size(); i++) {
        if (Incidencias[i]->estaActiva()) {
            Incidencias[i]->resolver();
        }
    }
}

double Equipo::calcularPrioridad() {
}

void Equipo::aplicarMantenimiento() {
}

string Equipo::getId() {
}

int Equipo::getCriticidad() {
}

double Equipo::getEstado() {
}

int Equipo::getTiempoInavtivo() {
}

int Equipo::incidenciaActivas() {
}
