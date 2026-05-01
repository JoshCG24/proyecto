//
// Created by joshu on 4/24/2026.
//

#include "CalculadorRiesgo.h"
double CalculadorRiesgo::calcularRiesgoGlobal(vector<Equipo *> equipos) {
    if (equipos.empty()) {
        return 0.0;
    }

    double sumaPrioridades = 0.0;
    for (int i = 0; i < equipos.size(); i++) {

        sumaPrioridades += equipos[i]->calcularPrioridad();
    }

    return sumaPrioridades / equipos.size();
}

string CalculadorRiesgo::clasificarRiesgoGlobal(vector<Equipo *> equipos) {
    double riesgo = calcularRiesgoGlobal(equipos);

    if (riesgo > 7.0) {
        return "ALTO";
    }
    if (riesgo > 4.0) {
        return "MEDIO";
    }
    return "BAJO";
}
