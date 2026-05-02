#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Equipo.h"
#include "CalcularPrioridad.h"
#include "OrdenadorEquipos.h"
#include "SelectorTecnicos.h"
#include "BuscarEquipos.h"
#include "GestorIncidencias.h"
#include "CalculadorRiesgo.h"
#include "ArchivoManager.h"
#include "Simulador.h"
using namespace std;

int main() {

    srand(time(nullptr));

    cout << "===== SISTEMA DE PLANIFICACION DE MANTENIMIENTO =====" << endl;
    cout << "Cargando datos iniciales desde archivos..." << endl;


    ArchivoManager archivoManager;
    CalcularPrioridad calcularPrioridad;
    OrdenadorEquipos ordenador;
    SelectorTecnicos selector;
    BuscarEquipos buscador;
    GestorIncidencias gestor;
    CalculadorRiesgo calculador;


    vector<Equipo*> equipos = archivoManager.cargarEquipos("equipos.txt");

    if (equipos.empty()) {
        cout << "Advertencia: No se cargaron equipos desde archivo. "
             << "Generando 100 equipos por defecto..." << endl;
        for (int i = 0; i < 100; i++) {
            int num = i + 1;
            string id;
            if (num < 10)       id = "EQ-00" + to_string(num);
            else if (num < 100) id = "EQ-0"  + to_string(num);
            else                id = "EQ-"   + to_string(num);

            int criticidad = (rand() % 10) + 1;
            double estado  = (rand() % 41) + 60;
            equipos.push_back(new Equipo(id, criticidad, estado));
        }
    }


    ordenador.ordenarPorId(equipos);


    int incidenciasCargadas = archivoManager.cargarIncidencias(
        "incidencias.txt", equipos, &buscador, &ordenador);

    cout << "Equipos cargados: "     << equipos.size()     << endl;
    cout << "Incidencias cargadas: " << incidenciasCargadas << endl;
    cout << "Iniciando simulacion de 30 dias..." << endl;
    cout << "========================================" << endl;


    Simulador simulador(equipos, &calcularPrioridad, &ordenador, &buscador,
                        &gestor, &selector, &calculador, &archivoManager);

    simulador.simular();

    cout << "========================================" << endl;
    cout << "Simulacion completada." << endl;
    cout << "Reporte diario guardado en: simulacion_diaria.txt" << endl;
    cout << "Reporte final guardado en: resultado_final.txt"   << endl;

    // Liberar memoria
    for (Equipo* e : equipos) {
        delete e;
    }
    equipos.clear();

    ArchivoManager gestorArchivos;
    gestorArchivos.imprimirArchivo("resultado_final.txt");
    // No imprime simulacion_diaria.txt completo (30 días) para no saturar la consola.

    return 0;
}