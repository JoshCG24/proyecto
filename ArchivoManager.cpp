//
// Created by joshu on 4/24/2026.
//
#include "ArchivoManager.h"
vector<Equipo*> ArchivoManager::cargarEquipos(const string& ruta) {
    vector<Equipo*> lista;
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        throw ArchivoInvalidoException();
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

void ArchivoManager::guardarReporteFinal(string ruta, string resumen) {
    ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ArchivoInvalidoException();
    }

    archivo << "===== RESUMEN FINAL DE SIMULACION =====" << endl;
    archivo << resumen << endl;
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