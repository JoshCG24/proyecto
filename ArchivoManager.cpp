//
// Created by joshu on 4/24/2026.
//

#include "ArchivoManager.h"
// Lee los equipos desde un archivo .txt
vector<Equipo*> ArchivoManager::cargarEquipos(string ruta) {
    vector<Equipo*> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de equipos." << endl;
        return lista;
    }

    string id, nombre;
    int criticidad;
    double estado;

    // Supongamos un formato simple: ID Nombre Criticidad Estado
    while (archivo >> id >> nombre >> criticidad >> estado) {
        lista.push_back(new Equipo(id, criticidad, estado));
    }

    archivo.close();
    return lista;
}

// Guarda el texto generado por un ReporteDiario en un archivo
void ArchivoManager::guardarReporteDiario(ReporteDiario* reporte) {
    // Abrimos en modo "app" (append) para no borrar lo anterior
    ofstream archivo("simulacion_diaria.txt", ios::app);

    if (archivo.is_open()) {
        archivo << reporte->generarTexto() << endl;
        archivo.close();
    }
}

// Crea un archivo final con el resumen de los 30 días
void ArchivoManager::guardarReporteFinal(string ruta, string resumen) {
    ofstream archivo(ruta);

    if (archivo.is_open()) {
        archivo << "===== RESUMEN FINAL DE SIMULACION =====" << endl;
        archivo << resumen << endl;
        archivo.close();
    }
}