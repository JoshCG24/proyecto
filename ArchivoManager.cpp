//
// Created by joshu on 4/24/2026.
//
#include <sstream>
#include "ArchivoManager.h"
vector<Equipo*> ArchivoManager::cargarEquipos(const string& ruta) {
    vector<Equipo*> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        throw ArchivoInvalidoException();  // antes era cout
    }

    string id;
    int criticidad;
    double estado;

    while (archivo >> id >> criticidad >> estado) {
        if (criticidad < 1 || criticidad > 10 || estado < 0 || estado > 100) {
            throw FormatoInvalidoException();  // validación de formato
        }
        lista.push_back(new Equipo(id, criticidad, estado));
    }

    if (lista.empty()) {
        throw FormatoInvalidoException();
    }

    archivo.close();
    return lista;
}

int ArchivoManager::cargarIncidencias(const string& ruta, vector<Equipo*>& equipos,BuscarEquipos* buscador, OrdenadorEquipos* ordenador) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ArchivoInvalidoException(ruta);
    }

    // Asegurar que equipos estén ordenados por ID para búsqueda binaria
    ordenador->ordenarPorId(equipos);

    string linea;
    int numLinea = 0;
    int cargadas = 0;

    while (getline(archivo, linea)) {
        numLinea++;
        if (linea.empty() || linea[0] == '#') continue;

        istringstream ss(linea);
        string incId, equipoId;
        int severidad, dia;

        if (!(ss >> incId >> equipoId >> severidad >> dia)) {
            throw FormatoInvalidoException("linea " + to_string(numLinea));
        }
        if (severidad < 1 || severidad > 3) {
            throw FormatoInvalidoException("severidad invalida en linea " + to_string(numLinea));
        }

        // Usar búsqueda binaria para encontrar el equipo
        Equipo* equipo = buscador->buscarBinario(equipos, equipoId);
        if (equipo == nullptr) {
            throw OperacionInconsistenteException("equipo " + equipoId + " no encontrado (linea " + to_string(numLinea) + ")");
        }

        string desc = (severidad == 1) ? "Desgaste menor" :
                           (severidad == 2) ? "Falla parcial" : "Falla critica";
        equipo->agregarIncidencia(new Incidencia(incId, desc, dia, severidad));
        cargadas++;
    }

    archivo.close();
    return cargadas;
}
void ArchivoManager::guardarReporteDiario(ReporteDiario* reporte) {
    if (reporte == nullptr) {
        throw OperacionInconsistenteException();
    }

    ofstream archivo("simulacion_diaria.txt", ios::app);
    if (!archivo.is_open()) {
        throw ArchivoInvalidoException();
    }

    archivo << reporte->generarTexto() << endl;
    archivo.close();
}

void ArchivoManager::guardarReporteFinal(const string& ruta, const string& resumen) {
    ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ArchivoInvalidoException(ruta);
    }
    archivo << resumen;
    archivo.close();
}
void ArchivoManager::imprimirArchivo(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ArchivoInvalidoException();
    }
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}