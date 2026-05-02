//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_ARCHIVOMANAGER_H
#define PROYECTO_ARCHIVOMANAGER_H
#include <vector>
#include <fstream>
using namespace std;
#include "Equipo.h"
#include "ReporteDiario.h"
#include "BuscarEquipos.h"
#include "OrdenadorEquipos.h"
#include <iostream>


class ArchivoManager {
    public:
    vector<Equipo*> cargarEquipos(const string& ruta);
    int cargarIncidencias(const string& ruta, vector<Equipo*>& equipos,BuscarEquipos* buscador, OrdenadorEquipos* ordenador);
    void guardarReporteDiario(ReporteDiario* reporte);
    void guardarReporteFinal(string ruta,string resumen);
    void imprimirArchivo(const std::string& nombreArchivo);
};


#endif //PROYECTO_ARCHIVOMANAGER_H