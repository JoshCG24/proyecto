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
    vector<Equipo*> equiposPendientesLista;
    int equiposPendientesConteo;
    double riesgoTotal;
    string estadoGeneral;

public:
    ReporteDiario(int id,vector<Equipo*> atendidos,vector<Equipo*> pendientesLista,double riesgo,string estado);
    string generarTexto();
};


#endif //PROYECTO_REPORTEDIARIO_H