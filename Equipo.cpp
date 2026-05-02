//
// Created by joshu on 4/24/2026.
//

#include "Equipo.h"
#include "Mantenimiento.h"

Equipo::Equipo(string id, int criticidad, double estado) {
    this->id = id;

    this->criticidad = criticidad;
    this->estado = estado;

}


void Equipo::degradar() {
    if (estado > 0) {
        estado -= 2.0;
        if (estado < 0) {
            estado = 0;
        }
        tiempo_inactivo++;
    }
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


void Equipo::setTiempoInactivo(int tiempo_inactivo) {
    this->tiempo_inactivo = tiempo_inactivo;
}

void Equipo::setEstado(double estado) {
    this->estado = estado;
}

int Equipo::getCriticidad()const  {
    return criticidad;
}

double Equipo::getEstado() const {
    return estado;
}

string Equipo::getId() const {
    return id;
}

int Equipo::getTiempoInactivo()const  {
    return tiempo_inactivo;
}
void Equipo::setPrioridad(double p) {
    prioridad = p;
}

double Equipo::getPrioridad() const {
    return prioridad;
}

int Equipo::getIncidenciaActivas() const {
    int contador = 0;

    for (int i = 0; i < Incidencias.size(); i++) {
        if (Incidencias[i]->estaActiva()) {
            contador++;
        }
    }

    return contador;
}
bool Equipo::tieneIncidenciaPendiente() const {

    return getIncidenciaActivas() > 0;
}

Equipo::~Equipo() {
    for (Incidencia* inc : Incidencias) {
        delete inc;
    }
    Incidencias.clear();
}


