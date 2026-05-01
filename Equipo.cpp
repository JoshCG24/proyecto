//
// Created by joshu on 4/24/2026.
//

#include "Equipo.h"

Equipo::Equipo(string id, int criticidad, double estado) {
    this->id = id;

    this->criticidad = criticidad;
    this->estado = estado;

}
double Equipo::calcularPrioridad() {
    // Esta es la fórmula base: Criticidad + (100 - Estado) + (Incidencias * factor)[cite: 1]
    double prioridad = (double)criticidad + (100.0 - estado) + (Incidencias.size() * 5.0);


    prioridad += (tiempo_inactivo * 2.0);

    return prioridad;
}

void Equipo::degradar() {
    if (estado > 0) {
        estado -= 2;
    }

    if (estado < 0) {
        estado = 0;
    }

    tiempo_inactivo ++;
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



void Equipo::aplicarMantenimiento(Mantenimiento* m) {
    m->aplicar(*this);
}


void Equipo::setTiempoInactivo(int tiempo_inavtivo) {
    this->tiempo_inactivo = tiempo_inavtivo;
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

string Equipo::getId() {
    return id;
}

int Equipo::getTiempoInavtivo() {
    return tiempo_inactivo;
}

int Equipo::getIncidenciaActivas() {
    int contador = 0;

    for (int i = 0; i < Incidencias.size(); i++) {
        if (Incidencias[i]->estaActiva()) {
            contador++;
        }
    }

    return contador;
}

