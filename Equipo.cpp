//
// Created by joshu on 4/24/2026.
//

#include "Equipo.h"

void Equipo::degradar() {
    estado -= 2;
    tiempo_inavtivo ++;

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
    double prioridad =
       (criticidad * 0.5) +
       (incidenciaActivas() * 0.3) +
       (tiempo_inavtivo * 0.2);

    return prioridad;
}

void Equipo::aplicarMantenimiento(Mantenimiento* mantenimiento) {
}

string Equipo::getId() {
}

void Equipo::setTiempoInavtivo(int tiempo_inavtivo) {
    this->tiempo_inavtivo = tiempo_inavtivo;
}

void Equipo::setEstado(double estado) {
    this->estado = estado;
}

int Equipo::getCriticidad() {
    return criticidad;
}

double Equipo::getEstado() {
    return estado;
}

int Equipo::getTiempoInavtivo() {
    return tiempo_inavtivo;
}

int Equipo::incidenciaActivas() {
    return incidenciaActivas();
}
