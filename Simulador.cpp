#include "Simulador.h"
#include "MantenimientoCorrectivo.h" // Necesario para aplicar reparaciones
#include "ReporteDiario.h"
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
    for (int i = 1; i <= diasSimulacion; i++) {
        ejecutarDia(i);
    }
    archivoManager->guardarReporteFinal("resultado_final.txt", "Simulacion de 30 dias completada.");
}

void Simulador::ejecutarDia(int dia) {
    cout << "--- Iniciando Dia " << dia << " ---" << endl;
    

    degradarEquipos();
    gestorIncidencias->actualizarIncidencias(equipos, dia);


    for(auto e : equipos) { e->calcularPrioridad(); } 
    ordenador->ordenarPorPrioridad(equipos);


    vector<Equipo*> seleccionados = selectorTecnicos->EquipoTecnicos(equipos);


    ejecutarMantenimientos(seleccionados);


    actualizarSistema();


    generarReporte(dia, seleccionados);
}

void Simulador::degradarEquipos() {
    for (auto e : equipos) { e->degradar(); }
}

void Simulador::ejecutarMantenimientos(const vector<Equipo*>& seleccionados) {

    MantenimientoCorrectivo mc(1, 30.0);

    for (auto e : seleccionados) {
        e->aplicarMantenimiento(&mc);
        e->setTiempoInactivo(0);
    }
}

void Simulador::actualizarSistema() {

}

void Simulador::generarReporte(int dia, const vector<Equipo*>& seleccionados) {
    double riesgo = calculadorRiesgo->calcularRiesgoGlobal(equipos);
    string estado = calculadorRiesgo->clasificarRiesgoGlobal(equipos);
    
    // Suponiendo que tu ReporteDiario tiene un constructor que recibe estos datos
    ReporteDiario* rd = new ReporteDiario(dia, seleccionados, (equipos.size() - seleccionados.size()), riesgo, estado);
    archivoManager->guardarReporteDiario(rd);
    delete rd;
}

Simulador::~Simulador() {
    // Aquí deberías limpiar la memoria de los punteros si el Simulador es dueño de ellos
}