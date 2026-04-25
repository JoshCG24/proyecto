//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_SIMULADOR_H
#define PROYECTO_SIMULADOR_H
#include <vector>
#include <memory>
#include <string>
#include "Equipo.h"
#include "CalculadorRiesgo.h"
#include "CalcularPrioridad.h"
#include "OrdenadorEquipos.h"
#include "SelectorTecnicos.h"
#include "BuscarEquipos.h"

#include "GestorIncidencias.h"

#include "ArchivoManager.h"

using namespace std;


class Simulador {
private:
    std::vector<Equipo*> equipos;

    int diasSimulacion = 30;
    int diaActual = 1;

    // Componentes del sistema
    CalcularPrioridad* calculadorPrioridad;
    OrdenadorEquipos* ordenador;
    BuscarEquipos* buscador;
    GestorIncidencias* gestorIncidencias;
    SelectorTecnicos* selectorTecnicos;
    CalculadorRiesgo* calculadorRiesgo;
    ArchivoManager* archivoManager;

public:
    // Constructor
    Simulador(std::vector<Equipo*>& equiposIniciales,
              CalcularPrioridad* cp,
              OrdenadorEquipos* ord,
              BuscarEquipos* bus,
              GestorIncidencias* gi,
              SelectorTecnicos* st,
              CalculadorRiesgo* cr,
              ArchivoManager* am);

    ~Simulador();

    // Control principal
    void simular();
    void ejecutarDia(int dia);

private:
    // Flujo interno del día
    void degradarEquipos();
    void actualizarIncidencias();
    void calcularPrioridades();
    void ordenarEquipos();
    vector<Equipo*> seleccionarEquipos();
    void ejecutarMantenimientos(const std::vector<Equipo*>& seleccionados);
    void actualizarSistema();
    void generarReporte(int dia, const std::vector<Equipo*>& seleccionados);
};

#endif //PROYECTO_SIMULADOR_H