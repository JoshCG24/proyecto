#ifndef PROYECTO_SIMULADOR_H
#define PROYECTO_SIMULADOR_H
#include <vector>
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
    vector<Equipo*> equipos;
    int diasSimulacion = 30;

    CalcularPrioridad* calculadorPrioridad;
    OrdenadorEquipos* ordenador;
    BuscarEquipos* buscador;
    GestorIncidencias* gestorIncidencias;
    SelectorTecnicos* selectorTecnicos;
    CalculadorRiesgo* calculadorRiesgo;
    ArchivoManager* archivoManager;

public:
    Simulador(vector<Equipo*>& equiposIniciales,
              CalcularPrioridad* cp,
              OrdenadorEquipos* ord,
              BuscarEquipos* bus,
              GestorIncidencias* gi,
              SelectorTecnicos* st,
              CalculadorRiesgo* cr,
              ArchivoManager* am);

    ~Simulador();
    void simular();

private:
    void ejecutarDia(int dia);
    void degradarEquipos();
    void ejecutarMantenimientos(const vector<Equipo*>& seleccionados);
    void actualizarSistema();
    void generarReporte(int dia, const vector<Equipo*>& seleccionados);
};

#endif