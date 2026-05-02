//
// Created by joshu on 4/24/2026.
//
#include "ArchivoManager.h"

vector<Equipo*> ArchivoManager::cargarEquipos(string ruta) {
    vector<Equipo*> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de equipos." << endl;
        return lista;
    }

    string id;
    int criticidad;
    double estado;

    while (archivo >> id >> criticidad >> estado) {
        if (criticidad < 1 || criticidad > 10 || estado < 0 || estado > 100) {
            cout << "Error: Formato invalido en equipo " << id << endl;
            continue;
        }
        lista.push_back(new Equipo(id, criticidad, estado));
    }

    archivo.close();
    return lista;
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
            std::cout << linea << std::endl; // Imprime cada línea en la consola
        }
        std::cout << "-------------------------------------------\n" << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
}
