//
// Created by joshu on 4/24/2026.
//

#include "ReporteDiario.h"

string ReporteDiario::generarTexto() {
    string reporte = "";

    // dia de accion
    reporte += "Dia " + to_string(id) + "\n";

    // los 3 equipos que mas prioridad
    reporte += "Asignados: ";
    for (int i = 0; i < equiposAtendidos.size(); i++) {
        reporte += equiposAtendidos[i]->getId() + " ";
    }
    reporte += "\n";

    // Mostrar faltantes
    reporte += "Backlog pendiente: " + to_string(equiposPendientes.size()) + "\n";

    // Datos del estado del laboratori
    reporte += "Riesgo global: " + to_string(riesgoTotal) + "\n";
    reporte += "Estado general: " + estadoGeneral + "\n";
    reporte += "----------------------------------\n";

    return reporte;

}
