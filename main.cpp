#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Equipo.h"
#include "Incidencia.h"
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
    try {
        srand(time(nullptr));

        cout << "===== SISTEMA DE PLANIFICACION DE MANTENIMIENTO =====" << endl;
        cout << "Cargando datos iniciales..." << endl;

        // Crear módulos
        ArchivoManager archivoManager;
        CalcularPrioridad calcularPrioridad;
        OrdenadorEquipos ordenador;
        SelectorTecnicos selector;
        BuscarEquipos buscador;
        GestorIncidencias gestor;
        CalculadorRiesgo calculador;

        vector<Equipo*> equipos;

        // 1. Crear los 100 equipos
        for (int i = 0; i < 100; i++) {
            string id;
            int num = i + 1;

            if (num < 10) {
                id = "EQ-00" + to_string(num);
            } else if (num < 100) {
                id = "EQ-0" + to_string(num);
            } else {
                id = "EQ-" + to_string(num);
            }

            int criticidad = (rand() % 10) + 1;
            double estado = (rand() % 41) + 60;

            equipos.push_back(new Equipo(id, criticidad, estado));
        }

        // 2. Generar 300 incidencias de prueba (para cumplir E3)
        for (int i = 0; i < 300; i++) {
            int idx = rand() % 100;
            int sev = (rand() % 3) + 1;
            Incidencia* inc = new Incidencia(
                "INC-" + to_string(i + 1),
                "Incidencia inicial",
                0,
                sev
            );
            equipos[idx]->agregarIncidencia(inc);
        }

        // Ordenar por ID para búsqueda binaria
        ordenador.ordenarPorId(equipos);

        cout << "Equipos cargados: " << equipos.size() << endl;
        cout << "Iniciando simulacion de 30 dias..." << endl;
        cout << "========================================" << endl;

        // Crear y ejecutar simulador
        Simulador simulador(equipos, &calcularPrioridad, &ordenador, &buscador,
                            &gestor, &selector, &calculador, &archivoManager);

        simulador.simular();

        cout << "========================================" << endl;
        cout << "Simulacion completada." << endl;
        cout << "Reporte diario guardado en: simulacion_diaria.txt" << endl;
        cout << "Reporte final guardado en: resultado_final.txt" << endl;

        // Mostrar reportes en consola (usando el mismo archivoManager)
        archivoManager.imprimirArchivo("resultado_final.txt");
        archivoManager.imprimirArchivo("simulacion_diaria.txt");

        // Liberar memoria de los equipos
        for (Equipo* e : equipos) {
            delete e;
        }
        equipos.clear();
    }
    catch (const ArchivoInvalidoException& e) {
        cerr << "Error fatal: " << e.what() << endl;
        return 1;
    }
    catch (const FormatoInvalidoException& e) {
        cerr << "Error fatal: " << e.what() << endl;
        return 1;
    }
    catch (const OperacionInconsistenteException& e) {
        cerr << "Error fatal: " << e.what() << endl;
        return 1;
    }
    catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << endl;
        return 1;
    }

    return 0;
}