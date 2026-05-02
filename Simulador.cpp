#include "Simulador.h"
#include "MantenimientoCorrectivo.h" // Necesario para aplicar reparaciones
#include "ReporteDiario.h"
#include "MantenimientoPreventivo.h"
#include <iostream>

Simulador::Simulador(vector<Equipo*>& equiposIniciales, CalcularPrioridad* cp, OrdenadorEquipos* ord, 
                     BuscarEquipos* bus, GestorIncidencias* gi, SelectorTecnicos* st, 
                     CalculadorRiesgo* cr, ArchivoManager* am) {
    equipos = equiposIniciales;
    calculadorPrioridad = cp;
    ordenador = ord;
    buscador = bus;
    gestorIncidencias = gi;
    selectorTecnicos = st;
    calculadorRiesgo = cr;
    archivoManager = am;
}

void Simulador::simular() {
    limpiarArchivosManualmente();
    for (int i = 1; i <= diasSimulacion; i++) {
        ejecutarDia(i);
    }
    archivoManager->guardarReporteFinal("resultado_final.txt", "Simulacion de 30 dias completada.");
}

void Simulador::ejecutarDia(int dia) {

    cout << "--- Iniciando Dia " << dia << " ---" << endl;


    degradarEquipos();
    gestorIncidencias->actualizarIncidencias(equipos, dia);


    for (Equipo* e : equipos) {
        double p = calculadorPrioridad->calcularPrioridad(e);
        e->setPrioridad(p);
    }
    ordenador->ordenarPorPrioridad(equipos); // ordena los equipos justo depsues de establecer la prioridad

    vector<Equipo*> seleccionados = selectorTecnicos->EquipoTecnicos(equipos);


    ejecutarMantenimientos(seleccionados);


    actualizarSistema();


    generarReporte(dia, seleccionados);
}

void Simulador::degradarEquipos() {
    for (Equipo* e : equipos) {
        e->degradar();
    }
}

void Simulador::ejecutarMantenimientos(const vector<Equipo*>& seleccionados) {
    for (Equipo* e : seleccionados) {
        Mantenimiento* m;

        if (e->getIncidenciaActivas() > 0) {
            m = new MantenimientoCorrectivo();
            // --- NUEVO: Cerramos las incidencias del equipo ---
            e->resolverIncidencia();
        } else {
            m = new MantenimientoPreventivo();
        }

        e->aplicarMantenimiento(m);
        e->setTiempoInactivo(0); // Reiniciamos su tiempo de espera

        delete m;
    }
}


void Simulador::actualizarSistema() {

}

void Simulador::generarReporte(int dia, const vector<Equipo*>& seleccionados) {
    double riesgo = calculadorRiesgo->calcularRiesgoGlobal(equipos);
    string estado = calculadorRiesgo->clasificarRiesgoGlobal(equipos);


    int backlogReal = 0;
    for (const Equipo* equipo : equipos) {

        if (equipo->tieneIncidenciaPendiente()) {
            backlogReal++;
        }
    }


    ReporteDiario* rd = new ReporteDiario(dia, seleccionados, backlogReal, riesgo, estado);
    archivoManager->guardarReporteDiario(rd);
    delete rd;
}

Simulador::~Simulador() {
}
void Simulador::limpiarArchivosManualmente() {

    std::ofstream archivo("simulacion_diaria.txt", std::ios::trunc);

    if (archivo.is_open()) {
        archivo.close();
    }
}