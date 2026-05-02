//
// Created by joshu on 4/24/2026.
//

#include "ReporteDiario.h"

ReporteDiario::ReporteDiario(int id, vector<Equipo *> atendidos, int pendientes, double riesgo, string estado) {
    this->id = id;
    this->equiposAtendidos = atendidos;
    this->equiposPendientes = pendientes;
    this->riesgoTotal = riesgo;
    this->estadoGeneral = estado;
}

string ReporteDiario::generarTexto() {
    string reporte = "";

    // dia de accion
    reporte += "Dia " + to_string(id) + "\n";
    reporte += "Top prioridad : ";
    for (size_t i = 0; i < equiposAtendidos.size(); i++) {
        reporte += equiposAtendidos[i]->getId() + " ("
                   + to_string(equiposAtendidos[i]->getPrioridad()).substr(0,3) + ")";
        if (i < equiposAtendidos.size() - 1) reporte += " , ";
    }
    reporte += "\n";
    // los 3 equipos que mas prioridad
    reporte += "Asignados: ";
    for (int i = 0; i < equiposAtendidos.size(); i++) {
        reporte += equiposAtendidos[i]->getId() + " ";
    }
    reporte += "\n";

    // Mostrar faltantes
    reporte += "Backlog pendiente: " + to_string(equiposPendientes) + "\n";

    // Datos del estado del laboratori
    reporte += "Riesgo global: " + to_string(riesgoTotal) + "\n";
    reporte += "Estado general: " + estadoGeneral + "\n";
    reporte += "----------------------------------\n";

    return reporte;

}
