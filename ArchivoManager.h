//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_ARCHIVOMANAGER_H
#define PROYECTO_ARCHIVOMANAGER_H
#include <vector>

#include "Equipo.h"
#include "ReporteDiario.h"


class ArchivoManager {
    vector<Equipo*> cargarEquipos(string ruta);
    void guardarReporteDiario(ReporteDiario* reporte);
    void guardarReporteFinal(string ruta,string resumen);
};


#endif //PROYECTO_ARCHIVOMANAGER_H