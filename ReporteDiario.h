//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_REPORTEDIARIO_H
#define PROYECTO_REPORTEDIARIO_H
#include <vector>

#include "Equipo.h"


class ReporteDiario {
private:
    int id;
    vector<Equipo*> equiposAtendidos;
    vector<Equipo*> equiposPendientes;
    double riesgoTotal;
    string estadoGeneral;

};


#endif //PROYECTO_REPORTEDIARIO_H