//
// Created by joshu on 4/24/2026.
//

#include "ReporteDiario.h"

ReporteDiario::ReporteDiario(int id,vector<Equipo*> atendidos,vector<Equipo*> pendientesLista,double riesgo,string estado) {
    this->id = id;
    this->equiposAtendidos = atendidos;
    this->equiposPendientesLista = pendientesLista;
    this->equiposPendientesConteo = (int)pendientesLista.size();
    this->riesgoTotal = riesgo;
    this->estadoGeneral = estado;
}

string ReporteDiario::generarTexto() {
        string reporte = "";


        reporte += "Dia " + to_string(id) + "\n";


        reporte += "Top prioridad : ";
        for (int i = 0; i < equiposAtendidos.size(); i++) {
            int parteEntera = (int)equiposAtendidos[i]->getPrioridad();
            int decimal     = (int)(equiposAtendidos[i]->getPrioridad() * 10) % 10;
            reporte += equiposAtendidos[i]->getId() + " (" + to_string(parteEntera) + "." + to_string(decimal) + ")";
            if (i < equiposAtendidos.size() - 1) reporte += " , ";
        }
        reporte += "\n";


        reporte += "Asignados: ";
        for (int i = 0; i < equiposAtendidos.size(); i++) {
            reporte += equiposAtendidos[i]->getId();
            if (i < equiposAtendidos.size() - 1) reporte += " , ";
        }
        reporte += "\n";


        reporte += "Backlog pendiente: " + to_string(equiposPendientesConteo) + "\n";


        if (!equiposPendientesLista.empty()) {
            reporte += "Equipos pendientes: ";
            for (int i = 0; i < equiposPendientesLista.size(); i++) {
                reporte += equiposPendientesLista[i]->getId();
                if (i < equiposPendientesLista.size() - 1) reporte += ", ";
            }
            reporte += "\n";
        }

       
        int parteEntera = (int)riesgoTotal;
        int decimales   = (int)(riesgoTotal * 100) % 100;
        string dec      = (decimales < 10) ? "0" + to_string(decimales) : to_string(decimales);
        reporte += "Riesgo global: " + to_string(parteEntera) + "." + dec + "\n";
        reporte += "Estado general: " + estadoGeneral + "\n";
        reporte += "----------------------------------\n";

        return reporte;
    }
