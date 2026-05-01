#include <iostream>
#include <vector>

#include "Equipo.h"
#include "Incidencia.h"
#include "Simulador.h"

#include "CalcularPrioridad.h"
#include "OrdenadorEquipos.h"
#include "BuscarEquipos.h"
#include "GestorIncidencias.h"
#include "SelectorTecnicos.h"
#include "CalculadorRiesgo.h"
#include "ArchivoManager.h"

using namespace std;

int main() {

    // try {
    //
    //     // ============================
    //     // 1. Crear dependencias
    //     // ============================
    //
    //     CalcularPrioridad* cp = new CalcularPrioridad();
    //     OrdenadorEquipos* ord = new OrdenadorEquipos();
    //     BuscarEquipos* bus = new BuscarEquipos();
    //     GestorIncidencias* gi = new GestorIncidencias();
    //     SelectorTecnicos* st = new SelectorTecnicos(3); // máximo 3 técnicos
    //     CalculadorRiesgo* cr = new CalculadorRiesgo();
    //     ArchivoManager* am = new ArchivoManager();
    //
    //     // ============================
    //     // 2. Crear equipos (RF1)
    //     // ============================
    //
    //     vector<Equipo*> equipos;
    //
    //     equipos.push_back(new Equipo("EQ-001", "PC-LAB-1", 9, 70));
    //     equipos.push_back(new Equipo("EQ-002", "PC-LAB-2", 6, 82));
    //     equipos.push_back(new Equipo("EQ-003", "PC-LAB-3", 8, 60));
    //     equipos.push_back(new Equipo("EQ-004", "PC-LAB-4", 5, 90));
    //     equipos.push_back(new Equipo("EQ-005", "PC-LAB-5", 7, 75));
    //
    //     // ============================
    //     // 3. Crear incidencias iniciales
    //     // ============================
    //
    //     Incidencia* i1 = new Incidencia("INC-001", "Falla disco", 3, 1);
    //     Incidencia* i2 = new Incidencia("INC-002", "Sobrecalentamiento", 2, 1);
    //
    //     equipos[0]->agregarIncidencia(i1);
    //     equipos[1]->agregarIncidencia(i2);
    //
    //     // ============================
    //     // 4. Crear simulador
    //     // ============================
    //
    //     Simulador sim(
    //         equipos,
    //         cp,
    //         ord,
    //         bus,
    //         gi,
    //         st,
    //         cr,
    //         am
    //     );
    //
    //     // ============================
    //     // 5. Ejecutar simulación (RF2)
    //     // ============================
    //
    //     sim.simular();
    //
    //     cout << "\nSimulacion completada correctamente.\n";
    //
    //     // ============================
    //     // 6. Liberar memoria
    //     // ============================
    //
    //     for (auto e : equipos) {
    //         delete e;
    //     }
    //
    //     delete cp;
    //     delete ord;
    //     delete bus;
    //     delete gi;
    //     delete st;
    //     delete cr;
    //     delete am;
    //
    // } catch (exception& e) {
    //     cerr << "Error: " << e.what() << endl;
    // }

    return 0;
}