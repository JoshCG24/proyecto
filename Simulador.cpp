//
// Created by joshu on 4/24/2026.
//

#include "Simulador.h"

Simulador::Simulador(std::vector<Equipo *> &equiposIniciales, CalcularPrioridad *cp, OrdenadorEquipos *ord,
    BuscarEquipos *bus, GestorIncidencias *gi, SelectorTecnicos *st, CalculadorRiesgo *cr, ArchivoManager *am) {
}

Simulador::~Simulador() {
}

void Simulador::simular() {
}

void Simulador::ejecutarDia(int dia) {
}

void Simulador::degradarEquipos() {
}

void Simulador::actualizarIncidencias() {
}

void Simulador::calcularPrioridades() {
}

void Simulador::ordenarEquipos() {
}

vector<Equipo *> Simulador::seleccionarEquipos() {
}

void Simulador::ejecutarMantenimientos(const std::vector<Equipo *> &seleccionados) {
}

void Simulador::actualizarSistema() {
}

void Simulador::generarReporte(int dia, const std::vector<Equipo *> &seleccionados) {
}
