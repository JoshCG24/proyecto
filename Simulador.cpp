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
    
    // 1. Los equipos se gastan y pueden fallar
    degradarEquipos();
    gestorIncidencias->actualizarIncidencias(equipos, dia);

    // 2. Calculamos qué tan urgente es cada uno y ordenamos
    for(auto e : equipos) { e->calcularPrioridad(); } 
    ordenador->ordenarPorPrioridad(equipos);

    // 3. Elegimos a los 3 "ganadores" del mantenimiento hoy
    vector<Equipo*> seleccionados = selectorTecnicos->EquipoTecnicos(equipos);

    // 4. Se reparan los equipos elegidos
    ejecutarMantenimientos(seleccionados);

    // 5. Los que NO se repararon, aumentan su tiempo inactivo
    actualizarSistema();

    // 6. Guardamos lo que pasó en el archivo
    generarReporte(dia, seleccionados);
}

void Simulador::degradarEquipos() {
    for (auto e : equipos) { e->degradar(); }
}

void Simulador::ejecutarMantenimientos(const vector<Equipo*>& seleccionados) {
    for (auto e : seleccionados) {
        // Si tiene fallas, aplicamos correctivo (esto le sube el estado)
        MantenimientoCorrectivo mc;
        e->aplicarMantenimiento(&mc);
        e->setTiempoInactivo(0); // Reset al ser atendido
    }
}

void Simulador::actualizarSistema() {
    // Aquí podrías marcar quiénes no fueron atendidos para subirles el tiempo inactivo
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