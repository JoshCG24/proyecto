//
// Created by joshu on 4/24/2026.
//
#include "ArchivoManager.h"
#include "Incidencia.h"
#include <sstream>
#include "BuscarEquipos.h"
#include "OrdenadorEquipos.h"


vector<Equipo*> ArchivoManager::cargarEquipos(const string& ruta) {
    vector<Equipo*> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de equipos: " << ruta << endl;
        return lista;
    }

    string id;
    int criticidad;
    double estado;
    int linea = 0;

    while (archivo >> id >> criticidad >> estado) {
        linea++;
        if (criticidad < 1 || criticidad > 10 || estado < 0 || estado > 100) {
            cout << "Error: Formato invalido en equipo " << id
                 << " (linea " << linea << "). Se omite." << endl;
            continue;
        }
        lista.push_back(new Equipo(id, criticidad, estado));
    }

    archivo.close();
    cout << "Equipos cargados desde " << ruta << ": " << lista.size() << endl;
    return lista;
}

int ArchivoManager::cargarIncidencias(const string& ruta, vector<Equipo*>& equipos,
                                      BuscarEquipos* buscador, OrdenadorEquipos* ordenador) {
    if (buscador == nullptr || ordenador == nullptr) {
        cout << "Error: buscador u ordenador nulos al cargar incidencias." << endl;
        return 0;
    }

    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de incidencias: " << ruta << endl;
        return 0;
    }

    // Asegura que la lista esté ordenada por ID para la búsqueda binaria.
    ordenador->ordenarPorId(equipos);

    int cargadas = 0;
    int descartadas = 0;
    int linea = 0;

    string lineaTexto;
    while (getline(archivo, lineaTexto)) {
        linea++;
        if (lineaTexto.empty()) continue;

        istringstream iss(lineaTexto);
        string incId, equipoId, descripcion;
        int severidad, dia;

        if (!(iss >> incId >> equipoId >> severidad >> dia)) {
            cout << "Error: Formato invalido en incidencia (linea " << linea
                 << "). Se omite." << endl;
            descartadas++;
            continue;
        }

        // Descripción puede contener varias palabras; toma el resto de la línea.
        getline(iss, descripcion);
        if (!descripcion.empty() && descripcion.front() == ' ') {
            descripcion.erase(0, 1);
        }
        if (descripcion.empty()) {
            descripcion = "Sin descripcion";
        }

        if (severidad < 1 || severidad > 3 || dia < 1 || dia > 30) {
            cout << "Error: Valores fuera de rango en " << incId
                 << " (linea " << linea << "). Se omite." << endl;
            descartadas++;
            continue;
        }

        // BÚSQUEDA BINARIA para asociar la incidencia al equipo.
        Equipo* equipo = buscador->buscarBinario(equipos, equipoId);
        if (equipo == nullptr) {
            cout << "Error: Equipo " << equipoId << " no existe para incidencia "
                 << incId << ". Se omite." << endl;
            descartadas++;
            continue;
        }

        Incidencia* nueva = new Incidencia(incId, descripcion, dia, severidad);
        equipo->agregarIncidencia(nueva);
        cargadas++;
    }

    archivo.close();
    cout << "Incidencias cargadas desde " << ruta << ": " << cargadas
         << " (descartadas: " << descartadas << ")" << endl;
    return cargadas;
}

void ArchivoManager::guardarReporteDiario(ReporteDiario* reporte) {
    if (reporte == nullptr) {
        cout << "Error: Reporte nulo." << endl;
        return;
    }

    ofstream archivo("simulacion_diaria.txt", ios::app);

    if (archivo.is_open()) {
        archivo << reporte->generarTexto() << endl;
        archivo.close();
    }
}

void ArchivoManager::guardarReporteFinal(string ruta, string resumen) {
    ofstream archivo(ruta);

    if (archivo.is_open()) {
        archivo << "===== RESUMEN FINAL DE SIMULACION =====" << endl;
        archivo << resumen << endl;
        archivo.close();
    }
}

void ArchivoManager::imprimirArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (archivo.is_open()) {
        std::cout << "\n--- Contenido de " << nombreArchivo << " ---" << std::endl;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        std::cout << "-------------------------------------------\n" << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
}