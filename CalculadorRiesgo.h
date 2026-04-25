//
// Created by joshu on 4/24/2026.
//

#ifndef PROYECTO_CALCULADORRIESGO_H
#define PROYECTO_CALCULADORRIESGO_H
#include <vector>

#include "Equipo.h"


class CalculadorRiesgo {
    public:
    double calcularRiesgoGlobal(vector<Equipo *> equipos);
    string clasificarRiesgoGlobal(vector<Equipo *> equipos);
};


#endif //PROYECTO_CALCULADORRIESGO_H